#include<bits/stdc++.h>
using namespace std;

#define mx 1005

int a[mx],amount,cnt;

vector<int>v[mx];
vector<int>res;
int vis[mx];

void bfs(int pos)
{

    queue<int>q;

    q.push(pos);

    vis[pos]=1;
    amount+=a[pos];
    cnt++;


    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        for(int xxx:v[x])
        {
            if(!vis[xxx])
            {
                vis[xxx]=1;
                cnt++;
                amount+=a[xxx];
                q.push(xxx);

            }
        }

    }



}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int ii=1; ii<=t; ii++)
    {

        for(int i=0; i<mx; i++)
            v[i].clear();

        memset(vis,0,sizeof(vis));
        res.clear();


        int n,q,sum=0;
        scanf("%d %d",&n,&q);


        for(int i=1; i<=n; i++)
        {

            scanf("%d",a+i);
            sum+=a[i];
        }

        while(q--)
        {
            int U,V;

            scanf("%d %d",&U,&V);
            v[U].push_back(V);
            v[V].push_back(U);
        }



        printf("Case %d: ",ii);

        if(sum%n)
        {
            printf("No\n");
            continue;
        }

        for(int i=1; i<=n; i++)
        {
            amount=0;
            cnt=0;
            int re;

            //cout<<vis[i]<<" ";

            if(!vis[i])
            {

                bfs(i);

            //cout<<amount<<" "<<cnt<<endl;

            if(amount && cnt)re=amount/cnt;

            res.push_back(re);
            }



        }

        sort(res.begin(),res.end());

        int val=res[0];
        bool flag=0;

        for(auto it:res)
        {
            if(val!=it){
                 printf("No\n");
                 flag=1;
                 break;
            }
        }



        if(flag==0)
        {
            printf("Yes\n");
        }


    }

    return 0;
}
