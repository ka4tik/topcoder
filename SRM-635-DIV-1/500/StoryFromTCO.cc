
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

class StoryFromTCO
{
    public:
#define ii pair<int,int>
        bool check(vector<int> &a,vector<int> &b)
        {
            for(int i=0;i<a.size();i++)
                if(a[i]>b[i])
                    return false;
            return true;
        }
        int minimumChanges(vector <int> places, vector <int> cutoff)
        {
            if(check(places,cutoff))
                return 0;
            vector<ii> v;
            for(int i=0;i<places.size();i++)
                v.push_back(ii(places[i],cutoff[i]));


            sort(v.begin(),v.end());

            vector<int> p,c;
            int ans=0;
            for(int i=0;i<v.size();i++)
            {
                if(v[i].first>v[i].second)
                {
                    p.push_back(v[i].first);
                    c.push_back(v[i].second);
                }
            }
            sort(v.begin(),v.end());
            sort(c.begin(),c.end());
            for(int i=0;i<v.size();i++)
            {
                vector<int> pc=p;
                vector<int> cc=c;
                if(v[i].first<=v[i].second)
                {
                    pc.push_back(v[i].first);
                    cc.push_back(v[i].second);
                }
                sort(pc.begin(),pc.end());
                sort(cc.begin(),cc.end());
                int flag=1;
                for(int j=0;j<pc.size();j++)
                {
                    if(pc[j]==v[i].first&&cc[j]==v[i].second&&(j+1==pc.size()||pc[j+1]!=v[i].first))
                    {
                        flag=0;
                    }
                }
                if(flag)
                {
                    c=cc;
                    p=pc;
                }
                if(check(p,c))
                    return c.size();
            }
            return -1;
        }
};

