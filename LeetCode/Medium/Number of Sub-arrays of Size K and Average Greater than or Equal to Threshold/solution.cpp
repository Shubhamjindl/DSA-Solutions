class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, avg = 0, count = 0;
        for(int i = 0; i < k; i++){
            sum += arr[i];
        }
        avg = sum/k;
        if(avg >= threshold){
            count++;
        }
        int low = 1, high = k;
        while(high < arr.size()){
            sum = sum + arr[high] - arr[low - 1];
            avg = sum/k;
            if(avg >= threshold){
                count++;
            }
            low++;
            high++;
        }
        return count;
    }
};