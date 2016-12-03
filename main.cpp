// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <numeric>
// #include <iterator>
// #include <functional>

// // O(nlog(n)) solution
// class solution {
// public:
//     int minSubArrayLen(int sum, const std::vector<int> & nums) {
// 	auto cpy = nums;
// 	std::sort(cpy.begin(), cpy.end(), std::greater<int>());
// 	std::vector<int> sums;
// 	std::partial_sum(cpy.begin(), cpy.end(), std::inserter(sums, sums.begin()));
// 	auto it = std::lower_bound(sums.begin(), sums.end(), sum);
// 	return int(std::distance(sums.begin(), it))+1;
//     }
// };


// #include <iostream>
// #include <vector>
// #include <algorithm>

// // O(nlog(n)) solution
// class solution {
// public:
//     int minSubArrayLen(int s, const std::vector<int> & nums) {
// 	auto cpy = nums;
// 	std::make_heap(cpy.begin(), cpy.end());
// 	std::pop_heap(cpy.begin(), cpy.end());
// 	int size = 1;
// 	int sum = 0;
// 	sum += cpy[cpy.size()-size];
// 	while (sum < s) {
// 	    std::sort_heap(cpy.begin(), cpy.end()-size);
// 	    size++;
// 	    sum += cpy[cpy.size()-size];
// 	}
// 	return size;
//     }
// };


#include <iostream>
#include <vector>
#include <algorithm>

class solution {
public:
    int minSubArrayLen(int s, const std::vector<int> & nums) {
	auto minmaxpair = std::minmax_element(nums.begin(), nums.end());
	int min = *minmaxpair.first, max = *minmaxpair.second;
	std::vector<int> buckets(max-min+1, 0);
	for (auto & n : nums)
	    buckets[n-min]++;
	int sum = 0, count = 0;
	for (size_t i = buckets.size()-1; i < buckets.size();) {
	    if (sum < s) {
		if (buckets[i] > 0) {
		    sum += i+min;
		    count++;
		    buckets[i]--;
		}
		else {
		    i--;
		}
	    }
	    else
		return count;
	}
	return 0;
    }
};

int main() {
    std::vector<int> nums{2,3,1,2,4,3};
    int sum = 7;
    
    solution soln;
    int minlen = soln.minSubArrayLen(sum, nums);
    std::cout << "The minimum length of the subarray whose sum is greater than or equal to " << sum << " is:\n" << minlen << std::endl;
}
