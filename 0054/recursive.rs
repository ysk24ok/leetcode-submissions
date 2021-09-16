struct Solution;

impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let (m, n) = (matrix.len(), matrix[0].len());
        let mut ret = Vec::with_capacity(m * n);
        Solution::recursive(matrix, &mut ret, 0, m, n);
        return ret;
    }

    pub fn recursive(matrix: Vec<Vec<i32>>, ret: &mut Vec<i32>, start: usize, m: usize, n: usize) {
        // left -> right
        for j in start..start+n {
            ret.push(matrix[start][j]);
        }
        // top -> bottom
        for i in start+1..start+m {
            ret.push(matrix[i][start+n-1]);
        }
        // right -> left
        if m > 1 {
            for j in (start..start+n-1).rev() {
                ret.push(matrix[start+m-1][j]);
            }
        }
        // bottom -> top
        if n > 1 {
            for i in (start+1..start+m-1).rev() {
                ret.push(matrix[i][start]);
            }
        }
        if m <= 2 || n <= 2 {
            return;
        }
        Solution::recursive(matrix, ret, start + 1, m - 2, n - 2);
    }
}

fn main() {
    let matrix = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
    let expected = vec![1, 2, 3, 6, 9, 8, 7, 4, 5];
    assert_eq!(Solution::spiral_order(matrix), expected);

    let matrix = vec![vec![1, 2, 3, 4], vec![5, 6, 7, 8], vec![9, 10, 11, 12]];
    let expected = vec![1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7];
    assert_eq!(Solution::spiral_order(matrix), expected);

    // 1 x 1
    let matrix = vec![vec![1]];
    let expected = vec![1];
    assert_eq!(Solution::spiral_order(matrix), expected);

    // 1 x 2
    let matrix = vec![vec![1, 2]];
    let expected = vec![1, 2];
    assert_eq!(Solution::spiral_order(matrix), expected);

    // 2 x 1
    let matrix = vec![vec![1], vec![2]];
    let expected = vec![1, 2];
    assert_eq!(Solution::spiral_order(matrix), expected);

    // 2 x 2
    let matrix = vec![vec![1, 2], vec![3, 4]];
    let expected = vec![1, 2, 4, 3];
    assert_eq!(Solution::spiral_order(matrix), expected);

    // 3 x 2
    let matrix = vec![vec![1, 2], vec![3, 4], vec![5, 6]];
    let expected = vec![1, 2, 4, 6, 5, 3];
    assert_eq!(Solution::spiral_order(matrix), expected);

    // 2 x 3
    let matrix = vec![vec![2, 5, 8], vec![4, 0, -1]];
    let expected = vec![2, 5, 8, -1, 0, 4];
    assert_eq!(Solution::spiral_order(matrix), expected);
}
