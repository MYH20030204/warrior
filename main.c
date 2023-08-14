#include <stdio.h>
#include <stdlib.h>

//链表的定义
typedef struct LNode
{
    int date;
    struct LNode* next;
}LNode, * LinkList;                  //LinkList 代表指向结构体的指针

//初始化链表
void InitList(LinkList* L1)        //传递一个指针的地址，即一个地址就必须要用一个新的指针来接收
{                                       //所以此时的L代表的是一个指向指针的指针，即指针的指针。
    *L1 = (LNode*)malloc(sizeof(LNode));     //所以对于二级二级指针就必须解引用（去掉外壳）
    (*L1)->next = NULL;                               //此时的指针   *L1==L （指针）
}
//链表的排序从低到高
void BubbleSort(LinkList *L) {

    int i, count = 0, num;//count记录链表结点的个数，num进行内层循环，
    LNode *p, *q, *tail;//创建三个指针，进行冒泡排序
    p = (*L);
    while (p->next != NULL)//计算出结点的个数
    {

        count++;
        p = p->next;
    }
    for (i = 0; i < count - 1; i++)//外层循环，跟数组冒泡排序一样
    {

        num = count - i - 1;//记录内层循环需要的次数，跟数组冒泡排序一样，
        q = (*L)->next;//令q指向第一个结点
        p = q->next;//令p指向后一个结点
        tail = (*L);//让tail始终指向q前一个结点，方便交换，也方便与进行下一步操作
        while (num--)//内层循环 次数跟数组冒泡排序一样
        {
            if (q->date > p->date)//如果该结点的值大于后一个结点，则交换
            {

                q->next = p->next;
                p->next = q;
                tail->next = p;
            }

            tail = tail->next;

            q = tail->next;

            p = q->next;
        }

    }
}


//头插法创建
void CreatFromHead(LinkList* L1)
{

    int x, y;
    printf("请输入要创建的结点个数\n");
    scanf("%d", &y);
    for (int a = 1; a <= y; a++)
    {
        LNode* s = (LNode*)malloc(sizeof(LNode));       // 每次创建结点都必须创建空间
        printf("请输入结点中的元素：");
        scanf("%d", &x);
        s->date = x;
        s->next = NULL;
        //在空链表中插入元素时和在有元素的链表中插入是不相同的
        if ((*L1)->next == NULL)     //若是在空表中插入第一个就把结点赋给头指针的next域
        {
            (*L1)->next = s;
        }
        else                            //接下来当表不为空时，就把接下来的结点插入
        {
            s->next = (*L1)->next;        //省略一个中间过程，头指针的next域为空，给了插入的第一个元素的next域
            (*L1)->next = s;               //第二个新结点s进来时此时的(*L1)->next 代表的是第一个结点的地址，因为是头插入
        }                                   //然后将新的结点s的地址给头指针即可
    }                                       //因为是头插法，所以输出的结果必然会与输入时相反
    BubbleSort(L1);
}

//尾插法创建
void CreatFromTail(LinkList* L2)
{
    int x,y;
    printf("请输入要创建的结点个数");
    scanf("%d",&y);
    for (int a=1;a<=y;a++)
    {
        LNode* cur=(*L2)->next;     //分情况，链表是否为空
        if((*L2)->next==NULL)
        {
            cur=(*L2)->next;
        }
       else {
            while (cur->next != NULL)          //每次进行尾插时都会进行找尾，然后再进行插入，注意for循环的整个范围
            {
                cur = cur->next;
            }
        }
        LNode* s = (LNode*)malloc(sizeof(LNode));   //每次创建一个结点都要创建空间
        printf("请输入结点中的元素：");
        scanf("%d", &x);
        s->date = x;                        //尾插法，一定要注意就是尾指针的更新
        s->next = NULL;                  //因为每一次插入都是都是从尾插入，而插入的位置就是尾指针所指向1的结点
        if ((*L2)->next == NULL)            //创建第一个结点时比较特殊
        {                               //创建第一个结点时，首先就要就行判断
            (*L2)->next= s;            //将第一个结点插入后，要加上更新尾指针，否则接下来的从第二个结点的插入都无法插入
                                        //  所以在for循环里加入了找尾的代码，这样就不用更新尾了
        }
        else
        {                   //将上一个结点的指针域（是一个空的，此时第一个结点即是尾巴），然后将下来的结点的地址给前一个的指针域
            cur->next=s; //即将第二个结点的地址给上一个空指针域，又因为第一个结点被尾指针所指，所以是r->next=s，此时s是一个新的结点

        }
    }
    BubbleSort(L2);//输入好结点元素后进行调用排序函数
}

