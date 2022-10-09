// Problem Link-> https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Solution Link -> https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/discuss/2652638/Top-Down-Approach-(With-comments)-or-Important-Note-or-Dp

class Solution {
    
public:
    int mod = 1e9 + 7;
    // NOTE: We need to pass dp array by reference to avoid creation of new copies just a reference is needed
    int getTotalWays(vector<vector<int>>& dp, int n, int k, int currTarget){
        
        if(currTarget < 0 || n < 0) return 0; // base case as we're decresing currTarget and n
        
        if(currTarget == 0 && n == 0) return 1; // possible case when we want to achive target of 0 with 0 dice
        
        if(dp[n][currTarget] != -1) return dp[n][currTarget]; // if answer already exists. for n, currTarget
        
        int totalways = 0;
        for(int faceVal = 1; faceVal<=k; faceVal++){
            // calculate only if faceVal is <= currTarget
            if(faceVal <= currTarget)
                totalways = (totalways + getTotalWays(dp, n - 1, k, currTarget - faceVal)) % mod;
        }
        dp[n][currTarget] = totalways;
        
        return totalways;
        
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        
        return getTotalWays(dp, n, k, target); 
    }
};