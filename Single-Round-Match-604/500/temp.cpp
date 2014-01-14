/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n);
int main()
{
    //freopen("in","r",stdin);

    int sum=0;
    for(int i=0;i<19;i++)
    {
        sum+=pow(3,i);
    }
    cout<<sum<<endl;
    return 0;
}

