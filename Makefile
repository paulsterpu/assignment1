build:  problema1.cpp problema2.cpp
	g++ problema1.cpp -o p1
	g++ problema2.cpp -o p2
run-p1: p1.o
	 ./p1
p1.o :
	g++ problema1.cpp -c -o p1.o
run-p2: p2.o
	 ./p2
p2.o :
	g++ problema2.cpp -c -o p2.o
clean:
	rm -f p1 p2
