#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024
#define MAX_CHAR 100

int main()
{
 char buf[MAX_LINE];  /*������*/
 FILE *fp;            /*�ļ�ָ��*/
 FILE *wp; 
 int len,j,k;             /*���ַ�����*/
 char john[4000][500];
 int i=0;
 char txt1[MAX_CHAR],txt2[MAX_CHAR],language[MAX_CHAR];
 char suffix[]=".txt";
 int vali=0;
 
while(vali==0)
{
	 printf("��������Ҫ��ȡ��txt�ļ����ļ���(��: phantom.txt �����������׺.txt):\n");            //�û��������� 
 	 gets(txt1);
     strcat(txt1,suffix);
     printf("���� %s �ļ��ж�ȡ����\n\n",txt1);
     if((fp = fopen(txt1,"r")) == NULL)
	 {
 		perror("fail to read");
 		vali = 0;
 		printf("�����˶��ļ�������������\n\n\n");
 	}
 	else
 	{
 		printf("�ɹ��ҵ��ļ�%s\n\n",txt1); 
 		vali=1;	 	
	 }
}


 printf("����������Ҫ��ȡ�����ԣ�����0ΪӢ�ģ�����1Ϊ����\n");    //�û���Ҫ��ȡ������ 
 gets(language);
 printf("���������%s",language);
 
 printf("�������ȡ��txt�ļ����ļ���(�������Լ���һ�����֣������������׺.txt):\n"); 
 gets(txt2);  //����Ҫ��gets��������scanf����Ϊscanf�ÿո����־�ַ��������������ǵ��ļ����ǿ��ܳ��ֿո�� 
 strcat(txt2,suffix);
 


 //��ȡ�ļ����洢 
 k=0;

 while(fgets(buf,MAX_LINE,fp) != NULL )
 {
 len = strlen(buf);
 buf[len-1] = '\0';  /*ȥ�����з�*/
 

int m,n1=0;             //��n1������ 
for(m=0;buf[m];m++)
if(buf[m]<0){m++;n1++;}

int n2=0;               //��n2��Ӣ����ĸ 
for(m=0;buf[m];m++){
	if((buf[m]>='a'&&buf[m]<='z')||(buf[m]>='A'&&buf[m]<='Z'))
	{m++;n2++;}
}

if(strcmp(language, "0")==0)    //��ȡӢ�� 
{
	 if(n1==0&&n2!=0){        
         for(j=0;j<len;j++)
   	         john[k][j]=buf[j];
         k++;
    }
}
else                            //��ȡ���� 
{
	 if(n1!=0){            
         for(j=0;j<len;j++)
   	         john[k][j]=buf[j];
         k++;
    }
}


 i++;
 }
 
 //�Ѵ�õ��ַ����� ������½���txt�ļ��� 
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

printf("�뵽��ǰ�ļ��в��� %s �ļ���������ȡ���������ļ���\n\n\n",txt2);
  return 0;
}

