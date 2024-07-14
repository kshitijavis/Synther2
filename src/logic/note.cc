#include "logic/note.h"

namespace synther {

namespace logic {

const std::map<NoteLetter, int> Note::kWholetoneIndices{
    {NoteLetter::C, 0}, {NoteLetter::D, 2}, {NoteLetter::E, 4},
    {NoteLetter::F, 5}, {NoteLetter::G, 7}, {NoteLetter::A, 9},
    {NoteLetter::B, 11}};

Note::Note(unsigned midi_index, Accidental priority)
    : midi_index_{midi_index},
      english_name_{ComputeEnglishName(midi_index, priority)} {}

Note::Note(int octave, NoteLetter note_letter, Accidental accidental)
    : midi_index_{ComputeMidiIndex(octave, note_letter, accidental)},
      english_name_{note_letter, accidental, octave} {}

int Note::GetMidiIndex() const { return midi_index_; }
int Note::GetOctave() const { return english_name_.octave; }
Accidental Note::GetAccidental() const { return english_name_.accidental; }
NoteLetter Note::GetNoteLetter() const { return english_name_.note_letter; };

Note::EnglishName Note::ComputeEnglishName(int midi_index,
                                           Accidental priority) {
  EnglishName english_name_;
  english_name_.octave = kBaseOctave + midi_index / kOctaveLength;
  int octave_index = midi_index % kOctaveLength;

  std::map<int, NoteLetter> reversedWholeToneIndices;
  for (const auto &wholeToneIndexPair : kWholetoneIndices) {
    reversedWholeToneIndices[wholeToneIndexPair.second] =
        wholeToneIndexPair.first;
  }

  auto potentialNote = reversedWholeToneIndices.find(octave_index);
  if (potentialNote != reversedWholeToneIndices.end()) {
    english_name_.note_letter = potentialNote->second;
    english_name_.accidental = Accidental::Natural;
    return english_name_;
  }

  switch (priority) {
    case Accidental::Natural:
      throw std::invalid_argument(
          "Note requires accidental, cannot provide Natural priority");
    case Accidental::Flat:
      english_name_.note_letter = reversedWholeToneIndices.at(octave_index + 1);
      break;
    case Accidental::Sharp:
      english_name_.note_letter = reversedWholeToneIndices.at(octave_index - 1);
      break;
  }

  english_name_.accidental = priority;
  return english_name_;
}

unsigned Note::ComputeMidiIndex(int octave, NoteLetter note_letter,
                                Accidental accidental) {
  if (octave < -1 || (octave == -1 && note_letter == NoteLetter::C &&
                      accidental == Accidental::Flat)) {
    throw std::invalid_argument("Note must be >= C_-1");
  }

  unsigned midi_index_of_prev_c = (octave - kBaseOctave) * kOctaveLength;
  unsigned midi_index_of_natural =
      midi_index_of_prev_c + kWholetoneIndices.at(note_letter);

  switch (accidental) {
    case Accidental::Natural:
      return midi_index_of_natural;
    case Accidental::Flat:
      return midi_index_of_natural - 1;
    case Accidental::Sharp:
      return midi_index_of_natural + 1;
  }
}

}  // namespace logic
}  // namespace synther