#include <iostream>
using namespace std;

struct node
{
    long long int info;
    node *next;
};    



class LinkedList
{
    private:
        node *L;
    public:
        LinkedList()
        {
            L = NULL;
        };
        int isempty();
        void add(long long int item);
        void print();
        int traverse_and_check(long long int k);
        void push(long long int k);
        int pop();
        
};


int LinkedList::isempty()
{
    int f=0;
    if (L==NULL)
    {
        f=1;
    }
    return f;
}
        
void LinkedList::add(long long int item)
{
    node *p;
    p=new node;
    p->info = item;
    if(L==NULL)
    {
        p->next=NULL;
        L=p; 
    }
    else
    {
        p->next=L;
        L=p;
    }    
}       

void LinkedList::print()
{
    if (isempty()==1)
    {
        return;
    } 
    node *p;
    p=L;
    while(p!=NULL)
    {
        cout<<p->info<<endl;
        p=p->next;
    };
}        


int LinkedList::traverse_and_check(long long int k)
{
    long long int p;
    long long int k1=k;
    node *temp;
    temp = L;
    while(temp !=NULL)
    {
          p=temp->info;  
          while(k1%p == 0)
          {
               k1=k1/p;
          };
          temp=temp->next;
    }
    return k1;
}


void LinkedList::push(long long int item)
{
    node *p;
    p=new node;
    if(L==NULL)
    {
        p->info=item;
        p->next=NULL;
        L=p;
    }
    else
    {
        p->info=item;
        p->next=L;
        L=p;
    }
}        


int LinkedList::pop()
{
    long long int n;
    n=L->info;
    L=L->next;
    return n;
}
//End of formation of LinkedList
