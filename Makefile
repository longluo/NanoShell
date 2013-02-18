#
# Makefile - Rules for building the NaSH program.
# 	Written by long.luo <uniqueluolong@gmail.com>
#	
#	History:
#		long.luo, 12/11/2012, created it.
#		long.luo, 13/11/2012, modified it.
#


# The compiler to be used.
ifndef COMPILER
COMPILER=gcc
endif

# Definitions for using GCC.
ifeq (${COMPILER}, gcc)

# The command for calling the compiler.
CC=gcc

# The flags passed to the compiler.
CFLAGS :=	-Wall \
			-Os  \
			-c

# The command for calling the linker.
LD=ld

# The Linker flags passed to the linker.
LDFLAGS := --gc-sections

# The PHONY targets.	
.PHONY: all clean

# The default rule, which causes the Application to be built.
all: NaSH

# The rule to create the target directory.
${COMPILER}:
	mkdir ${COMPILER}

# The rule for building the object file from each C source file.
%.o : %.c
	${CC} ${CFLAGS} -D${COMPILER} -o $@ $<

# The objects.
OBJS :=	main.o	\
		NanoShell_task.o	\
		NanoShell.o	\
		commands/about.o	\
		commands/memop.o

# The final executable file.
exec=NaSH
	
# The rule for building the application.
NaSH: ${OBJS}
	@echo "Done building object files"
	@echo
	$(CC) -o $@ $?
	@echo "Done"

# The rule to clean out all the build products.
clean:
	@echo "Cleaning object files..."
	rm -f ${wildcard *.o} ${wildcard commands/*.o} ${exec} 
	@echo "Done"
	
endif
