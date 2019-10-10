#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        int r=0,c=0,re=0;
        scanf("%d%d",&r,&c);

        if(r<=1||c<=1){
           printf("Case %d: %d\n",ii,max(r,c));
           continue;
        }

        if(r==2||c==2){
                int fi;
            if(r==2)fi=c;
            else fi=r;

            if(fi%4==1)re+=fi+1;
            else if(fi%4==2)re+=fi+2;
            else if(fi%4==3)re+=fi+1;
            else re+=fi;
        }
        else if((r*c)%2==0)re+=(r*c)/2;
        else re+=(r*c)/2+1;


        printf("Case %d: %d\n",ii,re);
    }

    return 0;
}
