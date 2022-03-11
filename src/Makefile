OBJ = main.cpp Aquarium.o Bestiole.o Milieu.o Accessoires/ConcreteCreatorCamouflage.o Accessoires/ConcreteCreatorCarapace.o Accessoires/ConcreteCreatorNageoire.o Accessoires/Camouflage.o Accessoires/Carapace.o Accessoires/Nageoire.o
CC = g++

main : $(OBJ)
	$(CC) -Wall -std=c++11 -o main $(OBJ) -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	$(CC) -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	$(CC) -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	$(CC) -Wall -std=c++11  -c Milieu.cpp -I .

Camouflage.o: Camouflage.cpp Camouflage.h IAccessoire.h
	$(CC) -Wall -std=c++11 -c Camouflage.cpp -I

Carapace.o: Carapace.cpp Carapace.h IAccessoire.h
	$(CC) -Wall -std=c++11 -c Carapace.cpp -I

Nageoire.o: Nageoire.cpp Nageoire.h IAccessoire.h
	$(CC) -Wall -std=c++11 -c Nageoire.cpp -I

ConcreteCreatorCamouflage.o: ConcreteCreatorCamouflage.cpp ConcreteCreatorCamouflage.h Camouflage.h
	$(CC) -Wall -std=c++11 -c ConcreteCreatorCamouflage.cpp -I

ConcreteCreatorCarapace.o: ConcreteCreatorCarapace.cpp ConcreteCreatorCarapace.h Carapace.h
	$(CC) -Wall -std=c++11 -c ConcreteCreatorCarapace.cpp -I

ConcreteCreatorNageoire.o: ConcreteCreatorNageoire.cpp ConcreteCreatorNageoire.h Nageoire.h
	$(CC) -Wall -std=c++11 -c ConcreteCreatorNageoire.cpp -I

clean:
	rm -f *.o ./Accessoires/*.o ./main


