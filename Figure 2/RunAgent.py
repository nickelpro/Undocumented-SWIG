import CAgent

TestAgent = CAgent.SecretAgent(451)
TestAgent.call_sign = "Fireman"
update = TestAgent.generate_update()
print(f"Agent {update.id:04}, call sign \"{update.call_sign}\", reports: "
    f"{update.secret}")
