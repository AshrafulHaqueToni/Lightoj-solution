#include<bits/stdc++.h>
using namespace std;

#define mx 55

int dp[mx][mx][mx];
int vis[mx][mx][mx];
int ii,len1,len2,len3,cnt;
char ch1[mx],ch2[mx],ch3[mx];

int func(int i,int j,int k)
{
    if(i>=len1 || j>=len2 || k>=len3)return 0;

    //cout<<i<<" "<<j<<" "<<k<<endl;
//    cnt++;
//    if(i==2 && j==0 && k==1)
//    {
//        cout<<cnt<<endl;;
//    }

    int &re=dp[i][j][k];

    if(vis[i][j][k]==ii)return re;
    vis[i][j][k]=ii;

    re=0;

    if(ch1[i]==ch2[j] && ch2[j]==ch3[k])
    {
        //cout<<i<<" "<<j<<" "<<k<<endl;
        re=1+func(i+1,j+1,k+1);
    }
    else
    {
        re=max({func(i,j,k+1),func(i,j+1,k),func(i+1,j,k)});
        //re=max({func(i,j,k+1),func(i,j+1,k),func(i+1,j,k),func(i+1,j+1,k),func(i+1,j,k+1),
            //func(i,j+1,k+1)});
    }

    return re;
}

void solve(int l)
{
    ii=l;
    scanf("%s%s%s",ch1,ch2,ch3);
    len1=strlen(ch1);
    len2=strlen(ch2);
    len3=strlen(ch3);
    //cout<<len1<<" "<<len2<<" "<<len3<<endl;

    printf("Case %d: %d\n",ii,func(0,0,0));

    return;

}

int main()
{
    int t=1;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
