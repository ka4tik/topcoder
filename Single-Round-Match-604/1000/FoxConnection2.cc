
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

#define db(x) cerr << #x << ": " << x << endl;
#define db2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define db3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define db4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define db5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define db6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
class FoxConnection2
{
public:
    #define mod 1000000007
    #define ll long long
    vector<int> g[55];
    int parent[55];
    int visit[55];
    ll rec(int u,int placed,int rem)
    {
        db3(u,placed,rem);
        if(rem==0)
            return 1;
        ll ans=0;
        int cnt=0;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(v==u) continue;
            if(v==parent[u]) continue;
            
            cnt++;
            if(placed)
                ans+=rec(v,placed,rem-1);
            else
            {
                ans+=rec(v,1,rem-1);
                if(ans>=mod) ans%=mod;
                ans+=rec(v,0,rem);
            }
            if(ans>=mod) ans%=mod;
        }
        if(cnt==0)
        {
            if(rem==1)
                return 1;
            else
                return 0;
        }
        return ans;
        
    }
    void dfs(int root)
    {
        visit[root]=1;
        for(int i=0;i<g[root].size();i++)
        {
            int v=g[root][i];
            if(!visit[v])
            {
                parent[v]=root;
                dfs(v);
            }
        }
    }
	int ways(vector <int> A, vector <int> B, int k)
	{
        int n=A.size()+1;
        for(int i=0;i<A.size();i++)
        {
            A[i]--;
            B[i]--;
            g[A[i]].push_back(B[i]);
            g[B[i]].push_back(A[i]);
        }
        for(int i=0;i<n;i++)
            visit[i]=0;
        dfs(0);
        for(int i=0;i<n;i++)
            db2(i,parent[i]);
        parent[0]=-1;
        return int(rec(0,0,k));
	}
};

