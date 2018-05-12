#include<stdio.h>
#include<stdlib.h>
#define maxSize 100

/*
zi'fu'hua
*/

typedef struct
{
    int data[maxSize];
    int length;
}SqList;
//int A[maxsize];
//int n;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode;

typedef struct DNode
{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode;

void initlist(SqList *A)
{
    A->length = 0;
}

int getElem(SqList L,int p,int *e)
{
    if(p<0||p>L.length-1)
        return 0;
    *e = L.data[p];
    return 1;
}

int randomlist(SqList *L,int step)
{
    int l = L->length;
    int i;
    for(i=0;i<l;i++)
    {
        L->data[i] = (i+1)*step;
    }
    return 0;
}

void printlist(SqList L)
{
    int l =L.length;
    int i;
    for(i=0;i<l;i++)
    {
        printf("%d->",L.data[i]);
    }
    printf("O\n");
}

int findelem(SqList L,int x,int (*compare)(int a,int b))
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if((*compare)(x,L.data[i])) return i;
    }
    return i;
}

int equal(int a,int b)
{
    if(a == b) return 1;
    else return 0;
}

int less(int a,int b)
{
    if(a<b) return 1;
    else return 0;
}

int insertelem(SqList *L,int p,int e)
{
    int i;
    if(p<0||p>(L->length-1)||L->length == maxSize) return 0; 
    for(i=L->length-1;i>=p;i--)
    {
        L->data[i+1] = L->data[i];
    }
    L->data[p]=e;
    ++(L->length);
    return 1;
}

int deleteelem(SqList *L,int k,int *e)
{
    int i;*e=L->data[k];
    if(k<0||k>(L->length-1)) return 0;
    for(i=k;i<=L->length-1;i++)
    {
        L->data[i] = L->data[i+1];
    }
    --(L->length);
    return 1;
}

void createlistR(LNode &L,int a[],int n)
{
    LNode *s,*r;
    int i;
    L = (LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    r =c;
    for(i=0;i<n;i++)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
}


void main()
{
    SqList* L=(SqList*)malloc(sizeof(SqList));
    initlist(L);
    L->length = 15;
    randomlist(L,2);
    printlist(*L);
    printf("%d\n",findelem(*L,12,equal));
    insertelem(L,findelem(*L,13,less),13);
    printlist(*L);
    int e;
    deleteelem(L,findelem(*L,14,equal),&e);
    printlist(*L);
    printf("%d",e);

}