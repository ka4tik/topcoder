
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
class WinterAndReindeers
{
    public:
        string a,b,c;
        vector<int> indexA,indexB;
        int dp[2555][2555][2];
        int done[2555][2555][2];
        int rec(int i,int j,int flag)
        {
            if(i==a.size()||j==b.size())
            {
                if(flag)
                    return INT_MIN;
                else
                    return 0;
            }
            if(done[i][j][flag]) return dp[i][j][flag];

            int ans=(a[i]==b[j])+rec(i+1,j+1,flag);
            ans=max(ans,rec(i+1,j,flag));
            ans=max(ans,rec(i,j+1,flag));
            if(flag)
            {
                if(indexA[i]!=-1&&indexB[j]!=-1)
                    ans=max(ans,int(c.size())+rec(indexA[i],indexB[j],0));
            }
            done[i][j][flag]=1;
            return dp[i][j][flag]=ans;
        }
        int getNumber(vector <string> allA, vector <string> allB, vector <string> allC)
        {
            a=b=c="";
            for(int i=0;i<allA.size();i++)
                a+=allA[i];
            for(int i=0;i<allB.size();i++)
                b+=allB[i];
            for(int i=0;i<allC.size();i++)
                c+=allC[i];
            indexA.assign(a.size(),-1);
            indexB.assign(b.size(),-1);
            for(int i=0;i<a.size();i++)
            {
                int k=0;
                int j;
                int flag=0;
                for(j=i;j<a.size();j++)
                {
                    if(a[j]==c[k])
                    {
                        k++;
                    }
                    if(k==c.size())
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    indexA[i]=j+1;
            }
            for(int i=0;i<b.size();i++)
            {
                int k=0;
                int j;
                int flag=0;
                for(j=i;j<b.size();j++)
                {
                    if(b[j]==c[k])
                    {
                        k++;
                    }
                    if(k==c.size())
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    indexB[i]=j+1;
            }
            for(int i=0;i<2555;i++)
                for(int j=0;j<2555;j++)
                    done[i][j][0]=done[i][j][1]=0;
            return (rec(0,0,1))<0?(0):(rec(0,0,1));
        }
};

