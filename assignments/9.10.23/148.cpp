/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
void Merge(vector<int>& ans, int s, int e) {
        int mid = (s + e) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;
        vector<int> first(len1);
        vector<int> second(len2);

        // Copy values
        for (int i = 0; i < len1; i++) {
            first[i] = ans[s + i];
        }

        for (int i = 0; i < len2; i++) {
            second[i] = ans[mid + 1 + i];
        }

        // Merge two sorted vectors
        int index1 = 0;
        int index2 = 0;
        int k = s;
        while (index1 < len1 && index2 < len2) {
            if (first[index1] < second[index2]) {
                ans[k++] = first[index1++];
            } else {
                ans[k++] = second[index2++];
            }
        }

        while (index1 < len1) {
            ans[k++] = first[index1++];
        }

        while (index2 < len2) {
            ans[k++] = second[index2++];
        }
    }

    void MergeSort(vector<int>& ans, int s, int e) {
        // Base Case
        if (s >= e)
            return;

        int mid = (s + e) / 2;

        // Left part
        MergeSort(ans, s, mid);

        // Right part
        MergeSort(ans, mid + 1, e);

        // Merge
        Merge(ans, s, e);
    }
    ListNode* sortList(ListNode* head) {
         vector<int>ans;
        ListNode*temp=head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n = ans.size();
        MergeSort(ans, 0, n - 1);
        ListNode*dummy=new ListNode();
       
        ListNode*dummy1=dummy;
        for(int i=0;i<ans.size();i++){
       dummy1->next=new ListNode(ans[i]);
        dummy1=dummy1->next;
        }
        return dummy->next;
    }
};