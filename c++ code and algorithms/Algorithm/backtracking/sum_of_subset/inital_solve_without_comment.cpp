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

    subset.push_back(nums[index]);
    cout<<"After pushing"<<endl;
    cout<<"index="<<index<<" ";
            cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    findSubsetSum(nums, target - nums[index], subset, index + 1);
    cout<<"After returning from 1st call"<<endl;
     cout<<"index="<<index<<" ";
            cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;

    subset.pop_back();
    cout<<"After poping"<<endl;
     cout<<"index="<<index<<" ";
            cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
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
