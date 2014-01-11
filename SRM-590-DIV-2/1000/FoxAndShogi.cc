
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

#define ii pair<int,int>
#define ll long long
#define mod 1000000007
class FoxAndShogi
{
    public:
        int n;
        ll dp[55][55];
        bool done[55][55];
        ll rec(vector<ii> &pawns,int index,int p)
        {
            if(index==pawns.size()) return 1;
            if(p==n) return 0;
            if(done[index][p]) return dp[index][p];

            ll ans=0;
            if(!pawns[index].second)//up pawn
            {
                for(int i=p;i<=pawns[index].first;i++)
                {
                    ans+=rec(pawns,index+1,i+1);
                if(ans>=mod) ans%=mod;
                }
            }
            else
            {
                for(int i=max(p,pawns[index].first);i<n;i++)
                {
                    ans+=rec(pawns,index+1,i+1);
                if(ans>=mod) ans%=mod;
                }

            }
            done[index][p]=1;
            return dp[index][p]=ans;
        }
        int differentOutcomes(vector <string> board)
        {
            this->n=board.size();
            ll res=1;
            for(int i=0;i<board[0].size();i++)
            {
                string col="";
                for(int j=0;j<board.size();j++)
                    col.push_back(board[j][i]);

                //cout<<col<<endl;
                vector<ii> pawns;

                for(int j=0;j<col.size();j++)
                    if(board[j][i]!='.')
                    {
                        if(board[j][i]=='U')
                        pawns.push_back(ii(j,0));
                        if(board[j][i]=='D')
                        pawns.push_back(ii(j,1));
                    }

                for(int j=0;j<55;j++)
                    for(int k=0;k<55;k++)
                        done[j][k]=0;
                res*=rec(pawns,0,0);
                if(res>=mod) res%=mod;
            }
            return int(res);
        }
};

