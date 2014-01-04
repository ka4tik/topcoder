
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
class TheSquareRootDilemma
{
    public:
        int countPairs(int N, int M)
        {
            //need to find number of pair (i,j) such that i*j is perfect square
            ll ans=0;
            for(int i=1;i<=N;i++)
            {
                map<int,int> factors;
                int n=i;
                for(int j=2;j*j<=n;j++)
                {
                    while(n%j==0)
                    {
                        factors[j]++;
                        n/=j;
                    }
                }
                if(n>1)
                    factors[n]++;

                int c=1;
                for(map<int,int>::iterator it=factors.begin();it!=factors.end();it++)
                    if(it->second&1)
                        c*=it->first;

                for(int j=1;c*j*j<=M;j++)
                    ans++;
            }
            return ans;
        }
};

