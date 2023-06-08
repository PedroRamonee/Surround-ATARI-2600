all: compile link run

compile:
	g++ -c *.cpp -ISFML/include

link:
	g++ *.o -o main -LSFML/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system 

run:
	./main.exe
