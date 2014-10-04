
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
vector<int> c1,c2;
#define MAXN 500
#include<bits/stdc++.h>
#define ii pair<int,int>
const int INF = INT_MAX;
int nn;
int n;
vector< vector<int> > g;
map<ii,int> m;
map<int,ii> rm;
int c[MAXN][MAXN], f[MAXN][MAXN], s, t, d[MAXN], ptr[MAXN], q[MAXN];
bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt) {
        int v = q[qh++];
        for (int to=0; to<n; ++to)
            if (d[to] == -1 && f[v][to] < c[v][to]) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
    }
    return d[t] != -1;
}

int dfs2(int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (int & to=ptr[v]; to<n; ++to) {
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs2(to, min (flow, c[v][to] - f[v][to]));
        if (pushed) {
            f[v][to] += pushed;
            f[to][v] -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, n * sizeof ptr[0]);
        while (int pushed = dfs2(s, INF))
            flow += pushed;
    }
    return flow;
}
vector<int> a1,b1,a2,b2;
int m1,m2;
struct Point
{
    int x;
    int y;
    Point (int x,int y)
    {
        this->x=x;
        this->y=y;
    }
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See 10th slides from following link for derivation of the formula
    // http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}
#define ii pair<int,int>
class SegmentDrawing
{
    public:
        int get(vector<int> c2,vector <int> x, vector <int> y, vector <int> redScore, vector <int> blueScore)
        {
            g.assign(n,vector<int>());
            int k=0;
            vector<int> blues;
            vector<int> reds;
            for(int i=0;i<nn;i++)
                for(int j=i+1;j<nn;j++)
                {
                    if(c2[i]==c2[j]&&c2[i])
                    {
                        m[ii(i,j)]=k;
                        rm[k]=ii(i,j);
                        blues.push_back(k);
                        k++;
                    }
                    else if(c2[i]==c2[j]&&!c2[i])
                    {
                        m[ii(i,j)]=k;
                        rm[k]=ii(i,j);
                        reds.push_back(k);
                        k++;
                    }
                }
            m1=reds.size();
            m2=blues.size();
            s=0;
            t=m1+m2+1;
            int sum=0;
            for(int i=0;i<=t;i++)
                for(int j=0;j<=t;j++)
                {
                    c[i][j]=0;
                    f[i][j]=0;
                    d[i]=0;
                    q[i]=0;
                }
            for(int i=0;i<m1;i++)
            {
                c[s][i+1]=redScore[rm[reds[i]].first*nn+rm[reds[i]].second];
                sum+=c[s][i+1];
            }
            for(int i=0;i<m2;i++)
            {
                c[m1+i+1][t]=blueScore[rm[blues[i]].first*nn+rm[blues[i]].second];
                sum+=c[m1+i+1][t];
            }
            for(int i=0;i<reds.size();i++)
            {
                for(int j=0;j<blues.size();j++)
                {
                    if(rm[reds[i]].first!=rm[blues[j]].first)
                    {
                        Point p1=Point(x[rm[reds[i]].first],y[rm[reds[i]].first]);
                        Point p2=Point(x[rm[reds[i]].second],y[rm[reds[i]].second]);
                        Point p3=Point(x[rm[blues[j]].first],y[rm[blues[j]].first]);
                        Point p4=Point(x[rm[blues[j]].second],y[rm[blues[j]].second]);
                        if(!doIntersect(p1,p2,p3,p4))
                        {
                            c[j+m1+1][i+1]=0;
                            c[i+1][j+m1+1]=0;
                        }
                        else
                            c[i+1][j+m1+1]=INT_MAX;
                    }
                }
            }
            n=m1+m2+2;
            return sum-dinic();
        }
        int maxScore(vector <int> x, vector <int> y, vector <int> redScore, vector <int> blueScore)
        {
            nn=x.size();
            int ans=0;
            for(int i=0;i<(1<<x.size());i++)
            {
                vector<int> c(x.size(),0);
                for(int j=0;j<x.size();j++)
                {
                    if(i&(1<<j))
                        c[j]=1;
                }
                ans=max(ans,get(c,x,y,redScore,blueScore));
            }
            return ans;
        }
};

