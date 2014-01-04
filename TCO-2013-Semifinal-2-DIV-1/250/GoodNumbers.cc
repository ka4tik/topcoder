
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
#define db6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;jk
class GoodNumbers
{
    public:
        ll lcm(ll a,ll b)
        {
            return (a*b)/__gcd(a,b);
        }
        int count(vector <int> a, vector <int> b, int N)
        {
            int n=a.size();
            ll ans=0;
            for(int i=1;i<(1<<n);i++)
            {
                ll m=1;
                vector<int> current;
                for(int j=0;j<n;j++)
                {
                    if(i&(1<<j))
                    {
                        m=lcm(m,a[j]);
                        current.push_back(b[j]);
                    }
                }
                //db(m);
                ll add=N/m;
                ll sub=0;
                for(int k=1;k<(1<<current.size());k++)
                {
                    ll t=m;
                    for(int j=0;j<current.size();j++)
                    {
                        if(k&(1<<j))
                        {
                            t=lcm(t,current[j]);
                        }
                    }
                    if(__builtin_popcount(k)&1)
                    {
                        sub+=N/t;
                    }
                    else
                        sub-=N/t;
                }
                //db2(add,sub);
                if(__builtin_popcount(i)&1)
                    ans+=(add-sub);
                else
                    ans-=(add-sub);
            }
            return ans;
        }
};

