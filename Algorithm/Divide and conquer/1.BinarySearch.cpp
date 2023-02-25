// Binary Search
// Time complexity: O(logn)

int binarySearch(int arr, int left, int right, x) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == x) return mid;
    else if (x < arr[mid]) binarySearch(arr, left, mid - 1, x);
    else binarySearch(arr, mid + 1, right, x);
}

int binarySearchIteration(int[] arr, int n, int x) {
    left = 0;
    right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x) return mid;
        else if (x < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }

    return -1;
}