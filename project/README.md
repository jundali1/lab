# README

[TOC]

## 功能

我们程序实现了对于DNA序列的压缩和解压缩的功能，这里给出的例子是对fastq文件的DNA序列的一个压缩过程。

首先是将fastq文件进行一个分割，提取出DNA序列和非序列信息；然后把非序列信息储存到information文件，对DNA序列进行压缩并输出到done文件，将压缩过程选取的种子及位置信息存入seed文件；最后，是根据seed文件的信息，对于done文件进行解压缩，恢复到原来的序列。

主要功能列举如下：

- 分离DNA序列信息和非序列信息（apart函数）
- 对DNA序列进行压缩（compress函数）
- 小写DNA文件转大写的转换（uppercase函数）
- 解压缩DNA序列（decompress函数）

## 文件说明

- `src`：存储了3个c文件proprecess.c、compress.c、decompress.c

- `include`：存储了3个头文件proprecess.h、compress.h、decompress.h
- `data`：存储了数据文件（文件格式为fastq）
- `target`：存储了输出文件，information（非序列信息）、ready（去除冗余信息的DNA序列）、seed（种子信息及位置）、done（压缩完文件）、decompression（解压缩后的DNA序列）

## 运行方法

makefile文件已经编写完毕，可以直接在Linux下make编译（由于是在Windows Vscode写的程序，要先把其中的文件路径进行一个修改），然后运行main.exe即可