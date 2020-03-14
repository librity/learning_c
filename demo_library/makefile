CC = gcc
CFLAGS = -Wall -g
BINS = librarytest libmystaticcode.a libmycode.so runtime_librarytest static_librarytest

all: $(BINS)

# Object file: intermediate compilation file that gets linked and integrated
# into the binary executable.
libmycode.o: libmycode.c mycode.h
	$(CC) $(CFLAGS) -c libmycode.c

# Shared Object file: object file that can be used by many different programs at
# runtime. Equivalent to a Windows .dll or a macOS .dylib . To make them 
# executable we put SO files in directories like /lib, /usr/lib, /usr/local/lib.
# Moder versions of make automatically generate systemlinks so the SO becomes
# available immediately after compile.
libmycode.so: libmycode.c mycode.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ libmycode.c -lc
# fPIC = Position Independent Code: code that can run anywhere on memory.

# .a Archive File aka Static Library: a non-shared Library that becomes part of
# the binary when compiled. 
libmystaticcode.a: libmycode.o
	ar rcs libmystaticcode.a libmycode.o
# r = replace (files), c = create (files), s = generate index (used by the
# compiler);

librarytest: librarytest.c libmycode.o
	$(CC) $(CFLAGS) -o $@ $^

runtime_librarytest: librarytest.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -lmycode
# lmycode: the "l" stands for "lib", and the compiler expects taht all library
# file names start with "lib".

static_librarytest: librarytest.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -lmystaticcode

clean:
	rm -rf *.o *.so *.dSYM $(BINS)