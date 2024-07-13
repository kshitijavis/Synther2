#include "note.h"

namespace synther {

namespace logic {

Note::Note(int midi_index) : midi_index_{midi_index} {}

int Note::GetMidiIndex() { return midi_index_; }

}  // namespace logic
}  // namespace synther