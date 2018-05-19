#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define MOD 1000000007LL
#define ck(XX) cout<<XX<<endl
#define Set(XX,POS) XX|(1<<POS)
#define reset(XX,POS) XX&(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define valid(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

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

int main()
{
	factorial(1000000LL,MOD);
	ck(fact[1000000]);
	return 0;
}
