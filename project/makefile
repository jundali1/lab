main:main.o compress.o decompress.o preprocess.o
gcc main.o compress.o decompress.o  preprocess.o -o main
main.o:main.c ./include/compress.h ./include/decompress.h ./include/preprocess.h
gcc -c main.c -o main.o
compress.o:./src/compress.c ./include/compress.h
gcc -c ./src/compress.c -o compress.o
decompress.o:./src/decompress.c ./include/decompress.h
gcc -c ./src/decompress.c -o decompress.o
preprocess.o:./src/preprocess.c ./include/preprocess.h
gcc -c ./src/preprocess.c -o preprocess.o