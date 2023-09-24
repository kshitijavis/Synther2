set(LOGIC note.cpp ${synther_SOURCE_DIR}/include/logic/note.h)
add_library(logic ${LOGIC})

target_include_directories(logic PUBLIC ${synther_SOURCE_DIR}/include)