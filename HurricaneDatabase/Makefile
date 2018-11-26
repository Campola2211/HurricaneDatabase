a.out: main.cpp HurricaneDatabase.o HurricaneEntry.o linked_list.o single_node.o
	g++ -std=c++11 main.cpp HurricaneDatabase.o HurricaneEntry.o linked_list.o single_node.o
HurricaneDataBase.o: HurricaneDataBase.cpp HurricaneDataBase.h
	g++ -std=c++11 -c HurricaneDataBase.cpp
HurricaneEntry.o: HurricaneEntry.cpp HurricaneEntry.h
	g++ -std=c++11 -c HurricaneEntry.cpp
linked_list.o: linked_list.cpp linked_list.h
	g++ -std=c++11 -c linked_list.cpp
single_node.o: single_node.cpp single_node.h
	g++ -std=c++11 -c single_node.cpp
clean:
	rm *.o a.out *gc*
