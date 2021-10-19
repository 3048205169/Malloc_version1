CC=gcc
CFLAGS=-O3 -fPIC
DEPS=my_malloc.h
MALLOC_VERSION=FF
WDIR=./

all: lib equal_size_allocs small_range_rand_allocs large_range_rand_allocs

lib: my_malloc.o
        $(CC) $(CFLAGS) -shared -o libmymalloc.so my_malloc.o

%.o: %.c my_malloc.h
        $(CC) $(CFLAGS) -c -o $@ $<

equal_size_allocs: equal_size_allocs.c
        $(CC) $(CFLAGS) -I$(WDIR) -L$(WDIR) -D$(MALLOC_VERSION) -Wl,-rpath=$(WDIR) -o $@ equal_size_allo\
cs.c -lmymalloc -lrt

small_range_rand_allocs: small_range_rand_allocs.c
        $(CC) $(CFLAGS) -I$(WDIR) -L$(WDIR) -D$(MALLOC_VERSION) -Wl,-rpath=$(WDIR) -o $@ small_range_ran\
d_allocs.c -lmymalloc -lrt

large_range_rand_allocs: large_range_rand_allocs.c
        $(CC) $(CFLAGS) -I$(WDIR) -L$(WDIR) -D$(MALLOC_VERSION) -Wl,-rpath=$(WDIR) -o $@ large_range_ran\
d_allocs.c -lmymalloc -lrt

clean:
        rm -f *~ *.o equal_size_allocs small_range_rand_allocs large_range_rand_allocs *.so

clobber:
        rm -f *~ *.o

