bool isToeplitz(vector<vector<int>>& mat) {
    // code here
    int M =  mat.size();
    int N = mat[0].size();
    for (int i = 0; i < M - 1; i++)
		for (int j = 0; j < N - 1; j++)
			// return false if any diagonal elements have different values
			if (mat[i][j] != mat[i + 1][j + 1])
				return false;
	return true;
}
