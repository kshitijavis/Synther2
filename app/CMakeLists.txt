set(APP_SOURCES
    "synther.cpp"
)

add_executable(${EXECUTABLE_NAME} ${APP_SOURCES})
target_link_libraries(${EXECUTABLE_NAME} PRIVATE
    ${LOGIC_LIBRARY_NAME}
)