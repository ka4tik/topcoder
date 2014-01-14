
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

class LeftRightDigitsGame
{
public:
    string find(string t)
    {
        if(t.size()==0)
            return "";
        string ret="";
        ret+=t[0];
        for(int i=1;i<t.size();i++)
        {
            if(t[i]>ret[0])
                ret+=t[i];
            else
                ret=t[i]+ret;
        }
        return ret;
    }
	string minNumber(string digits)
	{
        string ans="";
        for(int i=0;i<digits.size();i++)
            ans+='9';
        for(int i=0;i<digits.size();i++)
        {
            if(digits[i]!='0')
            {
                string c="";
                c+=char(digits[i]);
                string a=digits.substr(0,i);
                string b=digits.substr(i+1,digits.size());
                c+=find(a)+b;
                ans=min(ans,c);
            }
        }
        return ans;
	}
};

