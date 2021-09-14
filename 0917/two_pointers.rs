struct Solution;

impl Solution {
    pub fn reverse_only_letters(s: String) -> String {
        let (mut l, mut r): (usize, usize) = (0, s.len() - 1);
        let mut bytes = s.into_bytes();
        while l < r {
            let is_char_l_english = Solution::is_english_character(bytes[l] as i8);
            let is_char_r_english = Solution::is_english_character(bytes[r] as i8);
            if is_char_l_english && is_char_r_english {
                bytes.swap(l, r);
                l += 1;
                r -= 1;
            } else if is_char_l_english {
                r -= 1;
            } else if is_char_r_english {
                l += 1;
            } else {
                l += 1;
                r -= 1;
            }
        }
        return String::from_utf8(bytes).unwrap();
    }

    pub fn is_english_character(c: i8) -> bool {
        let diff = c - 'a' as i8;
        if 0 <= diff && diff < 26 {
            return true;
        }
        let diff = c - 'A' as i8;
        if 0 <= diff && diff < 26 {
            return true;
        }
        return false;
    }
}

fn main() {
    let (s, expected) = (String::from("ab-cd"), String::from("dc-ba"));
    assert_eq!(Solution::reverse_only_letters(s), expected);

    let (s, expected) = (String::from("a-bC-dEf-ghIj"), String::from("j-Ih-gfE-dCba"));
    assert_eq!(Solution::reverse_only_letters(s), expected);
}
