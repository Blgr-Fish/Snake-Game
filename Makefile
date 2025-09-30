CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp Snake.cpp SnakePart.cpp Food.cpp Game.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = snake-game

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
