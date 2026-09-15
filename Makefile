# Compiler settings
CC = gcc
# Added -MMD and -MP for automatic dependency generation
CFLAGS = -Wall -Wextra -std=c11 -Iinclude -MMD -MP
LDFLAGS = -lSDL2 -lm

# Directories
SRC_DIR = src
BUILD_DIR = build

# Project files
TARGET = functionPlotter
SRCS = $(SRC_DIR)/functionPlotter.c $(SRC_DIR)/plottify.c $(SRC_DIR)/tinyexpr.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# New variable for dependency files (.d)
DEPS = $(OBJS:.o=.d)

# Default target to build the program
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Rule to compile .c files into .o files inside the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up compiled files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Include the generated dependency files
-include $(DEPS)
