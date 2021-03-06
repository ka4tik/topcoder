
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

#include<climits>
class MarblePositioning
{
    public:
        double totalWidth(vector <int> r)
        {
            vector<double> radius;
            for(int i=0;i<r.size();i++) radius.push_back(r[i]);
            sort(radius.begin(),radius.end());
            double ans=LLONG_MAX;
            do
            {
                int n=radius.size();
                vector<double> p(n,0.0);
                for(int i=1;i<n;i++)
                {
                    double dist=0;
                    for(int j=0;j<i;j++)
                    {
                        dist=max(dist,p[j]+2*sqrt(radius[i]*radius[j]));
                    }
                    p[i]=dist;
                }
                ans=min(ans,p[n-1]-p[0]);
            }
            while(next_permutation(radius.begin(),radius.end()));
            return ans;
        }
};

