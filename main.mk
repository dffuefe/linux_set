write_only: writeA.o writeB.o rnw1.o
	gcc -o write_only writeA.o writeB.o rnw1.o
	
writeA.o: writeA.c write.h
	gcc -c writeA.c
	
writeB.o: write.h writeB.c rnw.h
	gcc -c writeB.c
	
rnw1.o: rnw1.c rnw.h
	gcc -c rnw1.c