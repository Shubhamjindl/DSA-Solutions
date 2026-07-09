class Solution {
public:
    int sumofsquares(int num){
        int sum = 0;
        while(num > 0){
            int digit = num % 10;
            num = num/10;
            sum = sum + digit * digit;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(fast != 1){
            slow = sumofsquares(slow);
            fast = sumofsquares(fast);
            fast = sumofsquares(fast);
            if(slow == fast && slow != 1){ // cycle present 
                return false;
            }
        }
        return true;
    }
};