
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

class AlienAndHamburgers
{
public:
	int getNumber(vector <int> type, vector <int> taste)
	{
        vector<int> cnt[111];
        for(int i=0;i<type.size();i++)
        {
            cnt[type[i]].push_back(taste[i]);
        }
        vector<int> t;
        for(int i=0;i<111;i++)
        {
            if(cnt[i].size())
            {
                int mx=*max_element(cnt[i].begin(),cnt[i].end());
                if(mx<0)
                {
                    t.push_back(mx);
                }
                else
                {
                    int sum=0;
                    for(int j=0;j<cnt[i].size();j++)
                    {
                        if(cnt[i][j]>0)
                            sum+=cnt[i][j];
                    }
                    t.push_back(sum);
                }
            }
        }
        sort(t.begin(),t.end());
        reverse(t.begin(),t.end());
        int sum=0;
        int total=0;
        for(int i=0;i<t.size();i++)
        {
            if((total*sum)<=((total+1)*(sum+t[i])))
            {
                total++;
                sum+=t[i];
            }
           
        }
        return (total)*sum;
	}
};
