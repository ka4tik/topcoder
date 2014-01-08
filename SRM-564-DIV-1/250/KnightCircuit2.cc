
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

class KnightCircuit2
{
public:
	int maxSize(int w, int h)
	{
        if(h<w)
            swap(h,w);

        // w is smallest side
        if(w==3&&h==3) return 8;
        if(w>=3) return w*h;

        if(w==1) return 1;

        if(w==2)
        {
            return (h+1)/2;
        }

	}
};

