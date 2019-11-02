struct Solution;

impl Solution {
    pub fn reverse_words(s: String) -> String {
        Solution::reverse(&s, 0, s.len() - 1);
        return s;
    }

    pub fn reverse(s: &String, i: usize, j: usize) {
        while (i < j) {
            let tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }
}

fn main() {
    let s = "the sky is blue";
    let mut got;
    got = Solution::reverse_words(s.to_string());
    //assert_eq!(got, "blue is sky the");
    assert_eq!(got, "elub si yks eht");
}
