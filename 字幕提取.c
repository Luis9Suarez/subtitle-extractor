#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024
#define MAX_CHAR 100

int main()
{
 char buf[MAX_LINE];  /*缓冲区*/
 FILE *fp;            /*文件指针*/
 FILE *wp; 
 int len,j,k;             /*行字符个数*/
 char john[4000][500];
 int i=0;
 char txt1[MAX_CHAR],txt2[MAX_CHAR],language[MAX_CHAR];
 char suffix[]=".txt";
 int vali=0;
 
while(vali==0)
{
	 printf("请输入您要读取的txt文件的文件名(如: phantom.txt 您不用输入后缀.txt):\n");            //用户输入需求 
 	 gets(txt1);
     strcat(txt1,suffix);
     printf("将从 %s 文件中读取数据\n\n",txt1);
     if((fp = fopen(txt1,"r")) == NULL)
	 {
 		perror("fail to read");
 		vali = 0;
 		printf("请您核对文件名后，重新输入\n\n\n");
 	}
 	else
 	{
 		printf("成功找到文件%s\n\n",txt1); 
 		vali=1;	 	
	 }
}


 printf("请输入您想要提取的语言，输入0为英文，输入1为中文\n");    //用户想要提取的语言 
 gets(language);
 printf("您输入的是%s",language);
 
 printf("请输入读取的txt文件的文件名(您可以自己起一个名字，您不用输入后缀.txt):\n"); 
 gets(txt2);  //这里要用gets，不能用scanf，因为scanf用空格符标志字符串结束。但我们的文件名是可能出现空格的 
 strcat(txt2,suffix);
 


 //读取文件并存储 
 k=0;

 while(fgets(buf,MAX_LINE,fp) != NULL )
 {
 len = strlen(buf);
 buf[len-1] = '\0';  /*去掉换行符*/
 

int m,n1=0;             //有n1个汉字 
for(m=0;buf[m];m++)
if(buf[m]<0){m++;n1++;}

int n2=0;               //有n2个英文字母 
for(m=0;buf[m];m++){
	if((buf[m]>='a'&&buf[m]<='z')||(buf[m]>='A'&&buf[m]<='Z'))
	{m++;n2++;}
}

if(strcmp(language, "0")==0)    //提取英文 
{
	 if(n1==0&&n2!=0){        
         for(j=0;j<len;j++)
   	         john[k][j]=buf[j];
         k++;
    }
}
else                            //提取中文 
{
	 if(n1!=0){            
         for(j=0;j<len;j++)
   	         john[k][j]=buf[j];
         k++;
    }
}


 i++;
 }
 
 //把存好的字符串们 输出到新建的txt文件中 
	if((wp=fopen(txt2,"wb"))==NULL)
	{
		printf("\nopen file Fail,close!");
		getchar();
		exit(1);
	}
	for(j=0;j<k;j++)
	{
		fputs(john[j],wp);
		fputs("\n",wp);
	}
	fclose(wp);	

printf("请到当前文件夹查找 %s 文件，您的提取结果在这个文件中\n\n\n",txt2);
  return 0;
}

