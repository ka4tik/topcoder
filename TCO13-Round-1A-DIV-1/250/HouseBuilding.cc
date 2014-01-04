
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

class HouseBuilding
{
public:
	int getMinimum(vector <string> area)
	{
        int ans=INT_MAX;
        for(int i=0;i<area.size();i++)
            for(int j=0;j<area[i].size();j++) area[i][j]-='0';
        for(int i=1;i<10;i++)
        {
            int cans=0;
            for(int j=0;j<area.size();j++)
            {
                for(int k=0;k<area[j].size();k++)
                {
                    cans+=min(abs(area[j][k]-i),abs(area[j][k]-(i-1)));
                }
            }
            ans=min(ans,cans);
        }
        return ans;
	}
};

