CXX = g++-9
CXXFLAGS = -std=c++17 -Wall -MMD -g
EXEC = game
OBJECTS = main.o TicTacToe.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}