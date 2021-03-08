tree: main.o treeoperations.o traversals.o
	gcc -o tree main.o treeoperations.o traversals.o
main.o: treeoperations.o traversals.o
	gcc -Wall -Werror -c main.c treeoperations.o traversals.o
treeoperations.o: tree.h
	gcc -Wall -Werror -c treeoperations.c  tree.h
traversals.o: tree.h
	gcc -Wall -Werror -c traversals.c tree.h
clean: 
	rm tree *.o *.out 