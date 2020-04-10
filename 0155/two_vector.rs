struct MinStack {
    minimum: Vec<i32>,
    stack: Vec<i32>
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {

    /** initialize your data structure here. */
    fn new() -> Self {
        MinStack{minimum: Vec::new(), stack: Vec::new()}
    }

    fn push(&mut self, x: i32) {
        self.stack.push(x);
        let len: usize = self.minimum.len();
        if len > 0 {
            self.minimum.push(std::cmp::min(x, self.minimum[len-1]));
        } else {
            self.minimum.push(x);
        }
    }

    fn pop(&mut self) {
        let len: usize = self.stack.len();
        assert!(len > 0);
        self.stack.pop();
        self.minimum.pop();
    }

    fn top(&self) -> i32 {
        let len: usize = self.stack.len();
        assert!(len > 0);
        return self.stack[len - 1];
    }

    fn get_min(&self) -> i32 {
        let len: usize = self.stack.len();
        assert!(len > 0);
        return self.minimum[len - 1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(x);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */
fn main() {
    let mut obj = MinStack::new();
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    assert!(obj.get_min() == -3);
    obj.pop();
    assert!(obj.top() == 0);
    assert!(obj.get_min() == -2);
}
