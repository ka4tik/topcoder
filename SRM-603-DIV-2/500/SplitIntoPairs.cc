//IN THE NAME OF GOD 
#include <iostream> 
#include <vector> 
#include <stack> 
#include <string> 
#include <algorithm> 
#include <cmath> 
#include <set> 
#include <queue> 
#include <map> 
#include <fstream> 
#include <utility> 
#include <sstream> 
#include <list> 
#include <iomanip> 
#include <functional> 
#include <deque> 
#include <ctime> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
#include <complex> 
#include <climits> 
#include <cctype> 
#include <cassert> 
#include <bitset> 
#include <limits> 
#include <numeric> 

using namespace std; 

#define timestamp(x) printf("Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define INF 0x3f3f3f3f 
#define pii pair < int , int > 
#define MP make_pair 
#define MOD 1000000007 
#define EPS 1e-9 

class SplitIntoPairs 
{ 
public: 
  int makepairs(vector <int> A, int X) 
  { 
    vector < long long > pos, neg, zero; 
    for (int i = 0; i < A.size(); i++){ 
      if (A[i] > 0) pos.push_back(A[i]); 
    } 
    for (int i = 0; i < A.size(); i++){ 
      if (A[i] < 0) neg.push_back(A[i]); 
    } 
    for (int i = 0; i < A.size(); i++){ 
      if (A[i] == 0) zero.push_back(A[i]); 
    } 
    sort(pos.begin(), pos.end()); 
    sort(neg.begin(), neg.end()); 
    long long sum = 0, j = 0; 
    for (int i = 0; i < neg.size() && j < pos.size(); i++){ 
      if (pos[j] * neg[i] >= X){ 
        sum++; 
        //pos.erase(pos.begin() + j); 
        pos.erase(pos.begin()); 
        neg.erase(neg.begin() + i); 
        i--; 
        j = 0; 
      } 
    } 
    if (neg.size() > zero.size()){ 
      sum += (int)(zero.size()); 
      int t = (int)(zero.size()); 
      while (t--) neg.erase(neg.begin()); 
    } 
    else{ 
      sum += (int)(neg.size()); 
      //sum += (int)(zero.size()) / 2; 
      int t = (int)(neg.size()); 
      while (t--) zero.erase(zero.begin()); 
    } 
    sum += (int)(neg.size()) / 2; 
    sum += (int)(pos.size()) / 2; 
    sum += (int)(zero.size()) / 2; 
    return sum; 
  } 
}; 

// Powered by FileEdit 
// Powered by TZTester 1.01 [25-Feb-2003] 
// Powered by CodeProcessor
