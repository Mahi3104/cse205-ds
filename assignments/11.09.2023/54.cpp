class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }
        int rowstart = 0, rowend = m - 1, colstart = 0, colend = n - 1;
        while (rowstart <= rowend && colstart <= colend) {
           
            for (int i = colstart; i <= colend; i++) {
                ans.push_back(matrix[rowstart][i]);
            }
            rowstart++;

            
            for (int i = rowstart; i <= rowend; i++) {
                ans.push_back(matrix[i][colend]);
            }
            colend--;

            
            if (rowstart <= rowend) {
                
                for (int i = colend; i >= colstart; i--) {
                    ans.push_back(matrix[rowend][i]);
                }
                rowend--;
            }

           
            if (colstart <= colend) {
                
                for (int i = rowend; i >= rowstart; i--) {
                    ans.push_back(matrix[i][colstart]);
                }
                colstart++;
            }
        }
        return ans;
    }
};
