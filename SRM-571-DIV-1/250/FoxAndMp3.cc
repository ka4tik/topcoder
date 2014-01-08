
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

class FoxAndMp3
{
    public:
        vector<string> ret;
        int n;
        string tostring(int x)
        {
            ostringstream os;
            os<<x;
            return os.str();
        }
        void rec(int x)
        {
            if(ret.size()==n||ret.size()==50)
                return;
            if(x!=0)
                ret.push_back(tostring(x)+".mp3");

            for(int i=(x==0);i<=9;i++)
            {
                if(x*10+i<=n)
                    rec(x*10+i);
            }
        }
        vector <string> playList(int n)
        {
            this->n=n;
            rec(0);
            return ret;
        }
};

