class Solution {
public:
void Merge(vector<int>& prices, int s, int e) {
        int mid = (s + e) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;
        vector<int> first(len1);
        vector<int> second(len2);

        // Copy values
        for (int i = 0; i < len1; i++) {
            first[i] = prices[s + i];
        }

        for (int i = 0; i < len2; i++) {
            second[i] = prices[mid + 1 + i];
        }

        // Merge two sorted vectors
        int index1 = 0;
        int index2 = 0;
        int k = s;
        while (index1 < len1 && index2 < len2) {
            if (first[index1] < second[index2]) {
                prices[k++] = first[index1++];
            } else {
                prices[k++] = second[index2++];
            }
        }

        while (index1 < len1) {
            prices[k++] = first[index1++];
        }

        while (index2 < len2) {
            prices[k++] = second[index2++];
        }
    }

    void MergeSort(vector<int>& prices, int s, int e) {
        // Base Case
        if (s >= e)
            return;

        int mid = (s + e) / 2;

        // Left part
        MergeSort(prices, s, mid);

        // Right part
        MergeSort(prices, mid + 1, e);

        // Merge
        Merge(prices, s, e);
    }
    int buyChoco(vector<int>& prices, int money) {
        
        int n=prices.size();
        MergeSort(prices,0,n-1);
        int sum=0;
        for(int i=0;i<2;i++){
            sum+=prices[i];
            }
            if(sum<=money)
            return money-sum;
            else
            return money;
    }
};