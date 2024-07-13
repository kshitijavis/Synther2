#pragma once

#include "note.h"

namespace synther {
namespace logic {

enum class KeyColor { kWhite, kBlack };

class Key {
 private:
  logic::Note note_;
  logic::KeyColor key_color_;
};

}  // namespace logic
}  // namespace synther