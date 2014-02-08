
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

class MysticAndCandiesEasy
{
public:
	int minBoxes(int C, int X, vector <int> high)
	{
        sort(high.begin(),high.end());
        reverse(high.begin(),high.end());
        int x=0,res=0;
        int lent=high.size();
        //reverse(high.begin(),high.end());
        for(int i=0;i<high.size();i++)
        {
            //if(C-high[i]>=X)
            //{
                //x++;
                //C=C-high[i];
            //}
            //else
            //{
                //res=lent-x;
                //break;
            //}
            int sum=0;
            for(int j=i+1;j<high.size();j++)
            {
                sum+=high[j];
            }
            if(C-sum>=X)
                return i+1;
        }
        return res;
	}
};

