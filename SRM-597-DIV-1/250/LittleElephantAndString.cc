
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

class LittleElephantAndString
{
    public:
        bool is_subsequence(string A,string B)//check if A is a subsequence of B
        {
            int n=A.size();
            int m=B.size();
            int i=0,j=0;
            while(i<n&&j<m)
            {
                if(A[i]==B[j])
                {
                    i++;
                    j++;
                }
                else
                    j++;

            }
            if(i==n) return 1;
            else return 0;
        }
        int getNumber(string A, string B)
        {
            if(multiset<char>(A.begin(),A.end())!=multiset<char>(B.begin(),B.end()))
                return -1;

            int N=A.size();
            for(int i=0;i<N;i++)
            {
                if(is_subsequence(B.substr(i,B.size()),A))
                    return i;
            }
        }
};

