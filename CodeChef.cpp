#include <bits/stdc++.h>
using namespace std;
#define fo(n) for (int i = 0; i < n; i++)
#define printall(nums) for (auto i : nums){cout << i << " "; } cout << endl;
#define inputall(nums) for (auto &i : nums) cin >> i;
#define ll long long
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define revall(x) reverse(all(x))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define mod 1000000007;

void solve()
{
    //input 1
    int n;
    cin >> n;
    vl nums(n, 0);
    inputall(nums);
    sortall(nums);
    revall(nums);
    printall(nums);

    vl ans(n, 0);
    printall(ans);
    cout << endl;

    // input 2
    // ll N, A, B;
    // cin >> N >> A >> B;
    // ll ans;
    // cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
