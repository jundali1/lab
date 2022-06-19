#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\\Users\\Doraemon\\Desktop\\bighomework\\include\\compress.h"
//调试发现对于长度不大于1000的DNA序列，出现8位完全匹配的可能性很小，f,n取3，6即可,但是这一模型完全可以处理更长更多的DNA序列。在更长的DNA上压缩效果比较好
//统计学模型在C中实现并不高效，有大量的时间空间浪费，并且为了确保的压缩唯一性需要多段迭代，改进——当确定seed长度n = 6时，取阈值N = 2,有至少两次匹配即这个seed出现三次时选择压缩它们。
void compression(int m,int n,FILE* o1,FILE* o3,FILE* o4){//通过ready.txt分离出压缩完的done.txt和种子信息seed.txt用于解码
	char str[1000];
	char temp[1000];int t1;
	int i = 0;
	char seed[n+1];//n是seed长度，需要多一位留给/0，不然会溢出
	int j = 0;
	int k = 0;
	int count = 0;
	int hang = 0;
	int a[M]; int t;
	memset(a,-1,sizeof(a));
	while(fgets(str,LONG,o1)!=NULL){
		hang+=1;
		
		//printf("hangshu = %d\n",hang);
		
		i = m;//m是迭代次数
		while(i){
			
			//printf("%d",i);
			//printf("%d\n",strlen(str));
			//printf("test2:i=%d\n",i);
			
			while(k<strlen(str)-n){
				memcpy(seed,str+k,n);
				t = 0;
				a[t]=k;t++; 
				
				//printf("seed=%s\n",seed);
				//printf("k=%d\n",k);
				//printf("str=%s\n",str+6);
				/*int a;
				if(strncmp(seed,str+6,6)==0) a=1;
				else a = 0;
				printf("testa=%d\n",a);*/
				
					for(j=n;j<strlen(str)-k-n;j++){
						//printf("j=%d\n",j);
						if(strncmp(seed,str+k+j,n)==0){
							//printf("found k=%d j=%d\n",k,j);
							count+=1;
							a[t]=k+j;t++;
							j+=n;
							}
						}
				if(count>=N) {
					memset(temp,0,strlen(temp));
					//printf("%d %s %d\n",hang,seed,i);
					fprintf(o3,"%d%s",hang,seed);//必须保存seed对应于哪一条DNA的信息
					t=0;
					while(a[t]!=-1&&t<M){
						fprintf(o3," %d",a[t]);
						//printf(" %d",a[t]);
						t++;
					}
					fprintf(o3,"\n");
					//printf("\n");
					
					t = 0;
					t1 = 0;
					while(t1<strlen(str)){
						if(t1!=a[t]){
							strncat(temp,str+t1,1);
							t1++;
						}
						else {
							t1+=n;
							t++;
						}
					}
					//printf("%s\n",temp);
					strcpy(str,temp);
	
					
					
					
					memset(a,-1,sizeof(a));
					t=0;
					break;
				}
				k++;
				count = 0;
				j = 0;
				memset(a,-1,M);t=0;
		}
			j = 0;
			k = 0;
			count = 0;
			memset(a,-1,M);t=0;
			i--;
		}
	//printf("%s",str);	
	fprintf(o4,str);
	}
	return;
}