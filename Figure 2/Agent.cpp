#include "Agent.hpp"

SecretAgent::SecretAgent(const int id) : id(id), call_sign("Spy"),
    health(100.0), random_engine(std::random_device{}()) {}

AgentUpdate SecretAgent::generate_update() {
  return AgentUpdate {
    .id = id,
    .cover_name = cover_name,
    .health = health,
    .secret = secret_generator(random_engine)
  };
}
