// Kruskal Algorithm
// by Linonymous


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); } } _;

#define read(x) freopen(x,"r",stdin)
#define write(x) freopen(x,"w",stdout)
#define REP(i,n) for( i=0;i<(n);i++)
#define FOR(i,a,b) for( i=(a);i<=(b);i++)
#define FORD(i,a,b) for( i=(a);i>=(b);i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ins insert

typedef pair<int,int> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
#define SZ 100005
ll a[SZ];

// Start of DSU

//Cycle find Algorithm

void initialize()
{
	for(ll i=0;i<SZ;i++)
		a[i]=i;
}

ll root(ll i)
{
	while(a[i]!=i)
	{
		i=a[i];
	}
	return i;
}

ll merge(ll x,ll y)
{
	ll root_x=root(x);
	ll root_y=root(y);
	a[root_x]=root_y;	
}

bool check(ll x,ll y)
{
	if(root(x)==root(y))
		return true;
	else 
		return false;	
}
//End Of DSU

pair<ll ,pair<ll,ll> > p[100005];
ll n;

ll kruskal(pair<ll ,pair<ll,ll> > p[])
{
	ll x,y,i,cost=0;
	for(i=0;i < n;i++)
	{
		x=p[i].second.first;
		y=p[i].second.second;
		if(root(x)!=root(y))
		{
			cost+=p[i].first;
			merge(x,y);
			cout<<"\nAdded New Edge: "<<x<<"--->"<<y<<"  Cost: "<<cost;
		}
	}	
	return cost;
}

int main()
{
	ll i,x,q,y,wt;
	cin>>n;
	initialize();
	REP(i,n)
	{
		cin>>x>>y>>wt;
		p[i]=make_pair(wt,make_pair(x,y));
	}
	sort(p,p+n);
	cout<<"\nMinimum Cost: "<<kruskal(p)<<endl;
    return 0;
}
