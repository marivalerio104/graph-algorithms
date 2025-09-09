# C++ compiler
XC = g++

# Directories
OBJ_DIR = build
SRC_DIR = src
BIN_DIR = bin

FLAGS = $(strip -Wall -Wextra)

# Creates a list of the cpp files in SRC_DIR
SOURCE_FILES = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/heap/*.cpp $(SRC_DIR)/graph/*.cpp)

# Creates a list of .o files based on the list of .cpp files
OBJECT_FILES = $(SOURCE_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Creates the executable
$(BIN_DIR)/graph_algorithms.exe: $(OBJECT_FILES)	
	mkdir -p $(@D)
	$(XC) $(OBJ_DIR)/*.o $(OBJ_DIR)/*/*.o -o $(BIN_DIR)/graph_algorithms.exe
	rm -rf $(OBJ_DIR) 
	
# Compiles the .cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(XC) $(FLAGS) -c $< -o $@

run: 
	bin/graph_algorithms.exe

# Deletes the BIN_DIR and OBJ_DIR directories
clean:
	rm -rf $(BIN_DIR) 
	rm -rf $(OBJ_DIR) 
	