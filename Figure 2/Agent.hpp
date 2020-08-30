#include <cstdint>
#include <string>
#include <random>

struct AgentUpdate {
  int id;
  std::string call_sign;
  float health;
  std::uint64_t secret;
};

class SecretAgent {
public:
  std::string call_sign;

  SecretAgent(int id);
  AgentUpdate generate_update();

private:
  const int id;
  float health;
  std::default_random_engine random_engine;
  std::uniform_int_distribution<std::uint64_t> secret_generator;
};
