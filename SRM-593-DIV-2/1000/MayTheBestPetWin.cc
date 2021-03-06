
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

class MayTheBestPetWin
{
    public:
        int calc(vector <int> A, vector <int> B)
        {
            vector<int> C;
            for(int i=0;i<A.size();i++)
                C.push_back(A[i]+B[i]);

            int maxw=accumulate(C.begin(),C.end(),0);

            vector<int> dp(maxw+1,0);
            vector<int> current(maxw+1);
            dp[C[0]]=1;
            dp[0]=1;
            for(int i=1;i<C.size();i++)
            {
                current.assign(maxw+1,0);
                for(int w=0;w<=maxw;w++)
                {
                    if(i-1>=0)
                        current[w]=dp[w];
                    if(w-C[i]>=0)
                        current[w]=current[w]||dp[w-C[i]];
                }
                swap(dp,current);
            }
            int ans=INT_MAX;
            int tA=accumulate(A.begin(),A.end(),0);
            int tB=accumulate(B.begin(),B.end(),0);
            for(int i=0;i<=maxw;i++)
            {
                if(dp[i])
                    ans=min(ans,max(tB-i,i-tA));
            }
            return ans;
        }
};

