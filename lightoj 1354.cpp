#include<bits/stdc++.h>
using namespace std;

char ch[100],ch1[100];

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

void solve(int ii)
{
    scanf("%s%s",ch,ch1);
    vector<int>v,vv;
    string ss="";
    for(int i=0;i<strlen(ch);i++)
    {
        if(ch[i]=='.')
        {
            v.push_back(stoi(ss));
            ss="";
        }
        else ss+=ch[i];
    }
    v.push_back(stoi(ss));
    ss="";
    for(int i=0;i<strlen(ch1);i++)
    {
        if(ch1[i]=='.')
        {
            int val=stoi(ss);
            ss="";
            int tem=binaryToDecimal(val);
            vv.push_back(tem);

        }
        else ss+=ch1[i];
    }
    int val=stoi(ss);
            ss="";
            int tem=binaryToDecimal(val);
            vv.push_back(tem);

    for(int i=0;i<4;i++)
    {
        if(v[i]!=vv[i])
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
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
