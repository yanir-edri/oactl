/**
 * Author: Yoav Linhart
 * License: ???
 * Description: given arr, an array of values in the range $[0, 2^n - 1]$, create another array contain such that:
 * contain[mask] = number of masks k in arr such that (mask AND k)==k.
 * (i.e, number of masks contained in mask).
 * We can use 2 1D dp arrays to reduce memory to $O(2^n)$.
 * Time: $O(2^n*n)$.
 * Status: Yes
 */
#pragma once
vi sos_dp(vi& arr, int max_bit) {
    int sz = (1LL << max_bit);
    vvi dp(max_bit+1, vi(sz, 0));
    for(auto v : arr) dp[0][v]++;
    rep(bit, 0, max_bit) {
        rep(i, 0, sz) {
            dp[bit+1][i] = dp[bit][i];
            if(i&(1LL<<bit)) dp[bit+1][i] += dp[bit][i^(1LL<<bit)];
        }
    }
    return dp[max_bit];
}
