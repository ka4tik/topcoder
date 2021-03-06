
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
class PalindromeMatrixDiv2
{
    public:
        int n,m;
        int ans0,ans1;
        vector<string> A;
        int visit[10][10];
        void dfs(int i,int j,int row,int col)
        {
            visit[i][j]=1;
            ans0+=(A[i][j]!='0');
            ans1+=(A[i][j]!='1');

            if(row&(1<<i))
            {
                if(!visit[i][m-1-j])
                    dfs(i,m-1-j,row,col);
            }
            if(col&(1<<j))
            {
                if(!visit[n-1-i][j])
                    dfs(n-1-i,j,row,col);
            }
        }
        int minChange(vector <string> A, int rowCount, int columnCount)
        {
            this->A=A;
            n=A.size();
            m=A[0].size();
            int ret=INT_MAX;
            for(int i=0;i<(1<<n);i++)
            {
                if(__builtin_popcount(i)!=rowCount)
                    continue;
                for(int j=0;j<(1<<m);j++)
                {
                    if(__builtin_popcount(j)!=columnCount)
                        continue;
                    int ans=0;
                    for(int k=0;k<n;k++)
                        for(int l=0;l<m;l++)
                            visit[k][l]=0;
                    for(int k=0;k<n;k++)
                    {
                        for(int l=0;l<m;l++)
                        {
                            if(!visit[k][l])
                            {
                                ans0=0;
                                ans1=0;
                                dfs(k,l,i,j);
                                ans+=min(ans0,ans1);
                            }
                        }
                    }
                    ret=min(ans,ret);

                }
            }
            return ret;
        }
};

