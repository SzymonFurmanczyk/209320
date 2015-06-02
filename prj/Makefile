#
#  To sa opcje dla kompilacji
#
APP=program9
CPP2FLAGS= -g -Iinc -Wall -pedantic -lrt
CPPFLAGS= -c -g -Iinc -Wall -pedantic -lrt
vpath %.o obj

DOXYGEN= doxygen
DOXYWIZARD = doxywizard
EVINCE= evince

OBJECTS= obj/main.o obj/Benchmark.o obj/GeneratoryDanych.o \
obj/Algorytm1.o obj/Algorytm2.o obj/Algorytm3.o obj/Algorytm4.o obj/Algorytm5.o obj/Algorytm6.o obj/Algorytm7.o obj/Algorytm8.o\
obj/ObserwatorZapisujacy.o \
obj/Lista.o obj/Stos.o obj/Kolejka.o obj/ArrayLista.o obj/HaszTab.o obj/DrzewoBinarne.o obj/DrzewoRB.o obj/Graf.o\

INCLUDES= inc/GeneratoryDanych.hh \
inc/Interfaces/AlgorytmAbs.hh \
inc/Algorytm1.hh inc/Algorytm2.hh inc/Algorytm3.hh inc/Algorytm4.hh inc/Algorytm5.hh inc/Algorytm6.hh inc/Algorytm7.hh inc/Algorytm8.hh\
inc/Interfaces/Obserwator.hh \
inc/ObserwatorZapisujacy.hh \
inc/Interfaces/Obserwowany.hh \
inc/Benchmark.hh \
inc/Interfaces/Zasobnik.hh \
inc/Lista.hh inc/Stos.hh inc/Kolejka.hh inc/ArrayLista.hh  inc/HaszTab.hh inc/DrzewoBinarne.hh inc/DrzewoRB.hh inc/Graf.hh\



__start__:  obj ./${APP}
	rm -f core.* core; ./${APP}

obj:
	mkdir -p obj

./${APP}: $(OBJECTS)
	g++ ${CPP2FLAGS} -o ./${APP} $(OBJECTS)

obj/main.o: main.cpp $(INCLUDES)
	g++ ${CPPFLAGS} main.cpp -o obj/main.o

obj/%.o: src/%.cpp inc/%.hh
	g++ ${CPPFLAGS} $< -o $@

obj/%.o: inc/Interfaces/%.hh
	g++ ${CPPFLAGS} $< -o $@

clean:
	rm -f obj/*.o program7


dox:
	cd .. && cd dox && $(DOXYGEN) Doxyfile
	cd .. && cd dox/latex && $(MAKE)

doxsetup:
	cd .. && cd dox && $(DOXYWIZARD) Doxyfile &

doxopen:
	cd .. && cd dox/latex && $(EVINCE) refman.pdf &

doxclean:
	cd .. && cd dox/latex && $(MAKE) clean

doxcleanall:
	cd .. && cd dox/latex && rm -r *.*

help:
	@echo
	@echo " make          - tworzenie i uruchomienie aplikacji"
	@echo " make clean    - usuniecie produktow kompilacji i konsolidacji"
	@echo
	@echo " make dox      - tworzenie dokumentacji programu"
	@echo " make doxopen  - otwieranie dokuentacji pdf "
	@echo " make doxsetup - ustawienia dokumentacji "
	@echo " make doxclean - czyszczenie katalogu dokumentacji "
	@echo " make doxcleanall - usowanie wszystkiego w folderze latex "
	@echo
	@echo " make help     - wyswietla niniejsza informacje"
	@echo
