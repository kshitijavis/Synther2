#pragma once

#include <key.h>

#include <vector>

namespace synther {
namespace logic {

class Keyboard {
 private:
  std::vector<logic::Key> keys_;
};

}  // namespace logic
}  // namespace synther