class Solution {
public:
    int sumofsquares(int n){
        int sum = 0;
        while(n != 0){
            int digit = n % 10;
            n = n/10;
            sum += digit * digit;
        }
        return sum;
    }
    bool isHappy(int n){
        int slow = n, fast = n;
        while(fast != 1 ){
            slow = sumofsquares(slow);
            fast = sumofsquares(sumofsquares(fast));
            if(slow == fast && fast != 1){
                return false;
            }
        }
        return true;
    }
};