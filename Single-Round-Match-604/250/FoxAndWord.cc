
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

class FoxAndWord
{
public:
    bool check(string c,string b)
    {
        int n=c.size(),m=b.size();
        char ch;
        string a=c;
        for(int i=0;i<n;i++)
        {
            ch=a[n-1];
            a=a.erase(n-1,1);
            a=ch+a;
            if(a==b)
                return 1;
        }
        return 0;
        //for(int i=0;i<a.size();i++)
        //{ 
            //string t1="";
            //for(int j=0;j<i;j++)
            //{
                //t1+=a[j];
            //}
            //string t2="";
            //for(int j=i;j<a.size();j++)
            //{
                //t2+=a[j];
            //}
            //if(t1.size()>=0&&t2.size()>=0)
            //{
                //if(t2+t1==b)
                    //return 1;
            //}
        //}
        //return 0;
    }
	int howManyPairs(vector <string> words)
	{
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(check(words[i],words[j]))
                    ans++;
            }
        }
        return ans;
	}
};

