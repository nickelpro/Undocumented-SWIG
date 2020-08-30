#include <cstdint>
#include <string>

struct AgentUpdate {
  int id;
  std::string cover_name;
  float health;
  std::uint64_t secret;
};
