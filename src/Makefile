CC = g++
COM = comportements
ACC = Accessoires
CAP = Capteurs
BESTIOLES = Bestiole.o IBestiole.o ConcreteCreatorBestiole.o
COMPORTEMENTS = $(COM)/Deplacements.o $(COM)/ComportementPeureuse.o #$(COM)/ComportementGregaire.o $(COM)/ComportementKamikaze.o $(COM)/ComportementPersMultiple.o $(COM)/ComportementPrevoyante.o
ACCESSOIRES = #$(ACC)/ConcreteCreatorCamouflage.o $(ACC)/ConcreteCreatorCarapace.o $(ACC)/ConcreteCreatorNageoire.o $(ACC)/Camouflage.o $(ACC)/Carapace.o $(ACC)/Nageoire.o
CAPTEURS = #$(CAP)/capteurFactory.o
OBJ = main.cpp Aquarium.o Milieu.o  $(BESTIOLES) $(COMPORTEMENTS) $(ACCESSOIRES) $(CAPTEURS)

main : $(OBJ)
	$(CC) -Wall -std=c++11 -o main $(OBJ) -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	$(CC) -Wall -std=c++11  -c Aquarium.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	$(CC) -Wall -std=c++11  -c Milieu.cpp -I .

##### Bestioles
IBestiole.o : IBestiole.h IBestiole.cpp
	$(CC) -Wall -std=c++11  -c IBestiole.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp IBestiole.h
	$(CC) -Wall -std=c++11  -c Bestiole.cpp -I .

ConcreteCreatorBestiole.o: ConcreteCreatorBestiole.cpp ConcreteCreatorBestiole.h BestiolesFactory.h Bestiole.h
	$(CC) -Wall -std=c++11  -c ConcreteCreatorBestiole.cpp -I .

##### Comportements
ComportementPeureuse.o: ComportementPeureuse.h ComportementPeureuse.cpp IComportement.h 
	$(CC) -Wall -std=c++11  -c ComportementPeureuse.cpp -I .

ComportementGregaire.o: ComportementGregaire.h ComportementGregaire.cpp IComportement.h 
	$(CC) -Wall -std=c++11  -c ComportementGregaire.cpp -I .

ComportementKamikaze.o: ComportementKamikaze.h ComportementKamikaze.cpp IComportement.h 
	$(CC) -Wall -std=c++11  -c ComportementKamikaze.cpp -I .

ComportementPersMultiple.o: ComportementPersMultiple.h ComportementPersMultiple.cpp IComportement.h 
	$(CC) -Wall -std=c++11  -c ComportementPersMultiple.cpp -I .

ComportementPrevoyante.o: ComportementPrevoyante.h ComportementPrevoyante.cpp IComportement.h 
	$(CC) -Wall -std=c++11  -c ComportementPrevoyante.cpp -I .

Deplacements.o: Deplacements.h Deplacements.cpp
	$(CC) -Wall -std=c++11  -c Deplacements.cpp -I .

##### Accessoires
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

##### Capteurs
# capteurFactory.o : capteur.h yeux.h corps.h oreilles.h capteurFactory.cpp
# 	$(CC) -Wall -std=c++11  -c capteurFactory.cpp -I .

clean:
	rm -f *.o ./$(ACC)/*.o ./$(COM)/*.o ./$(CAP)/*.o ./main



