// Merge Sort
// Time complexity: O(nlogn) (At worst: O(n^2))

#include <iostream>
#include <vector>

void printVector(std::vector<int>& arr) {
    for (auto num : arr) {
        std::cout << num << ' ';
    }

    std::cout << std::endl;
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> sortedArr(right - left + 1);

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            sortedArr[k] = arr[i];
            i++;
        } else {
            sortedArr[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid) {
        sortedArr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        sortedArr[k] = arr[j];
        j++;
        k++;
    }

    for (int m = left; m <= right; ++m) {
        arr[m] = sortedArr[m - left];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr,  mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    std::cout << "===== Start =====" << std::endl;

    std::vector<int> numbers = { 5, 4, 3, 2, 1 };

    std::cout << "Before sorted: ";
    printVector(numbers);

    mergeSort(numbers, 0, numbers.size() - 1);

    std::cout << "After sorted: ";
    printVector(numbers);
}