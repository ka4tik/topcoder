
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

class EllysCoprimesDiv2
{
public:
	int getCount(vector <int> num)
	{
        sort(num.begin(),num.end());
        int ans=0;
        for(int i=1;i<num.size();i++)
        {
            if(__gcd(num[i],num[i-1])==1)
                continue;
            int flag=0;
            for(int j=num[i-1];j<=num[i];j++)
            {
                if(__gcd(num[i-1],j)==1&&__gcd(num[i],j)==1)
                    flag=1;
            }
            if(flag)
                ans++;
            else
                ans+=2;
        }
        return ans;
	}
};

