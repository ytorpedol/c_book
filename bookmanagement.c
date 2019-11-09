#define HEADER1 ".......................................BOOK..........................................\n"
#define HEADER2 "|     bname     |     author    |          press     |price|     number      | sum |\n"               // book name书名 author作者 press出版社 price价格 number编号 sum总数
#define HEADER3 "......................................BORROW.........................................\n"
#define HEADER4 "|     name      |     number    |           inumber  |     bname    |  year  | exp |\n"         //name借阅人名字 number书籍编号 id number证件号 book name书名 day借阅日期 exp是否逾期
#define HEADER5 ".....................................................................................\n"
#define FORMAT1 "|%-15s|%-15s|%-20s|%5d|%-15s|%5d|\n"
#define FORMAT2 "|%-15s|%-15s|%-20s|%-15d|-%5d|-%5s|\n"
#define END ".........................................................................................\n"
#define DATA1 p->data1.bname,p->data1.author,p->data1.press,p->data1.price,p->data1.num,p->data1.sum
#define DATA2 r->data2.name, r->data2.num, r->data2.inum, r->data2.bname, r->data2.year, r->data2.exp,r->data2.jieshu
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int saveflag=0; /*是否需要存盘的标志变量*/  
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
typedef struct bnode        /* 定义借书信息链表的结点结构*/
{
 struct borrow data2;
 struct bnode *next;
}Bnode,*Blink;
void addtime(Blink b);
void menu()
{
	system("cls");
	printf("欢迎进入图书管理系统\n");
	printf(".....................menu.......................\n");
	printf(".      1 添加书籍           2 删除书籍.\n");
	printf(".      3 搜索书籍           4 书籍信息.\n");
	printf(".      5 借书               6 还书    .\n");
	printf(".      7 借阅信息           8 退出系统.\n");
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
void Disp(Link l)  /* 显示链表中存储的图书记录*/
{
 Node *p;
 p = l->next;
 if (!p)             /*p=NULL 则说明暂无记录*/
 {
  printf("\n= = =>没有记录!\n");
  getchar();
  return;
 }
 printf("\n\n");
 printf(HEADER1);
 printf(HEADER2);
 printf(HEADER5);
 while (p)           /*逐条输出链表中存储的图书信息*/
 {
  printf(FORMAT1, DATA1);
  p = p->next;
  printf(HEADER5);
 }
 getchar();
}
void Bdisp(Blink l)   /*显示存储的借书人的记录*/
{
 Bnode *r;
 r= l->next;
 if (!r)           /*p=NULL则说明无记录*/
 {
  printf("\n= == = =>没有记录!\n");
  getchar();
  return;
 }
 printf("\n\n");
 printf(HEADER3);
 printf(HEADER4);
 printf(HEADER5);
while (r)       /*逐条输出链表中存储的借书人信息*/
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
   printf("超过长度!\n");
 }while(len>lens);
 
   if(len < lens)
 strcpy(t, n);
}
void numberinput(int * t,char * notice)
{
	int n;
	printf(notice);             /*显示提示信息*/
	scanf("%d",&n);               /*输入字符串*/
	*t=n;               /*将输入的值拷贝到指针t中*/
}
void Add(Link l)      /* 增加图书的记录*/
{
	int sum,price;
 Node *p, *r, *s;
 char ch, flag = 0, num[10];
 r = l;
 s = l->next;
 system("color b2");
 system("cls");
 Disp(l);                   /*先输出已有的图书信息*/
 while (r->next != NULL)
  r = r->next;
 while (l)
 {
  while (l)
  {
  stringinput(num, 15, "input number(press '0' return menu):"); /* 输入书号*/
   flag = 0;
   if (strcmp(num, "0") == 0)        /*输入0退出操作，返回主界面*/
   {
    return;
   }
   s = l->next;
   while (s)
   {                                            /*查询输入的书号是否已经存在*/
    if (strcmp(s->data1.num, num) == 0)
    {
     flag = 1;
     break;
    }
    s = s->next;
   }
  if (flag == 1)                     /* 提示用户是否重新输入*/
  {
   getchar();
   printf("=====>这个编号 %s 已存在,是否重新输入?(y/n):", num);
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
			printf("\n 分配存储器失败");
			return;
		}
		strcpy(p->data1.num,num);
		stringinput(p->data1.bname,15,"bname:");
	    numberinput(&price,"price:"); /*输入定价到p->data.price中*/
		 p->data1.price =price;
        stringinput(p->data1.author,15,"author:"); /* 输入作者的名称 p->data.author */
        stringinput(p->data1.press,15,"press:"); /*输入出版社名到 p->data.pub中*/
        numberinput(&sum,"sum:"); 
		p->data1.sum= sum;
         p->next = NULL;
       r->next = p;          /*将新结点插入链表中*/
       r = p;
}
return;
}
void Save(Link l)    /* 将图书信息数据存盘 */
{
 FILE *fp;
 Node *p; 
 int count = 0;
 fp = fopen("d:\\book", "wb");   /* 以只写方式打开二进制文件 */
 if (fp == NULL)
 {                                 /* 打开文件失败 */
  printf("\n=====>open file error!\n");
  getchar();
  return;
 }
 p = l->next;

 while (p)
 {
  if (fwrite(p, sizeof(Node), 1, fp) == 1)
  {                                    /* 写记录到磁盘文件中 */
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
void Saveoi(Blink l)   /* 将借书信息存盘 */
{
 FILE *fp;
 Bnode *p; 
 int count = 0;
 fp = fopen("d:\\jieshu", "wb");   /*只写方式打开二进制文件 */
 if (fp == NULL)
 {                                /*打开文件失败*/
  printf("\n=====>open file error!\n");
  getchar();
  return;
 }
 p = l->next;
while (p)
 {
  if (fwrite(p, sizeof(Bnode), 1, fp) == 1)  /*写记录到磁盘文件中*/
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
void Sea(Link l)    /* 图书查询 */
{
 int select;
 char searchinput[20];
 Node *p;
 if (!l->next)
                  /* 若链表为空*/
 {
  system("cls");
  printf("\n=========>没有找到\n");
  getchar();
  return;
 }
 printf("\n\t1搜索图书编号 \n\t2搜索书名 \n\t3搜索作者 \n");
 printf("   please choice[1,2,3]:");
 scanf("%d", &select);
 if (select==1)   /* 按书号查询*/
 {
  stringinput(searchinput,15, "input the extsiting student number:");
  p = Locate(l,searchinput,"number");
  if (p)       /* p!=NULL*/
  {
   printdata1(p);
   printf(END);
   printf("按任意键返回");
   getchar();
  }
  else 
  printf("没有找到\n");
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
   printf("按任意键返回");
   getchar();
  }
  else
   printf("没有找到\n");
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
   printf("按任意键返回");
   getchar();
  }
  else
   printf("没有找到\n");
  getchar();
 }
 else
  printf("错误");
 getchar(); 
}
void Del(Link l)    /* 删除指定的图书记录*/
{
 int sel;
 Node *p, *r;
 char findmess[20];
 if (!l->next)
 {
  system("cls");
  printf("\n====>没有找到!\n");
  getchar();
  return;
 }
 system("cls");
 Disp(l);
 printf("\n     ======>1 删除书编号======>2删除书名======>3删除作者:");
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
   free(p);       /*将p所指的结点从链表中去除,释放内存*/
   printf("\n == == = >删除成功!\n");
   getchar();
  }
  else
   printf("没有找到");
  getchar();
 }
 else if (sel == 2)    /* 按书号查询*/
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
   printf("\n====>删除成功!\n");
   getchar();
  }
  else
   printf("没有找到\n");
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
   printf("\n====>删除成功!\n");
   getchar();
  }
  else
   printf("没有找到\n");
  getchar();
 }
 else
  printf("wrong\n");
 getchar();
}
void addtime(Blink b)
{
	char num[15];
    Bnode *p,*r,*s;/* 实现添加的临时的结构体指针变量*/
	char flag=0;
	int Year,Month,Day;
	r=b;
	s=b-> next;
	system("cls");
	while(r-> next!=NULL)
	r=r-> next;     /*将指针移至于链表最末尾，准备添加记录*/
		p=(Bnode * )malloc(sizeof(Bnode));     /*为新增记录申请内存空间*/
		if(!p)
		{ 
			printf("\n allocate memory failure");   /*如没有申请到，请打印提示信息*/
			return;    /*返回主页面*/ 
		}
	    stringinput(num,15,"input number(press '0' return menu):");
        strcpy(p-> data2.num,num);      /*将字符串num拷贝到p-> data.num中*/
		numberinput(&Year,"请输入当前年份");
		p->data2.year=Year;
			printf("请输入月日：");
		scanf("%d%d",&Month,&Day);
        p->data2.tianshu=day(p->data2.year,Month,Day);
			p->next=NULL;    /*表明这是链尾的尾部节点*/
		r-> next=p;    /*将新建的节点加入链表尾部中*/
		r=p;
		saveflag=1;			
}
int day(int YEAR,int MONTH,int DAY)
{
int i,j,x;
int num=0;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};//平年2月28天 365天
int b[12]={31,29,31,30,31,30,31,31,30,31,30,31};//闰年2月29天 366天
//判断是否为闰年
if ((YEAR%4==0)&&(YEAR%100!=0)||(YEAR%4==0)&&(YEAR%400==0))
x=1;//是闰年
else
x=0;//是平年
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
                      /* 输入借书人的编号*/
  if (strcmp(number, "0") == 0)
   break;
  stringinput(booknum, 15, "please input the number of book:");  /*输入书号*/
  addtime(b);
