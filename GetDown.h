#include<iostream>
#include <fstream>
using namespace std;

class GetDown
{
    private:
        int P[3249];//to store primes
        int D[3249];//to store differences in consecative primes
    public:
        GetDown()
        {
            P[0]=1;
 			for(int i=1;i<3249;i++)
 			{
			 	 char *inname = "prime.txt";
				 ifstream infile(inname);
				 int j=0;
				 while (infile >> i) 
				 {
    			 	   P[j]=i;
    				   j=j+1;
                 }
                 D[0]=1;
                 for(int i=1;i<3249;i++)
                 {
                     D[i]=P[i]-P[i-1];
                 }    
            }
         };
         int GoDown(int a,int i);
         int Search(int r);
         int display(int i);
};       


int GetDown::GoDown(int a,int i)
{
    a=a-D[i];
    return a;
}    


int GetDown::Search(int k)
{
    int i=0;
 	while(P[i]<=k)
 	{
 	    i=i+1;
 	}
 	i=i-1;
  	return i;    
}   

int GetDown::display(int i)
{
    int p;
    p = P[i];
    return p;
}    
                    
