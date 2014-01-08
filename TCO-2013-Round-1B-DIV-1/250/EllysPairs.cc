
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

class EllysPairs
{
public:
#include<climits>
	int getDifference(vector <int> know)
	{
        sort(know.begin(),know.end());
        vector<int> rev=know;
        reverse(rev.begin(),rev.end());
        int mx=INT_MIN,mn=INT_MAX;
        for(int i=0;i<know.size();i++)
        {
            mx=max(mx,know[i]+rev[i]);
            mn=min(mn,know[i]+rev[i]);
        }
        return mx-mn;
	}
};

