#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<int> v;
    vector<int> dp;
    int n;
    int f(int cH){
        if(dp[cH] != -1) return dp[cH];
        if(cH>=n) return 0;
        return dp[cH] = max(f(cH+1), v[cH] + f(cH+2));
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n==1) return nums[0];
        else if(n==2) return max(nums[1], nums[0]);
        dp.resize(n+1,-1);
        dp[n-1] = v[n-1];
        dp[n-2] = v[n-2];

        for(int i = n-3; i>=0; i--){
            dp[i] = max(v[i]+dp[i+2], dp[i+1]);
        }
        int ans = dp[0];
        return ans;
    }
};