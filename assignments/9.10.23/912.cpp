class Solution {
public:
void Merge(vector<int>& nums, int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int* first = new int[len1];
    int* second = new int[len2];

    // Copy values
    int k = s;
    for (int i = 0; i < len1; i++) {
        first[i] = nums[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = nums[k++];
    }

    // Merge two sorted numsays
    int index1 = 0;
    int index2 = 0;
    k = s;
    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            nums[k++] = first[index1++];
        }
        else {
            nums[k++] = second[index2++];
        }
    }
    while (index1 < len1) {
        nums[k++] = first[index1++];
    }
    while (index2 < len2) {
        nums[k++] = second[index2++];
    }

    delete[] first;
    delete[] second;
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
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums,0,nums.size()-1);
        return nums;
    }
};