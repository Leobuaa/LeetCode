/**
 * https://leetcode.com/problems/validate-stack-sequences/solution/
 * 
 * Approach 1: Greedy
 * Intuition
 *
 * We have to push the items in order, so when do we pop them?
 *
 * If the stack has say, 2 at the top, then if we have to pop that value next, we must do it now. That's because any subsequent push will make the top of the stack different from 2, and we will never be able to pop again.
 *
 * Algorithm
 *
 * For each value, push it to the stack.
 *
 * Then, greedily pop values from the stack if they are the next values to pop.
 *
 * At the end, we check if we have popped all the values successfully.
 */

class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int N = pushed.length;
        Stack<Integer> stack = new Stack();

        int j = 0;
        for (int x: pushed) {
            stack.push(x);
            while (!stack.isEmpty() && j < N && stack.peek() == popped[j]) {
                stack.pop();
                j++;
            }
        }

        return j == N;
    }
}