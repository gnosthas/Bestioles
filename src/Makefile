OBJ = main.cpp Aquarium.o Bestiole.o IBestiole.o ConcreteCreatorBestiole.o Milieu.o capteurFactory.o corps.o oreilles.o yeux.o
CC = g++

main : $(OBJ)
	$(CC) -Wall -std=c++11 -o main $(OBJ) -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	$(CC) -Wall -std=c++11  -c Aquarium.cpp -I .

IBestiole.o : IBestiole.h IBestiole.cpp
	$(CC) -Wall -std=c++11  -c IBestiole.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp IBestiole.h
	$(CC) -Wall -std=c++11  -c Bestiole.cpp -I .

capteurFactory.o: Capteurs/capteurFactory.cpp Capteurs/capteurFactory.h Capteurs/capteur.h Capteurs/yeux.h Capteurs/oreilles.h Capteurs/corps.h
	$(CC) -Wall -std=c++11 -c Capteurs/capteurFactory.cpp -I .

corps.o: Capteurs/corps.cpp Capteurs/capteur.h Capteurs/corps.h
	$(CC) -Wall -std=c++11 -c Capteurs/corps.cpp -I .

yeux.o: Capteurs/yeux.cpp Capteurs/capteur.h Capteurs/yeux.h
	$(CC) -Wall -std=c++11 -c Capteurs/yeux.cpp -I .
	
oreilles.o: Capteurs/oreilles.cpp Capteurs/capteur.h Capteurs/oreilles.h
	$(CC) -Wall -std=c++11 -c Capteurs/oreilles.cpp -I .
	

Milieu.o : Milieu.h Milieu.cpp IBestiole.h Bestiole.h
	$(CC) -Wall -std=c++11  -c Milieu.cpp -I .

clean:
	rm -f *.o ./Accessoires/*.o ./main

# main : main.cpp Aquarium.o Bestiole.o Milieu.o
# 	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o -I . -lX11 -lpthread

# Aquarium.o : Aquarium.h Aquarium.cpp
# 	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

# Bestiole.o : Bestiole.h Bestiole.cpp
# 	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

# Milieu.o : Milieu.h Milieu.cpp
# 	g++ -Wall -std=c++11  -c Milieu.cpp -I .



