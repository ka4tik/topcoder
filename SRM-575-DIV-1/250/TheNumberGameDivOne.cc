
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

class TheNumberGameDivOne
{
public:
    #define ll long long
    #define db(x) cerr << #x << ": " << x << endl;
    #define db2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define db3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define db4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define db5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define db6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;  
    map<ll,int> factorize(ll n)
    {
        map<ll,int> ret;
        for(ll i=2;i*i<=n;i++)
        {
            while(n%i==0)
            {
                n/=i;ret[i]++;
            }
        }
        if(n>1)
            ret[n]++;
        return ret;
    }
    int brute(ll n)
    {
        map<ll,int> m=factorize(n);
        vector<ll> f;
        for(map<ll,int>::iterator it=m.begin();it!=m.end();it++)
        {
            while(it->second)
            {
                it->second--;
                f.push_back(it->first);
                cout<<it->first<<" "; 
            }
        }
        return 0;
        if(f.size()==1)// is prime
            return 0;
        for(int i=1;i<(1<<f.size())-1;i++)
        {
            ll t=1;
            for(int j=0;j<f.size();j++)
            {
                if(i&(1<<j))
                    t*=f[j];
            }
            if(!brute(n-t))
                return 1;
        }
        return 0;
    }
	string find(long long n)
	{
        db(brute(747));
        return "";
        vector<int> wins,loss;
        for(int i=1;i<=30;i++)
        {
            if(brute(i))
                wins.push_back(i);
            else
                loss.push_back(i);

            //db2(i,brute(i));
        }
        for(int i=0;i<wins.size();i++)
        {
            cout<<wins[i]<<endl;
        }
        for(int i=0;i<loss.size();i++)
        {
            cout<<loss[i]<<endl;
        }
		return string();
	}
};

