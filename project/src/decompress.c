#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\\Users\\Doraemon\\Desktop\\bighomework\\include\\decompress.h"

void getseed(char seeds[],char str[])//这个函数用来捕获seed
{
    int start,end;
    for(int i=0;i<1000;i++)
    {
        if(str[i]=='A'||str[i]=='T'||str[i]=='C'||str[i]=='G')
        {
            if(str[i-1]>47 && str[i-1]<58)start=i;
            if(str[i+1]==' ')
            {
                end=i;
                break;
            }
        }
    }
    for(int j=start;j<=end;j++)
    {
        seeds[j-start]=str[j];
    }
}

void getnumber(int nums[],char str[])//这个函数用来捕获seed文件每一行中的数字(这里针对的是长度1000以下的DNA序列)
{
    int i=0;
    int j=0;
    while(str[i]!='\n')
    {
        if(str[i]>47 && str[i]<58)
        {
            if(str[i+1]>47 && str[i+1]<58)
            {
                if(str[i+2]>47 && str[i+2]<58)
                {
                    nums[j]=(str[i]-48)*100+(str[i+1]-48)*10+str[i+2]-48;
                    i+=3;
                    j++;
                }
                else
                {
                    nums[j]=(str[i]-48)*10+str[i+1]-48;
                    j++;
                    i+=2;
                }

            }
            else
            {
                nums[j]=str[i]-48;
                j++;
                i++;
            }
        }
        else i++;
    }
}

void decompression(FILE *fo3,FILE *fo4,FILE *fo5)
{
    char str[50][1000];
    int i=0;
    while(i<50)
    {
        fgets(str[i],1000,fo4);
        i++;
    }

    fseek(fo4,0,SEEK_SET);

    char str2[1000],seed[6],tmp[1000];
    int num[101];//M+1
    for(int i=0;i<101;i++)num[i]=-1;
    int j;
    int start,end;
    while(fgets(str2,1000,fo3)!=NULL)
    {
        memset(tmp,0,sizeof(tmp));
        getnumber(num,str2);
        getseed(seed,str2);

        start=0,end=num[1];
        strncat(tmp,str[num[0]-1]+start,end-start);
        strncat(tmp,seed,6);
        j=2;
        while(num[j]!=-1)
        {
            start=end;
            end=num[j]-6*(j-1);
            strncat(tmp,str[num[0]-1]+start,end-start);
            strncat(tmp,seed,6);
            j++;
        }
        strncat(tmp,str[num[0]-1]+end,1000);

        strcpy(str[num[0]-1],tmp);
    }
    
    i=0;
    while(i<50)
    {
        fprintf(fo5,"%s",str[i]);
        i++;
    }
}
