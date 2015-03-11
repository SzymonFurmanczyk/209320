#
#  To sa opcje dla kompilacji
#
APP=program1
CPP2FLAGS= -g -std=c++11 -Iinc -Wall -pedantic
CPPFLAGS= -c -g -std=c++11 -Iinc -Wall -pedantic

__start__:  obj ./${APP}
	rm -f core.* core; ./${APP}

obj:
	mkdir -p obj

./${APP}: obj/main.o obj/Benchmark.o
	g++ ${CPP2FLAGS} -o ./${APP} obj/main.o obj/Benchmark.o

obj/main.o: src/main.cpp inc/Benchmark.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Benchmark.o: src/Benchmark.cpp inc/Benchmark.hh 
	g++ ${CPPFLAGS} -o obj/Benchmark.o src/Benchmark.cpp


clean:
	rm -f obj/*.o program1
help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make help   - wyswietla niniejsza informacje"
	@echo
