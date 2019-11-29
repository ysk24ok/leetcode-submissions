use std::collections::VecDeque;

// before
//  deck: 2 3 5 7 11 13 17
//  queue: 0 1 2 3 4 5 6
//  ret: - - - - - - -
// after 1st step:
//  queue: 2 3 4 5 6 1
//  ret: 2 - - - - - -
// after 2nd step:
//  queue: 4 5 6 1 3
//  ret: 2 - 3 - - - -
// after 3rd step:
//  queue: 6 1 3 5
//  ret: 2 - 3 - 5 - -
// after 4th step:
//  queue: 3 5 1
//  ret: 2 - 3 - 5 - 7
// after 5th step:
//  queue: 1 5
//  ret: 2 - 3 11 5 - 7
// after 6th step:
//  queue: 5
//  ret: 2 13 3 11 5 - 7
// after last step:
//  queue: -
//  ret: 2 13 3 11 5 17 7
struct Solution;

impl Solution {
    pub fn deck_revealed_increasing(mut deck: Vec<i32>) -> Vec<i32> {
        deck.sort();
        let size: usize = deck.len();
        let mut ret: Vec<i32> = vec![0; size];
        let mut q: VecDeque<usize> = VecDeque::with_capacity(size);
        for idx in 0..size {
            q.push_back(idx);
        }
        for i in 0..size {
            let idx: usize = q.pop_front().unwrap();
            ret[idx] = deck[i];
            let val = q.pop_front();
            match val {
                None => break,
                Some(_) => q.push_back(val.unwrap())
            };
        }
        return ret;
    }
}

fn main() {
    let deck: Vec<i32> = vec![17,13,11,2,3,5,7];
    let got: Vec<i32> = Solution::deck_revealed_increasing(deck);
    let expected: Vec<i32> = vec![2,13,3,11,5,17,7];
    assert_eq!(got, expected);
}
