#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
#define CK cout<<"1"<<endl
int prime[1000000];
bool mark[1000100];
int nprime=0;
int pf[1000100];
vector <int> factor;

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


void prime_factorization(int n)
{
    MS(pf,0);
    factor.clear();

    int s = sqrt(n)+1;
    int i = 1;
    while(prime[i]<=s && n != 1)
    {
        if(n%prime[i]==0)
        {
            if(pf[prime[i]] == 0) factor.push_back(prime[i]);
            n=n/prime[i];
            pf[prime[i]]++;
        }
        else {i++;}
    }
    if(n != 1) {
        if(pf[n] == 0) factor.push_back(n);
        pf[n]++;
    }
    return;
}

int main()
{
    sieve(1000000);
    int n;
    cin >> n;
    prime_factorization(n);

    for(int i=0; i<factor.size();i++)
    {
        cout<<factor[i]<<" = "<<pf[factor[i]]<<endl;
    }
    return 0;
}
