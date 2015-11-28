all: src/*
	g++ -Wall src/*.cc -c bin/
	ar rcs bin/libdanylib.a bin/danylib.o

install: all
	#make the directories they go in
	mkdir -p /usr/local/lib/danylib/
	mkdir -p /usr/local/include/danylib/

	#copy the files over
	cp bin/libdanylib.a /usr/local/lib/danylib/libdanylib.a
	cp src/danylib.hh /usr/local/include/danylib/danylib.hh
