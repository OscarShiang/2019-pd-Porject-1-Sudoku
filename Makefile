all: solve generate transform

solve: solve.o sudoku.o
	g++ -o solve sudoku.o solve.o

generate: generate.o sudoku.o
	g++ -o generate sudoku.o generate.o

transform: transform.o sudoku.o
	g++ -o transform sudoku.o transform.o

solve.o: sudoku.h solve.cpp
	g++ -c solve.cpp

generate.o: sudoku.h generate.cpp
	g++ -c generate.cpp

transform.o: transform.cpp sudoku.h
	g++ -c transform.cpp

Sudoku.o: sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

clean:
	rm *.o