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

class TypoCoderDiv2
{
    public:	int count(vector <int> rating)
            {
                int ans=0;

                if(rating[0]>=1200)
                    ans=0;

                for(int i=1;i<rating.size();i++)
                {
                    if(rating[i-1]<1200&&rating[i]>=1200)
                        ans++;
                    if(rating[i-1]>=1200&&rating[i]<1200)
                        ans++;
                }
                return ans;
            }
};

