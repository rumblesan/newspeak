include_directories(include)
include_directories(../lib/include)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(newspeak
    ${SOURCES}
)

target_link_libraries(newspeak newspeak-lib)

find_package(BCLib REQUIRED)
include_directories("${BCLIB_INCLUDE_DIRS}")
target_link_libraries(newspeak bclib)

