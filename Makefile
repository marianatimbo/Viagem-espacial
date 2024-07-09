FLAGS = -g -Wall -pedantic
OBJECT = obj/main.o obj/administracao.o obj/astronauta.o obj/voo.o

all: administracao

compile: ${OBJECT}
		g++ ${OBJECT} -o administracao

run:
		./administracao

obj/main.o: main.cpp class/astronauta.h class/voo.h class/administracao.h
		g++ ${FLAGS} -c main.cpp -o obj/main.o

obj/administracao.o: src/administracao.cpp class/voo.h class/astronauta.h
		g++ ${FLAGS} -c src/administracao.cpp -o obj/administracao.o

obj/astronauta.o: src/astronauta.cpp class/administracao.h
		g++ ${FLAGS} -c src/astronauta.cpp -o obj/astronauta.o

obj/voo.o: src/voo.cpp class/voo.h
		g++ ${FLAGS} -c src/voo.cpp -o obj/voo.o
