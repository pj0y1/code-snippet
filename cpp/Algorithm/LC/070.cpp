class Solution {
public:
    int climbStairs(int n) {
        // 本质是fib数列 Fib(n) = Fib(n-1) + Fib(n-2)
        long long a = 1, b = 2;
        while (n > 1){
            long long tmp = a + b;
            a = b;
            b = tmp;
            n--;
        }
        return (int)a;
    }
};
