Human: main.o Chinese.o Englishman.o Human.o
	g++ -o $@ $^
%.o: %.cpp
	g++ -c -o $@ $<
clean:
	rm -rf *.o Human
