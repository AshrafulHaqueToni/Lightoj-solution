#include<bits/stdc++.h>
using namespace std;

#define mx 1000005

char ch1[mx],ch[mx];
int len1,len2;

vector<int> build_lps()
{
    vector<int>tem(len1);
    int idx=0;
    for(int i=1;i<len1;)
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
      //  cout<<i<<" "<<j<<endl;
    }
    return j;
}

void solve(int ii)
{
    scanf("%s",ch);
    len1=len2=strlen(ch);
    reverse_copy(ch,ch+len1,ch1);
    int match=kmp();
    printf("Case %d: %d\n",ii,2*len1-match);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
