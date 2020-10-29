// Created by ash_98

/*
   In mathematics, Zeckendorf's theorem, named after Belgian mathematician 
   Edouard Zeckendorf, is a theorem about the representation of integers 
   as sums of Fibonacci numbers.

Zeckendorf's theorem states that every positive integer can be 
represented uniquely as the sum of one or more distinct Fibonacci
 numbers in such a way that the sum does not include any two
 consecutive Fibonacci numbers. More precisely, if N is any positive integer, 
there exist positive integers ci ≥ 2, with ci + 1 > ci + 1, such that

*/
      
#include<bits/stdc++.h>
using namespace std;

#define mx 50
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int n,m,k,ii;
int Fibo[mx];

void pre()
{
  Fibo[0]=1;
  Fibo[1]=1;
  /* 44th Fibonacchi number is first number that greater than 1e9*/
  for(int i=1;i<=44;i++)
  {
    Fibo[i]=Fibo[i-1]+Fibo[i-2];

  }
}

void solve()
{
   
    scanf("%d",&n);
    int sesh=44;
    bitset<mx>bt;
    int st=0;
   // cout<<n<<endl;
    while(n>0)
    {
       int be=1,en=sesh;
      int shuru=en;
      while(be<=en)
      {
        int mid=(be+en)/2;
        if(Fibo[mid]>n)
        {
           en=mid-1;
        }
        else
        {
           be=mid+1;
           shuru=mid;
         }
      }
     // cout<<shuru<<endl;
      n-=Fibo[shuru];
      bt[shuru]=true;
      sesh=shuru-2;
      if(!st)st=shuru;
     // cout<<n<<endl;

    }
    printf("Case %d: ",++ii);
    for(int i=st;i>=1;i--)printf("%d",(int)bt[i]);
    printf("\n");
    

}

int main()
{
  int t=1;
  pre();
  scanf("%d",&t);
  while(t--)
  {
    solve();
  }

  return 0;
}
