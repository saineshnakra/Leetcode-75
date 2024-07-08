class Solution {
public:
int josephus(int n, int k) {
        if (n == 1) {
            return 0;
        }
        return ((josephus(n - 1, k) + k) % n);
    }

    int findTheWinner(int n, int k) {
        return josephus(n, k) + 1;
    }
};
