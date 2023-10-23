class Solution {
public:
int partition(vector<int>& expected,int s,int e){
    int pivot=expected[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(expected[i]<=pivot){
            count++;
        }
    }
    int pivotindex=s+count;
    swap(expected[pivotindex],expected[s]);

    int i=s,j=e;
    while(i<pivotindex && j>pivotindex){
        while(expected[i]<=pivot){
            i++;
        }
        while(expected[j]>pivot){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(expected[i++],expected[j--]);
        }
    }
    return pivotindex;
}
void QuickSort(vector<int>& expected,int s,int e){
     if(s>=e){
        return;
    }
    int p=partition(expected,s,e);
    QuickSort(expected,s,p-1);
    QuickSort(expected,p+1,e);
}
    int heightChecker(vector<int>& heights) {
      vector<int>expected=heights;
       QuickSort(expected,0,expected.size()-1);
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=expected[i]){
                count++;
            }
        }
    return count;
    }
};