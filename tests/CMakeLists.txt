include_directories(include)
include_directories(../lib/include)

set(TEST_SOURCES
    "src/speakvm-test.c"
    )

foreach(TEST_FILE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable("newspeak-${TEST_NAME}" ${TEST_FILE})
    target_link_libraries("newspeak-${TEST_NAME}" newspeak-lib)
    add_test("${TEST_NAME}s" "newspeak-${TEST_NAME}")
endforeach(TEST_FILE)

