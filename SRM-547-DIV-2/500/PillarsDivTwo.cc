
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

class PillarsDivTwo
{
    public:
        vector<int> height;
        int w;
        bool done[111][111];
        double dp[111][111];
        double rec(int i,int j)
        {
            if(i==height.size()) return 0;
            double ret=0;
            if(done[i][j])
                return dp[i][j];
            for(int k=1;k<=height[i];k++)
            {
                ret=max(ret,sqrt(((j-k)*(j-k))+w*w)+rec(i+1,k));
            }
            done[i][j]=1;
            return dp[i][j]=ret;
        }
        double maximalLength(vector <int> height, int w)
        {
            this->height=height;
            this->w=w;
            double ans=0;
            for(int i=0;i<111;i++)
                for(int j=0;j<111;j++)
                    done[i][j]=0;

            for(int i=1;i<=height[0];i++)
                ans=max(ans,rec(1,i));
            return ans;
        }
};

