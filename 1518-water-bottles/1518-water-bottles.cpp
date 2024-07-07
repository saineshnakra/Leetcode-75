class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        res += numBottles;
        int rem = 0;
        while (numBottles + rem >= numExchange) {
            res += (numBottles + rem) / numExchange >= 1
                       ? (numBottles + rem) / numExchange
                       : 0;
            int temp_num = numBottles;
            numBottles = (numBottles + rem) / numExchange >= 1
                             ? (numBottles + rem) / numExchange
                             : 0;
            rem = (temp_num+ rem) % numExchange >= 1
                       ? (temp_num + rem) % numExchange
                       : 0;
        }
        return res;
    }
};