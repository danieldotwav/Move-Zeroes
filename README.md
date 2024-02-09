## Introduction

This C++ project includes an efficient algorithm for rearranging elements in an integer array such that all zeros are moved to the end while maintaining the relative order of the non-zero elements. This manipulation is performed in-place, demonstrating an efficient use of memory and computational resources.

## Algorithm

### **Move Zeroes**

#### Logic

The algorithm uses a two-pointer approach to process the array. The `left` pointer marks the position for the next non-zero element, and the `right` pointer scans through the array looking for non-zero elements. When a non-zero element is found by the `right` pointer, it is swapped with the element at the `left` pointer if they are not the same, effectively moving all zeros to the end while maintaining the order of non-zero elements.

#### Complexity Analysis

- **Time Complexity:** O(n) - The algorithm scans through the array a single time, making the time complexity linear with respect to the size of the input array.
- **Space Complexity:** O(1) - It operates in-place with a constant amount of extra space, leading to constant space complexity.

### Code Snippet

```cpp
void moveZeroes(vector<int>& nums) {
    int len = nums.size();
    if (len == 0 || len == 1) { return; }

    int left = 0, right = 0;
    while (right < len) {
        if (nums[right] != 0) {
            if (right != left) {
                nums[left] = nums[right];
                nums[right] = 0;
            }
            left++;
        }
        ++right;
    }
}
```