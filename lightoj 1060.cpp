#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

ll lca[21][21];
char ch[21];
ll k,len;
int cnt[26];


ll permutation(int n)
{
    ll val=1;

    for(int i=0;i<26;i++)
    {
        val*=lca[n][cnt[i]];
        n-=cnt[i];
    }

    return val;
}

void func(int pos,int baki)
{
    if(pos>len)
    {
        printf("\n");
        return;
    }

    int i;

    for(i=0;i<26;i++)
    {
        if(cnt[i])
        {
            cnt[i]--;

            ll val=permutation(len-pos);

            if(val>=k)break;

            k-=val;

            cnt[i]++;
        }
    }

    printf("%c",'a'+i);

    func(pos+1,k);
}


int main()
{
    ///প্যাস্কেলের ত্রিভুজ
    for(int i=0; i<=20; i++)
    {
        lca[i][0]=lca[i][i]=1;

        for(int j=1; j<i; j++)
        {
            lca[i][j]=lca[i-1][j]+lca[i-1][j-1];
        }
    }

     int t;
     scanf("%d",&t);

     for(int ii=1;ii<=t;ii++)
     {
         scanf("%s%lld",ch,&k);

         len=strlen(ch);

         memset(cnt,0,sizeof cnt);

         for(int i=0;i<len;i++)cnt[ch[i]-'a']++;

         ll lenth=permutation(len);

         if(lenth<k)
         {
             printf("Case %d: Impossible\n",ii);
         }
         else
         {
             printf("Case %d: ",ii);
             func(1,k);
         }
     }

     return 0;
}
