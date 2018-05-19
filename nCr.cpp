#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define MOD 1000000007
#define pii pair<LL,LL>
#define ck(XX) cout<<XX<<endl
#define Set(XX,POS) XX|(1<<POS)
#define reset(XX,POS) XX&(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define valid(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
pii extnuc(LL a,LL b)
{
    if(b==0)return pii(1,0);
    pii d=extnuc(b,a%b);
    return pii(d.second,d.first-d.second*(a/b));
}

LL ModInverse(LL n, LL m)
{
    pii d=extnuc(n,m);
    return ((d.first%m)+m)%m;
}

LL fact[MAX+10];
//generate all factorial in range ([1,n] mod P) using loop
template <class type1> void factorial(type1 n, type1 p)
{
	fact[0] = 1;

	for(type1 i=1; i<= n; i++)
	{
		fact[i] = ((fact[i-1]%p) * (i%p))%p;
	}
	return;
}

// return nCr % P
LL nCr(LL n, LL r, LL p)
{
	return (fact[n]%p * ModInverse((fact[r] * fact[n-r])%p,p)%p)%p;
}




int main()
{
	FAST
	factorial(1000000,MOD);
	ck(nCr(6,2,MOD));
	return 0;
}
