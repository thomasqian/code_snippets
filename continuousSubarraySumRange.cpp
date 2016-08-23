bool DEBUG = false;

int numRange(vector<int> &A, int B, int C) {
    int count = 0;
    int maxPtr = 0;
    int minPtr = 0;
    int maxSum = 0;
    int minSum = 0;
    
    for (int i = 0; i < A.size(); ++i) {
        
        maxSum += A[i];
        minSum = A[i];
        minPtr = i;
        
        while (maxPtr < i && maxSum > C) {
            maxSum -= A[maxPtr++];
        }
        
        /*** SUB-OPTIMAL CODE ***/
        while (minPtr > 0 && minSum < B) {
            minSum += A[--minPtr];   
        }

        if (DEBUG) {
            cout << i << ": maxPtr is at " << maxPtr << " with sum " << maxSum << endl;
            cout << i << ": minPtr is at " << minPtr << " with sum " << minSum << endl; 
        }

        if (maxPtr == minPtr) {
            if (minPtr == i && A[i] >= B && A[i] <= C) ++count;
            else if (minPtr != i && minSum >= B && A[i] <= maxSum) ++count;
        } else if (maxPtr <= minPtr) {
            if (DEBUG) cout << "adding to count: " << minPtr - maxPtr + 1 << endl;
            count += minPtr - maxPtr + 1;
        }
        
    }
    
    return count;
}