#include"stdio.h"
#include"stdlib.h"
#include<iostream>

using namespace std;

/*
   For example, the array {4, 3, 1, 8, 5, 1, 1, 1} is a Lebowski array because:
   a. 4 is even and 4 = 3 + 1 (3 and 1 are odd) 
   b. 8 is even and 8 = 5 + 1 + 1 + 1 (5 and 1 are odd) 
   */
int isLebowski(int a[ ], int len)
{
  int j=0,sum=0;

  bool isLeb=true;
  for (int i=0;i<len;i++)
  {
    if (0==a[i]%2)
    {
      j=i+1;
      while ( 0!=a[j]%2)
      {
        sum+=a[j++];
      }
      if ( a[i]!=sum)
        isLeb=false;
    }
  }
  if(isLeb)
    return 1;
  else
    return 0;
}
int main() 
{
  int a[] ={4} ;//0 no odd-valued elements immediately follow 4
  cout<<isLebowski(a,sizeof(a)/sizeof(int))<<endl;

  int b[]={4, 1, 3, 1, 2, 1, 1};//0 The sum of the odd-valued elements that follow 4 is 5, not 4.
  cout<<isLebowski(b,sizeof(b)/sizeof(int))<<endl;

  int c[]={2, 3, -1, 1, -1, 4, 3, 1};//1 The sum of the odd-valued elements that follow 2 is 2 and the sum of the odd-valued elements that follow 4 is 4.
  cout<<isLebowski(c,sizeof(c)/sizeof(int))<<endl;

  int d[]={4, 8, 12};//0 4 is not immediately followed by any odd-valued elements.
  cout<<isLebowski(d,sizeof(d)/sizeof(int))<<endl;

  int e[]={0, 1, -1, 8, 5, 1, 1, 1};//1 0 == 1 + -1 and 8 == 5 + 1 + 1 + 1 
  cout<<isLebowski(e,sizeof(e)/sizeof(int))<<endl;

  int f[]={-4, 5, -9, 4, 1, 1, 1, 1};//1 -4 == 5 + -9 and 4 == 1 + 1 + 1 + 1
  cout<<isLebowski(f,sizeof(f)/sizeof(int))<<endl;

  int g[]={2, 1, 1, 4, 1, 1};//0 4 != 1+1 (be sure to handle the last even number correctly)
  cout<<isLebowski(g,sizeof(g)/sizeof(int))<<endl;

  int h[]={0, 2, 1, 1};//0 No odd-valued elements immediately follow 0 in the array.
  cout<<isLebowski(h,sizeof(h)/sizeof(int))<<endl;

  int i[]={5, 3, 1};//1 If the array has no even-valued elements, then logically it must be a Lebowski array because it cannot be the case that there is an even-valued element that does not satisfy the condition.
  cout<<isLebowski(i,sizeof(i)/sizeof(int))<<endl;

  int j[]={5, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1};//1 2 == 1 + 1. Note that a Lebowski array does not have to begin with an even number.
  cout<<isLebowski(j,sizeof(j)/sizeof(int))<<endl;

  return 0;
}
