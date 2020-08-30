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
  SecretAgent(int id, const std::string& call_sign);

  AgentUpdate generate_update();
  enum combat_result {
    COMBAT_DEFEAT,
    COMBAT_VICTORY,
    COMBAT_TIE,
  };
  combat_result combat(SecretAgent& other);

private:
  const int id;
  float health;
  std::default_random_engine random_engine;
  std::uniform_int_distribution<std::uint64_t> secret_generator;
  std::uniform_real_distribution<float> combat_generator;
};
