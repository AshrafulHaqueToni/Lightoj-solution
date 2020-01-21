#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mx 10000005


int n;
bool a[mx];
vector<int>prime;

void solve(int ii)
{
    scanf("%d",&n);

    int cnt=0;

    for(int i=0;prime[i]<=(n/2);i++)
    {
        if(a[n-prime[i]]==0)cnt++;
    }

    printf("Case %d: %d\n",ii,cnt);


   return;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1;

    scanf("%d",&t);

    a[0] = true;
	a[1] = true;

	for (int i = 2; i <mx; i++) {
		if(a[i] == false) {

			prime.push_back(i);
			for (int j = 2 * i; j < mx; j = j + i) {
				a[j] = true;
			}

		}
	}

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
