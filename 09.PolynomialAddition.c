// C Language Implementation for performing Addition,Multiplication,Subtraction Using singly Linked List
// Contributed on : 05/10/2020
#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int coe;
    int man;
    struct node *next;
}NODE;
typedef struct poly
{
    NODE *st;
}POLY;
void init(POLY *t)
{
    t->st=NULL;
}
NODE *createNode(int c,int m)
{
    NODE *a=(NODE*)malloc(sizeof(NODE));
    a->coe=c;
    a->man=m;
    a->next=NULL;
    return a;
}
void display(POLY *t)
{
    NODE *a=t->st;
    if(a==NULL)
    {
        printf("\nEmpty LIST\n");
        return;
    }
    printf("LIST : \n");
    while(a!=NULL)
    {
        if(a->coe>0)
            printf(" + ");
        printf("%dx%d",a->coe,a->man);
        a=a->next;
    }
}
void createList(POLY *t)
{
    int c,m;
    NODE *a=t->st,*b;
    while(t->st!=NULL)
    {
        t->st=a->next;
        free(a);
        a=t->st;
    }
    while(1)
    {
        printf("\n COE MAN : ");
        scanf("%d%d",&c,&m);
        if(c==0 && m==0)
            break;
        if(c==0)
            continue;
        if(t->st==NULL)
        {
            t->st=a=createNode(c,m);
        }
        else
        {
            if(m>=b->man)
            {
                printf("\nInvalid");
                continue;
            }
            a=createNode(c,m);
            b->next=a;
        }
        b=a;
    }
}
void sort(POLY *t)
{
    NODE *a=t->st,*b,*c;
    int co,ma;
    while(a->next!=NULL)
    {
        b=a;
        c=a->next;
        while(c!=NULL)
        {
            if(c->man > b->man)
                b=c;
            c=c->next;
        }
        if(a!=b)
        {
            co=a->coe;
            a->coe=b->coe;
            b->coe=co;
            ma=a->man;
            a->man=b->man;
            b->man=ma;
        }
        a=a->next;
    }
}
void delAll(POLY *t)
{
    NODE *a=t->st;
    while(t->st!=NULL)
    {
        t->st=a->next;
        free(a);
        a=t->st;
    }
}
void Add(POLY *r,POLY *p,POLY *q)
{
    NODE *a=p->st,*b=q->st,*c,*d;
    int co,ma;
    delAll(r);
    while(a!=NULL && b!=NULL)
    {
        if(a->man==b->man)
        {
            co=a->coe+b->coe;
            ma=a->man;
            a=a->next;
            b=b->next;
        }
        else if(a->man > b->man)
        {
            co=a->coe;
            ma=a->man;
            a=a->next;
        }
        else
        {
            co=b->coe;
            ma=b->man;
            b=b->next;
        }
        if(r->st==NULL)
            r->st=c=createNode(co,ma);
        else
        {
            c=createNode(co,ma);
            d->next=c;
        }
        d=c;
    }
    while(a!=NULL)
    {
        c=createNode(a->coe,a->man);
        d->next=c;
        d=c;
    }
    while(b!=NULL)
    {
        c=createNode(b->coe,b->man);
        d->next=c;
        d=c;
    }
}

void Subtract(POLY *r,POLY *p,POLY *q)
{
    NODE *a=p->st,*b=q->st,*c,*d;
    int co,ma;
    delAll(r);
    while(a!=NULL && b!=NULL)
    {
        if(a->man==b->man)
        {
            co=a->coe-b->coe;
            ma=a->man;
            a=a->next;
            b=b->next;
        }
        else if(a->man > b->man)
        {
            co=a->coe;
            ma=a->man;
            a=a->next;
        }
        else
        {
            co=-b->coe;
            ma=b->man;
            b=b->next;
        }
        if(r->st==NULL)
            r->st=c=createNode(co,ma);
        else
        {
            c=createNode(co,ma);
            d->next=c;
        }
        d=c;
    }
    while(a!=NULL)
    {
        c=createNode(a->coe,a->man);
        d->next=c;
        d=c;
    }
    while(b!=NULL)
    {
        c=createNode(-b->coe,b->man);
        d->next=c;
        d=c;
    }
}

void multiply(POLY *r,POLY *p,POLY *q)
{
    NODE *a=p->st,*b=q->st,*c,*d;
    delAll(r);
    int co,ma;
    while(b!=NULL)
    {
        a=p->st;
        while(a!=NULL)
        {
            co=a->coe*b->coe;
            ma=a->man+b->man;
            if(r->st==NULL)
                r->st=c=createNode(co,ma);
            else
            {
                c=createNode(co,ma);
                d->next=c;
            }
            d=c;
            a=a->next;
        }
        b=b->next;

        sort(r);
        a=r->st;
        NODE  *b;
        while(a->next!=NULL)
        {
            int co=a->coe;
            b=a->next;
            if(a->man==b->man)
            {
                co+=b->coe;
                a->next=b->next;
                free(b);
            }
            a->coe=co;
            a=a->next;
        }
    }
}
int main()
{
    int opt;
    POLY a,b,c;
    init((&a));
    init (&b);
    init((&c));
    while(1)
    {
        printf("\n1.CreateList 1\n2.CreateList 2\n3.display 1\n4.display  2\n5.display 3\n6.add\n7.subtract\n8.multiply\nOption :\n");
        scanf("%d",&opt);
        if(opt>8)
            break;
        switch (opt) {
            case 1:
                createList(&a);break;
            case 2:
                createList(&b);break;
            case 3:
                display(&a);break;
            case 4:
                display(&b);break;
            case 5:
                display(&c);break;
            case 6:
                Add(&c,&a,&b);break;
            case 7:
                Subtract(&c,&a,&b);break;
            case 8:
                multiply(&c,&a,&b);
        }
    }
    return 0;
}
