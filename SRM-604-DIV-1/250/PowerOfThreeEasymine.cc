
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
class PowerOfThreeEasy
{
    public:
        string tostring(int x)
        {
            ostringstream os;
            os<<x;
            return os.str();
        }
        int power[50];
        string ableToGet(int x, int y)
        {
            power[0]=1;
            for(int i=1;i<20;i++)
                power[i]=power[i-1]*3;
            for(int i=0;i<20;i++)
            {
                for(int j=0;j<(1<<i);j++)
                {
                    int up=0;
                    int down=0;
                    for(int k=0;k<i;k++)
                    {
                        if(j&(1<<k))
                        {
                            up+=power[k];

                        }
                        else
                            down+=power[k];
                    }
                    if(up==x&&y==down)
                        return "Possible";
                }
            }
            return "Impossible";
        }
};

