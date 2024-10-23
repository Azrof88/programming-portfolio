//Problem Statement: Given a set of integers and a target sum,
// determine if there exists a subset of the given integers that adds up to the target sum.
#include <bits/stdc++.h>

using namespace std;

void findSubsetSum(const vector<int>& nums, int target, vector<int>& subset, int index) {
    if (target == 0) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }
    if (target < 0 || index >= nums.size()) {
        return;
    }

    // Include the current number
    subset.push_back(nums[index]);
    findSubsetSum(nums, target - nums[index], subset, index + 1);

    // Exclude the current number
    subset.pop_back();
    findSubsetSum(nums, target, subset, index + 1);
}

int main() {
    vector<int> nums;
    int n, target;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> subset;
    cout << "Subsets that sum to " << target << " are: " << endl;
    findSubsetSum(nums, target, subset, 0);

    return 0;
}
