OBJ = main.o cochon.o zombie.o concreteCreatorCochon.o concreteCreatorZombie.o
CC = g++

program: $(OBJ)
	$(CC) -o program $(OBJ)

main.o: main.cpp concreteCreatorCochon.h concreteCreatorZombie.h
	$(CC) -c main.cpp

zombie.o: zombie.cpp zombie.h mob.h
	$(CC) -c zombie.cpp

cochon.o: cochon.cpp cochon.h mob.h
	$(CC) -c cochon.cpp

concreteCreatorZombie.o: concreteCreatorZombie.cpp concreteCreatorZombie.h mobFactory.h mob.h
	$(CC) -c concreteCreatorZombie.cpp

concreteCreatorCochon.o: concreteCreatorCochon.cpp concreteCreatorCochon.h mobFactory.h mob.h
	$(CC) -c concreteCreatorCochon.cpp


clean:
	rm -f *.o