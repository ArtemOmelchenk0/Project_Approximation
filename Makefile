aprox: main.o splines.o points.o aproksymator_na_bazie.o gauss_seidel/libge.a
	$(CC) -o aprox  main.o splines.o points.o aproksymator_na_bazie.o -L gauss_seidel -l ge

intrp: main.o splines.o points.o interpolator.o gauss_seidel/libge.a
	$(CC) -o intrp  main.o splines.o points.o interpolator.o -L gauss_seidel -l ge

prosta: main.o splines.o points.o prosta.o
	$(CC) -o prosta  main.o splines.o points.o prosta.o	

aproksymator_na_bazie.o: makespl.h points.h gauss_seidel/solve.h
	$(CC) -I gaus -c aproksymator_na_bazie.c

interpolator.o: makespl.h points.h gauss_seidel/solve.h
	$(CC) -I gaus -c interpolator.c

.PHONY: clean

clean:
	-rm *.o aprox intrp prosta
