person: main.o person.o  dog.o
	g++ -o $@ $^

main.o: main.cpp
	g++ -c -o $@ $<

person.o: person.cpp
	g++ -c -o $@ $<

dog.o: dog.cpp
	g++ -c -o $@ $<

clean:
	rm -rf person *.o





