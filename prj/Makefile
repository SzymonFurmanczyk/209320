#
#  To sa opcje dla kompilacji
#
APP=program1
CPP2FLAGS= -g -Iinc -Wall -pedantic -lrt
CPPFLAGS= -c -g -Iinc -Wall -pedantic -lrt

__start__:  obj ./${APP}
	rm -f core.* core; ./${APP}

obj:
	mkdir -p obj

./${APP}: obj/main.o obj/Benchmark.o obj/Lista.o obj/Stos.o obj/Kolejka.o
	g++ ${CPP2FLAGS} -o ./${APP} obj/main.o obj/Benchmark.o obj/Lista.o obj/Stos.o obj/Kolejka.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Benchmark.o: src/Benchmark.cpp inc/Benchmark.hh 
	g++ ${CPPFLAGS} -o obj/Benchmark.o src/Benchmark.cpp

obj/Lista.o: src/Lista.cpp inc/Lista.hh 
	g++ ${CPPFLAGS} -o obj/Lista.o src/Lista.cpp

obj/Stos.o: src/Stos.cpp inc/Stos.hh 
	g++ ${CPPFLAGS} -o obj/Stos.o src/Stos.cpp

obj/Kolejka.o: src/Kolejka.cpp inc/Kolejka.hh 
	g++ ${CPPFLAGS} -o obj/Kolejka.o src/Kolejka.cpp

clean:
	rm -f obj/*.o program2
dox:
	cd .. && cd dox/latex && $(MAKE)
doxclean:
	cd .. && cd dox/latex && $(MAKE) clean
help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make help   - wyswietla niniejsza informacje"
	@echo
