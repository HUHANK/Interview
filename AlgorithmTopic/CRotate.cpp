#include <stdio.h>
#include <iostream>
#include <vector>
#include "CTimeStat.h"

using namespace std;

class CRotate {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int* ibuf = new int[nums.size()];

        memcpy(ibuf, &(nums[nums.size() - k]), k * sizeof(int));
        memcpy(ibuf + k, &(nums[0]), (nums.size() - k) * sizeof(int));
        memcpy(&(nums[0]), ibuf, nums.size() * sizeof(int));

        delete[] ibuf;
    }
};

void TestRotate()
{
    vector<int> v = { 1,2,3,4,5,6,7 };
    int k = 3;
    CRotate c;
    c.rotate(v, k);

    printf("Result: ");
    for (auto i : v)
    {
        printf("%d ", i);
    }
    printf("\n");
}