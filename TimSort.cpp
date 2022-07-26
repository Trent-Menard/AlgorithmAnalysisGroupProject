#include <utility>
import GenAlgs;

// Overries parent sort
int* TimSort::sort() {
    const int RUN = 32;
    int n = this->size;

    // min() returns smaller of _Left and _Right
    // Call insertionSort()
    for (int i = 0; i < n; i += RUN)
        insertionSort(this->sorted, i, std::min((i + RUN - 1), (n - 1)));

    // Merge from RUN to 2 * RUN.
    for (int s = RUN; s < n; s = 2 * s) {
        // Set starting point of left sub array to merge arr[left..left+size-1] & arr[left+size, left+2*size-1]
        // Increase left by 2 * size for each merge
        for (int left = 0; left < n; left += 2 * s) {
            int mid = left + s - 1; // Ending point of left sub array mid+1 is starting point of right sub array
            int right = std::min((left + 2 * s - 1), (n - 1));
            merge(this->sorted, left, mid, right); // Merge sub array arr[left.....mid] & arr[mid+1....right]
        }
    }

    return this->sorted;
}

// Insertion sort for RUN chunks
void TimSort::insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++)
    {
        int t = arr[i];
        int j = i - 1;
        while (j >= left && t < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = t;
    }
}

// Merge sorted chunks
void TimSort::merge(int arr[], int l, int m, int r) {

    int len1 = m - l + 1, len2 = r - m;

    int* left = new int[len1];
    int* right = new int[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i]; // Fill left array

    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i]; // Fill right array

    int i = 0;
    int j = 0;
    int k = l;

    // Iterate both arrays left and right
    while (i < len1 && j < len2)
    {
        // Increment I & push to larger array if left element is less than right
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }

        //Increment J if right element is greater
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements in left array
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }

    // Copy remaining elements in right array
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}
// Citation
// https://tutorialspoint.dev/algorithm/sorting-algorithms/timsort