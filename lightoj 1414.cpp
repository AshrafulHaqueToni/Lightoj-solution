#include<bits/stdc++.h>
using namespace std;

char c;
string mnth[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
map<string,int>m;
void solve(int ii)
{
    for(int i=0;i<12;i++)m[mnth[i]]=i+1;
    int d1,d2,y1,y2;
    string m1,m2;
    cin>>m1>>d1>>c>>y1;
    cin>>m2>>d2>>c>>y2;


        if(m[m2]==2 && d2<29)y2--;
        if(m[m2]<2)y2--;
        if(m[m1]>2)y1++;
        long long ans=y2/4-(y1-1)/4;
        ans-=y2/100-(y1-1)/100;
        ans+=y2/400-(y1-1)/400;

        printf("Case %d: %lld\n",ii,ans);

}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
