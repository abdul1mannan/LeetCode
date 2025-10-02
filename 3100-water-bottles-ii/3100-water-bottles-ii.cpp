class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int cnt=numBottles;

        while(numBottles>=numExchange){
            int rem=numBottles-numExchange;
            cnt++;
            numBottles=rem+1;
            numExchange++;
        }
        return cnt;
    }
};