#include <stdio.h>
#include <iostream>
#include <vector>
#include "CTimeStat.h"

using namespace std;


class CTwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size()-1; i++)
        {
            //if (nums[i] > target) continue;
            for (int j = i+1; j < nums.size(); j++)
            {
                //if (nums[j] <= target)
                    if (target == nums[i] + nums[j])
                    {
                        res.push_back(i);
                        res.push_back(j);
                        return res;
                    }
            }
        }
        return res;
    }
};


void testTwoSum()
{
    CTwoSum c;
    vector<int> v = { -3,4,3,90 };
    int target = 0;

    vector<int> res = c.twoSum(v, target);

    printf("Result: ");
    for (auto i : res)
    {
        printf("%d ", i);
    }
    printf("\n");
}