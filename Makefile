.PHONY: clean
CFLAGS = -Wall -g -std=c++20
OBJ = main.o test.o registering_thrower.o subservient_element_functions.o complex_number.o vector_exceptions.o\
Sequence\sequence_exceptions.o

main: $(OBJ)
	g++ $(OBJ) -o main

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

clean:
	del $(OBJ) main