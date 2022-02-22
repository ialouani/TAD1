all: build 
test_directs: exec_test
build: tests.c liste_chainee.c
	gcc tests.c liste_chainee.c -o $@
exec_test: build
	./build 
clean:
	rm -f *.c~ *.h~ build #*.h.gch 
