#include<bits/stdc++.h>
using namespace std;

#define mx 100005

int ar[mx];

int n,q;

void solve(int ii)
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)scanf("%d",&ar[i]);
    sort(ar,ar+n);
    printf("Case %d:\n",ii);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int pos=lower_bound(ar,ar+n,x)-ar;
        int pos1=upper_bound(ar,ar+n,y)-ar;
        cout<<pos1<<" "<<pos<<endl;
        if(ar[pos]<x)pos++;
        if(ar[pos1]>y || pos1==n)pos1--;
        printf("%d\n",max(0,pos1-pos+1));
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
