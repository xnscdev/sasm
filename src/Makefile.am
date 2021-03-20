AM_CFLAGS = -std=gnu99 -Wall -pedantic -Werror=implicit -fno-common
AM_CXXFLAGS = -std=gnu++11 -Wall -pedantic -fno-exceptions -frtti
AM_YFLAGS = -d -Wno-yacc -Wcex

BUILT_SOURCES = intel-parse.hh

bin_PROGRAMS = sasm

noinst_LIBRARIES = libsasm.a

libsasm_a_SOURCES =	\
	assemble.cc	\
	assemble.hh	\
	coff.h		\
	directive.hh	\
	dtv-define.cc	\
	dtv-times.cc	\
	elf.h		\
	expr.hh		\
	gen-coff.cc	\
	gen-coff.hh	\
	gen-elf.cc	\
	gen-elf.hh	\
	inst.hh		\
	inst-call.cc	\
	inst-callf.cc	\
	inst-dec.cc	\
	inst-div.cc	\
	inst-idiv.cc	\
	inst-imul.cc	\
	inst-in.cc	\
	inst-inc.cc	\
	inst-int.cc	\
	inst-jmp.cc	\
	inst-jmpf.cc	\
	inst-lea.cc	\
	inst-mov.cc	\
	inst-mul.cc	\
	inst-neg.cc	\
	inst-not.cc	\
	inst-pop.cc	\
	inst-push.cc	\
	inst-repnz.cc	\
	inst-repz.cc	\
	inst-ret.cc	\
	inst-out.cc	\
	inst-test.cc	\
	inst-xchg.cc	\
	insts-arith.cc	\
	insts-ascii.cc	\
	insts-jf.cc	\
	insts-loop.cc	\
	insts-rotshf.cc	\
	insts-str.cc	\
	insts-zo.cc	\
	memloc.cc	\
	opcodes.h	\
	registers.cc	\
	util.cc		\
	util.hh

sasm_SOURCES =		\
	driver.cc	\
	error.cc	\
	error.hh	\
	intel-lex.ll	\
	intel-parse.yy

sasm_LDADD = libsasm.a
