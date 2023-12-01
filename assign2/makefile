COMPILER=g++
EXE_FILE=database_run

all: $(EXE_FILE)

$(EXE_FILE): catalog.o catalog.h game.o game.h run_catalog.cpp
	$(COMPILER) catalog.o game.o run_catalog.cpp -o $(EXE_FILE)

catalog.o: catalog.h catalog.cpp game.h game.cpp
	$(COMPILER) -c catalog.cpp game.cpp

clean:
	rm -f *.o $(EXE_FILE)
