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
