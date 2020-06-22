#include <bits/stdc++.h>
// #include "stdafx.h"
// #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL)
#define cases ll t; cin>>t; while(t--)
#define nl "\n"
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//Take input
inline int getn(){
	int n=0, c=gc();
	while(c < '0' || c > '9') c = gc();
	while(c >= '0' && c <= '9')
		n = (n<<3) + (n<<1) + c - '0', c = gc();
	return n;
}
//unordered_map<int, int> cnt[rtn+1];

//=======================================================================================
void solveTwoPointer() {
faster;
    ll int n,i=0,it,j=-1, k=1, flag=0; cin >> n;
    ll int targetsum; cin >> targetsum;
    vi sum;
        fo(i,n) {
            int ip; cin>> ip;
            sum.pb(ip);
        }
    sortall(sum);
    /* tr(it,sum){
        cout << *it << nl;
    }*/
    ll f=sum.front(),s=sum.back();
    i=0;
    fo(i,n) {
        if(f+s == targetsum) {
            flag=1;
            break;
        }
        else if(f+s > targetsum) {
            s= sum.end() [j--];
        }
        else if(f+s < targetsum) {
            f = sum.begin() [k++];
        }
    }
    if(flag) cout << "Target Sum found, Elements are " << f << " and " << s << nl; 
    else cout << "No Match found" << nl;
}

void solveUsingMap() {
    
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    

    // Solve using two pointer
    // solveTwoPointer();
    



	return 0;
} 
