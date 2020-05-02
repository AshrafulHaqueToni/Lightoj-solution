#include<bits/stdc++.h>
using namespace std;

#define mx 1000005
char str[mx],subst[mx];
int b[mx];

void preprocess()
{
    int m=strlen(subst);
    int i=0,j=-1;
    b[i]=-1;
    while(i<m)
    {
        while(j>0 && subst[i]!=subst[j])j=b[j];
        i++;
        j++;
        b[i]=j;
    }
}
int kmp()
{
    int n=strlen(str);
    int m=strlen(subst);
    int i=0,j=0,cnt=0;
    preprocess();
    while(i<n)
    {
        while(j>0 && str[i]!=subst[j])j=b[j];
        i++;
        j++;
        if(j==m)
        {
            cnt++;
            j=b[j];
        }
    }
    return cnt;
}
void solve(int ii)
{
    scanf(" %s %s",str,subst);
    printf("Case %d: %d\n",ii,kmp());
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
