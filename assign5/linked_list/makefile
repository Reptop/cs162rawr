COMPILER=g++
EXE_FILE=run

all: $(EXE_FILE)

$(EXE_FILE): linked_list.o node.o test_linked_list.cpp
	$(COMPILER) linked_list.o node.o test_linked_list.cpp -o $(EXE_FILE)

linked_list.o: linked_list.h linked_list.cpp
	$(COMPILER) -c linked_list.cpp

node.o: node.h node.cpp
	$(COMPILER) -c node.cpp

clean:
	rm -f *.o $(EXE_FILE)

