#pragma once

#include <map>

namespace synther {

namespace logic {

enum class NoteLetter { A, B, C, D, E, F, G };
enum class Accidental { Sharp, Flat, Natural };

/**
 * Represents a music note. Uses the MIDI standard to index notes based on their
 * distance from C_-1. Allows notes to take on various other forms, such as
 * English standard (A#, Bb, ...)
 */
class Note {
 public:
  static const NoteLetter kBaseNote = NoteLetter::C;
  static constexpr int kBaseOctave = -1;
  static constexpr size_t kOctaveLength = 12;

  /**
   * Construct note given a midi index, as an offset from the base note C_-1
   * @param midi_index the index of the note from C_-1
   * @param priority if the note requires an accidental, this param specifies
   * which type of accidental takes priority. If the note requires an
   * accidental, but priority is passes as Natural, then an exception is thrown.
   * If the note does not require an accidental, then priority is ignored
   */
  Note(unsigned midi_index, Accidental priority);

  /**
   * Construct note given English name components. The smallest possible note is
   * C_-1
   * @param note_letter an English note letter
   * @param accidental sharp, flat or natural
   * @param octave the octave of the note. Smallest possible value is -1
   */
  Note(int octave, NoteLetter note_letter, Accidental accidental);

  int GetMidiIndex() const;
  int GetOctave() const;
  Accidental GetAccidental() const;
  NoteLetter GetNoteLetter() const;

  bool operator==(const Note& other) const;
  bool EqualsMidiIndex(const Note& other) const;

 private:
  static const std::map<NoteLetter, int> kWholetoneIndices;

  struct EnglishName {
    NoteLetter note_letter;
    Accidental accidental;
    int octave;
  };

  unsigned midi_index_;
  EnglishName english_name_;

  EnglishName ComputeEnglishName(int midi_index, Accidental priority);
  unsigned ComputeMidiIndex(int octave, NoteLetter note_letter, Accidental accidental);
};

/**
 * An iterator for Notes. Allows traversing the musical scale in a consistent way. Priotizes
 * constructions based on Accidental::Sharp
 *
 * Incrementing and decrementing causes the iterator to create new instances of Note.
 * Notes are not maintained in memory during iteration.
 */
class NoteIterator {
  using iterator_category = std::forward_iterator_tag;
  using different_type = int;
  using value_type = Note;
  using pointer = Note*;
  using reference = Note&;

 public:
  static const Accidental kDefaultAccidental = Accidental::Sharp;

  NoteIterator(Note note);
  const Note& operator*() const;
  const Note* operator->() const;
  NoteIterator operator++();     // prefix
  NoteIterator operator++(int);  // postfix
  bool operator==(const NoteIterator& other) const;
  bool operator!=(const NoteIterator& other) const;

 private:
  Note note_;

  bool equals(const NoteIterator& other) const;
  Note getNextNote() const;
};

}  // namespace logic

}  // namespace synther