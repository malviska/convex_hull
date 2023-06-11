# Makefile

# Compiler options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Source directory
SRC_DIR := ./src

# Object directory
OBJ_DIR := ./obj

# Include directory
INC_DIR := ./include

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Target executable
TARGET := ./bin/tp2

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
