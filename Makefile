all:
	g++ -o encoder main.cpp hash.cpp

encoder: main.cpp
	g++ -o encoder main.cpp

clean: 
	rm encoder