# Top-level Makefile

# Macros
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INCLUDE := include
TARGET := $(BIN_DIR)/myprogram

# Default target
all:
	@$(MAKE) -C $(SRC_DIR)

# Clean all
clean:
	@$(MAKE) -C $(SRC_DIR) clean
	@echo "Cleaned top-level"

# Phony targets
.PHONY: all clean

