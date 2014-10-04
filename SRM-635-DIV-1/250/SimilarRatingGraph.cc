
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

#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

#define ll long long
class SimilarRatingGraph
{
    public:
        double dist(ll x1,ll y1,ll x2,ll y2)
        {
            return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }
        double maxLength(vector <int> d, vector <int> r)
        {
            vector<ll> date,rating;
            for(int i=0;i<d.size();i++)
                date.push_back(d[i]);
            for(int i=0;i<r.size();i++)
                rating.push_back(r[i]);
            double ans=0;
            for(ll i=0;i<date.size();i++)
            {
                for(ll j=0;j<date.size();j++)
                {
                    if(i==j)continue;
                    if(j+1>=date.size())
                        continue;
                    ll x=date[i+1]-date[i];
                    ll y=date[j+1]-date[j];
                    ll flag=0;
back:
                    ll k=0;
                    double I=0;
                    while(i+k<date.size()&&j+k<date.size())
                    {
                        if(!k||(((date[i+k]-date[i+k-1])*(x)==(date[j+k]-date[j+k-1])*(y)
                                        &&((rating[i+k]-rating[i+k-1])*x==(rating[j+k]-rating[j+k-1])*y))))
                        {
                            if(k)
                                I+=dist(date[j+k-1],rating[j+k-1],date[j+k],rating[j+k]);
                            k++;
                        }
                        else
                            break;
                    }
                    ans=max(ans,I);
                    swap(x,y);
                    if(!flag)
                    {
                        flag=1;
                        goto back;
                    }
                }
            }
            return ans;
        }
};

