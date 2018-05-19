#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define MOD 1000000007
#define ck(XX) cout<<XX<<endl
#define set(XX,POS) XX|(1<<POS)
#define reset(XX,POS) XX&(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("soutput.txt","w",stdout)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
int mark[5000010], phi[5000010];


int phiSieve(int n)
{
    for(int i=1; i<=n; i++) phi[i]=i;
    phi[1] = 1;
    mark[1] = 1;

    for(int i=2; i<=n ;i++)
    {
        if(!mark[i])
        {
            for(int j=i; j<=n; j+=i)
            {
                mark[j]=1;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}



int main()
{
    Fout;
    phiSieve(5000000);
    for(int i=1; i<=5000000; i++); //cout<<i<<"="<<phi[i]<<endl;

    return 0;
}
