#
#  To sa opcje dla kompilacji
#
APP=projekt
CPP2FLAGS= -std=c++1y -g -Iinc -Wall -pedantic
CPPFLAGS= -std=c++1y -c -g -Iinc -Wall -pedantic
vpath %.o obj

DOXYGEN= doxygen
DOXYWIZARD = doxywizard
EVINCE= evince

OBJECTS= obj/main.o obj/kontener.o

INCLUDES= inc/kontener.hh


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

clean:
	rm -f obj/*.o projekt


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
