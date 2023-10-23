class Solution {
public:
 void Merge(vector<int>& nums, int s, int e) {
        int mid = (s + e) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;
        vector<int> first(len1);
        vector<int> second(len2);

        // Copy values
        for (int i = 0; i < len1; i++) {
            first[i] = nums[s + i];
        }

        for (int i = 0; i < len2; i++) {
            second[i] = nums[mid + 1 + i];
        }

        // Merge two sorted vectors
        int index1 = 0;
        int index2 = 0;
        int k = s;
        while (index1 < len1 && index2 < len2) {
            if (first[index1] < second[index2]) {
                nums[k++] = first[index1++];
            } else {
                nums[k++] = second[index2++];
            }
        }

        while (index1 < len1) {
            nums[k++] = first[index1++];
        }

        while (index2 < len2) {
            nums[k++] = second[index2++];
        }
    }

    void MergeSort(vector<int>& nums, int s, int e) {
        // Base Case
        if (s >= e)
            return;

        int mid = (s + e) / 2;

        // Left part
        MergeSort(nums, s, mid);

        // Right part
        MergeSort(nums, mid + 1, e);

        // Merge
        Merge(nums, s, e);
    }

    void sortColors(vector<int>& nums) {
        int n=nums.size();
        MergeSort(nums,0,n-1);
       
    }
};