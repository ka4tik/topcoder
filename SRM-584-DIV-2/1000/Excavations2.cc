
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

#define ll long long
class Excavations2
{
public:
    ll C[55][55];
    bool done[55][55];
    ll dp[55][55];
    vector<int> c;
    ll rec(int index,int rem)
    {
        if(index==c.size()&&rem==0)
            return 1;
        if(index==c.size()) return 0;
        if(done[index][rem]) return dp[index][rem];

        ll ans=0;
        for(int i=1;i<=c[index]&&i<=rem;i++)
        {
            ans+=C[c[index]][i]*rec(index+1,rem-i);
        }
        done[index][rem]=1;
        return dp[index][rem]=ans;
    }
	long long count(vector <int> kind, vector <int> found, int K)
	{
        for(int i=0;i<55;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(i==0||j==0)
                    C[i][j]=1;
                else
                    C[i][j]=C[i-1][j]+C[i-1][j-1];
            }
        }
        set<int> f;
        map<int,int> cnt;
        for(int i=0;i<found.size();i++)
            f.insert(found[i]);

        for(int i=0;i<kind.size();i++)
            if(f.count(kind[i]))
                cnt[kind[i]]++;

        c.clear();
        for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++)
            c.push_back(it->second);
            
        for(int i=0;i<55;i++)
            for(int j=0;j<55;j++)
                done[i][j]=0;
        return rec(0,K);
	}
};

