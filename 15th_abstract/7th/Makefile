#Human: main.o Chinese.o Englishman.o Human.o
Human: main.o libHuman.so
	g++ -o $@ $< -L./ -lHuman
%.o: %.cpp
	g++ -fPIC -c -o $@ $<
libHuman.so: Chinese.o Human.o Englishman.o
	g++ -shared -o $@ $^
clean:
	rm -rf *.o Human *.so
