
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

class SplitIntoPairs
{
public:
	int makepairs(vector <int> A, int X)
	{
        int cntpos=0,cntneg=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>0)
                cntpos++;
            else
                cntneg++;
        }
        if(cntpos%2==0&&cntneg%2==0)
            return A.size()/2;

        long long t1=INT_MAX;
        long long t2=INT_MAX;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]<0)
            {
                t1=min(t1,(long long)-A[i]);
            }
            else
            {
                t2=min(t2,(long long)A[i]);
            }
        }
        if(((-t1)*(t2))>=X)
            return A.size()/2;
        else
            return (A.size()/2-1);

	}
};

