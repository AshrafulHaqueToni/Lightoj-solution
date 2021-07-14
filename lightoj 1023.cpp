// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
 
void solve()
{
    vector<char>character;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)character.push_back('A'+i);
    int cnt=0;
    printf("Case %d:\n",++ii);
    do{
        if(cnt==k)return;
        for(char a:character)printf("%c",a);
        printf("\n");
        cnt++;
    }
    while(next_permutation(character.begin(),character.end()));

}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
