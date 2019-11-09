#define HEADER1 ".......................................BOOK..........................................\n"
#define HEADER2 "|     bname     |     author    |          press     |price|     number      | sum |\n"               // book name���� author���� press������ price�۸� number��� sum����
#define HEADER3 "......................................BORROW.........................................\n"
#define HEADER4 "|     name      |     number    |           inumber  |     bname    |  year  | exp |\n"         //name���������� number�鼮��� id number֤���� book name���� day�������� exp�Ƿ�����
#define HEADER5 ".....................................................................................\n"
#define FORMAT1 "|%-15s|%-15s|%-20s|%5d|%-15s|%5d|\n"
#define FORMAT2 "|%-15s|%-15s|%-20s|%-15d|-%5d|-%5s|\n"
#define END ".........................................................................................\n"
#define DATA1 p->data1.bname,p->data1.author,p->data1.press,p->data1.price,p->data1.num,p->data1.sum
#define DATA2 r->data2.name, r->data2.num, r->data2.inum, r->data2.bname, r->data2.year, r->data2.exp,r->data2.jieshu
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int saveflag=0; /*�Ƿ���Ҫ���̵ı�־����*/  
typedef struct book
{
	char bname[15];
	char author[15];
	char press[20];
	int price;
	char num[15];
	int sum;
}book;
typedef struct borrow
{
	char name[15];
	char num[15];
	char inum[15];
	char bname[15];
    int  year;
	int tianshu,jieshu;
	char exp[5];
}borrow;
typedef struct node
{
	struct book data1;
	struct node *next;
}Node,*Link;
typedef struct bnode        /* ���������Ϣ����Ľ��ṹ*/
{
 struct borrow data2;
 struct bnode *next;
}Bnode,*Blink;
void addtime(Blink b);
void menu()
{
	system("cls");
	printf("��ӭ����ͼ�����ϵͳ\n");
	printf(".....................menu.......................\n");
	printf(".      1 ����鼮           2 ɾ���鼮.\n");
	printf(".      3 �����鼮           4 �鼮��Ϣ.\n");
	printf(".      5 ����               6 ����    .\n");
	printf(".      7 ������Ϣ           8 �˳�ϵͳ.\n");
	printf("................................................\n");
}
void printfheader()
{
	printf(HEADER1);
	printf(HEADER2);
	printf(HEADER3);
	printf(HEADER4);
	printf(HEADER5);
}
void printdata(Node *pp,int a,Bnode *rr)
{
	Node *p;Bnode *r;
	if(a==1)
	{  p=pp;
	   printf(FORMAT1,DATA1);
	}
	else{
		 r=rr;
		 printf(FORMAT2,DATA2);
	}
}
void Wrong()
{
	printf("\n\n\n\n\n.....Error:input has wrong!press any key to continue.....\n");
	getchar();
}
void Disp(Link l)  /* ��ʾ�����д洢��ͼ���¼*/
{
 Node *p;
 p = l->next;
 if (!p)             /*p=NULL ��˵�����޼�¼*/
 {
  printf("\n= = =>û�м�¼!\n");
  getchar();
  return;
 }
 printf("\n\n");
 printf(HEADER1);
 printf(HEADER2);
 printf(HEADER5);
 while (p)           /*������������д洢��ͼ����Ϣ*/
 {
  printf(FORMAT1, DATA1);
  p = p->next;
  printf(HEADER5);
 }
 getchar();
}
void Bdisp(Blink l)   /*��ʾ�洢�Ľ����˵ļ�¼*/
{
 Bnode *r;
 r= l->next;
 if (!r)           /*p=NULL��˵���޼�¼*/
 {
  printf("\n= == = =>û�м�¼!\n");
  getchar();
  return;
 }
 printf("\n\n");
 printf(HEADER3);
 printf(HEADER4);
 printf(HEADER5);
while (r)       /*������������д洢�Ľ�������Ϣ*/
 {
  printf(FORMAT2,DATA2);
  r = r->next;
  printf(HEADER5);
 }
 getchar();
}
void stringinput(char *t, int lens, char *notice)
{
 char n[50];
 int len = 0;
 do
 {
  printf(notice);
  scanf("%s",n);
  while(n[len++] != '\0');
  if(len > lens)
   printf("��������!\n");
 }while(len>lens);
 
   if(len < lens)
 strcpy(t, n);
}
void numberinput(int * t,char * notice)
{
	int n;
	printf(notice);             /*��ʾ��ʾ��Ϣ*/
	scanf("%d",&n);               /*�����ַ���*/
	*t=n;               /*�������ֵ������ָ��t��*/
}
void Add(Link l)      /* ����ͼ��ļ�¼*/
{
	int sum,price;
 Node *p, *r, *s;
 char ch, flag = 0, num[10];
 r = l;
 s = l->next;
 system("color b2");
 system("cls");
 Disp(l);                   /*��������е�ͼ����Ϣ*/
 while (r->next != NULL)
  r = r->next;
 while (l)
 {
  while (l)
  {
  stringinput(num, 15, "input number(press '0' return menu):"); /* �������*/
   flag = 0;
   if (strcmp(num, "0") == 0)        /*����0�˳�����������������*/
   {
    return;
   }
   s = l->next;
   while (s)
   {                                            /*��ѯ���������Ƿ��Ѿ�����*/
    if (strcmp(s->data1.num, num) == 0)
    {
     flag = 1;
     break;
    }
    s = s->next;
   }
  if (flag == 1)                     /* ��ʾ�û��Ƿ���������*/
  {
   getchar();
   printf("=====>������ %s �Ѵ���,�Ƿ���������?(y/n):", num);
   scanf("%c", &ch);
   if (ch == 'y' || ch == 'Y')
    continue;
   else
    return;
  }
  else
  {
   break;
  }
 }
		p=(Node *)malloc(sizeof(Node));
		if(!p)
		{
			printf("\n ����洢��ʧ��");
			return;
		}
		strcpy(p->data1.num,num);
		stringinput(p->data1.bname,15,"bname:");
	    numberinput(&price,"price:"); /*���붨�۵�p->data.price��*/
		 p->data1.price =price;
        stringinput(p->data1.author,15,"author:"); /* �������ߵ����� p->data.author */
        stringinput(p->data1.press,15,"press:"); /*������������� p->data.pub��*/
        numberinput(&sum,"sum:"); 
		p->data1.sum= sum;
         p->next = NULL;
       r->next = p;          /*���½�����������*/
       r = p;
}
return;
}
void Save(Link l)    /* ��ͼ����Ϣ���ݴ��� */
{
 FILE *fp;
 Node *p; 
 int count = 0;
 fp = fopen("d:\\book", "wb");   /* ��ֻд��ʽ�򿪶������ļ� */
 if (fp == NULL)
 {                                 /* ���ļ�ʧ�� */
  printf("\n=====>open file error!\n");
  getchar();
  return;
 }
 p = l->next;

 while (p)
 {
  if (fwrite(p, sizeof(Node), 1, fp) == 1)
  {                                    /* д��¼�������ļ��� */
   p = p->next;
   count++;
  }
  else
  {
   break;
  }
 }
 if (count > 0)
 {
  getchar();
  printf("\n\n\n\t save file complete,total saved's record number is:%d\n", count);
  getchar();
 }
 else
 {
  system("cls");
  printf("the current link is empty,no student record is saved!\n");
  getchar();
 }
 fclose(fp);
}
void Saveoi(Blink l)   /* ��������Ϣ���� */
{
 FILE *fp;
 Bnode *p; 
 int count = 0;
 fp = fopen("d:\\jieshu", "wb");   /*ֻд��ʽ�򿪶������ļ� */
 if (fp == NULL)
 {                                /*���ļ�ʧ��*/
  printf("\n=====>open file error!\n");
  getchar();
  return;
 }
 p = l->next;
while (p)
 {
  if (fwrite(p, sizeof(Bnode), 1, fp) == 1)  /*д��¼�������ļ���*/
  { 
   p = p->next;
   count++;
  }
  else
  {
   break;
  }
 }
 if (count > 0)
 {
  getchar();
  printf("\n\n\n\t save file complete,total saved's record number is:%d\n", count);
  getchar();
 }
 else
 {
  system("cls");
  printf("the current link is empty,no student record is saved!\n");
  getchar();
 }
 fclose(fp);
}
Node *Locate(Link l, char *s, char*t)
{
 Link p;
 p = l;printf(t);
 while (p != NULL)
 {
  if (strcmp(p->data1.num,s)==0)
  return p;
  p=p->next;
 }
}
void printdata1(Node *s)
{
 Node *p;
 p=s;
 printf(FORMAT1, DATA1);
}
void Sea(Link l)    /* ͼ���ѯ */
{
 int select;
 char searchinput[20];
 Node *p;
 if (!l->next)
                  /* ������Ϊ��*/
 {
  system("cls");
  printf("\n=========>û���ҵ�\n");
  getchar();
  return;
 }
 printf("\n\t1����ͼ���� \n\t2�������� \n\t3�������� \n");
 printf("   please choice[1,2,3]:");
 scanf("%d", &select);
 if (select==1)   /* ����Ų�ѯ*/
 {
  stringinput(searchinput,15, "input the extsiting student number:");
  p = Locate(l,searchinput,"number");
  if (p)       /* p!=NULL*/
  {
   printdata1(p);
   printf(END);
   printf("�����������");
   getchar();
  }
  else 
  printf("û���ҵ�\n");
  getchar();
 }
 else if (select == 2)
 {
  stringinput(searchinput, 15, "input the existing bookname:");
  p = Locate(l, searchinput, "bname");
  if (p)
  {
   printdata1(p);
   printf(END);
   printf("�����������");
   getchar();
  }
  else
   printf("û���ҵ�\n");
  getchar();
 }
 else if (select == 3)
 {
  stringinput(searchinput, 15, "input the existing author:");
  p = Locate(l, searchinput, "author");
  if (p)
  {
   printdata1(p);
   printf(END);
   printf("�����������");
   getchar();
  }
  else
   printf("û���ҵ�\n");
  getchar();
 }
 else
  printf("����");
 getchar(); 
}
void Del(Link l)    /* ɾ��ָ����ͼ���¼*/
{
 int sel;
 Node *p, *r;
 char findmess[20];
 if (!l->next)
 {
  system("cls");
  printf("\n====>û���ҵ�!\n");
  getchar();
  return;
 }
 system("cls");
 Disp(l);
 printf("\n     ======>1 ɾ������======>2ɾ������======>3ɾ������:");
 printf("Please choice [1,2,3]");
 scanf("%d", &sel);
 if (sel == 1)
 {
  stringinput(findmess, 10, "input the existing num:");
  p = Locate(l,findmess,"num");
  if (p)
  {
   r = l;
   while (r->next != p)
    r = r->next;
   r->next = p->next; 
   free(p);       /*��p��ָ�Ľ���������ȥ��,�ͷ��ڴ�*/
   printf("\n == == = >ɾ���ɹ�!\n");
   getchar();
  }
  else
   printf("û���ҵ�");
  getchar();
 }
 else if (sel == 2)    /* ����Ų�ѯ*/
 {
  stringinput(findmess, 15, "input the exsting bookname");
  p = Locate(l,findmess,"bname");
  if (p)
  {
   r = l;
   while (r->next != p)
    r = r->next;
   r->next = p->next;
   free(p);
   printf("\n====>ɾ���ɹ�!\n");
   getchar();
  }
  else
   printf("û���ҵ�\n");
  getchar();
 }
 else if (sel == 3)   
 {
  stringinput(findmess, 15, "input the exsting author");
  p = Locate(l, findmess, "author");
  if (p)
  {
   r = l;
   while (r->next != p)
    r = r->next;
   r->next = p->next;
   free(p);
   printf("\n====>ɾ���ɹ�!\n");
   getchar();
  }
  else
   printf("û���ҵ�\n");
  getchar();
 }
 else
  printf("wrong\n");
 getchar();
}
void addtime(Blink b)
{
	char num[15];
    Bnode *p,*r,*s;/* ʵ����ӵ���ʱ�Ľṹ��ָ�����*/
	char flag=0;
	int Year,Month,Day;
	r=b;
	s=b-> next;
	system("cls");
	while(r-> next!=NULL)
	r=r-> next;     /*��ָ��������������ĩβ��׼����Ӽ�¼*/
		p=(Bnode * )malloc(sizeof(Bnode));     /*Ϊ������¼�����ڴ�ռ�*/
		if(!p)
		{ 
			printf("\n allocate memory failure");   /*��û�����뵽�����ӡ��ʾ��Ϣ*/
			return;    /*������ҳ��*/ 
		}
	    stringinput(num,15,"input number(press '0' return menu):");
        strcpy(p-> data2.num,num);      /*���ַ���num������p-> data.num��*/
		numberinput(&Year,"�����뵱ǰ���");
		p->data2.year=Year;
			printf("���������գ�");
		scanf("%d%d",&Month,&Day);
        p->data2.tianshu=day(p->data2.year,Month,Day);
			p->next=NULL;    /*����������β��β���ڵ�*/
		r-> next=p;    /*���½��Ľڵ��������β����*/
		r=p;
		saveflag=1;			
}
int day(int YEAR,int MONTH,int DAY)
{
int i,j,x;
int num=0;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};//ƽ��2��28�� 365��
int b[12]={31,29,31,30,31,30,31,31,30,31,30,31};//����2��29�� 366��
//�ж��Ƿ�Ϊ����
if ((YEAR%4==0)&&(YEAR%100!=0)||(YEAR%4==0)&&(YEAR%400==0))
x=1;//������
else
x=0;//��ƽ��
if (x)
{
for (i=0;i<MONTH-1;i++)
num+=b[i];
num=num+DAY;
}
else
{
for (j=0;j<MONTH-1;j++)
num+=a[j];
num+=DAY;
}
return num;
}
void Bor(Link l,Blink b)
{
 Node *q;
 Bnode *t, *s, *k;
 char number[10], booknum[10];
 system("cls");
 t = b->next;
 if (!t)
 {
  printf("\n=====>Not record!\n");
 }
 printf("\n\n");
 printf(HEADER3);
 printf(HEADER4);
 printf(HEADER5);
while (t)
 {
  printf(FORMAT2, t->data2.name, t->data2.bname, t->data2.inum, t->data2.num,t->data2.year,t->data2.exp);
  t = t->next;
  printf(HEADER5);
 }
 while (l)
 {
  s = b;
 q = l->next;
  while (s->next != NULL)
   s = s->next;
  stringinput(number, 10, "please input the number of member:");
                      /* ��������˵ı��*/
  if (strcmp(number, "0") == 0)
   break;
  stringinput(booknum, 15, "please input the number of book:");  /*�������*/
  addtime(b);
do
  {
   if (strcmp(q->data1.num,number) == 0)  /* �鿴����Ƿ���� */
    break;
   else
    q = q->next;
  } 
  while (q != NULL);
 if (q == NULL)
   {
   printf("the book is not exist!");
   return;
   }
   else
   {
          /* �����ڴ�ռ�*/
     k = (Bnode*)malloc(sizeof(Bnode));
     if (!k)
     {
      printf("\n allocate memory failure");
               /* ��û�����뵽��������ʾ��Ϣ */
      return;
     }
     strcpy(k->data2.num, q->data1.num);
     strcpy(k->data2.bname, q->data1.bname);
     k->next = NULL;
     s->next = k;    /* ���½��������� */
     s = k;
    }
 Saveoi(b);          /* д��¼�������ļ� */
 getchar();
 }
}
void huanshu(Link l,Blink b)
{
	int a;         
	Bnode *p;
	Node *p1;
	char inum[13],searchinput[6];
	int Year,Month,Date;
   stringinput(inum,15,"���������֤����:");/*ƥ��֤����*/
   stringinput(searchinput,15,"������������:");/*ƥ�����*/
   printf("��ֱ����뵱ǰ�������գ�\n");
   scanf("%d%d%d",&Year,&Month,&Date);
   if(p->data2.year-Year==1)
   {
	   if(day(Year,Month,Date)<30)
	   {
           if((day(Year,Month,Date)+(365-p->data2.tianshu))-30>0)
			   printf("���Ľ���ʱ���Ѿ���ʱ���븶��%d\n",(day(Year,Month,Date)+(365-p->data2.tianshu))-30);
	   }
   }
   else if(p->data2.year-Year>1)
	   printf("���Ľ���ʱ���Ѿ���ʱ���븶��%d\n",(p->data2.year-Year)*365+(365-p->data2.tianshu));
   else if(day(Year,Month,Date)-p->data2.tianshu>30)
	   printf("���Ľ���ʱ���Ѿ���ʱ���븶��%d\n",day(Year,Month,Date)-p->data2.tianshu);
   a=p1->data1.sum++;
   printf("�����������%d��",a);
}
void Exi()  /* �˳�ϵͳ */
{
 menu();
}
void main()
{
Link l; Blink b;     /*��������*/
FILE *fp;        /* �ļ�ָ�� */
int select;
int count = 0;
Node *p, *r;
Bnode *s, *k;  system("color a1");
b =(Bnode*)malloc(sizeof(Bnode));
 if (!b)
 {
  printf("\n allocate memory faliure "); /*���û�����뵽����ӡ��ʾ��Ϣ*/
  return;                /*����������*/
 }
 b->next = NULL;
 k = b;
 fp = fopen("d:\\borrow","ab+");
 if (fp == NULL)
 {
  printf("\n =====>can not open file!\n");
  exit(0);
 }
 while (!feof(fp))
 {
  s = (Bnode*)malloc(sizeof(Bnode));
  if (!s)
  {
   printf("memory malloc failure!\n"); /*û������ɹ�*/
   exit(0);
  }
  if (fread(s, sizeof(Bnode), 1, fp) == 1)  /*���ļ��ж�ȡ�������Ϣ��¼*/
  {
   s->next = NULL;
   k->next = s;
   k = s;
  }
 }
 fclose(fp);
 l = (Node*)malloc(sizeof(Node));
 if (!l)
 {
  printf("\n allocate memory failure "); /* ���û�����뵽����ӡ��ʾ��Ϣ*/
  return;                 /* ����������*/
 }
 l->next = NULL;
 r = l;
 fp =fopen("d:\\book","ab+");
 if (fp == NULL)
 {
  printf("\n =====> can't open file!\n");
  exit(0);
 }

 while (!feof(fp))
 {
  p = (Node*)malloc(sizeof(Node));
  if (!p)
  {
   printf("memory malloc faliure!\n");   /* û������ɹ� */
   exit(0);
  }
  if (fread(p, sizeof(Node), 1, fp) == 1)   /* ���ļ��ж�ȡͼ����Ϣ��¼*/
  {
   p->next = NULL;
   r->next = p;
   r = p;
   count++;
  }
 }
 fclose(fp);
 printf("\n =====> open file sucess,the total records number is:%d.\n", count);
 menu();
 while (l)
 {
  p = r;
  printf("\n    Please Enter your choice(1~8):");
  scanf("%d", &select);
switch(select)
{
case 1:Add(l);break;
case 2:Del(l);break;
case 3:Sea(l);break;
case 4:Disp(l);break;
case 5:Bor(l,b);break;
case 6:huanshu(l,b);break;
case 7:Bdisp(b);break;
case 8:Exi();break;
default:Wrong();getchar();break;
}
 }
}