cmake_minimum_required(VERSION 3.10)
project(DreamBerdWings)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cc)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS src/*.hh src/*.hxx)

set(FLEX_INPUT src/parse/dreamberd-scanner.ll)
set(BISON_INPUT src/parse/dreamberd-parser.yy)

set(FLEX_OUTPUT src/parse/dreamberd-scanner.yy.cc)
set(BISON_OUTPUT src/parse/dreamberd-parser.tab.cc)
set(BISON_HEADER src/parse/dreamberd-parser.tab.hh)

add_custom_command(
    OUTPUT ${FLEX_OUTPUT}
    COMMAND flex -o ${FLEX_OUTPUT} ${FLEX_INPUT}
    DEPENDS ${FLEX_INPUT}
    COMMENT "Generating lexer with Flex"
)

add_custom_command(
    OUTPUT ${BISON_OUTPUT} ${BISON_HEADER}
    COMMAND /usr/local/Cellar/bison/3.8.2/bin/bison -o ${BISON_OUTPUT} ${BISON_INPUT}
    DEPENDS ${BISON_INPUT}
    COMMENT "Generating parser with Bison"
)

add_executable(dreamberdwings
    ${SOURCES}
    ${FLEX_OUTPUT}
    ${BISON_OUTPUT}
)

add_custom_target(dbw ALL
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dreamberdwings> dbw
    DEPENDS dreamberdwings
    COMMENT "Copying dreamberdwings to dbw"
)

add_custom_target(format
    COMMAND clang-format -i ${SOURCES} ${HEADERS}
    COMMENT "Formatting source files with clang-format"
)
