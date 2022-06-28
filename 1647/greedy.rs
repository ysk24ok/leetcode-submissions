use std::collections::HashMap;
use std::collections::HashSet;

struct Solution;

impl Solution {
    pub fn min_deletions(s: String) -> i32 {
        let mut freq_per_char = HashMap::new();
        for c in s.chars() {
            let freq = freq_per_char.entry(c).or_insert(0);
            *freq += 1;
        }
        let mut seen_freq = HashSet::new();
        let mut delete_count = 0;
        for (_, orig_freq) in freq_per_char.iter() {
            let mut freq = *orig_freq;
            while seen_freq.contains(&freq) {
                delete_count += 1;
                freq -= 1;
            }
            if freq > 0 {
                seen_freq.insert(freq);
            }
        }
        return delete_count;
    }
}

fn main() {
    let (s, expected) = (String::from("aab"), 0);
    assert_eq!(Solution::min_deletions(s), expected);

    let (s, expected) = (String::from("aaabbbcc"), 2);
    assert_eq!(Solution::min_deletions(s), expected);

    let (s, expected) = (String::from("ceabaacb"), 2);
    assert_eq!(Solution::min_deletions(s), expected);

    let (s, expected) = (String::from("bbcebab"), 2);
    assert_eq!(Solution::min_deletions(s), expected);
}
