include_directories(include)
include_directories(../collections/include)
include_directories(../parser/include)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(newspeak
    ${SOURCES}
)

target_link_libraries(newspeak newspeak-collections)
target_link_libraries(newspeak newspeak-parser)
