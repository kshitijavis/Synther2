#include "synther.h"

#include <iostream>
#include "logic/note.h"

int main(int argc, char *argv[]) {
  std::cout << argv[0] << " Version " << synther_VERSION_MAJOR << "."
            << synther_VERSION_MINOR << std::endl;
  std::cout << "Usage: " << argv[0] << std::endl;
  return 0;
}