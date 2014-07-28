
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


#define db(x) cerr << #x << ": " << x << endl;
#define db2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define db3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define db4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define db5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define db6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
class FixedDiceGameDiv1
{
    public:
        int a,b,c,d;
        long double dp[2555][55];
        long double dp2[2555][55];
        bool done[2555][55];
        bool done2[2555][55];
        long double rec(int sum,int n,int s)
        {
            //db3(sum,n,s);
            if(n==0)
            {
                if(sum==0)
                    return 1;
                else
                    return 0;
            }
            if(done[sum][n])
                return dp[sum][n];
            long double ans=0;
            for(int i=1;i<=s;i++)
            {
                if(sum-i>=0)
                    ans+=rec(sum-i,n-1,s);
            }
            done[sum][n]=1;
            return dp[sum][n]=ans;
        }
        long double rec2(int sum,int n,int s)
        {
            if(n==0)
            {
                if(sum==0)
                    return 1;
                else
                    return 0;
            }
            if(done2[sum][n])
                return dp2[sum][n];
            long double ans=0;
            for(int i=1;i<=s;i++)
            {
                if(sum-i>=0)
                    ans+=rec2(sum-i,n-1,s);
            }
            done2[sum][n]=1;
            return dp2[sum][n]=ans;
        }

        long double getExpectation(int a, int b, int c, int d)
        {
            this->a=a;
            this->b=b;
            this->c=c;
            this->d=d;
            int sum1=0;int sum2=0;
            for(int i=0;i<a;i++) sum1+=b;
            for(int i=0;i<c;i++) sum2+=d;
            long double total=0;
            long double ans=0;
            long double t=0;
            for(int i=1;i<=sum2;i++)
            {
                if(i<c)
                    continue;
                for(int j=i+1;j<=sum1;j++)
                {
                    if(j<a)
                        continue;
                    //ans+=rec(j,a,b)*rec2(i,c,d)*double(j);
                    total+=rec(j,a,b)*rec2(i,c,d);
                }
            }
            for(int i=1;i<=sum2;i++)
            {
                if(i<c)
                    continue;
                for(int j=i+1;j<=sum1;j++)
                {
                    if(j<a)
                        continue;
                    t+=(rec(j,a,b)*rec2(i,c,d)*double(j))/total;
                }
            }
            if(total==0)
                return -1;
            //db2(ans,total);
            long double ret=ans/total;
            //db(ret);
            return t;
        }
};

