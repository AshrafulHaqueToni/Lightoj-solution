#include<bits/stdc++.h>
using namespace std;



void solve(int ii)
{
    string ch,ch1;
    getline(cin,ch);
    getline(cin,ch1);
    map<int,int>mp1,mp2;
    int n=ch.size();
    int m=ch1.size();
    for(int i=0;i<n;i++)
    {
        if(ch[i]>='A')ch[i]=tolower(ch[i]);
        mp1[ch[i]-'a']++;
    }
    for(int i=0;i<m;i++)
    {
        if(ch1[i]>='A')ch1[i]=tolower(ch1[i]);
        mp2[ch1[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(mp1[i]!=mp2[i])
        {
            printf("Case %d: No\n",ii);
            return;
        }
    }
    printf("Case %d: Yes\n",ii);
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
