COMPILER=g++
EXE_FILE=shop_run

all: $(EXE_FILE)

$(EXE_FILE): coffee.o coffee.h display.o display.h menu.o menu.h order.o order.h shop.o shop.h prog.cpp
	$(COMPILER) coffee.o display.o menu.o order.o shop.o prog.cpp -o $(EXE_FILE)

coffee.o: coffee.h coffee.cpp
	$(COMPILER) -c coffee.cpp

display.o: display.h display.cpp
	$(COMPILER) -c display.cpp

menu.o: menu.h menu.cpp
	$(COMPILER) -c menu.cpp

order.o: order.h order.cpp
	$(COMPILER) -c order.cpp

shop.o: shop.h shop.cpp
	$(COMPILER) -c shop.cpp

clean:
	rm -f *.o $(EXE_FILE)
