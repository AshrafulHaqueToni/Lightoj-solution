#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
int a[1001];
int num_divi(int n)
{
    int count=1;
    for(int i=2;i<=n;i++)
    {
        int c=0;
        while(n%i==0)
        {
            c++;
            n/=i;
        }
        if(c!=0){count=count*(c+1);}
    }
    return count;
}

int main()
{
    for(int i=1;i<=1000;i++)
    {
        a[i]=num_divi(i);
    }
    for(int i=1;i<=35;i++)
    {
        for(int j=1000;j>=1;j--)
        {
            if(a[j]==i)arr.push_back(j);
        }
    }
    int t,n,k=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<"Case "<<k<<": "<<arr[n-1]<<endl;
        k++;
    }
    return 0;

}

