#include <iostream>
#include <vector>

//#define BOTTOM_UP

void get_subsequences(std::vector<std::vector<int>>& holder, std::vector<int>& nums, std::vector<int>& current, const int idx)
{
    if (idx >= static_cast<int>(nums.size()))
    {
        holder.push_back(current);
        return;
    }

#ifdef BOTTOM_UP
    get_subsequences(holder, nums, current, idx + 1);

    auto current_item = nums.at(idx);
    current.push_back(current_item);

    get_subsequences(holder, nums, current, idx + 1);

    current.pop_back();
#else // top down
    auto current_item = nums.at(idx);
    current.push_back(current_item);

    get_subsequences(holder, nums, current, idx + 1);

    current.pop_back();

    get_subsequences(holder, nums, current, idx + 1);
#endif
}

int main()
{
    std::vector<std::vector<int>> holder;
    std::vector<int> nums {1,2,3,4};
    std::vector<int> current;

    get_subsequences(holder, nums, current, 0);

    // print subsequences
    for(const auto& row : holder)
    {
        for(const auto& r : row)
        {
            std::cout << r << " ";
        }

        std::cout << "\n";
    }

    return 0;
}
