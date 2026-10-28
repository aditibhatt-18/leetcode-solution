class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid=low+ (high-low)/2;
            long long total_hrs = 0;

            for(int i =0;i<=piles.size()-1;i++){
                total_hrs+= (1LL*piles[i] + mid-1) / mid;
            }

            if(total_hrs<=h) high = mid-1;
            else low = mid+1;

        }
        return low;
    }
};