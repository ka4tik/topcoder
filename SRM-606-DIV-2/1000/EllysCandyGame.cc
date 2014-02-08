
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
#include<climits>

class EllysCandyGame
{
    public:
        int n;
        vector<int> sweets;
        int rec(int d)
        {
            int res=INT_MIN;
            for(int i=0;i<sweets.size();i++)
            {
                if(sweets[i]!=0)
                {
                    if(i>0)
                        sweets[i-1]*=2;
                    if(i+1<sweets.size())
                        sweets[i+1]*=2;
                    int old=sweets[i];
                    sweets[i]=0;
                    res=max(res,-rec(-(d+old)));
                    sweets[i]=old;
                    if(i>0)
                        sweets[i-1]/=2;
                    if(i+1<sweets.size())
                        sweets[i+1]/=2;

                }
            }
            if(res==INT_MIN)
                res=d;
            return res;
        }
        string getWinner(vector <int> sweets)
        {
            this->sweets=sweets;
            n=sweets.size();
            int diff=rec(0);
            if(diff<0)
                return "Kris";
            else if(diff>0)
                return "Elly";
            else
                return "Draw";
        }
};

