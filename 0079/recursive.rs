struct Solution;

impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        let (m, n) = (board.len(), board[0].len());
        let word_as_bytes = word.as_bytes();
        let mut visited = vec![vec![false; n]; m];
        for i in 0..m {
            for j in 0..n {
                if Solution::recursive(&board, i, j, word_as_bytes, 0, &mut visited) {
                    return true;
                }
            }
        }
        return false;
    }

    fn recursive(board: &Vec<Vec<char>>, i: usize, j: usize, word_as_bytes: &[u8], word_idx: usize, visited: &mut Vec<Vec<bool>>) -> bool {
        if visited[i][j] || board[i][j] != word_as_bytes[word_idx] as char {
            return false;
        }
        if word_idx == word_as_bytes.len() - 1 {
            return true;
        }
        visited[i][j] = true;
        let mut ret = false;
        let (m, n) = (board.len(), board[0].len());
        if i < m - 1 {
            ret = ret || Solution::recursive(&board, i + 1, j, word_as_bytes, word_idx + 1, visited);
        }
        if i > 0 {
            ret = ret || Solution::recursive(&board, i - 1, j, word_as_bytes, word_idx + 1, visited);
        }
        if j < n - 1 {
            ret = ret || Solution::recursive(&board, i, j + 1, word_as_bytes, word_idx + 1, visited);
        }
        if j > 0 {
            ret = ret || Solution::recursive(&board, i, j - 1, word_as_bytes, word_idx + 1, visited);
        }
        visited[i][j] = false;
        return ret;
    }
}

fn main() {
    let board = vec![vec!['A', 'B', 'C', 'E'], vec!['S', 'F', 'C', 'S'], vec!['A', 'D', 'E', 'E']];
    let word = String::from("ABCCED");
    let expected = true;
    assert_eq!(Solution::exist(board, word), expected);

    let board = vec![vec!['A', 'B', 'C', 'E'], vec!['S', 'F', 'C', 'S'], vec!['A', 'D', 'E', 'E']];
    let word = String::from("SEE");
    let expected = true;
    assert_eq!(Solution::exist(board, word), expected);

    let board = vec![vec!['A', 'B', 'C', 'E'], vec!['S', 'F', 'C', 'S'], vec!['A', 'D', 'E', 'E']];
    let word = String::from("ABCB");
    let expected = false;
    assert_eq!(Solution::exist(board, word), expected);
}
