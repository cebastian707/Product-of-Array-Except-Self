/*By::Cebastian Santiago
* Leetcode 238
*/
#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
	//set the vectors
	std::vector<int> left;
	std::vector<int> right;
	std::vector<int> ans;
	int temp = 1;
	int rights = 1;
	int sizes = 0;
	//get the elements of the left factor 
	for (int i = 0; i < nums.size(); i++) {
		temp = temp * nums[i];
		left.push_back(temp);
	}

	
	//get the elements into the right vector
	for (int j = nums.size()-1;j >= 0; j--) {
		rights = rights * nums[j];
		right.push_back(rights);
	}

	//set the first element in the output array
	 sizes = nums.size() - 2;
	 temp = 1 * right[sizes];
	 ans.push_back(temp);

	//check both arrays
	for (size_t i = 1; i < nums.size(); i++){
		sizes--;
		//if we reach the last element just insert it
		if (i == nums.size()-1) {
			ans.push_back(left[i-1]);
			break;
		}

		temp = left[i - 1] * right[sizes];
		ans.push_back(temp);

	}

	return ans;
}



int main() {
	std::vector<int> nums = {4,3,2,1,2 };
	std::vector<int> ans;

	ans = productExceptSelf(nums);

	for (size_t i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << std::endl;
	}
	return 0;
}