
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

class MiddleCode
{
public:
	string encode(string s)
	{
        string resp;
        int tam=s.size();
        for(int i=0;i<s.size()!=0;i++)
        {
            if(s.size()%2==0)
            {
                char temp=min(s[s.size()/2],s[(s.size()/2)-1]);
                int pos;
                if(temp==s[s.size()/2])
                    pos=s.size()/2;
                else
                    pos=(s.size()/2)-1;
                resp+=temp;
                s.erase(s.begin()+pos);
            }
            else
            {
                char temp=s[s.size()/2];
                resp+=temp;
                s.erase(s.begin()+s.size()/2);
            }
        }
        return resp;
            
	}

};

