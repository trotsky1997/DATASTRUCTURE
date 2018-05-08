#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
//#define OK 1
//#define ERROR 0
//#define OVERFLOW 2
typedef int Status;
typedef struct
{
    int* elem;//
    int length;
    int listsize;
}SqList;
//data structure definition done
Status Init_Sq(SqList *L)//sequence list initiataion
{
    L->elem = (int *) malloc(LIST_INIT_SIZE*sizeof(int));
    if(! L->elem) return 0;
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return 1;
} //线性表初始化

Status ListInsert_Sq(SqList *L,int i,int e)//element insert
{
    int *new_base,*q,*p;
    if(i < 1 || i > L->length + 1) return 0;
    if(L->length >= L->listsize)
    {
        new_base =(int *)realloc(L->elem,(L->listsize + LISTINCREMENT)* sizeof(int));
        if(! L->elem && ! new_base) return 0;
        L->elem = new_base;
        L->listsize += LISTINCREMENT;
    }
    q = &L->elem[i-1];
    for(p = &L->elem[L->length - 1];p >= q; p --)
    {
        *(p + 1) = *p;
    }
    *q = e;
    ++L->length;
    return 1;

}


Status equal(int a,int b)//compare logical segment of "equal"
{
    if(a==b) return 1;
    else return 0;
}


int LocateElem_sq(SqList *L,int e,Status (*compare)(int,int))//search for the 1st element adquired for of the sequence list
{
    int i = 1;
    int *p;
    p = L->elem;
    while(i<=L->length && !(*compare)(*p++,e)) ++i;
    if(i <= L->length) return i;
    else return 0;
}

Status PrintList(SqList *L)//sequence list print
{
    if(!(L->elem)){

        return 0;

    }
    else {for(int i=0;i < L->length;i++)
        {
        printf("%d->",L->elem[i]);
        }
        return 1;
        }
}


Status deletelist(SqList *L,int i,int *e)//delete element from pointed list
{
    if(i < 1 || (i>L->length)) return 0;
    int *p,*q;
    i = i-1;
    p = &(L->elem[i]);
    *e = *p;
    q = &(L->elem[L->length - 1]);
    for(++p;p<=q;p++)
    {
        *(p-1) = *p;
    }
    --L->length;
    return 1;
}


int mergelist(SqList *La,SqList *Lb,SqList *Lc)//merge the list
{
    int *pa,*pb,*pc;
    pa = La->elem;pb = Lb->elem;
    Lc->listsize = Lc->length = La->length + Lb->length;
    pc = Lc->elem;
    if(!(Lc->elem)) return 0;
    int *pa_last,*pb_last;
    pa_last =&La->elem[(La->length)-1];
    pb_last =&Lb->elem[(Lb->length)-1];
    while(pa <= pa_last && pb <= pb_last)
        {
        if(*pa >= *pb) *pc++ = *pb++;
        else *pc++=*pa++;
        }
    while(pa <= pa_last) *pc++ = *pa++;
    while(pb <= pb_last) *pc++ = *pb++;
    return 1;
}


int destorylist(SqList *L)//free the list
{
    int *p;
    for(p = &(L->elem[L->length - 1]);p > (L->elem);p--)
    {
        free(p);L->length--;
    }
    printf("\ndone");
}


void main()
{
    int i;
    SqList L;
    printf("%d",Init_Sq(&L));
    for(i=1;i<=15;i++)
    {
        ListInsert_Sq(&L,i,i);
    }
    for(i=0;i<15;i++)
    {
        printf(" %d",L.elem[i]);
    }

    printf("\n%d",LocateElem_sq(&L,14,equal));
    printf("%d",*L.elem);
    PrintList(&L);
    deletelist(&L,13,&i);
    printf("   %d   ",i);
    PrintList(&L);

    SqList L2,L3;
    Init_Sq(&L2);Init_Sq(&L3);
    for(i=1;i<=15;i++)
    {
        ListInsert_Sq(&L2,i,i+4);
    }
    mergelist(&L,&L2,&L3);
    printf("\n");
    PrintList(&L3);
    destorylist(&L);destorylist(&L2);destorylist(&L3);
    PrintList(&L3);
}

