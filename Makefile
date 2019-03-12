sudoku: sudoku.o main.o
	g++ -o sudoku sudoku.o main.o

main.o: main.cpp sudoku.h
	g++ -c main.cpp

Sudoku.o: sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

clean:
	rm *.o