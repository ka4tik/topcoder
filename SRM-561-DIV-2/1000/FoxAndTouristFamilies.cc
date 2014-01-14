
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

class FoxAndTouristFamilies
{
public:
    int visit[55];
    vector<int> g[55];
    vector<int> A,B,f;
    int n;
    int cnt;
    void dfs(int u,int index)
    {
        visit[u]=1;
        cnt++;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(!visit[v])
            {
                if(u==A[index]&&v==B[index])
                    continue;
                if(v==A[index]&&u==B[index])
                    continue;
                dfs(v,index);
            }
        }
    }
	double expectedLength(vector <int> A, vector <int> B, vector <int> f)
	{
        this->n=A.size()+1;
        this->f=f;
        this->A=A;
        this->B=B;
        double ans=0;
        for(int i=0;i<A.size();i++)
        {
            g[A[i]].push_back(B[i]);
            g[B[i]].push_back(A[i]);
        }
        
        for(int i=0;i<A.size();i++)
        {
            double p=1;
            for(int j=0;j<f.size();j++)
            {
                for(int k=0;k<55;k++)
                    visit[k]=0;
                cnt=0;
                dfs(f[j],i);
                int x=n-cnt;
                p*=double(x)/double(n-1);
            }
            ans+=p;
        }
        return ans;
	}
};

