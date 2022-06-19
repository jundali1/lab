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
