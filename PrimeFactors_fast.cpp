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
#include "LinkedList.h"
#include "GetDown.h"
using namespace std;
static LinkedList PF;// To store the prime factors
static GetDown GD;


int Check_BasicPrimes(int n)
//This function is to check whether the given number
//is divisible by basic primes i.e. {2,3,5,7,11,13}
//and to reduce the no if it is divisible.
{
 	int P_basic[6]={2,3,5,7,11,13};
	for(int i=0;i<6;i++)
	{
	 	if(n%P_basic[i]==0)
        {
		 	PF.push(P_basic[i]);
        }		 		  			 	
	 	while(n%P_basic[i]==0)
		 {
		  	  n=n/P_basic[i];
          }
     } 
     return n;
}


int LeftChild(int n)
//Here is the function LeftChild(n) which will return
//the left child of given number.
//Finding the LeftChild is fasten using class GetDown.h  
{
    int a;
    float n1=n;
    a = int (sqrt(n1));
    //We can write a = 30030*q + r
    int q = a/30030;
    int r = a%30030;
    int i=-1;
    i = GD.Search(r);
    a = GD.display(i);
    while(n%a !=0)
    {
       a=GD.GoDown(a,i);
       i=i-1;
       if(i==-1)
       {
          q=q-1;
          i=3248;
       }    
    };
    return a;
} 


int SquareCheck(int n)
// Since the prime factors of n^2 and n are same,this
// function will convert any square to its root (if the
// root is interger)
{
    int j=0;
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
    cin>>n;
    LinkedList S;//Will be used as a stack
    int nl,nr;//nl=leftchild ,nr=rightchild
    int e;//flag veriable
    int k=0;
    n = Check_BasicPrimes(n);
    if(n==1)
    {
		cout<<"Prime factors are "<<endl;
		PF.print();
		system("pause");
		return 0;
    }
    
    while (k!=1)
    {
          if (n==1)
          {
	           while(n==1)
	           {
		            n=S.pop();
		            n=PF.traverse_and_check(n);
				}
          };
          n = SquareCheck(n);
          nl=LeftChild(n);
          if (nl==1)
          {
              PF.push(n);
              e=S.isempty();
              if(e==1)
              {
	                break;
              }
              n=S.pop();
              n=PF.traverse_and_check(n);
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
                   PF.push(n);
               }
          }
    }
    
    //This is to remove 1 if present
    k=PF.pop();
    if(k!=1)
    {
        PF.push(k);
    };
    cout<<"The prime factors are "<<endl;
    PF.print();
    system ("pause");
    return 0;
}
