#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef vector<vector<ll>> mat;
const ll mod=1e9+7,inf=1e15;
const int N=1005;
ll n,r,l,e,a[N],ans;
priority_queue<ll> L;
priority_queue<ll,vector<ll>,greater<ll>> R;
void solve(){
    cin>>n>>r>>l;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    while(L.size()) L.pop();
    while(R.size()) R.pop();
    ans=0; e=r;
    if(a[1]>e){
        ans+=a[1]-e;
        a[1]=e;
    }
    for(int i=2;i<=n;i++){
        e=min(e+2*r,l);
        if(a[i]>e){
            ans+=a[i]-e;
            a[i]=e;
        }
    }
    L.emplace(a[1]); R.emplace(a[1]);
    for(int i=2;i<=n;i++){
        ll lp=L.top(),rp=R.top()+2ll*r*(i-1ll);
        if(a[i]<lp){
            ans+=lp-a[i];
            L.emplace(a[i]); L.emplace(a[i]); L.pop();
            R.emplace(lp-2ll*r*(i-1ll));
        }
        else if(a[i]>rp){
            ans+=a[i]-rp;
            R.emplace(a[i]-2ll*r*(i-1ll)); R.emplace(a[i]-2ll*r*(i-1ll)); R.pop();
            L.emplace(rp);
        }
        else{
            L.emplace(a[i]); R.emplace(a[i]-2ll*r*(i-1ll));
        }
        lp=L.top(),rp=R.top()+2ll*r*(i-1ll);
    }
    ll curR=R.top()+2ll*r*(n-1ll);
    if(curR<l-r){
        R.pop(); ll t=1;
        while(R.size()&&R.top()+2ll*r*(n-1ll)<l-r){
            ans+=t*((R.top()+2ll*r*(n-1ll))-curR);
            curR=R.top()+2ll*r*(n-1ll);
            R.pop(); t++;
        }
        ans+=t*(l-r-curR);
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<"\n";
        solve();
    }
    return 0;
}