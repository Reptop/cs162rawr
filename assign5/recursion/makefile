COMPILER=g++
EXE_FILE=run

all: $(EXE_FILE)

$(EXE_FILE): stairs.o recurse.cpp
	$(COMPILER) stairs.o recurse.cpp -o $(EXE_FILE)

stairs.o: stairs.h stairs.cpp
	$(COMPILER) -c stairs.cpp

clean:
	rm -f *.o $(EXE_FILE)
