#include <iostream>
#include <stdio.h> 
#include<time.h>
#include<stdlib.h>
#include <windows.h> 
#include <conio.h>

using namespace std;
/*��������*/ 
int map [4][4];                  //��ͼ
int color [4][4];                //��ǣ����߼�����
int Score;                       //�֔� 
int count;                       //�ж�GAMEOVER��ѭ����
int Print ();                    //��ӡ����
void Sdir ();                    //���������
void Printcover ();               //���ɷ��� 
void Judgeend ();                 
void Judgezero ();
void Printinfo ();
void Printuse ();
int T,x1,y1,judgeend,judgezero;
int Topscore=16;
char input;

//���̽���
void up ();
void down ();
void left ();
void right ();


int main(){
	//����
	back2:
	system("cls");
	Printcover();
	back1:
	char input=_getch();
	if(input!='1'&&input!='2'&&input!='3'&&input!='4')goto back1;
	else
	{
		switch(input)
		{
			case '1':break;
			case '2':
			{
				system("cls");
				Printuse();
				getch();
				system("cls");
				goto back2;
				break;
			}
				
			case'3':
				{
					system("cls");
					Printinfo();
					getch();
					system("cls");
				    goto back2;
				    break;
			    }
			case'4':goto stop;break;
		}
		
	}
	//���涼�Ƿ��� 
	
	system("cls"); 
		
	srand(( int ) time ( 0 ) );      //����������� 
	for(int i = 0; i < 4; i++)
	for(int j = 0; j < 4; j++)
	{
		map[i][j]=0,color[i][j]=0;
	} 
	Sdir ();
	Sdir ();                  //��ʼ��
	 
	do 
	{ system("cls");         //���԰��������ע�͵� 
	Print ();
	T=0;
	back:                   //��Ч�ƶ�/�������back
    char input=_getch();
    if(input!='W' && input!='S' && input!='A' && input!= 'D')
   {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		printf("\t\t\t[WARNING]��������Ч�ַ�(������д����)��\n"); 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);
		goto back;
}
else
{
	    switch ( input )
	    {
		case 'W': up () ; break;
		case 'S': down() ;break;
		case 'A': left() ;break;
		case 'D': right() ;break;
     	} 
     	
     	if(T!=0)Sdir();////////��Ч�ƶ��������жϿ򣬽���end judge 
     	else
     	{
     		Judgezero();
     		if(judgezero==0)
     		{   backto:
     			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	        	printf("\t\t\t[ERROR]��Ч�ƶ���\n"); 
	    	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		        FOREGROUND_GREEN | FOREGROUND_BLUE);
		    goto back;
			}
			else
			{
				Judgeend();
				if(judgeend!=0)goto backto;
				else
				{
			    printf("\t\t\t\t\t YOU LOST!\n");Sleep(1000);
		 	    printf("\t\t\t\t\t �Ƿ����¿�ʼ���� Y/ �� N��");      //���� 
				 while(1)
			{   char input=_getch();
				if(input=='Y')goto back2;
		        if(input=='N')goto stop;
			}                   
		 	    break;               /////////����ѭ������ 
				}
			}
		}
}

for(int i = 0; i < 4; i++)   /////////�жϽ�������2 WIN 
	 for(int j = 0; j < 4 ; j++)
	 {
	 	if(map[i][j]==Topscore)Topscore*=2;
		 
		 if(map[i][j] == 2048 ) /////////������==������ 
		 {
		 	system("cls");
	        Print();
	        printf("\t\t\t\t\t YOU WIN! \n");Sleep(1000);
	        printf("\t\t\t\t\t �Ƿ����¿�ʼ���� Y/ �� N��");
			
			while(1)
			{   char input=_getch();
				if(input=='Y')goto back2;
		        if(input=='N')goto stop;
			} 
		 }
	 }	                          
	 
	}
	while(1); 
    //���� 
    stop:
	system("cls");
	printf("\t\t\t\t\t���\n");Sleep(1000);
	printf("\n\t\t\t\t\twww.bilibili.com\n\t\t\t\t\tAll Rights Reserved") ;Sleep(1000);
	printf("\n\n\t\t\t\t\t�������������Ϸ\n");getch();
	return 0;
} 


