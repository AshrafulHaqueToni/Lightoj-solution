#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        int num;
        string s;
        scanf("%d",&num);
        cin>>s;
        printf("Case %d: ",ii);

        num=num%3;

        if(s=="Alice")
        {
            if(num==1){
                printf("Bob\n");
                continue;
            }

            printf("Alice\n");
            continue;

        }
        if(num==0){
            printf("Alice\n");
            continue;
        }

        printf("Bob\n");
    }


    return 0;
}
