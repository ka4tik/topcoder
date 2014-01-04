
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
class TheFourSquares
{
    public:
        int check(int a,int b,int c,int d,int n,int m)
        {
            if(a+b>n)
                return 0;
            if(a+d>n&&d+a>m)
                return 0;
            if(c+b>n&&c+b>m)
                return 0;
            if(c+d>n)
                return 0;
            if(a+c>m)
                return 0;
            if(b+d>m)
                return 0;

            return 1;

        }
        int getans(int n,int m)
        {
            int mx=max(n,m);
            int ans=0;
            for(int i=1;i<=mx;i++)
                for(int j=1;j<=mx;j++)
                    for(int k=1;k<=mx;k++)
                        for(int l=1;l<=mx;l++)
                            if(check(i,j,k,l,n,m))
                                ans++;
            return ans;
        }
        int countPlacements(int n, int m)
        {
            if(n>m)
                swap(n,m);

            for(int i=1;i<n;i++)
            {
                int a=i;

                
            }
        }
};

