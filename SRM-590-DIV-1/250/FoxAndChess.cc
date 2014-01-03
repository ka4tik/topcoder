
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

class FoxAndChess
{
    public:
        string ableToMove(string start, string target)
        {

            string imp="Impossible";
            string pos="Possible";
            if(start.size()!=target.size())
                return imp;
            if(multiset<char>(start.begin(),start.end())!=multiset<char>(target.begin(),target.end()))
                return imp;

            string t1="",t2="";
            for(int i=0;i<start.size();i++)
                if(start[i]!='.')
                    t1+=start[i];

            for(int i=0;i<target.size();i++)
                if(target[i]!='.')
                    t2+=target[i];

            if(t1!=t2)
                return imp;

            vector<int> Lstart,Rstart;
            vector<int> Ltarget,Rtarget;
            for(int i=0;i<start.size();i++)
            {
                if(start[i]=='L')
                    Lstart.push_back(i);
                if(start[i]=='R')
                    Rstart.push_back(i);
            }

            for(int i=0;i<target.size();i++)
            {
                if(target[i]=='L')
                    Ltarget.push_back(i);
                if(target[i]=='R')
                    Rtarget.push_back(i);
            }

            for(int i=0;i<Lstart.size();i++)
            {
                if(Ltarget[i]>Lstart[i])
                    return imp;
                for(int j=Lstart[i];j!=Ltarget[i];j--)
                {
                    if(start[j]=='R')
                        return imp;
                }
            }
            for(int i=0;i<Rstart.size();i++)
            {
                if(Rtarget[i]<Rstart[i])
                    return imp;
                for(int j=Rstart[i];j!=Rtarget[i];j++)
                {
                    if(start[j]=='L')
                        return imp;
                }
            }
            return pos;

        }
};

