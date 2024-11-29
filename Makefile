lexer: src/parse/dreamberd-scanner.yy.cc

src/parse/dreamberd-scanner.yy.cc: src/parse/dreamberd-scanner.ll
	flex -o src/parse/dreamberd-scanner.yy.cc src/parse/dreamberd-scanner.ll
