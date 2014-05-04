CXX = g++
CXXFLAGS = -Wall -MMD -lX11
EXEC = quadris
OBJECTS = main.o function.o rootapproximator.o scope.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
	