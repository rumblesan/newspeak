include_directories(include)

find_package(BISON 3.0)
find_package(FLEX 2.5)

bison_target(NSParser grammar/newspeak.y ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c)
flex_target(NSLexer
    grammar/newspeak.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
    COMPILE_FLAGS --header-file=${CMAKE_CURRENT_BINARY_DIR}/lex.yy.h
)
add_flex_bison_dependency(NSLexer NSParser)

add_executable(newspeak
    ${BISON_NSParser_OUTPUTS}
    ${FLEX_NSLexer_OUTPUTS}
)

