/*Find longest Arithmetic Progression in an integer array A of size N, and return its length.

More formally, find longest sequence of indices, 0 < i1 < i2 < … < ik < ArraySize(0-indexed) such that sequence A[i1], A[i2], …, A[ik] is an Arithmetic Progression.

Arithmetic Progression is a sequence in which all the differences between consecutive pairs are the same, i.e sequence B[0], B[1], B[2], …, B[m - 1] of length m is an Arithmetic Progression if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == … == B[m - 1] - B[m - 2]*/

int Solution::solve(const vector<int> &arr) {
    int n = arr.size(), res = 2;
    if(n <= 2)
        return n;
    vector<unordered_map<int, int>> dp(n);  //(key, value) => (position, difference)
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            int diff = arr[i] - arr[j];
            dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
            res = max(res, dp[i][diff]);
        }
    }
    return res;
}
