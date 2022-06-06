use std::collections::HashSet;

struct Solution;

impl Solution {
    pub fn has_all_codes(s: String, k: i32) -> bool {
        let expected_counts = 2u32.pow(k as u32) as usize;
        let mut unique = HashSet::new();
        let mask = (1 << k) - 1;
        let mut hash_val = 0;
        let k_as_usize = k as usize;
        for (i, c) in s.chars().enumerate() {
            hash_val <<= 1;
            hash_val += c.to_digit(10).unwrap();
            hash_val &= mask;
            if i < k_as_usize - 1 {
                continue;
            }
            unique.insert(hash_val);
            if unique.len() == expected_counts {
                return true;
            }
        }
        return false;
    }
}

fn main() {
    let (s, k, expected) = (String::from("00110110"), 2, true);
    assert_eq!(Solution::has_all_codes(s, k), expected);

    let (s, k, expected) = (String::from("0110"), 1, true);
    assert_eq!(Solution::has_all_codes(s, k), expected);

    let (s, k, expected) = (String::from("0110"), 2, false);
    assert_eq!(Solution::has_all_codes(s, k), expected);

    let (s, k, expected) = (String::from("0"), 20, false);
    assert_eq!(Solution::has_all_codes(s, k), expected);

    let (s, k, expected) = (String::from("101000100011111001110010"), 3, true);
    assert_eq!(Solution::has_all_codes(s, k), expected);

    let (s, k, expected) = (String::from("00110"), 2, true);
    assert_eq!(Solution::has_all_codes(s, k), expected);

    let (s, k, expected) = (String::from("000011010111011001001111111001000100100100010100101100001101101101110001100100101111100111001001111001001010111010010101101001001110011100110101001001001000000110101001010011101100110110100010000"), 7, false);
    assert_eq!(Solution::has_all_codes(s, k), expected);
}
