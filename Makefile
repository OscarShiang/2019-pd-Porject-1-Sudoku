transform: sudoku.o transform.o
	g++ -o transform sudoku.o transform.o

transform.o: transform.cpp sudoku.h
	g++ -c transform.cpp

Sudoku.o: sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

clean:
	rm *.o