import random, time

import CAgent

class Agency:
  def __init__(self, agency_size, call_signs):
    self.agents = []

    for i in range(agency_size):
      call_sign = random.choice(call_signs)
      call_signs.remove(call_sign)
      self.agents.append(CAgent.SecretAgent(i, call_sign))

  def select_combatant(self):
    return random.choice(self.agents)

  def __bool__(self):
    return bool(self.agents)

Western_Agency = Agency(5, open("English Call Signs.txt").read().splitlines())
Eastern_Agency = Agency(5, open("Russian Call Signs.txt").read().splitlines())

def run_combat_round(attacking_agency, defending_agency):
  attacker = attacking_agency.select_combatant()
  defender = defending_agency.select_combatant()
  result = attacker.combat(defender)

  if result == attacker.COMBAT_VICTORY:
    print(f"Agent \"{attacker.call_sign}\" ambushed Agent "
        f"\"{defender.call_sign}\" and defeated them!")
    defending_agency.agents.remove(defender)

  elif result == attacker.COMBAT_DEFEAT:
    print(f"Agent \"{attacker.call_sign}\" engaged Agent "
        f"\"{defender.call_sign}\", but it was a trap! "
        f"Agent \"{attacker.call_sign}\" was subdued.")
    attacking_agency.agents.remove(attacker)

  else:
    print(f"Agent \"{attacker.call_sign}\" engaged Agent "
        f"\"{defender.call_sign}\", and neither side won decisively. "
        "Both agents retreat to lick their wounds.")

# Defines the sleep interval, so smaller numbers are faster
COMBAT_SPEED = 2

while Western_Agency and Eastern_Agency:
  first = random.choice((Western_Agency, Eastern_Agency))
  second = Western_Agency if first is Eastern_Agency else Eastern_Agency

  run_combat_round(first, second)
  time.sleep(COMBAT_SPEED)

  if Western_Agency and Eastern_Agency:
    run_combat_round(second, first)
    time.sleep(COMBAT_SPEED)

if(Western_Agency):
  print("The East has fallen to the West")
else:
  print("The West has fallen to the East")