do
  {
   if (strcmp(q->data1.num,number) == 0)  /* 查看书号是否存在 */
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
          /* 申请内存空间*/
     k = (Bnode*)malloc(sizeof(Bnode));
     if (!k)
     {
      printf("\n allocate memory failure");
               /* 如没有申请到，输入提示信息 */
      return;
     }
     strcpy(k->data2.num, q->data1.num);
     strcpy(k->data2.bname, q->data1.bname);
     k->next = NULL;
     s->next = k;    /* 将新结点插入链表 */
     s = k;
    }
 Saveoi(b);          /* 写记录到磁盘文件 */
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
   stringinput(inum,15,"请输入你的证件号:");/*匹配证件号*/
   stringinput(searchinput,15,"请输入你的书号:");/*匹配书号*/
   printf("请分别输入当前的年月日：\n");
   scanf("%d%d%d",&Year,&Month,&Date);
   if(p->data2.year-Year==1)
   {
	   if(day(Year,Month,Date)<30)
	   {
           if((day(Year,Month,Date)+(365-p->data2.tianshu))-30>0)
			   printf("您的借书时间已经超时，请付费%d\n",(day(Year,Month,Date)+(365-p->data2.tianshu))-30);
	   }
   }
   else if(p->data2.year-Year>1)
	   printf("您的借书时间已经超时，请付费%d\n",(p->data2.year-Year)*365+(365-p->data2.tianshu));
   else if(day(Year,Month,Date)-p->data2.tianshu>30)
	   printf("您的借书时间已经超时，请付费%d\n",day(Year,Month,Date)-p->data2.tianshu);
   a=p1->data1.sum++;
   printf("当该数库存有%d本",a);
}
void Exi()  /* 退出系统 */
{
 menu();
}
void main()
{
Link l; Blink b;     /*定义链表*/
FILE *fp;        /* 文件指针 */
int select;
int count = 0;
Node *p, *r;
Bnode *s, *k;  system("color a1");
b =(Bnode*)malloc(sizeof(Bnode));
 if (!b)
 {
  printf("\n allocate memory faliure "); /*如果没有申请到，打印提示信息*/
  return;                /*返回主界面*/
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
   printf("memory malloc failure!\n"); /*没有申请成功*/
   exit(0);
  }
  if (fread(s, sizeof(Bnode), 1, fp) == 1)  /*从文件中读取借书的信息记录*/
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
  printf("\n allocate memory failure "); /* 如果没有申请到，打印提示信息*/
  return;                 /* 返回主界面*/
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
   printf("memory malloc faliure!\n");   /* 没有申请成功 */
   exit(0);
  }
  if (fread(p, sizeof(Node), 1, fp) == 1)   /* 从文件中读取图书信息记录*/
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