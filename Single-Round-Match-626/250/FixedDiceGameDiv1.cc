
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
    double dp[51][2501];
        double getExpectation(int a, int b, int c, int d)
        {
            if(a*b<=c*1)
                return -1;
            for(int i=0;i<=a;i++)
                for(int j=0;j<=a*b;j++)
                    dp[i][j]=0;
            dp[0][0]=1.0;
            for(int i=1;i<=a;i++)
                for(int j=1;j<=a*b;j++)
                {
                    dp[i][j]=0;
                    for(int k=1;k<=b;k++)
                        if(i-k>=0)
                            dp[i][j]+=dp[i-1][j-k];
                }
            double up,down;
            int x,y;
            double bala,payeen;
            bala=0;
            payeen=0;
            for(int i=c;i<=c*d;i++)
            {
                x=max(i+1,a);
                y=a*b;
                if(x>y) continue;
                up=down=0;
                for(int j=x;j<=y;j++)
                {
                    up+=dp[a][j]*j;
                    down+=dp[a][j];
                }
                bala+=up/down;
                payeen++;
            }
            return bala/payeen;

        }

};

