COMPILER=g++ -std=c++11 -g
EXE_FILE=asm4

all: $(EXE_FILE)

$(EXE_FILE): bats.o event.o game.o gold.o room.o stalactites.o wumpus.o player.o main.cpp
	$(COMPILER) bats.o event.o game.o gold.o room.o stalactites.o wumpus.o player.o main.cpp -lcurses -o $(EXE_FILE)

bats.o: bats.h bats.cpp
	$(COMPILER) -c bats.cpp

event.o: event.h event.cpp
	$(COMPILER) -c event.cpp

game.o: game.h game.cpp
	$(COMPILER) -c game.cpp

gold.o: gold.h gold.cpp
	$(COMPILER) -c gold.cpp

room.o: room.h room.cpp
	$(COMPILER) -c room.cpp

stalactites.o: stalactites.h stalactites.cpp
	$(COMPILER) -c stalactites.cpp

wumpus.o: wumpus.h wumpus.cpp
	$(COMPILER) -c wumpus.cpp

player.o: player.h player.cpp
	$(COMPILER) -c player.cpp

clean:
	rm -f *.o $(EXE_FILE)

