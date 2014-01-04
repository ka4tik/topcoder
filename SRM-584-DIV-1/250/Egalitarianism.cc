
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

class Egalitarianism
{
public:
	int maxDifference(vector <string> isFriend, int d)
	{
        int n=isFriend.size();
        vector< vector<int> > dist(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dist[i][j]=(isFriend[i][j]=='Y');
            }
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][j]==0&&dist[i][k]!=0&&dist[k][j]!=0)
                    {
                       dist[i][j]=dist[i][k]+dist[k][j]; 
                    }
                    else if(dist[i][k]!=0&&dist[k][j]!=0)
                    {
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        for(int i=1;i<n;i++)
            if(dist[i][0]==0) //means not one connected component 
                return -1;

        int t=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                t=max(t,dist[i][j]);
        }

        return t*d;
	}
};

