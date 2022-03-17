OBJ = main.cpp Aquarium.o Bestiole.o Milieu.o 
CC = g++

main : $(OBJ)
	$(CC) -Wall -std=c++11 -o main $(OBJ) -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	$(CC) -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	$(CC) -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
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



