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
  std::string call_sign {"Spy"};

  SecretAgent(int id);
  AgentUpdate generate_update();

private:
  const int id;
  float health {100.0};
  std::default_random_engine random_engine {std::random_device{}()};
  std::uniform_int_distribution<std::uint64_t> secret_generator;
};
