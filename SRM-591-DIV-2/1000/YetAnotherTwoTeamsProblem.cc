
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

#define ll long long
#define db(x) cerr << #x << ": " << x << endl;
#define db2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define db3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define db4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define db5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define db6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
class YetAnotherTwoTeamsProblem
{
public:
	long long count(vector <int> skill)
	{
        int sum=accumulate(skill.begin(),skill.end(),0);
        ll ans=0;
        for(int i=0;i<=sum;i++)
        {
            int a=i;
            int b=sum-a;
            if(a>b)
            {
                int c=a-b;
                vector<int> t;
                for(int j=0;j<skill.size();j++)
                    if(skill[j]>=c)
                        t.push_back(skill[j]);

                //db3(a,b,c);
                if(t.size()==0)
                    continue;
                vector<int> dp(a+1,0);
                vector<int> curr=dp;
                dp[t[0]]=1;
                dp[0]=1;
                for(int j=1;j<t.size();j++)
                {
                    curr.assign(a,0);
                    for(int w=0;w<=a;w++)
                    {
                        curr[w]+=dp[w];
                        if(w-t[j]>=0)
                            curr[w]+=dp[w-t[j]];
                    }
                    swap(dp,curr);
                }
                ans+=dp[a];
                //db(ans);
            }
        }
        return ans;
	}
};

