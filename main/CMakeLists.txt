file(GLOB_RECURSE MAIN_SOURCES "src/main.c")

add_executable(newspeak ${MAIN_SOURCES})

set_property(TARGET newspeak PROPERTY C_STANDARD 99)
