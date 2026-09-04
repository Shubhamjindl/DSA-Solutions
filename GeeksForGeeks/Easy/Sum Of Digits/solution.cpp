class Solution {
  public:
    int sumOfDigits(int n) {
        if(n == 0){
            return 0;
        }
        int currdigit = n % 10;
        int prevsum = sumOfDigits(n/10);
        return prevsum + currdigit;
    }
};