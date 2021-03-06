
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class BlackBoxDiv2
{
public:
    #define ll long long
    #define mod 1000000007
    ll C[55][55];
    ll dp[55][55];
    bool done[55][55];
    int n,m;
    ll rec(int h,int w)
    {
        if(h==0&&w==0) return 1;
        if(h==0&&w!=0) return 0;

        if(done[h][w]) return dp[h][w];
        ll ans=0;
        for(int r=0;r<=(m-w);r++)
        {
            for(int s=0;s<=w;s++)
            {
                if(r+s>=1)
                {
                    ans+=(((C[m-w][r]*C[w][s])%mod)*(rec(h-1,w-s)))%mod;
                    if(ans>=mod) ans%=mod;
                }
            }
        }
        done[h][w]=1;
        return dp[h][w]=ans;
    }
	int count(string front, string side)
	{
        n=side.size();
        m=front.size();

        for(int i=0;i<55;i++)
            for(int j=0;j<=i;j++)
            {
                if(i==0||j==0)
                    C[i][j]=1;
                else
                    C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
            }

        int w=0,h=0;
        for(int i=0;i<front.size();i++)
            if(front[i]=='B')
                w++;

        for(int i=0;i<side.size();i++)
            if(side[i]=='B')
                h++;

        if(h==0&&w==0) return 1;
        if(h==0||w==0) return 0;

        for(int i=0;i<55;i++)
            for(int j=0;j<55;j++)
                done[i][j]=0;

        n=w;;
        m=h;

		return rec(w,h);
	}
};