//单链表的查找（按照序号）
LNode *GetDate(LinkList*L3,int i)           //返回值为一个指针，所以是LNode *GetDate
{

    LNode *p;
    if (i<=0)       //确定查找位置
        return NULL;
    p=(*L3);
    int j=0;        //当作一个计数器，当i=j时，即可
    while ((p->next!=NULL)&&(j<i))
    {
        p=p->next;
        j++;
    }
    if(i==j)
        return p;
    else
        return NULL;
}
//单链表的查找（按内容查找）
int GetDate2(LinkList *L4,int key)
{
    LNode *p;
    int j=1;    //结点数
    p=(*L4)->next;
    while (p->next!=NULL)
    {
        if(p->date!=key)
        {
            p=p->next;
            ++j;
        }
        else
            break;

    }
    return j;
}

//单链表的长度
int ListLength(LinkList *L5)
{
    LNode *p;
    p=(*L5)->next;
    int j=0;
    while (p!=NULL)     //若为空表则返回长度为0
    {
        p=p->next;
        j++;
    }
    return j;
}

//单链表的插入
int InsList(LinkList *L6,int i,int e)              //在单链表中第i个位置插入值为e的新结点
{
    LNode *pre,*s;
    int k=0;
    if (i<=0)
    { printf("插入位置不合理\n");
        return 0;}
    pre=(*L6);
    while(pre!=NULL&&k<i-1) //表未查完且未查到第i-1个结点时  重复，
    {                       //直到pre指向第i-1个结点
        pre=pre->next;
        k+=1;
    }//查找到第i-1个结点

    if(pre==NULL)
    {
        printf("插入位置不合理\n");

        return 0;
    }
    s=(LNode*) malloc(sizeof (LNode));
    s->date=e;
    s->next=pre->next;  //pre原本指向第i个结点，现在s插入在之前，所以由s指
    pre->next=s;

    printf("插入成功\n");
    return 1;

}

//单链表的删除
int DelList(LinkList *L7,int i)
{
    LNode *pre,*r;
    int k=0;
    pre=(*L7);
    while((pre->next!=NULL)&&(k<i-1))   //寻找所删除的元素的前驱结点
    {
        pre=pre->next;
        k+=1;
    }//查找到第i-1个结点
    if(pre->next==NULL)     //没有找到合适的前驱位置，所以删除位置不合法
    {
        printf("删除位置错误\n");
        return 0;
    }
    r=pre->next;//将第i个结点进行命名
    pre->next=r->next;//修改指针，删除结点r 如果需要打印出来则要进行存入 *e=r->date,将被删的元素存入，
    free(r);
    return 1;


}


