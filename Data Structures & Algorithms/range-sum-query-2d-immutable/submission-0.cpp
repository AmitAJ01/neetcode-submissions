class NumMatrix {
public:
    vector<vector<int>> presum;
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        presum.resize(r+1,vector<int>(c+1,0));

        for(int i=0; i<r; i++){
            int prefix=0;
            for(int j=0; j<c; j++){
                prefix+=matrix[i][j];
                int above = presum[i][j+1];
                presum[i+1][j+1]=prefix+above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int bottom = presum[row2+1][col2+1];
        int above = presum[row1][col2+1];
        int left = presum[row2+1][col1];
        int leftmost = presum[row1][col1];
        return bottom - above - left + leftmost;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */