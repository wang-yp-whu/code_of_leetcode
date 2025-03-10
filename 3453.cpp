#include "m.h"

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long tot_area = 0;
        int max_y = 0;
        for (auto& sq : squares) {
            int l = sq[2];
            tot_area += 1LL * l * l;
            max_y = max(max_y, sq[1] + l);
        }

        auto check = [&](double y) -> bool {
            double area = 0;
            for (auto& sq : squares) {
                double yi = sq[1];
                if (yi < y) {
                    double l = sq[2];
                    area += l * min(y - yi, l);
                }
            }
            return area >= tot_area / 2.0;
        };

        double left = 0, right = max_y;
        for (int i = 0; i < 47; i++) {
            double mid = (left + right) / 2;
            (check(mid) ? right : left) = mid;
        }
        return (left + right) / 2; // 区间中点误差小
    }
};
//采用了二分的思想，求解在Y = y水平线以下的正方形总面积，若其二倍大于总面积，则二分y，直到最小的那一个
//循环次数的设定是另一个难点，这里是假设了循环次数的上限，此时再次二分的差值小于一个给定的极小值