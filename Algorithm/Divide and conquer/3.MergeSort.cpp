// Merge Sort
// Time complexity: O(nlogn)

void mergeSort(int[] arr, n) {
    if (n > 1) {
        int mid = n / 2;

        mergeSort(arr[0:mid], mid);
        mergeSort(arr[mid:n], n - mid);

        merge(arr[0:n], arr[0:mid], arr[mid:n], mid, n - mid);
    }
}

void merge(int[] arr, int[] arr1, int[] arr2, n1, n2) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}