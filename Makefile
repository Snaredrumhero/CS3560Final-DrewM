CC=g++
CFLAGS=-g -Wall


final: count.cpp
	$(CC) $(CFLAGS) -o final count.cpp
