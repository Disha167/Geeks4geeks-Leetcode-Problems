class Solution {
public:
    /*The aim of this question is to maximize your profit by choosing a single day to buy one stock & choosing a different day to sell that stock.*/
    int maxProfit(vector<int>& prices) {
      /*In brute force, what we have to do is we have to make 1 transaction at max so we try for every index & then subtract it from maximum at right. Traverse from right, and keep on updating the right_max as well as the profit*/  
        int max_right=INT_MIN,profit=0;
        for(int i=prices.size()-1;i>=0;i--)
        {
            if(prices[i]>max_right)
                max_right=prices[i];
            else if((max_right-prices[i])>profit)
                profit=max_right-prices[i];
        }
        return profit;
    }
};
