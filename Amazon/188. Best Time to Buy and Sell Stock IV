class Solution {
    private:
    vector<vector<vector<int>>>dp;
    int h(vector<int>& p, int k, int i, int t, int can_buy){
        if(i >= p.size() || t == k)
        return 0;
        if(dp[i][t][can_buy] != -1)
        return dp[i][t][can_buy];
        int profit = h(p, k, i + 1, t, can_buy);
        if(can_buy)
        profit = max(profit, -p[i] + h(p, k, i + 1, t, 0));
        else
        profit = max(profit, p[i] + h(p, k, i + 1, t + 1, 1));

        return dp[i][t][can_buy] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        dp = vector<vector<vector<int>>>(prices.size(), vector<vector<int>>(k, vector<int>(2, -1)));
        return h(prices, k, 0, 0, 1);
    }
};
