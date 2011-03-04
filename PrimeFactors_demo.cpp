/*
  Name: PrimeFactors
  Copyright: 
  Author: TALE PRAFULLKUMAR P. 072074
  Date: 15/03/10 14:14
  Description: This program will be used to factorize a given number.
               It will display all the distinct prime factors of the 
               given number. The concept of trees is being used.
*/

#include<iostream>
#include <cmath>
using namespace std;
// We will be needing LinkedList to store the values of 
// primes obtained and something that can be used as the
// stack to handle trees

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
    int p;
    int k1=k;
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
    int n;
    n=L->info;
    L=L->next;
    return n;
}
//End of formation of LinkedList


int LeftChild(int n)
//Here is the function LeftChild(n) which will return
//the left child of given number. 
//The LeftChild of a given number is defined as largest integer 
//which is a factor of a given number and which is less than 
//its square root. 
//The RightChild of a given number is defined as corresponding 
//factor to the LeftChild.
//Ex.  Let the given number be  59832. 
//The square root of a given number is 249.60 
//but 216 is the largest integer which divides 59832 and 
//which is less than its  square root. 
//The corresponding RightChild is 59832/216 = 277.
{
      int a;
      float n1 =n;//converting to float so as to able to use sqrt
      a = int (sqrt(n1));
      while(n%a !=0)
      {
           a=a-1;
      };
      return a;
} 


int SquareCheck(int n)
// Since the prime factors of n^2 and n are same, this
// function will convert any square to its root (if the
// root is integer).
// This is to eliminate the duplicate pushing in stock and
// hence to reduce the calculations
{
    int j=0;//flag veriable
    int a;
    while (j==0)
    {
        float n1=n;
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
    int n;
    cout<<"Enter the number   "<<endl;
    cout<<endl;
    cin>>n;
    LinkedList P;// To store the prime numbers
    LinkedList S;//Will be used as a stack
    int nl,nr;//nl LeftChild of a given number. lly nr.
    int e;//flag veriable
    int k=0;//will be used to keep tab on stack
    while (k!=1)
    {
          n = SquareCheck(n);
          cout<<endl;
          cout<<"2.THe output of squarecheck   "<<n<<endl;
          cout<<endl;
          system("pause");
          nl=LeftChild(n);
          cout<<endl;
          cout<<"3.The left chld of "<<n<<" is "<<nl<<endl;
          cout<<endl;
          system("pause");
          if (nl==1)
          {
			  P.push(n);
  			  cout<<endl;   
              cout<<"4.The Prime Array P is "<<endl;
              cout<<endl;
              P.print();
              cout<<endl;
              system ("pause");
              e=S.isempty();
              if(e==1)
              {
	                break;
              }
              n=S.pop();
              n=P.traverse_and_check(n);
              cout<<endl;
              cout<<"5.The value of n  "<<n<<endl;
              cout<<endl;
              system("pause");
              if (n==1)
          	  {
	           	 while(n==1)
	           	 {
       			    cout<<endl;
       			    cout<<"1.This is bcos n =1"<<endl;
       			    cout<<endl;
       			    system ("pause");
       			    n=S.pop();
		            n=P.traverse_and_check(n);
				 }
		 	   };
          }
          else
          {
              nr=n/nl;
              cout<<endl;
              cout<<"6.The right chld of "<<n<<" is "<<nr<<endl;
              cout<<endl;
              system("pause");
              S.push(nr);
              n = nl;
          };
          cout<<endl;
          cout<<"7.THe stack is "<<endl;
          cout<<endl;
          S.print();
          cout<<endl;
          system("pause");
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
    
    cout<<endl;
    cout<<"8.The final ans is "<<endl;
    cout<<endl;
    P.print();
    cout<<endl;
    system ("pause");
    return 0;
}
