# Macros
CC := gcc
CFLAGS := -Wall -I../$(INCLUDE)
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,../obj/%.o,$(SRC))
TARGET := ../bin/myprogram

# Default target
all: $(TARGET)

# Link objects
$(TARGET): $(OBJ) | ../bin
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files to objects
../obj/%.o: %.c | ../obj
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if not exist
../obj ../bin:
	mkdir -p $@

# Clean objects and executable
clean:
	rm -f ../obj/*.o
	rm -f ../bin/myprogram
	@echo "Cleaned src objects and executable"

.PHONY: all clean

