OBJ = main.cpp Aquarium.o Bestiole.o IBestiole.o ConcreteCreatorBestiole.o Milieu.o comportements/ComportementPeureuse.o comportements/Deplacements.o #Capteurs/capteurFactory.o
CC = g++

main : $(OBJ)
	$(CC) -Wall -std=c++11 -o main $(OBJ) -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	$(CC) -Wall -std=c++11  -c Aquarium.cpp -I .

IBestiole.o : IBestiole.h IBestiole.cpp
	$(CC) -Wall -std=c++11  -c IBestiole.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp IBestiole.h
	$(CC) -Wall -std=c++11  -c Bestiole.cpp -I .

ConcreteCreatorBestiole.o: ConcreteCreatorBestiole.cpp ConcreteCreatorBestiole.h BestiolesFactory.h Bestiole.h
	$(CC) -Wall -std=c++11  -c ConcreteCreatorBestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	$(CC) -Wall -std=c++11  -c Milieu.cpp -I .

ComportementPeureuse.o: ComportementPeureuse.h ComportementPeureuse.cpp IComportement.h 
	$(CC) -Wall -std=c++11  -c ComportementPeureuse.cpp -I .

Deplacements.o: Deplacements.h Deplacements.cpp
	$(CC) -Wall -std=c++11  -c Deplacements.cpp -I .

# capteurFactory.o : capteur.h yeux.h corps.h oreilles.h capteurFactory.cpp
# 	$(CC) -Wall -std=c++11  -c capteurFactory.cpp -I .

clean:
	rm -f *.o ./Accessoires/*.o ./comportements/*.o ./Capteurs/*.o ./main

# main : main.cpp Aquarium.o Bestiole.o Milieu.o
# 	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o -I . -lX11 -lpthread

# Aquarium.o : Aquarium.h Aquarium.cpp
# 	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

# Bestiole.o : Bestiole.h Bestiole.cpp
# 	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

# Milieu.o : Milieu.h Milieu.cpp
# 	g++ -Wall -std=c++11  -c Milieu.cpp -I .



