#include "Agent.hpp"

SecretAgent::SecretAgent(const int id) : id(id) {}

AgentUpdate SecretAgent::generate_update() {
  return AgentUpdate {
    .id = id,
    .call_sign = call_sign,
    .health = health,
    .secret = secret_generator(random_engine)
  };
}
