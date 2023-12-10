class Solution {
    int find(int curr, int prev,vector<int>& stones,  vector<vector<int>>&dp ){
        if(curr==stones.size()-1)return 1;
        if(dp[curr][prev]!=-1)return dp[curr][prev];
        int k= stones[curr]-stones[prev];
        int CurrentResult= 0;
        for(int j=k-1;j<=k+1;j++){
            int nextcurr=lower_bound(stones.begin(),stones.end(),stones[curr]+j)-stones.begin();
            if(nextcurr<stones.size() && (stones[nextcurr]==stones[curr]+j && nextcurr> curr)){
                CurrentResult|=find(nextcurr, curr, stones, dp);
                }
        }
      return dp[curr][prev]=CurrentResult;  
    }
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>>dp(stones.size()+3, vector<int>(stones.size()+3,-1));
         if(stones[1] != 1) {
            return 0;
        }
        return find(1,0, stones, dp);
        
    }
};
int main() {
    Solution solution;
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    bool result = solution.canCross(stones);

  cout << "Can the frog cross? " << (result ? "Yes" : "No") << endl;

    return 0;
}
