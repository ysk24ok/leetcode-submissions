struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut profit = 0;
        for idx in 1..prices.len() {
            if prices[idx-1] < prices[idx] {
                profit += prices[idx] - prices[idx-1];
            }
        }
        return profit;
    }
}

fn main() {
    let (prices, expected) = (vec![7, 1, 5, 3, 6, 4], 7);
    assert_eq!(Solution::max_profit(prices), expected);
    
    let (prices, expected) = (vec![1, 2, 3, 4, 5], 4);
    assert_eq!(Solution::max_profit(prices), expected);

    let (prices, expected) = (vec![7, 6, 4, 3, 1], 0);
    assert_eq!(Solution::max_profit(prices), expected);
}
