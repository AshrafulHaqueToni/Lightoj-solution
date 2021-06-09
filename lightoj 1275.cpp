// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
int N,C;

double func(double T)
{
    return T*(C-T*N);
}
 
void solve()
{
    
    scanf("%d%d",&N,&C);
    if(N>C)
    {
        printf("Case %d: 0\n",++ii );
        return;
    }
    if(C==0 || N==0)
    {
        printf("Case %d: 0\n",++ii );
        return;
    }
    double be=0,en=1e8;
    int magic=200;
    while(magic--)
    {
        double mid1=(be+be+en)/3.00;
        double mid2=(be+en+en)/3.00;
        if(func(mid1)>=func(mid2))
        {
            en=mid2;
        }
        else be=mid1;
    }
    int op1=ceil(be);
    int op2=floor(be);
    if(func(op1)<=func(op2))op1=op2;
    printf("Case %d: %d\n",++ii,op1 );
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
