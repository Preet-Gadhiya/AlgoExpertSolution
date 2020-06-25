//Learning C++ STL

#include <bits/stdc++.h>
#include <vector>
#include <set>
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

bool f(int x, int y) {
        return x > y; //(if x < y, sorts assending)
}

void vectorDemo() {
    vi a = {1,2,3,4};
    cout << a[1] << nl;
    sort(a.begin(),a.end()); //nlogn

    //Binary search on Vector

    bool present = binary_search(all(a),3);    //logn search
    a.pb(5);
    a.pb(5);
    a.pb(5);
    a.pb(5);
    a.pb(6);
    //1,2,3,4,5,5,5,5,6

    //First occurence of 5
    auto it = lower_bound(all(a),5); //>= -> first 5
    vi::iterator it2 = upper_bound(all(a),5); //> -> greater than 5 (6 in our vector)
    
    cout << *it << " " << *it2 << nl << it2-it << nl; //*it returns value, it returns index

    //it2 -it gives count of a number (upperbound(x) - lowerbound(x))

    //sort in rev order

    sort(all(a),f);
    vi::iterator it3;
    /* tr(it3,a) {
        cout << *it3 << " ";
    } */

    for(int &x : a) {
        x++;
       
    }
    for(int x : a) {
     cout << x << " ";
       
    }
    
}

void setDemo() {
    set <int> s;
    s.insert(1);
    s.insert(2);
    s.insert(-1);

    for(int x : s) {
        cout << x << " ";
    }
    cout << nl;

    auto it = s.find(-1);
    if(it==s.end())
        cout << "Not present";
    else {
        cout << *it << nl;
    }

    auto it2 = s.lower_bound(-1);
    auto it3 = s.upper_bound(0);
    auto it4 = s.upper_bound(2);
    /* if(it4==s.end())
        cout <<"No result found for it4" << " it2 = "<< *it2 << " it3 = " << *it3 << nl;
    else
        cout << *it2 << *it3 << *it4 << nl; */
    s.erase(-1); //logn time
     
    for(int x : s) {
        cout << x << " ";
    }
    cout << nl;

    

}

void mapDemo() {
    map<int,int> m;
    m[1] = 100;
    m[2] = 200;
    m[3] = 300;
    m[1000000] = 1;
    map<char,int> cnt;
    string x = "Preet gadhiya";



    for(char c : x) {
        cnt[c]++; 
    }

    //find or del key x.find() and x.erase() 
    cout << cnt['e'] << " " << cnt['a'] << " " << nl;
}

void powerOfSTL() {
    set < pair<int,int> > s;
    s.insert({2,3});
    s.insert({10,20});
    s.insert({30,400});
    s.insert({401,450});

    int point = 1100;
    auto it = s.upper_bound({ point, INT_MAX });
    if(it==s.begin()) {
        cout << "No Match found 1" << nl;
        return;
    }
    it--;
    pair<int,int> current = *it;
    if( current.first <= point  && point <= current.second)
        cout << " Yes it is present" << nl;
    else
    {
        cout<< "No Match Found" << nl;
    }
    

}
void orderedAndUnorderedMap() {
    map<char,int> m;
    unordered_map<char, int> u;
    string s = "Preet Gadhiya Arunbhai";
    for(char a : s) m[a]++; //nlogn
    for(char b : s) u[b]++; //o(n)

    //some comparision ordered vs unordered
    //add(key,value) - log(n) vs o(1)
    //erase(key) - log(n) vs o(1)

    //ordered map > bst(each nodes stores key value pair) o(logn) > set(each node store value) is subbset of map
    //unordered map > hashing o(1) + array

}

void codeforcesProblem() {
     //Given an array, split into two parts such that sum of first part = sum of second part, we can move any one element 

    ll int n; cin >> n;
    vi A(n+5, 0);
    ll int sum=0;
    for(int i=0; i<n; i++) cin >> A[i], sum+=A[i];
    if(sum & 1) {
        cout <<"NO"<<nl;
        return ;
    }
    unordered_map<ll, int> first,second;
    first[A[0]]=1;
    for(int i=1; i<n; i++) second[A[i]]++;
    ll sdash=0;
    for(int i=0; i<n; i++) {
        sdash+=A[i];
        if(sdash == sum/2) {
            cout << "YES" << nl;
            return ;
        }
        if(sdash < sum/2) {
            ll x = sum / 2 - sdash;
            //delete from second half and insert to first
            if(second[x] > 0) {
                cout << "YES"<<nl;
                return ;
            }
        }
        else {
            ll y = sdash - sum / 2;
            if(first[y] > 0) {
                cout << "YES"<<nl;
                return ;
            }
        }
        first[A[i+1]]++;
        second[A[i+1]]--;
    }
    cout << "NO" << nl;

	return ;
}

int main()
{
    
    //vectorDemo();
    //setDemo();
    //mapDemo();
    //powerOfSTL();
    //orderedAndUnorderedMap();

    //codeforcesProblem();

   

    
} 
