Human: main.o Chinese.o Englishman.o
	g++ -o $@ $^
%.o: %.cpp
	g++ -c -o $@ $<
clean:
	rm -rf *.o Human
