libge: matrix.o gauss.o solve.o
	ar rvs libge.a $^

matrix.o: matrix.c matrix.h
gauss.o: gauss.c gauss.h matrix.h
util.o: solve.c solve.h gauss.h matrix.h

.PHONY: clean

clean:
	rm *.o libge.a
