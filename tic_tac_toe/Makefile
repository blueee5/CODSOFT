CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC = src
OBJ = build

all: $(OBJ)/main.o $(OBJ)/board.o
	$(CXX) $(CXXFLAGS) -o tic_tac_toe $(OBJ)/main.o $(OBJ)/board.o

$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/board.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/board.o: $(SRC)/board.cpp $(SRC)/board.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/board.cpp -o $(OBJ)/board.o

clean:
	rm -rf $(OBJ)/*.o tic_tac_toe

.PHONY: clean
