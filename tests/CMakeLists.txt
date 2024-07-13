include(Catch)

if(ENABLE_TESTING)
    set(TEST_MAIN "unit_test")
    set(TEST_SOURCES 
        "test_note.cc"
    )
    set(TEST_INCLUDES "./")

    add_executable(${TEST_MAIN} ${TEST_SOURCES})
    target_include_directories(${TEST_MAIN} PUBLIC ${TEST_INCLUDES})
    target_link_libraries(${TEST_MAIN} PRIVATE
        ${LOGIC_LIBRARY_NAME}
        Catch2::Catch2WithMain
    )

    catch_discover_tests(${TEST_MAIN})

    # Run make check to compile tests (make unit_test) AND run them (make test)
    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
    add_dependencies(check ${TEST_MAIN})
endif()