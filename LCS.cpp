#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define ULL unsigned LL
#define EPS 0.00000001
#define PI acos(-1.0)
#define MOD 1000000007
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define ck(XX) cout<<XX<<endl
#define Set(XX,PS) XX|(1<<PS)
#define Reset(XX,PS) XX&(~(1<<PS))
#define Toggle(XX,PS) (XX^(1<<PS))
#define Check(XX,PS) (bool)(XX&(1<<PS))
#define SORT(v) sort(v.begin(),v.end())
#define REVERSE(V) reverse(v.begin(),v.end())
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define VALID(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define SIZE(ARRAY) sizeof(ARRAY)/sizeof(ARRAY[0])
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

#define MX 1000
string A,B;
bool visited[MX][MX];
int dp[MX][MX];
vector <string> ss;

int LCS(int i, int j)
{

    if(A[i]=='\0' || B[j]=='\0') return 0;
    if(visited[i][j]) return dp[i][j];

    int ans=0;
    if(A[i] == B[j]) ans = 1+LCS(i+1,j+1);
    else ans = max(LCS(i+1,j),LCS(i,j+1));
    visited[i][j] = 1;
    dp[i][j] = ans;

    return dp[i][j];
}


string ans;
void printAll(int i,int j)
{
	if(A[i]=='\0' or B[j]=='\0'){
		ss.push_back(ans);
		cout<<ans<<endl;
		return;
	}
	if(A[i]==B[j]){
		ans+=A[i];
		printAll(i+1,j+1);
		ans.erase(ans.end()-1);
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1]) printAll(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1]) printAll(i,j+1);
		else
		{
			printAll(i+1,j);
			printAll(i,j+1);
		}
	}
}

int main()
{
    FAST;

    cin >>A>>B;
    //if(LCS(0,0)==0) {cout<<":(\n";return 0;}
    printAll(0,0);
    //sort(ss.begin(),ss.end());

    //cout<<ss[0]<<endl;
    return 0;
}
