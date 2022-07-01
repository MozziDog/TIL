// solution #1 무식하게 풀기
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        for(int i = 0; i<(mat.size() + mat[0].size()); i++){
            if(i % 2 == 0)
                for(int j=mat.size() -1; j>=0; j--){
                    for(int k=0; k<mat[0].size(); k++){
                        if(j+k == i)
                        {
                            result.push_back(mat[j][k]);
                            break;
                        }
                    }
                }
            else
                for(int j=0; j<mat.size(); j++){
                    for(int k=0; k<mat[0].size(); k++){
                        if(j+k == i)
                        {
                            result.push_back(mat[j][k]);
                            break;
                        }
                    }
                }
        }
        return result;
    }
};

// solution #2 조금 더 깔끔하게 다시 풀어봄.
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        for(int i=0; i<mat.size() + mat[0].size(); i++){ // i는 가로세로 인덱스의 합
            if(i%2 == 0)
                for(int j= i; j>=0; j--) {  // j는 세로 인덱스
                    int k = i-j;        // k는 가로 인덱스
                    if(j >= mat.size() || k >= mat[0].size())
                        continue;
                    result.push_back(mat[j][k]);
                }
            else
                for(int j=0; j<=i; j++) {
                    int k = i-j;
                    if(j >= mat.size() || k >= mat[0].size())
                        continue;
                    result.push_back(mat[j][k]);
                }
        }
        return result;
    }
};

// solution #3 숏코딩?
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        for(int i=0; i<mat.size() + mat[0].size(); i++){ // i는 가로세로 인덱스의 합
            for(int j= i%2==0?i:0; i%2==0?j>=0:j<=i; i%2==0?j--:j++) {  // j는 세로 인덱스
                int k = i-j;        // k는 가로 인덱스
                if(j >= mat.size() || k >= mat[0].size())
                    continue;
                result.push_back(mat[j][k]);
            }
        }
        return result;
    }
};