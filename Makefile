src := src
bin := bin
inc := include
lib := lib


all: main.o
	g++ main.o -o $(bin)/App
	bin/App
main.o: $(src)/main.cpp
	g++ -c $(src)/main.cpp
clean:
	del *.o 
	del $(bin)\App.exe