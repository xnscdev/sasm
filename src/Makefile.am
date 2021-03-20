AM_CFLAGS = -std=gnu99 -Wall -pedantic -Werror=implicit -fno-common
AM_CXXFLAGS = -std=gnu++11 -Wall -pedantic -fno-exceptions -frtti
AM_YFLAGS = -d -Wno-yacc -Wcex

BUILT_SOURCES = intel-parse.hh

bin_PROGRAMS = sasm

sasm_SOURCES =		\
	assemble.cc	\
	assemble.hh	\
	coff.h		\
	driver.cc	\
	elf.h		\
	error.cc	\
	error.hh	\
	expr.hh		\
	inst.hh		\
	inst-in.cc	\
	inst-neg.cc	\
	inst-not.cc	\
	inst-out.cc	\
	insts-str.cc	\
	insts-zo.cc	\
	intel-lex.ll	\
	intel-parse.yy	\
	memloc.cc	\
	opcodes.h	\
	registers.cc	\
	util.cc		\
	util.hh
