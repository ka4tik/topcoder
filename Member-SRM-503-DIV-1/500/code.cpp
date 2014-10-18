#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long modpow(long long n,long long p)
{
    long long ret=1;
    while(p)
    {
        if(p&1){
            ret=ret*n;
            if(ret>=mod) ret%=mod;
        }

        p=p/2;
        n*=n;
        if(n>=mod)
            n%=mod;
    }
    return ret;
}
int main()
{
    //freopen("in","r",stdin);

    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    return 0;
}

