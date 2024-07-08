set(APP_SOURCES
    "synther.cpp"
)
set(APP_INCLUDES
    "${CMAKE_BINARY_DIR}/configured_files/include"
)

message(STATUS "${CMAKE_BINARY_DIR}/configured_files/include")

add_executable(${EXECUTABLE_NAME} ${APP_SOURCES})
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${APP_INCLUDES})
target_link_libraries(${EXECUTABLE_NAME} PRIVATE
    ${LOGIC_LIBRARY_NAME}
)