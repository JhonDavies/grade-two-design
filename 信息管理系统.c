#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define MAXLEN 1000

struct student_type
{
    int num;//ѧ�Ż򿼺�
    char name[50];//����
    char clas[50];//�༶
};

typedef struct student_type DataType;

typedef struct
{
    DataType list[MAXLEN+1]; //������Ա�Ԫ��
    int length; //������Ա��
}SeqList;

/*����*/
void password();//��������
void menu();//�˵�
void input(SeqList *L);//����ѧ����Ϣ
int search(SeqList* L, int tnum);//��ѧ�Ų���
int del(SeqList *L, int tnum, DataType *py);//ɾ����Ϣ
void output(SeqList *L);

/*������*/
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
            case 2: printf("����������ҵ�ѧ��:\n");
                    scanf("%d",&tnum);
		            k=search(L,tnum);
			        if(k==0)
                        printf("���޴��ˣ�\n");
                    else
			        {   printf("��ѧ����������ϢΪ��\n");
                        printf("  ѧ��    ����     �༶\n");
                        printf("%10d%10s%10s\n",L->list[k].num,L->list[k].name,L->list[k].clas);
                    }
                    getchar();
                    getchar();
			        break;
            case 3: printf("�������ɾ��ѧ����ѧ��:\n");
		            scanf("%d",&tnum);
		            k=del(L,tnum,&y);
			        if(k==0)
                        printf("ɾ��ʧ�ܣ�\n");
                    else
                    {
				        printf("ɾ���ɹ���\n");
                        printf("��ɾ��ѧ����������ϢΪ��\n");
				        printf("  ѧ��    ����     �༶\n");
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

void password()//��������
{
    char cipher[20]={"123456"},a[20];
    int i,j;
    for(i=0;i<3;i++)//�����������
    {
        printf("��ӭ����ѧ����Ϣ����ϵͳ\n");
        printf("����������:");
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
        printf("�������\n");
        Sleep(1000);
        system("cls");
    }
    printf("������������˳�ϵͳ!");
    Sleep(3000);
    exit(1);
}
void menu()//�˵�
{
    printf("***********ϵͳ���ܲ˵�**********\n");
    printf("*  1-----------����ѧ����Ϣ     *\n");
    printf("*  2-----------��ѧ�Ų���       *\n");
    printf("*  3-----------ɾ��ָ��ѧ��ѧ�� *\n");
    printf("*  4-----------���ѧ����Ϣ     *\n");
    printf("*  0-----------�˳�ϵͳ         *\n");
    printf("*********************************\n");
    printf("���������ѡ��:");

}
void input(SeqList *L)//����ѧ����Ϣ
{
    int i;
    printf("������ѧ����������");
    scanf("%d",&L->length);
    printf("������ѧ����ѧ�ţ��������༶:\n");
    for(i=1;i<=L->length;i++)
        scanf("%d%s%s",&L->list[i].num,L->list[i].name,&L->list[i].clas);
}
void output(SeqList *L)//���ѧ����Ϣ
{ int i;
  printf("  ѧ��    ����     �༶\n");
  for(i=1;i<=L->length;i++)
       printf("%10d%10s%10s\n",L->list[i].num,L->list[i].name,L->list[i].clas);
  printf("\n");
}
int search(SeqList* L, int tnum)//��ѧ�Ų���
{
    int i;
    L->list[0].num=tnum;
    i=L->length;
    while(L->list[i].num!=tnum)
        i--;
    return(i);
 //���ҳɹ�����Ԫ�����ڵ�λ�ã�������ʧ�ܣ�����0
}
int del(SeqList *L, int tnum, DataType *py)//ɾ����Ϣ
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
