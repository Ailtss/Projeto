INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./build
LIB_DIR = ./lib
BIN_DIR = ./bin
DOC_DIR = ./doc

.PHONY: all clean debug doxy doc

CC = g++
CPPFLAGS += -I$(INC_DIR) -ansi -Wall -pedantic -ansi -Wpedantic -pg -std=c++11 -I -g.
LDFLAGS += -L$(LIB_DIR)
LDLIBS += -lm
RM = rm -f

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
PROG = $(BIN_DIR)/PetFera

all: $(PROG)

$(PROG): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

debug: all

debug: CPPFLAGS += -g -O0

doxy:
	doxygen -g

doc:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
