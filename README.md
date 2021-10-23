It is so interested to do discover the implementation of malloc function in C. Details will be shown in README.pdf file in this repository.

In the C library, it uses Linked-Node-Like structure to make a list to mark whether a bunch of memory is freed or not. (e.g. free list). However, This little program aims to record all the memory allocated not only freed but also memory is use.

The basic judgement of this method(recording all the memory) is: it will be slower than the originial one of C library. I will do the comparison between mine and C library.
