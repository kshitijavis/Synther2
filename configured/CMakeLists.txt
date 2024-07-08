configure_file(
    "config.h.in" # File we want to move
    "${CMAKE_BINARY_DIR}/configured_files/include/config.h" # Where to move to
    ESCAPE_QUOTES
)