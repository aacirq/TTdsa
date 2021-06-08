//
// Created by renxin on 2021/6/8.
//

#include "ttdsa.h"

int main() {
    vector<int> vec1 = {};

    // Vector (0): [  ]
    print(vec1);

    // Vector (5): [ 1, 2, 3, 4, 5 ]
    print({1, 2, 3, 4, 5});

    vector<vector<int>> mvec1 = {};
    // Vector of vector (0): [
    //
    // ]
    print(mvec1);

    // Vector of vector (3): [
    // 	   [ 1 ],
    // 	   [ 1, 2 ],
    // 	   [ 1, 2, 3 ]
    // ]
    print({{1}, {1, 2}, {1, 2, 3}});

    return 0;
}