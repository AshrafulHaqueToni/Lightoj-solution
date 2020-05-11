#include<bits/stdc++.h>
using namespace std;

#define mx 1000005

char ch1[mx],ch[mx];
int len1,len2;

vector<int> build_lps()
{
    vector<int>tem(len2);
    int idx=0;
    for(int i=1;i<len2;)
    {
        if(ch1[i]==ch1[idx])
        {
            tem[i]=idx+1;
            idx++;
            i++;
        }
        else
        {
            if(idx!=0)idx=tem[idx-1];
            else tem[i]=idx,i++;
        }
       // cout<<i<<" "<<idx<<endl;
    }
    return tem;
}

int kmp()
{
    int cnt=0;
    vector<int>lps=build_lps();
    int i=0,j=0;
    while(i<len1)
    {
        if(ch[i]==ch1[j])i++,j++;
        else
        {
            if(j!=0)j=lps[j-1];
            else i++;
        }
        if(j==len2)
        {
            j=lps[j-1];
            cnt++;///koy bar ace sei tar jonno

        }
    }
    return cnt;
}

void solve(int ii)
{
    scanf("%s%s",ch,ch1);
    len1=strlen(ch);
    len2=strlen(ch1);
    printf("Case %d: %d\n",ii,kmp());
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}

