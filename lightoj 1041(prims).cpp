
#include<bits/stdc++.h>

using namespace std;

#define         ash ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         pb push_back


const int mod =1e9+7;
const int N =5e6+5;
typedef long long ll;

vector<pair<int,int> >v[105];
vector<int>color(105,0),parent(105,0);
unordered_map<int,int>dis;
int fi;

void span(int start)
{
    for(int i=0;i<105;i++)dis[i]=INT_MAX;

    dis[start]=0;


    set<pair<int,int> >s;
    s.insert({dis[start],start});


    while(!s.empty())
    {
        auto it=s.begin();
        int Node=it->second;
        color[Node]=1;
        s.erase(it);

        fi+=dis[Node];

        for(int i=0;i<v[Node].size();i++)
        {
            int x=v[Node][i].first;
            int cost=v[Node][i].second;
            if(cost<dis[x]&&!color[x])
            {
                auto finder=s.find({dis[x],x});
                if(finder!=s.end())s.erase(finder);

                dis[x]=cost;
                s.insert({cost,x});
                parent[x]=Node;

            }
        }
    }


}



int main()
{

    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        int mm,j;
        cin>>mm;
        fi=0;
        map<string,int>m;

        int k=1;
        while(mm--)
        {
            string s,ss;
            int w;
            cin>>s>>ss>>w;
            if(m.find(s)==m.end()){
                m[s]=k++;
            }
            if(m.find(ss)==m.end()){
                m[ss]=k++;
            }

            v[m[s]].pb({m[ss],w});
            v[m[ss]].pb({m[s],w});

        }

        span(1);
        int node=m.size();

        cout << "Case " << ii << ": ";

        for(j=1; j<=node; j++){
            if(!color[j]){
                cout << "Impossible\n";
                break;
            }
        }


        if(j == (node+1)){
            cout << fi << "\n";
        }


        for(int i=0;i<=105;i++){
            v[i].clear();
            color[i]=0;
            parent[i]=0;
        }
        dis.clear();
    }



    return 0;
}
