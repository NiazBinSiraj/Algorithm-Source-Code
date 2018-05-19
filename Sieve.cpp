//Sieve Algorithm
// Range 10^7

//Algorithm 1
//Index start from 1
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define eps 0.00000001
#define pi 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define MS(XX,YY) memset(XX,YY,sizeof(XX))
#define runtime printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

LL prime[10000000];
bool mark[10000110];
LL nprime=0;

void sieve(LL n)
{
    LL i,j,limit = sqrt(n)+2;

    mark[1] = 1;

    for(i=4;i<=n;i+=2) mark[i]=1;
    prime[++nprime]=2;
    for(i=3;i<=n;i+=2)
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

int main()
{
    //LL n=10000100;
    //Fout;
    sieve(5000000);
    cout<<prime[0]<<endl;
    //for(int i=1; i<=nprime; i++) cout<<prime[i]<<endl;
    return 0;
}


//Algorithm 2
/*char ap[N];
void siv()
{
    int i,j,sq,p;
    sq=sqrt(N)+2;
    ap[1]=1;
    for(i=2;i<sq;i++){
        if(!ap[i]){
            for(j=i*i;j<N;j+=i)ap[j]=1;
        }
    }
}*/
