// search_33.cpp : 定义控制台应用程序的入口点。
//
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int searchNum(vector<int>& nums, int target, int left, int right)
{
	if (left == right)
	{
		if (nums[left]==target)
		{
			return left;
		}
		return -1;
	}
	if (left > right)return -1;
	
	int mid = (left + right) / 2;
	if (nums[mid] == target)return mid;
	//升序4,5,6,7
	if (nums[right]>nums[left])
	{
		if (nums[mid] > target)
		{
			return searchNum(nums, target, left, mid);
		}
		else if (nums[mid] < target)
		{
			return searchNum(nums, target, mid + 1, right);
		}
	}
	//4,5,6,7,0,1,2
	else 
	{
		//left 升序4,5,6,7
		if (nums[mid] > nums[left])
		{
			if (nums[mid] > target&&nums[left] < target)
			{
				return searchNum(nums, target, left, mid);	
			}
			else
			{
				return searchNum(nums, target, mid + 1, right);
			}
		}
		else
		{
			if (nums[mid]<target&&nums[right]>target)
			{
				return searchNum(nums, target, mid + 1, right);
			}
			return searchNum(nums, target, left, mid);	
				
		}
	}
	return -1;
}

int search(vector<int>& nums, int target) {
	if (nums.size() == 0)return -1;
	return searchNum(nums, target, 0, nums.size()-1);
}

int main()
{
	vector<int> nums = { 4,5,6,7,8,0,1,2 };
	cout << search(nums, 8);
    return 0;
}

