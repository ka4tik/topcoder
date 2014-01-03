
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

class PilingRectsDiv2
{
public:
	int getmax(vector <int> X, vector <int> Y, int limit)
	{
        int flag=0;
        for(int i=0;i<X.size();i++)
        {
            if(X[i]*Y[i]>=limit)
            {
                flag=1;
            }

        }
        if(!flag)
            return -1;
        int ans=0;
        for(int i=1;i<=200;i++)
        {
            for(int j=1;j<=200;j++)
            {
                if(i*j>=limit)
                {
                    int cnt=0;
                    for(int k=0;k<X.size();k++)
                    {
                        if((X[k]>=i&&Y[k]>=j)||
                                (Y[k]>=i&&X[k]>=j))
                            cnt++;
                    }
                    ans=max(ans,cnt);

                }
            }
        }
        return ans;
	}
};

