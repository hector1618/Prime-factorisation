/*
  Name: PrimeFactors
  Copyright: 
  Author: TALE PRAFULLKUMAR P. 072074
  Date: 15/03/10 14:14
  Description: THis program will be used to factorize a given number.
               It will display all the distinct prime factors of the 
               given number. The concpets of trees is being used.
*/

#include<iostream>
#include <cmath>
using namespace std;
// We will be needing LinkedList to store the values of 
// primes obtaioned and something that can be used as the
// stack to handel trees

// Formation of LinkedList
struct node
{
	int info;
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
        void add(int item);
        void print();
        int traverse_and_check(int k);
        void push(int k);
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
        
void LinkedList::add(int item)
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


int LinkedList::traverse_and_check(int k)
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


void LinkedList::push(int item)
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

int LeftChild(int n)
//Here is the function LeftChild(n) which will return
//the left child of given number.
{
      int a;
      float n1 = n;
      a = int (sqrt(n1));
      while(n%a !=0)
      {
           a=a-1;
      };
      return a;
} 


int SquareCheck(long long int n)
// Since the prime factors of n^2 and n are same,this
// function will convert any square to its root (if the
// root is interger)
{
    int j=0;
    long long int a;
    while (j==0)
    {
        float n1 = n;
        a = (int) sqrt(n1);
        if(n==a*a)
        {
             n=a;
        }
        else
        {
            j=1;
        };
    }
    return n;
}



int main()
{
    long long int n;
    cout<<"Enter the number   "<<endl;
    cin>>n;
    LinkedList P;// To store the prime numbers
    LinkedList S;//Will be used as a stack
    //S.push(n);
    long long int nl,nr;
    int e;//flag veriable
    int k=0;
    while (k!=1)
    {
          if (n==1)
          {
	           while(n==1)
	           {
		            n=S.pop();
		            n=P.traverse_and_check(n);
				}
          };
          n = SquareCheck(n);
          nl=LeftChild(n);
          if (nl==1)
          {
              P.push(n);
              e=S.isempty();
              if(e==1)
              {
	                break;
              }
              n=S.pop();
              n=P.traverse_and_check(n);
          }
          else
          {
              nr=n/nl;
              S.push(nr);
              n = nl;
          };
          k=S.isempty();//checking whether the stack 
                       //is empty or not
          //This is a check for the last element
          if (k==1)
          {
               nl = LeftChild(n);
               if(nl!=1)
               {
                   k=0;
               }
               else
               {
                   P.push(n);
               }
          }
    }
    
    cout<<"The prime factors are "<<endl;
    P.print();
    system ("pause");
    return 0;
}
