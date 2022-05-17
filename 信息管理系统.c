#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define MAXLEN 1000

struct student_type
{
    int num;//学号或考号
    char name[50];//姓名
    char clas[50];//班级
};

typedef struct student_type DataType;

typedef struct
{
    DataType list[MAXLEN+1]; //存放线性表元素
    int length; //存放线性表表长
}SeqList;

/*函数*/
void password();//输入密码
void menu();//菜单
void input(SeqList *L);//输入学生信息
int search(SeqList* L, int tnum);//按学号查找
int del(SeqList *L, int tnum, DataType *py);//删除信息
void output(SeqList *L);

/*主函数*/
int main()
{
    int ch=1,k,tnum;
    DataType y;
    SeqList a,*L=&a;
    password();
    while(ch!=0)
    {
        system("cls");
        menu();
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: input(L);
                    break;
            case 2: printf("请输入待查找的学号:\n");
                    scanf("%d",&tnum);
		            k=search(L,tnum);
			        if(k==0)
                        printf("查无此人！\n");
                    else
			        {   printf("该学生的完整信息为：\n");
                        printf("  学号    姓名     班级\n");
                        printf("%10d%10s%10s\n",L->list[k].num,L->list[k].name,L->list[k].clas);
                    }
                    getchar();
                    getchar();
			        break;
            case 3: printf("请输入待删除学生的学号:\n");
		            scanf("%d",&tnum);
		            k=del(L,tnum,&y);
			        if(k==0)
                        printf("删除失败！\n");
                    else
                    {
				        printf("删除成功！\n");
                        printf("被删除学生的完整信息为：\n");
				        printf("  学号    姓名     班级\n");
                        printf("%10d%10s%10s\n",y.num,y.name,y.clas);
			        }
			        getchar();
			        getchar();
			        break;
            case 4: output(L);
                    getchar();
                    getchar();
                    break;
        }
    }
    return 0;
}

void password()//输入密码
{
    char cipher[20]={"123456"},a[20];
    int i,j;
    for(i=0;i<3;i++)//三次输入机会
    {
        printf("欢迎进入学生信息管理系统\n");
        printf("请输入密码:");
        for(j=0;a[j-1]!=13;j++)
        {
            a[j]=getch();
            if(a[j]==8&&j>0)
            {
                printf("\b \b");
                j--;
            }
            else if(j>=0&&a[j]!=13)
                printf("*");
            else if(a[j]==13)
                printf("\n");
            else
                printf(" ");
        }
        a[j-1]='\0';
        if(strcmp(cipher,a)==0)
            return;
        printf("密码错误！\n");
        Sleep(1000);
        system("cls");
    }
    printf("三次输入错误，退出系统!");
    Sleep(3000);
    exit(1);
}
void menu()//菜单
{
    printf("***********系统功能菜单**********\n");
    printf("*  1-----------输入学生信息     *\n");
    printf("*  2-----------按学号查找       *\n");
    printf("*  3-----------删除指定学号学生 *\n");
    printf("*  4-----------输出学生信息     *\n");
    printf("*  0-----------退出系统         *\n");
    printf("*********************************\n");
    printf("请输入你的选择:");

}
void input(SeqList *L)//输入学生信息
{
    int i;
    printf("请输入学生的人数：");
    scanf("%d",&L->length);
    printf("请输入学生的学号，姓名及班级:\n");
    for(i=1;i<=L->length;i++)
        scanf("%d%s%s",&L->list[i].num,L->list[i].name,&L->list[i].clas);
}
void output(SeqList *L)//输出学生信息
{ int i;
  printf("  学号    姓名     班级\n");
  for(i=1;i<=L->length;i++)
       printf("%10d%10s%10s\n",L->list[i].num,L->list[i].name,L->list[i].clas);
  printf("\n");
}
int search(SeqList* L, int tnum)//按学号查找
{
    int i;
    L->list[0].num=tnum;
    i=L->length;
    while(L->list[i].num!=tnum)
        i--;
    return(i);
 //查找成功返回元素所在的位置；若查找失败，返回0
}
int del(SeqList *L, int tnum, DataType *py)//删除信息
{  int i,j;
   i=search(L,tnum);
   if(i==0)
     return 0;
   else
   { *py=L->list[i];
     for(j=i+1;j<=L->length;j++)
        L->list[j-1]=L->list[j];
     L->length--;
     return 1;
   }
}
