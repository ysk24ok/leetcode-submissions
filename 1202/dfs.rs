use std::collections::HashMap;

struct Solution;

// TODO: TLE
impl Solution {
    pub fn smallest_string_with_swaps(s: String, pairs: Vec<Vec<i32>>) -> String {
        let mut neighbors = HashMap::new();
        for pair in pairs {
            let (i0, i1) = (pair[0] as usize, pair[1] as usize);
            neighbors.entry(i0).or_insert(Vec::new()).push(i1);
            neighbors.entry(i1).or_insert(Vec::new()).push(i0);
        }
        let mut ret: Vec<char> = vec!['a'; s.len()];
        let mut visited: Vec<bool> = vec![false; s.len()];
        for index in 0..s.len() {
            if visited[index] {
                continue;
            }
            // isolated node
            if !neighbors.contains_key(&index) {
                ret[index] = s.chars().nth(index).unwrap();
                continue;
            }
            let mut indices: Vec<usize> = Vec::new();
            Solution::dfs(index, &neighbors, &mut visited, &mut indices);
            let mut chars: Vec<char> = indices.iter().map(|i| s.chars().nth(*i).unwrap()).collect();
            indices.sort();
            chars.sort();
            for i in 0..indices.len() {
                ret[indices[i]] = chars[i];
            }
        }
        return ret.into_iter().collect();
    }

    // Get all indices of the same group
    pub fn dfs(index: usize, neighbors: &HashMap<usize, Vec<usize>>, visited: &mut Vec<bool>, indices: &mut Vec<usize>){
        visited[index] = true;
        indices.push(index);
        for neighbor in neighbors.get(&index).unwrap() {
            if visited[*neighbor] {
                continue;
            }
            Solution::dfs(*neighbor, neighbors, visited, indices);
        }
    }
}

fn main() {
    let (s, pairs, expected) = (String::from("dcab"), vec!{vec!{0, 3}, vec!{1, 2}}, String::from("bacd"));
    let actual = Solution::smallest_string_with_swaps(s, pairs);
    assert_eq!(actual, expected);

    let (s, pairs, expected) = (String::from("dcab"), vec!{vec!{0, 3}, vec!{1, 2}, vec!{0, 2}}, String::from("abcd"));
    let actual = Solution::smallest_string_with_swaps(s, pairs);
    assert_eq!(actual, expected);

    let (s, pairs, expected) = (String::from("cba"), vec!{vec!{0, 1}, vec!{1, 2}}, String::from("abc"));
    let actual = Solution::smallest_string_with_swaps(s, pairs);
    assert_eq!(actual, expected);

    let (s, pairs, expected) = (String::from("dcab"), Vec::new(), String::from("dcab"));
    let actual = Solution::smallest_string_with_swaps(s, pairs);
    assert_eq!(actual, expected);
}
