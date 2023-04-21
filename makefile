main: main.o timer.o
	g++ -o $@ $^
%.o : %.cpp timer.hpp
	g++ -c -o $@ $<
