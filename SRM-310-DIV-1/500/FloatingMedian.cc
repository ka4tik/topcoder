/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n);
#define MAXN 1111111
struct debugger{template<typename T> debugger& operator,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#define db(args...) do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
class FloatingMedian {
    public:
    int tree[MAXN];
    void update(int index,int value)
    {
        assert(index!=0);
        while(index<MAXN)
        {
            tree[index]+=value;
            index+=(index&-index);
        }
    }
    int sum(int index)
    {
        int s=0;
        while(index>0)
        {
            s+=tree[index];
            index-=(index&-index);
        }
        return s;
    }
    int binary_search(int K)
    {
        int lo=1;
        int hi=MAXN-1;
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            //db(lo,mid,hi,sum(lo),sum(mid),sum(hi));
            if(sum(mid)<((K+1)/2))
                lo=mid+1;
            else
                hi=mid;
        }
        return lo-1;
    }
    long long sumOfMedians(int seed, int mul, int add, int N, int K);
};
long long FloatingMedian::sumOfMedians(int seed, int mul, int add, int N, int K)
{

    vector<long long> values(N);
    values[0]=seed;
    for(int i=1;i<N;i++){
        values[i] = (values[i-1]*mul+add)%65536;
    }
    for(int i=0;i<N;i++) values[i]++;

    long long sum=0;
    for(int i=0;i<N;i++) {
        update(values[i], 1);
        if (i >= K-1) 
        {
            sum+=binary_search(K);
            update(values[i-K+1],-1);     
        }
    }
    return sum;
}
//int main()
//{
    ////freopen("in","r",stdin);
    //FloatingMedian fm;
    //int seed,mul,add,N,K;
    //seed=3;
    //mul=1;
    //add=1;
    //N=10;
    //K=3;
    //cout<<fm.sumOfMedians(seed,mul,add,N,K);
//}
