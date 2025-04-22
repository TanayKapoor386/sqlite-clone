# Compiler
CC = gcc

# common compiler warnings, ensure C99 standard is used, and include debug symbols
# Compiler flags
CFLAGS = -Wall -Wextra -std=c99 -g

# Dependencies to check for necessary recompile
DEPS = main.h

# All .c files compile into object files
OBJ = main.o

# Pattern rule
# % states that for all .c files, make a .o file and recompile if any header in DEPS changes
# ONLY compile with no linking
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


# Link all objects into executable
db: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# make.clean deletes all .o files
clean:
	rm -f *.o db