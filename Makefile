all: src/string.cc
	g++ -Wall src/string.cc -c
	ar rcs libdanylib.a string.o

install: all
	#make the directories they go in
	mkdir -p /usr/local/lib/danylib/
	mkdir -p /usr/local/include/danylib/

	#copy the files over
	cp libdanylib.a /usr/local/lib/danylib/libdanylib.a
	cp src/danylib.hh /usr/local/include/danylib/danylib.hh
