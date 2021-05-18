a.out: bloom_filter.o test3.o
	gcc bloom_filter.o test3.o -lm
bloom_filter.o:	bloom_filter.c bloom_filter.h
	gcc -c bloom_filter.c -lm 
test2.o : test2.c bloom_filter.h
	gcc -c test3.c -lm