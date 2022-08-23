// f(n,m) = (m % n + x) % n = (m + x) % n;


class Solution {
public:
    int f(int n, int m) {
        if (n == 1)
            return 0;
        int x = f(n-1, m);
        return (m + x) % n;
    }
    int lastRemaining(int n, int m) {
        return f(n,m);
    }
};