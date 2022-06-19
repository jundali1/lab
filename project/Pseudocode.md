```c
#ifndef COMPRESS
#define COMPRESS
#include<stdio.h>

#define N 2
//N是设定的对于一个seed，找到几个完全匹配时决定压缩的阈值。
#define M 100
//M是一段DNA中任意seed最多可以出现几次，应该要接近LONG/seed长度n
#define LONG 1000
//LONG是数据DNA的最大长度

Function compression(m,n,o1,o2,o4);
#endif
```

```c
#ifndef DECOMPRESS
#define DECOMPRESS

#include<stdio.h>

Function getseed(seeds[],str[]);
Function getnumber(nums[],str[]);
Function decompression(fo3,fo4,fo5);

#endif
```

```c
#ifndef PREPROCESS
#define PREPROCESS
#include<stdio.h>

Function apart(p,o1,o2);

Function uppercase(fi,fo);//将小写字母转化为大写字母以便后续压缩
#endif
```

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\\Users\\Doraemon\\Desktop\\bighomework\\include\\compress.h"
//调试发现对于长度不大于1000的DNA序列，出现8位完全匹配的可能性很小，f,n取3，6即可,但是这一模型完全可以处理更长更多的DNA序列。在更长的DNA上压缩效果比较好
//统计学模型在C中实现并不高效，有大量的时间空间浪费，并且为了确保的压缩唯一性需要多段迭代，改进——当确定seed长度n = 6时，取阈值N = 2,有至少两次匹配即这个seed出现三次时选择压缩它们。
Function compression(m,n,o1,o3,o4){//通过ready.txt分离出压缩完的done.txt和种子信息seed.txt用于解码
	Dim str as char(1000);
	Dim temp as char(1000);Dim t1 as int;
	Dim i as int; i <- 0;
	Dim seed as char(n+1);//n是seed长度，需要多一位留给/0，不然会溢出
	Dim j as int; j <- 0;
	Dim k as int; k <- 0;
	Dim count as int; count <- 0;
	Dim hang as int; hang <- 0;
	Dim a as int(M);Dim t as int;
	memset(a,-1,sizeof(a));
	while fgets(str,LONG,o1)!=NULL
		do
        hang+=1;
		
		//printf("hangshu = %d\n",hang);
		
		i <- m;//m是迭代次数
		while i
			
			//printf("%d",i);
			//printf("%d\n",strlen(str));
			//printf("test2:i=%d\n",i);
			do
			while k<strlen(str)-n
				do
                memcpy(seed,str+k,n);
				t <- 0;
				a[t]<-k;t++; 
				
				//printf("seed=%s\n",seed);
				//printf("k=%d\n",k);
				//printf("str=%s\n",str+6);
				/*int a;
				if(strncmp(seed,str+6,6)==0) a=1;
				else a = 0;
				printf("testa=%d\n",a);*/
				
					for j<-n to j<strlen(str)-k-n-1
						//printf("j=%d\n",j);
                        do j++
						if(strncmp(seed,str+k+j,n)==0)
                            then
							//printf("found k=%d j=%d\n",k,j);
							count+=1;
							a[t]<-k+j;
    						t++;
							j+=n;
							
						
				if(count>=N) 
                    then
					memset(temp,0,strlen(temp));
					//printf("%d %s %d\n",hang,seed,i);
					fprintf(o3,"%d%s",hang,seed);//必须保存seed对应于哪一条DNA的信息
					t<-0;
					while a[t]!=-1&&t<M
						do
                        fprintf(o3," %d",a[t]);
						//printf(" %d",a[t]);
						t++;
					
					fprintf(o3,"\n");
					//printf("\n");
					
					t <- 0;
					t1 <- 0;
					while (t1<strlen(str))
						do
                        if(t1!=a[t])
                            then
							strncat(temp,str+t1,1);
							t1++;
						else 
							t1+=n;
							t++;
					//printf("%s\n",temp);
					strcpy(str,temp);
	
					memset(a,-1,sizeof(a));
					t<-0;
					break;
				
				k++;
				count <- 0;
				j <- 0;
				memset(a,-1,M);
    			t<-0;
		
			j <- 0;
			k <- 0;
			count <- 0;
			memset(a,-1,M);t<-0;
			i--;
	//printf("%s",str);	
	fprintf(o4,str);
	
End compression

```

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\\Users\\Doraemon\\Desktop\\bighomework\\include\\decompress.h"

Function getseed(seeds[],str[])//这个函数用来捕获seed
{
    Dim start as int;
    Dim end as int;
    for i<-0 to 1000
    	do i++
    
        if(str[i]=='A'||str[i]=='T'||str[i]=='C'||str[i]=='G')
            then
            if(str[i-1]>47 && str[i-1]<58) then vstar<-i;
            if(str[i+1]==' ')
                then 
                end<-i;
                break;
            
    for j<-start to end
        do j++;
        seeds[j-start]<-str[j];
End getseed

Function getnumber(nums[],str[])//这个函数用来捕获seed文件每一行中的数字(这里针对的是长度1000以下的DNA序列)
{
    i<-0;
    j<-0;
    while str[i]!='\n'
    	do
        if(str[i]>47 && str[i]<58)
        	then
            if(str[i+1]>47 && str[i+1]<58)
            	then
                if(str[i+2]>47 && str[i+2]<58)
                	then
                    nums[j] <- (str[i]-48)*100+(str[i+1]-48)*10+str[i+2]-48;
                    i+=3;
                    j++;
                
                else
                	then 
                    nums[j]<-(str[i]-48)*10+str[i+1]-48;
                    j++;
                    i+=2;
         
            else
            	then
                nums[j] <- str[i]-48;
                j++;
                i++;

        else 
        then i++;
End getnumber


Function decompression(FILE *fo3,FILE *fo4,FILE *fo5)

    Dim str as char[50][1000];
    i <- 0;
    while i<50
    	do
        fgets(str[i],1000,fo4);
        i++;
    

    fseek(fo4,0,SEEK_SET);

    Dim str2 as char(1000);
    Dim seed as char(6);
    Dim tmp as char(1000);
    Dim num as int(101);//M+1
    for  i<-0 to 100
    do i++;
    num[i] <- -1;
    Dim j as int;
    Dim start as int;
    Dim end as int;
    while fgets(str2,1000,fo3)!=NULL
    	do
        memset(tmp,0,sizeof(tmp));
        getnumber(num,str2);
        getseed(seed,str2);

        start <- 0,end <- num[1];
        strncat(tmp,str[num[0]-1]+start,end-start);
        strncat(tmp,seed,6);
        j <- 2;
        while(num[j]!=-1)
        {
            start <- end;
            end <- num[j]-6*(j-1);
            strncat(tmp,str[num[0]-1]+start,end-start);
            strncat(tmp,seed,6);
            j++;
        }
        strncat(tmp,str[num[0]-1]+end,1000);

        strcpy(str[num[0]-1],tmp);
    }
    
    i <- 0;
    while(i<50)
    	do
        fprintf(fo5,"%s",str[i]);
        i++;
End decompression

```

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\\Users\\Doraemon\\Desktop\\bighomework\\include\\preprocess.h"

Function apart(p,o1,o2){//数据初步分离，非字符串信息到information.txt,未压缩字符串到ready.txt
	Dim str as char(1000);
	i <- 0;
	while(fgets(str,500,p)!=NULL)
	 	do
        switch(i%4)
		 	case 0:
			 	fprintf(o2,"%s",str);
			 	break;
		 	case 1:
			 	fprintf(o1,"%s",str);
			 	break;
		 	case 3:
			 	fprintf(o2,"%s",str);
			 	break;
		 
		i+=1;
End apart	


Function uppercase(fi,fo)
{
	Dim str as char(1000);
	i <- 0;
	while(fgets(str,500,fi)!=NULL)
		do
        i <- 0;
        while(str[i]!='\n')
        	do 
            str[i] <- str[i]-32;
            i++;
        
        //printf("%s\n",str);
        fprintf(fo,"%s",str);
	
	return;
End uppercase
```

```c
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"C:\\Users\\Doraemon\\Desktop\\bighomework\\include\\compress.h"
#include"C:\\Users\\Doraemon\\Desktop\\bighomework\\include\\preprocess.h"
#include"C:\\Users\\Doraemon\\Desktop\\bighomework\\include\\decompress.h"


Function main()

	const char* FILE_NAME_IN = "C:\\Users\\Doraemon\\Desktop\\bighomework\\data\\BA1.fastq";//目标文件
	const char* FILE_NAME_OUT1 = "C:\\Users\\Doraemon\\Desktop\\bighomework\\target\\ready.txt";
	const char* FILE_NAME_OUT2 = "C:\\Users\\Doraemon\\Desktop\\bighomework\\target\\information.txt";
	const char* FILE_NAME_OUT3 = "C:\\Users\\Doraemon\\Desktop\\bighomework\\target\\seed.txt";
	const char* FILE_NAME_OUT4 = "C:\\Users\\Doraemon\\Desktop\\bighomework\\target\\done.txt";//压缩完的文件
	const char* FILE_NAME_OUT5 = "C:\\Users\\Doraemon\\Desktop\\bighomework\\target\\decompression.txt";
	
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
```

