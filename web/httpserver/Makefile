web: web.o http_conn.o
	cc -o web web.o
http_conn.o: http_conn.cpp http_conn.h
	cc -o http_conn.cpp
web.o:  web.cpp
	cc -o web.cpp
clean:
	rm web web.o http_conn.o
