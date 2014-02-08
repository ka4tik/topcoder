
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

class OneDimensionalRobotEasy
{
public:
	int finalPosition(string c, int A, int B)
	{
        int p=0;
        for(int i=0;i<c.size();i++)
        {
            if(c[i]=='R')
            {
                p++;
            }
            else
            {
                p--;
            }
            if(p>B)
                p=B;
            if(p<-A)
                p=-A;

        }
        return p;
	}
};

