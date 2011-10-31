#include"stdio.h"
#include"stdlib.h"
#include<iostream>

using namespace std;

int isJeffian(int a[ ], int len)
{
  int min=100000,count=0;
  for (int i=0;i<len;i++)
  {
    bool isPrime=true;
    for (int j=2;j<a[i];j++)
    {
      if (0==a[i]%j)
        isPrime=false;
    }
    if (isPrime)
    {
      count++;
      if (a[i]<min)
        min=a[i];
    }
  }
  if (min==count && count>0)
    return 1;
  else
    return 0;
}

int main() 
{
  int a[] ={7, 4, 11, 6, 13, 11, 17, 8, 10, 13, 7} ;//1 7 is the smallest prime in the array and there are 7 primes
  cout<<isJeffian(a,sizeof(a)/sizeof(int))<<endl;

  int b[]={3,4,7,6,5};//1 3 is the smallest prime but there are 4 primes in the array
  cout<<isJeffian(b,sizeof(b)/sizeof(int))<<endl;

  int c[]={8, 4, 6, 9};//0 the array must contain at least one prime
  cout<<isJeffian(c,sizeof(c)/sizeof(int))<<endl;

  int d[]={3, 2, 2, 2};//0 3 is the smallest prime but there is only 1 prime in the array
  cout<<isJeffian(d,sizeof(d)/sizeof(int))<<endl;

  int e[]={3, 3, 3};//1 3 is the smallest prime and there are 3 primes in the array
  cout<<isJeffian(e,sizeof(e)/sizeof(int))<<endl;

  int h[]={-3, 0, 4};//0 the array must contain at least one prime.
  cout<<isJeffian(h,sizeof(h)/sizeof(int))<<endl;
  return 0;
}
