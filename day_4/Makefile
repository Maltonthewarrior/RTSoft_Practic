PREFIX = /usr/local/bin
All:
	cc -c bin_sem.c
	cc -c file_1.c
	cc -c file_2.c
	cc bin_sem.o file_2.o -o file_2
	cc bin_sem.o file_1.o -o file_1 
bin_sem.o: bin_sem.c bin_sem.h
	cc -c bin_sem.c
file_1.o: file_1.c bin_sem.h
	cc -c file_1.c
file_2.o: file_2.c bin_sem.h
	cc -c file_2.c
clean:
	rm -f *.o
install: 
	install $(TARGET) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)
