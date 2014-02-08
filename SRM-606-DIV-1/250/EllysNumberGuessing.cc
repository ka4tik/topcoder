
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
class EllysNumberGuessing
{
    public:
        int getNumber(vector <int> guesses, vector <int> answers)
        {
            set<int> s;
            int p1=guesses[0]+answers[0];
            int p2=guesses[0]-answers[0];
            if(p1>=1&&p1<=1000000000)
                s.insert(p1);
            if(p2>=1&&p2<=1000000000)
                s.insert(p2);
            for(int i=1;i<guesses.size();i++)
            {
                int p1=guesses[i]+answers[i];
                int p2=guesses[i]-answers[i];
                set<int> sn;
                for(set<int>::iterator it=s.begin();it!=s.end();it++)
                {
                    int flag=0;
                    if(p1>=1&&p1<=1000000000)
                    {
                        if(*it==p1)
                            flag=1;
                    }
                    if(p2>=1&&p2<=1000000000)
                    {
                        if(*it==p2)
                            flag=1;
                    }
                    if(flag)
                        sn.insert(*it);
                }
                s=sn;
                if(s.size()==0)
                    return -2;
            }
            if(s.size()==1)
                return *s.begin();
            else
                return -1;
        }
};