//单链表的合并
LinkList  MergeLinList(LinkList LA,LinkList LB)     //此时传递时只是指针与指针之间的传递
{                                                   //我也不直到为什么二级指针在这有问题
    LNode *pa,*pb;
    LinkList LC;
    InitList(&LC);
    LNode *r;   //r始终指向表LC的末尾
    pa=(LA)->next;
    pb=(LB)->next;                          //合并两个递增的单链表，出来的单链表也是递增的
    //将表LC初始化为空表
    LC=(LA);
    LC->next=NULL;
    r=LC;
    while (pa!=NULL&&pb!=NULL)
    {
        if(pa->date<=pb->date)
        {
            r->next=pa;
            r=pa;
            pa=pa->next;
        }
        else if(pa->date>pb->date)
        {
            r->next=pb;
            r=pb;
            pb=pb->next;
        }
    }
    if(pa)
    { r->next=pa;}
    else
    {r->next=pb;}
    free(LB);  //释放空间
    return(LC);
}
//链表的打印
void printfLinkList(LinkList* L0)
{
    LNode* ptr = (*L0)->next;         //运用辅助指针，将头指针的next域（记得解引用）给辅助指针，然后在进行判断指针域情况
    while (ptr != NULL)                 //当指针域等于空时，跳出循环系统
    {
        printf("%d->",ptr->date);           //当指针域不等于空时，说明结点存在，通过辅助指针访问结点中的数据
        ptr = ptr->next;                        //第一个结点的next域指向的是下一个结点的地址，所以依次赋给ptr依次访问
    }

}
int main()
{
    LinkList L;//定义了一个头指针 而 LNode * L代表定义了一个新结点L，两者含义相同只不过提高可读性
    LinkList La=NULL;
    LinkList Lb=NULL;
    printf("\n");
    rs:
    printf("\n");

    printf("    1.  初始化单链表\n");
    printf("    2.  头插法创建单链表\n");
    printf("    3.  尾插法创建单链表\n");
    printf("    4.  按序号查找元素\n");
    printf("    5.  按内容查找元素\n");
    printf("    6.  计算单链表的长度\n");
    printf("    7.  在单链表中的某元素前插入元素\n");
    printf("    8.  删除单链表中的某一个元素\n");
    printf("    9.  合并两个单链表\n");
    printf("    0.  退出单链表\n");


    int option = 0;//选项变量初始化
    printf("请输入所要操作的选项（第一步为必须步骤！）\n");
    scanf("%d", &option);
    switch (option)
    {
        case 1:
            printf("初始化单链表成功\n");
            InitList(&L);            //此时传递的是一个指向结构体LNode的指针的地址 ，即传递的是一个指针的地址！（后面也是）
            printf ("\n");
            goto rs;
        case 2:
            printf("开始进行头插法创建单链表\n");
            CreatFromHead(&L);
            printf("输出单链表\n");
            printfLinkList(&L);
            printf ("\n");
            goto rs;
        case 3:
            printf("开始进行尾插法创建单链表\n");
            CreatFromTail(&L);
            printf("输出单链表\n");
            printfLinkList(&L);
            printf ("\n");
            goto rs;
        case 4:
            printf("请输入要查找的结点\n");
            int k;
            scanf ("%d",&k);
            LNode *p=GetDate(&L,k);
            printf("结点%d的数据是%d",k,p->date);
            printf ("\n");
            goto rs;
        case 5:
            printf("请输入要查找的元素\n");
            int p1;
            scanf ("%d",&p1);
            int result=GetDate2(&L,p1);
            printf("元素%d的结点数是第%d个",p1,result);
            printf ("\n");
            goto rs;
        case 6:
            printf ("输出单链表的长度\n");
            int length=ListLength(&L);
            printf("长度为%d",length);
            printf ("\n");
            goto rs;
        case 7:
            printf("请输入所要插入的位置和元素\n");
            int date,location;
            scanf("%d %d",&location,&date);
            InsList(&L,location,date);
            printf("打印单链表\n");
            printfLinkList(&L);
            printf ("\n");
            goto rs;
        case 8:
            printf("请输入所要删除的结点\n");
            int n;
            scanf("%d",&n);
            DelList(&L,n);
            printf("打印单链表\n");
            printfLinkList(&L);
            printf ("\n");
            goto rs;
        case 9:
            printf("初始化两个单链表La和Lb\n");
            InitList(&La);
            InitList(&Lb);                          //书55页
            printf("运用尾插法为单链表赋值\n");         //此时必须创建两个递增的单链表
            printf("为第一个La表赋值\n");
            CreatFromTail(&La);
            printf("----------------------------\n");
            printf("为第二个Lb表赋值\n");
            CreatFromTail(&Lb);
            printf("----------------------------\n");
            printf("打印La\n");
            printfLinkList(&La);
            printf ("\n");
            printf("打印Lb\n");
            printfLinkList(&Lb);
            printf ("\n");
            printf("传递两个单链表\n");
            LinkList LL;        //将两个单链表合并后的新表借助这个辅助表进行打印出来
            InitList(&LL);
            LL=MergeLinList(La,Lb);
            printf("打印合并后的单链表\n");
            printfLinkList(&LL);
            printf ("\n");
            goto rs;

        case 0:
            printf(" 退出\n");
        default:
            return 0;

    }




















    return 0;
}