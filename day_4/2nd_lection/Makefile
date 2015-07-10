PREFIX = /usr/local/bin
All:
	cc -c client.c
	cc -c server.c
	cc client.o -o client
	cc server.o -o server 
client.o: client.c
	cc -c client.c
server.o: server.c 
	cc -c server.c
clean:
	rm -f *.o
install: 
	install $(TARGET) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)
