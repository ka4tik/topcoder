
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include<climits>
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

class ORSolitaire
{
    public:
        int getMinimum(vector <int> num, int goal)
        {

            vector<int> numbers;
            for(int i=0;i<num.size();i++)
                if(((goal|num[i])^goal)==0)
                    numbers.push_back(num[i]);
            if(numbers.size()==0)
                return 0;
            int ans=INT_MAX;
            for(int i=32;i>=0;i--)
            {
                if(goal&(1<<i))
                {
                    int cnt=0;
                    for(int j=0;j<numbers.size();j++)
                    {
                        if(numbers[j]&(1<<i))
                        {
                            cnt++;
                        }
                    }
                    ans=min(ans,cnt);
                }
            }
            return ans;
        }
};