//�������� 
void Sdir()
{   
	do {
		 x1=rand()%4,y1=rand()%4;
	}
	while(map[x1][y1]!=0);
	if(rand()%2==1)map[x1][y1]=4;
	else map[x1][y1]=2;
}
///////////////////////////////����
void Printcover()
{
printf("\n\n\n\n\n");
printf("\t\t\t 222222222222222         000000000            444444444       888888888     \n") ;
printf("\t\t\t2:::::::::::::::22     00:::::::::00         4::::::::4     88:::::::::88   \n") ;
printf("\t\t\t2::::::222222:::::2  00:::::::::::::00      4:::::::::4   88:::::::::::::88 \n") ;
printf("\t\t\t2222222     2:::::2 0:::::::000:::::::0    4::::44::::4  8::::::88888::::::8\n") ;
printf("\t\t\t            2:::::2 0::::::0   0::::::0   4::::4 4::::4  8:::::8     8:::::8\n") ;
printf("\t\t\t            2:::::2 0:::::0     0:::::0  4::::4  4::::4  8:::::8     8:::::8\n") ;
printf("\t\t\t         2222::::2  0:::::0     0:::::0 4::::4   4::::4   8:::::88888:::::8 \n") ;
printf("\t\t\t    22222::::::22   0:::::0 000 0:::::04::::444444::::444  8:::::::::::::8  \n") ;
printf("\t\t\t  22::::::::222     0:::::0 000 0:::::04::::::::::::::::4 8:::::88888:::::8 \n") ;
printf("\t\t\t 2:::::22222        0:::::0     0:::::04444444444:::::4448:::::8     8:::::8\n") ;
printf("\t\t\t2:::::2             0:::::0     0:::::0          4::::4  8:::::8     8:::::8\n") ;
printf("\t\t\t2:::::2             0::::::0   0::::::0          4::::4  8:::::8     8:::::8\n") ;
printf("\t\t\t2:::::2       2222220:::::::000:::::::0          4::::4  8::::::88888::::::8\n") ;
printf("\t\t\t2::::::2222222:::::2 00:::::::::::::00         44::::::44 88:::::::::::::88 \n") ;
printf("\t\t\t2::::::::::::::::::2   00:::::::::00           4::::::::4   88:::::::::88   \n") ;
printf("\t\t\t22222222222222222222     000000000             4444444444     888888888     \n\n\n\n") ;
printf("\t\t\t\t������д����\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED);
			printf("\t\t\t\t 1 ��ʼ��Ϸ       2 ��Ϸ˵��\n");
            printf("\t\t\t\t 3 ������Ϣ       4 �˳���Ϸ\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

 } 
 void Judgezero()
 {      count=0;
        judgezero=0;
 		do {
		 x1=rand()%4,y1=rand()%4;count++;
		 if(count>50)
		 {  
		    judgezero=1;
		 	break;
		 }
	   }while(map[x1][y1]!=0);
 }
 
 void Judgeend()
 {
    judgeend=0;
 	for(int i=0;i<4;i++)
 	for(int j=0;j<3;j++)
 	{
 		if(map[i][j]==map[i][j+1])
 		{
 			judgeend=1;break;
		}
	}
	for(int j=0;j<4;j++)
 	for(int i=0;i<3;i++)
 	{
 		if(map[i][j]==map[i+1][j])
 		{
 			judgeend=1;break;
		}
	}
	
 }
 
////////////////////////////////////��ӡ��Ϸ����
int Print()
{ 

	printf("\n\n\n\n");
	printf("\t\t\t�ϣ�W\t�£�S\t��A\t�ң�D\n");
	printf("\t\t\t�X�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�[\n");
    printf("\t\t\t�U       �U       �U       �U       �U\n");
    printf("\t\t\t");
    for(int j=0;j<4;j++)
      {   printf("�U   %d",map[0][j]);
          int q=10;int sec=0;
	      while((map[0][j]/q)>0)
	           { q=q*10;sec++;}
	for(int io=0;io<3-sec;io++)printf(" ");
	
}
printf("�U\n");
  
    printf("\t\t\t�U       �U       �U       �U       �U\n");
    printf("\t\t\t�d�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�g\n");
    printf("\t\t\t�U       �U       �U       �U       �U\n");
    printf("\t\t\t");
	for(int j=0;j<4;j++)
{   printf("�U   %d",map[1][j]);
    int q=10;int sec=0;
	while((map[1][j]/q)>0)
	{   q=q*10;
		sec++;
	}
	for(int io=0;io<3-sec;io++)printf(" ");
	
}
printf("�U\n");
	
	
    printf("\t\t\t�U       �U       �U       �U       �U\n");
    printf("\t\t\t�d�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�g\n");
    printf("\t\t\t�U       �U       �U       �U       �U\n");
     printf("\t\t\t");
   for(int j=0;j<4;j++)
{   printf("�U   %d",map[2][j]);
    int q=10;int sec=0;
	while((map[2][j]/q)>0)
	{   q=q*10;
		sec++;
	}
	for(int io=0;io<3-sec;io++)printf(" ");
	
}
    printf("�U\n");
    printf("\t\t\t�U       �U       �U       �U       �U\n");
    printf("\t\t\t�d�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�p�T�T�T�T�T�T�T�g\n");
    printf("\t\t\t�U       �U       �U       �U       �U\n");
     printf("\t\t\t");
   for(int j=0;j<4;j++)
{   printf("�U   %d",map[3][j]);
    int q=10;int sec=0;
	while((map[3][j]/q)>0)
	{   q=q*10;
		sec++;
	}
	for(int io=0;io<3-sec;io++)printf(" ");
}
    printf("�U\n");
   
    printf("\t\t\t�U       �U       �U       �U       �U\n");
    printf("\t\t\t�^�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�a\n");
    printf("\n\n\t\t\t ��ǰ�÷�  %d\n",Score);
    printf("\n\n\t\t\t ��ǰ��λ��");
    switch(Topscore)
    {
    	case 16:{
    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
    		cout<<"Ӣ����ͭ"<<'\n'; 
    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 32:{
			cout<<"��������"<<'\n';
			break;
		}
		case 64:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
			cout<<"��ҫ�ƽ�"<<'\n';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 128:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_BLUE);
			cout<<"���󲬽�"<<'\n';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 256:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"����ʯ"<<'\n';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 512:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_BLUE);
			cout<<"������ʦ"<<'\n';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 1024:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
			cout<<"�ܳ���ʦ"<<'\n';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		case 2048:{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED);
			cout<<"��ǿ����"<<'\n';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
	}
	
} 
void Printinfo()
{
	
	printf("\n\n\n\n\n");
	printf("\n\n\t\t\t\t\t �Ĵ���ѧ2019����������ҽѧ�뷨ҽѧԺ\n");
	printf("\n\n\t\t\t\t\t ����ҽѧ ФXX\n");
	printf("\n\n\t\t\t\t\t ID��2019151610031\n");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t 2019.12.19 \n"); 
}
void Printuse()
{
	printf("\n\n\n\n\t\t\t\t 1.ʹ�ü��̿����������ң����и��ӻ����Ǹ������˶��� \n");
	printf("\n\n\n\n\t\t\t\t 2.��ͬ���ֵ���������,��ײʱ���ֻ���ӡ� \n");
	printf("\n\n\n\n\t\t\t\t 3.ÿ�λ���ʱ,�հ״������ˢ�³�һ�����ֵĸ��ӡ� \n");
	printf("\n\n\n\n\t\t\t\t 4.�����治���˶�ʱ(������ȫ������������ʱ),��Ϸ����;�����������������2048ʱ,��Ϸʤ���� \n");
}
//////////////////////////////���������߼�////////////////// 
void up()
{
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	color[i][j]=0;
	
   for(int j=0;j<4;j++)
	{
		for(int i=1;i<4;i++)
		{
			if(map[i][j]!=0)
			{	if(map[i-1][j]==0)
				{
					int x=i-1;
					while(map[x][j]==0&&x>=0)x--;
					swap(map[i][j],map[x+1][j]);
					i=x+1;T++;
				}
				
				if(map[i][j]==map[i-1][j]&&color[i-1][j]==0)
				{
					map[i][j]=0;map[i-1][j]*=2;color[i-1][j]=1;Score+=10;T++;
				}
			
			}
		}
	}
}

void down()
{
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	color[i][j]=0;
	
	for(int j=0;j<4;j++)
	{
		for(int i=2;i>=0;i--)
		{
			if(map[i][j]!=0)
			{	if(map[i+1][j]==0)
				{
					int x=i+1;
					while(map[x][j]==0&&x<4)x++;
					swap(map[i][j],map[x-1][j]);
					i=x-1;if(i==3)i--;
					T++;
				}
				
				if(map[i][j]==map[i+1][j]&&color[i+1][j]==0)
				{
					map[i][j]=0;map[i+1][j]*=2;color[i+1][j]=1;Score+=10;T++;
				}
			
			}
		}
	}
}
void left()

{
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	color[i][j]=0;
	
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			if(map[i][j]!=0)
			{	if(map[i][j-1]==0)
				{
					int x=j-1;
					while(map[i][x]==0&&x>=0)x--;
					swap(map[i][j],map[i][x+1]);
					j=x+1;T++;
				}
				
				if(map[i][j]==map[i][j-1]&&color[i][j-1]==0)
				{
					map[i][j]=0;map[i][j-1]*=2;color[i][j-1]=1;Score+=10;T++;
				}
			
			}
		}
	}
}
void right()
{

	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	color[i][j]=0;
	
	for(int i=0;i<4;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if(map[i][j]!=0)
			{	if(map[i][j+1]==0)
				{
					int x=j+1;
					while(map[i][x]==0&&x<4)x++;
					swap(map[i][j],map[i][x-1]);
					j=x-1;if(j==3)j--;T++;
				}
				
				if(map[i][j]==map[i][j+1]&&color[i][j+1]==0)
				{
					map[i][j]=0;map[i][j+1]*=2;color[i][j+1]=1;Score+=10;T++;
				}
			
			}
		}
	}
}
