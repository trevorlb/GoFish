testGame: goFishDriver.o deck.o card.o player.o
	g++ -o testGame goFishDriver.o deck.o card.o player.o
driver: goFishDriver.cpp deck.h card.h player.h
	g++ -c goFishDriver.cpp
player.o: player.cpp player.h deck.h card.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp
