#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi                  first
#define se                  second
#define ll                  long long
#define ull                 unsigned long long
#define lld                 long double
#define pb                  push_back
#define mp                  make_pair
#define pqb                 priority_queue<int>
#define pqs                 priority_queue<int,vi,greater<int> >
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define mod                 1000000007
#define inf                 1e18
#define ps(x,y)             cout<< fixed << setprecision(y) << x
#define reset(a, b)         memset(a, b, sizeof(a))
#define w(x)                int x; cin>>x; while(x--)
#define finc(s, e, k)       for(int i=s; i<e; i+=k)
#define f(s, e)             finc(s, e, 1)
#define frange(x)           finc(0, x, 1)
#define repeat(x)           frange(x)
#define all(cont)           cont.begin(), cont.end()
#define rall(cont)          cont.end(), cont.begin()
#define mk(arr,n,type)                  type *arr=new type[n];
#define copyArray(src, des, n, type)    type des[n]; frange(n){des[i] = src[i];}
//================================
typedef pair<int, int>      pii;
typedef pair<ll, ll>        pl;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef vector<pii>         vpii;
typedef vector<pl>          vpl;
typedef vector<vi>          vvi;
typedef vector<vl>          vvl;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//=================================
mt19937                                 rng(chrono::steady_clock::now().time_since_epoch().count());
//=================================

void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.fi); cout << ","; _print(p.se); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

void stale_flippant() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #define deb(x) cout << #x <<" "; _print(x); cout << endl;
#else
    #define deb(x)
#endif
}

template<class Container>
void split(const string& str, Container& cont, char delim = ' ') {
  stringstream ss(str);
  string token;
  while (getline(ss, token, delim)) 
    cont.push_back(token);
}

ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vvi grid;

int ans = 1;

void dfs(int x, int y, int dir)
{
	grid[x][y] = 2;

	for (int i=0; i<4; i++)
	{
		dir--;
		if (dir == -1) dir = 3;

		int _x = x + dx[dir];
		int _y = y + dy[dir];

		if (_x >=0 and _x<n and _y>=0 and _y<m and grid[_x][_y] == 0)
		{
			ans++;
			dfs(_x, _y, dir);
			return;
		}
	}

	int d = (dir+2) % 4;

	int _x = x + dx[d];
	int _y = y + dy[d];

	if (_x >=0 and _x<n and _y>=0 and _y<m and grid[_x][_y] != 1)
	{
		dfs(_x, _y, dir);
		return;
	}
}

//=================================
int main() 
{
    stale_flippant();

    cin >> n >> m;
    grid = vvi(n, vi(m));

    int x, y, _x, _y, d;
    cin >> x >> y >> d;

    for (int i=0; i<n; i++)
    	for (int j=0; j<m; j++)
    		cin >> grid[i][j];

    dfs(x, y, d);

    cout << ans;
    return 0;
}





