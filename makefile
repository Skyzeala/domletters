C = g++
CPPFLAGS = -Wall -g

default: 	domletters

domletters: domletters.cpp

.PHONY: clean
clean:
	rm -f *o
	rm -f domletters 

