
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

class PiecewiseLinearFunction
{
public:
    vector<int> t;
    int check(int m)
    {
        int ret=0;
        for(int i=1;i<t.size();i++)
        {
            if((t[i-1]<=m&&t[i]>=m)||(t[i-1]>=m&&t[i]<=m))
                ret++;
        }
        for(int i=1;i<t.size()-1;i++)
        {
            if(t[i]==m)
                ret--;
        }
        return ret;
    }
	int maximumSolutions(vector <int> Y)
	{
        for(int i=1;i<Y.size();i++)
        {
            if(Y[i-1]==Y[i])
                return -1;
        }
        t=Y;
        for(int i=0;i<t.size();i++) t[i]*=2;
        int ans=0;
        for(int i=0;i<Y.size();i++)
        {
            for(int j=0;j<Y.size();j++)
            {
                ans=max(ans,check(Y[i]+Y[j]));
            }
        }
        return ans;
	}
};

