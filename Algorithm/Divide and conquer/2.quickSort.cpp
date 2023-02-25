// Quick Sort
// Time complexity: O(nlogn) (At worst: O(n^2))

int partition(int[] arr, int n) {
    int left = 1;
    int right = n - 1;

    while (left < right) {
        while (left < n && arr[left] < arr[0]) left++;
        while (right > 0 && arr[right] > arr[0]) right--;

        if (left < right) swap(arr[left], arr[right]);
        else swap(arr[right], arr[0]);
    }

    int newPivot = right;

    return newPivot;
}

int quickSort(int[] arr, int n) {
    if (n > 1) {
       int pivot = partition(arr, n);

       quickSort(arr[0: pivot], pivot);
       quickSort(arr[pivot + 1: n], n - pivot - 1);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}