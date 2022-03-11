

main : main.cpp Aquarium.o Bestiole.o Milieu.o concreteCreatorYeux.o yeux.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o concreteCreatorYeux.o yeux.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

yeux.o : Capteurs/yeux.h Capteurs/yeux.cpp

	g++ -Wall -std=c++11 -c Capteurs/yeux.cpp -I .

concreteCreatorYeux.o : Capteurs/concreteCreatorYeux.h Capteurs/concreteCreatorYeux.cpp
	g++ -Wall -std=c++11 -c Capteurs/concreteCreatorYeux.cpp -I .

clean : 
	rm -f *.o ./main