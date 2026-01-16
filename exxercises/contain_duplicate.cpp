#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>

int main()
{

    std::vector<int> nums = {1, 2, 3, 3};
    std::unordered_set<int> s(nums.begin(), nums.end());
    return s.size() != nums.size();
}
