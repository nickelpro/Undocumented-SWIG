#include "Agent.hpp"

SecretAgent::SecretAgent(const int id) : call_sign("Spy"), id(id),
    health(100.0), random_engine(std::random_device{}()),
    combat_generator(0, 100) {}

SecretAgent::SecretAgent(const int id, const std::string& call_sign) :
    call_sign(call_sign), id(id), health(100.0),
    random_engine(std::random_device{}()), combat_generator(0, 100) {}

AgentUpdate SecretAgent::generate_update() {
  return AgentUpdate {
    .id = id,
    .call_sign = call_sign,
    .health = health,
    .secret = secret_generator(random_engine)
  };
}

SecretAgent::combat_result SecretAgent::combat(SecretAgent& other) {
  other.health -= combat_generator(random_engine);
  if(other.health > 0)
    health -= combat_generator(random_engine);
  else
    return SecretAgent::COMBAT_VICTORY;
  if(health > 0)
    return SecretAgent::COMBAT_TIE;
  return SecretAgent::COMBAT_DEFEAT;
}
