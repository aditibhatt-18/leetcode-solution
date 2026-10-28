class Solution {
public:
    bool possible (vector<int>& bloomDay, int day ,int m, int k){
      int n = bloomDay.size();
      int bloom = 0;
      int bouquets = 0;
      for (int i = 0; i<n;i++){
        if(bloomDay[i]<=day) bloom++;
        else {
            bouquets += bloom / k;
            bloom =0;
        }
      }
      bouquets += bloom / k;

      return bouquets >=m;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element( bloomDay.begin(), bloomDay.end());;
        int high = *max_element( bloomDay.begin(), bloomDay.end());

        long long val = 1LL*m*k;
        if(val > n) return -1;

        while(low<=high){
            int mid = low + (high- low) / 2 ;

            if (possible(bloomDay, mid, m, k)) high = mid -1;
            else low = mid+1;
        }
        return low;
    }
};