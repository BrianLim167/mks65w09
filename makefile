all: dirinfo.c
	gcc dirinfo.c -o dirinfo
run: all
	./dirinfo
clean:
	rm -f *~
	rm -f *.o
