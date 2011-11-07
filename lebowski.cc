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
      sum=0;
      j=i+1;
      if (0==a[j]%2)
        return 0;
      while ( 0!=a[j]%2)
      {
        cout<<"sum add"<<a[j]<<endl;
        sum+=a[j++];
        cout<<"sum ="<<sum <<endl;
      }
      if ( a[i]!=sum)
      {
        cout<<i<<","<<a[i]<<","<<sum<<endl;
        isLeb=false;
      }
    }
  }
  if(isLeb)
    return 1;
  else
    return 0;
}
int main() 
{
  int c[]={2, 3, -1, 1, -1, 4, 3, 1};//1 The sum of the odd-valued elements that follow 2 is 2 and the sum of the odd-valued elements that follow 4 is 4.
  cout<<isLebowski(c,sizeof(c)/sizeof(int))<<endl;
  return 0;
}
