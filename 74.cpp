#include "m.h"

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //我是可以迅速确定这个元素应该到第几行去寻找的
        //那么我想到的是两次二分（第一次确定行，第二次确定列）
        int row = 0;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m - 1; 
        while(left <= right)
        {
            row = (left + right) / 2;
            if(matrix[row][n - 1] == target)
            {
                return true;
            }
            else if(matrix[row][n - 1] < target)
            {
                left = row + 1;
            }
            else
            {
                right = row;
            }
            if(row ==  (left + right) / 2)
            {
                break;
            }
        }
        row = right;
        //这里的行应该再用if判断与邻居的两行判断才能真正的确定
        left = 0, right = n - 1;
        int mid = 0;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(matrix[row][mid] == target)
            {
                return true;
            }
            else if(matrix[row][mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1,3,5,7},{10,11,16,20},{23,30,34,50}
    };
    int target = 10;
    Solution s;
    bool r = s.searchMatrix(matrix, target);
    return 0;
}