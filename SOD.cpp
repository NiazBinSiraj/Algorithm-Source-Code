#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define Fout freopen("soutput.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
int prime[100000];
bool mark[1000010];
int nprime=0;

template <class X>  X ipow(X base, X exp)
{
    X result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

void sieve(int n)
{
    int i,j,limit = sqrt(n)+2;

    mark[1] = 1;

    for(i=4;i<=n;i+=2) mark[i]=1;
    prime[++nprime]=2;
    for(i=3;i<=n;i++)
    {
        if(!mark[i])
        {
            prime[++nprime]=i;

            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}
int SOD(int n)
{
    if(n==1) return 1;
    int s = sqrt(n)+2,res=1,cnt=0;
    int i = 1;
    while(prime[i]<=s)
    {
        if(n%prime[i]==0)
        {
            n=n/prime[i];
            cnt++;
            if(n==1) {res=res*((ipow(prime[i],cnt+1)-1)/(prime[i]-1));break;}
        }
        else
        {
            res=res*((ipow(prime[i],cnt+1)-1)/(prime[i]-1));
            i++;
            cnt=0;
        }
    }
    if(n != 1) res=res*((ipow(n,2)-1)/(n-1));

    return res;
}



int main()
{
    sieve(1000000);

    return 0;
}
