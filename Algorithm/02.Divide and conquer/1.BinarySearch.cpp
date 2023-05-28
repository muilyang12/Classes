// Binary Search
// Time complexity: O(logn)

#include <iostream>

int binarySearch(int arr[], int left, int right, int x) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == x) return mid;
    else if (x < arr[mid]) binarySearch(arr, left, mid - 1, x);
    else binarySearch(arr, mid + 1, right, x);
}

int main() {
	std::cout << "===== Start =====" << std::endl;

    int arr[] = { 10, 15, 30, 45, 50, 77, 80 };
    std::cout << "Number " << 30 << " at " << binarySearch(arr, 0, 7, 30) << std::endl;
    std::cout << "Number " << 80 << " at " << binarySearch(arr, 0, 7, 80) << std::endl;
    std::cout << "Number " << 10 << " at " << binarySearch(arr, 0, 7, 10) << std::endl;
    
}