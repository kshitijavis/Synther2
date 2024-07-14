#pragma once

#include <set>

#include "note.h"

namespace synther {
namespace logic {

enum class KeyColor { White, Black };

class Key {
 public:
  Key(const Note& note);

  KeyColor GetKeyColor() const;
  const Note& GetNote() const;
  bool IsPressed() const;

  void Press();
  void Release();

 private:
  const logic::Note note_;
  logic::KeyColor key_color_;
  bool is_pressed_;

  KeyColor ComputeKeyColor(unsigned midi_index);
};

}  // namespace logic
}  // namespace synther