#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for(int ii=1; ii<=t; ii++)
    {
        int n,q,mx=-1;

        scanf("%d %d",&n,&q);

        vector<int>all,query;
        vector<pair<int,int> >v;

        map<int,int>m;

        for(int i=0; i<n; i++)
        {
            int u,vv;

            scanf("%d %d",&u,&vv);

            mx=max({mx,u,vv});

            all.push_back(u);
            all.push_back(vv);
            v.push_back({u,vv});
        }

        for(int i=0; i<q; i++)
        {
            int qq;

            scanf("%d",&qq);
            mx=max(mx,qq);

            all.push_back(qq);
            query.push_back(qq);
        }

        sort(all.begin(),all.end());

        int idx=1;

        for(int i=0; i<all.size(); i++)
        {
            if(m.find(all[i])==m.end())
                m[all[i]]=idx++;
        }

        int outer[m[mx]+5]= {0},inner[m[mx]+5]= {0};

        for(int i=0; i<v.size(); i++)
        {
            int left=m[v[i].first];
            int right=m[v[i].second];

            outer[left]++;
            outer[right+1]--;
        }

        int sum=0;

        for(int i=1; i<=m[mx]; i++)
        {
            sum+=outer[i];
            inner[i]=sum;

        }

        printf("Case %d:\n",ii);

        for(int i=0; i<query.size(); i++)
        {
            int re=inner[m[query[i]]];
            printf("%d\n",re);
        }
    }

    return 0;
}
