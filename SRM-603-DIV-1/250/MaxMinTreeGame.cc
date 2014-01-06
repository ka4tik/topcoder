
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

class MaxMinTreeGame
{
    public:
        vector< vector<int> > g;
        int n;
        int findend(vector <int> edges, vector <int> costs)
        {
           n=costs.size();
           vector<int> deg(n,0);
           for(int i=0;i<edges.size();i++)
           {
               deg[i+1]++;
               deg[edges[i]]++;
           }
           int ans=0;
           for(int i=0;i<n;i++)
               if(deg[i]==1)
                   ans=max(ans,costs[i]);
           return ans;
        }
};

