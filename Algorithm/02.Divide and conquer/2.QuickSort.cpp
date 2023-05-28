// Quick Sort
// Time complexity: O(nlogn) (At worst: O(n^2))

#include <iostream>
#include <vector>

void swap(std::vector<int>& arr, int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void printVector(std::vector<int>& arr) {
    for (auto num : arr) {
        std::cout << num << ' ';
    }

    std::cout << std::endl;
}

int partition(std::vector<int>& arr, int left, int right) {
    int pivot = arr[left];
    int start = left + 1;
    int end = right;

    while (start < end) {
        while (start < right && arr[start] < pivot) start++;
        while (end > left && arr[end] > pivot) end--;

        if (start < end) swap(arr, start, end);
        else swap(arr, end, left);
    }

    int newPivot = end;

    return newPivot;
}

void quickSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);

        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    std::cout << "===== Start =====" << std::endl;

    std::vector<int> numbers = { 5, 4, 3, 2, 1 };

    std::cout << "Before sorted: ";
    printVector(numbers);

    quickSort(numbers, 0, numbers.size() - 1);

    std::cout << "After sorted: ";
    printVector(numbers);
}