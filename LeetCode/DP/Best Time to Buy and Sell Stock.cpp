/*
122. Best Time to Buy and Sell Stock 2 in Array section

Basically,
One variable to store max profit;
One points at where to buy and one for where to sell
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int maxprofit = 0;
        int sell = 1, buy = 0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[sell]-prices[buy]>maxprofit){
                maxprofit = prices[sell]-prices[buy];
            }
            if(prices[i+1]<prices[buy]) buy = i+1;
            sell++;
        }
        return maxprofit;
    }
};
