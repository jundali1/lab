#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"C:\\Users\\Doraemon\\Desktop\\bighomework\\include\\compress.h"
#include"C:\\Users\\Doraemon\\Desktop\\bighomework\\include\\preprocess.h"
#include"C:\\Users\\Doraemon\\Desktop\\bighomework\\include\\decompress.h"


Function main()

	const char* FILE_NAME_IN <- "BA1.fastq";//目标文件
	const char* FILE_NAME_OUT1 <- "ready.txt";
	const char* FILE_NAME_OUT2 <- "information.txt";
	const char* FILE_NAME_OUT3 <- "seed.txt";
	const char* FILE_NAME_OUT4 <- "done.txt";//压缩完的文件
	const char* FILE_NAME_OUT5 <- "decompression.txt";
	
	FILE* fi <- fopen(FILE_NAME_IN, "r");
	FILE* fo1 <- fopen(FILE_NAME_OUT1, "r+");
	FILE* fo2 <- fopen(FILE_NAME_OUT2, "rw+");
	FILE* fo3 <- fopen(FILE_NAME_OUT3, "rw+");
	FILE* fo4 <- fopen(FILE_NAME_OUT4, "rw+");
	FILE* fo5 <- fopen(FILE_NAME_OUT5, "rw+");

	
	apart(fi,fo1,fo2);
	fseek(fo1,0,SEEK_SET);
	compression(3,6,fo1,fo3,fo4);
	fseek(fo3,0,SEEK_SET);
	fseek(fo4,0,SEEK_SET);
	decompression(fo3,fo4,fo5);

	fclose(fi);
	fclose(fo1);
	fclose(fo2);
	fclose(fo3);
	fclose(fo4);
	fclose(fo5);

	return 0;
End main
