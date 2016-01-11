include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")
add_library(newspeak-collections SHARED ${SOURCES})
