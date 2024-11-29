all: dbw

dreamberdwings: src/main.cc src/parse/dreamberd-scanner.yy.cc src/parse/dreamberd-parser.tab.cc src/parse/dreamberd-driver.cc
	g++ src/main.cc src/parse/dreamberd-scanner.yy.cc src/parse/dreamberd-parser.tab.cc src/parse/dreamberd-driver.cc -o dreamberdwings -std=gnu++17
dbw: dreamberdwings
	cp dreamberdwings dbw

all: parser

lexer: src/parse/dreamberd-scanner.yy.cc
parser: src/parse/dreamberd-parser.tab.cc

src/parse/dreamberd-scanner.yy.cc: src/parse/dreamberd-scanner.ll
	flex -o src/parse/dreamberd-scanner.yy.cc src/parse/dreamberd-scanner.ll

src/parse/dreamberd-parser.tab.cc: src/parse/dreamberd-parser.yy
	bison src/parse/dreamberd-parser.yy -o src/parse/dreamberd-parser.tab.cc

clean:
	rm -rf src/parse/dreamberd-scanner.yy.cc
	rm -rf src/parse/dreamberd-parser.tab.cc src/parse/dreamberd-parser.tab.hh src/parse/location.hh src/parse/position.hh src/parse/stack.hh
	rm -rf dreamberdwings dbw

format:
	clang-format -i src/*/*.hh src/*/*.cc src/main.cc
