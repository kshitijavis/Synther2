configure_file(
    "config.hpp.in" # File we want to move
    "${CMAKE_BINARY_DIR}/configured_files/include/config.hpp" # Where to move to
    ESCAPE_QUOTES
)