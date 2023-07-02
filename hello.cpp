#include<bits/stdc++.h>
using namespace std;
int t, n, m;
vector<int> v(200005);
int solve(int x){ // 如果有x天，最大值為res
    int res = 0, r = -1;
    for(int i = 0; i<n && v[i]>r; i++){ // 遍歷整個array，但如果可以寫的line會被扣光就不加了
        if(i%x == 0) r++;
        res += v[i]-r;
    }
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> v[i];
        int l = 1, r = n+1, mid;
        while(l < r){ // 用二分搜去找ans
            mid = l+(r-l)/2;
            if(solve(mid) >= m) r = mid;
            else l = mid+1;
        }
        cout << (l==n+1?-1:l) << "\n";
    }
    return 0;
}