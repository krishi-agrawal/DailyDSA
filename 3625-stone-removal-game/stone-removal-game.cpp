class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        bool isAliceTurn = true;
        while(n >= 0) {
            if(n - x >= 0) {
                n -= x;
                x--;
                isAliceTurn = !isAliceTurn;
            } else {
                return !isAliceTurn;
            }
        }
        return false;
    }
};