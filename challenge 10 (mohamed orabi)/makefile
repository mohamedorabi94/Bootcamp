CFLAGS += -Wl,-Map=main.map
sum.exe: main.o func1.o func2.o
	gcc -o sum.exe main.o func1.o func2.o
	gcc $^ --output $@ $(CFLAGS)
main.o: func1.h func2.h main.c
	gcc -c main.c
func1.o: func1.h func1.c 
	gcc -c func1.c
func2.o: func2.h func2.c 
	gcc -c func2.c
clean:
	del *.o *.exe *.map

	