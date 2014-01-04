
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

class BallsSeparating
{
public:
	int minOperations(vector <int> red, vector <int> green, vector <int> blue)
	{
        int n=red.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i==j) continue;
                    if(j==k) continue;
                    if(i==k) continue;

                    int cans=0;
                    cans+=(blue[i]+green[i]);
                    cans+=(blue[j]+red[j]);
                    cans+=(red[k]+green[k]);
                    for(int l=0;l<n;l++)
                    {
                        if(l==i||l==j||l==k) continue;
                        cans+=min(blue[l]+green[l],
                                min(blue[l]+red[l],
                                red[l]+green[l]));
                    }
                    ans=min(ans,cans);
                }
            }
        }
        if(ans==INT_MAX)
            ans=-1;
        return ans;
	}
};

