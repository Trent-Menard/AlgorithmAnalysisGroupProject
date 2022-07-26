import GenAlgs;

// Overrides parent sort
int* SelectionSort::sort() {
    int i, j, min_idx;
    int n = this->size - 1;

    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in unsorted array 
        min_idx = i;

        for (j = i + 1; j < n; j++) {
            if (this->sorted[j] < this->sorted[min_idx])
                min_idx = j;

            // Swap the found minimum element with the first element 
            this->swap(&this->sorted[min_idx], &this->sorted[i]);
        }
    }

    return this->sorted;
}
// Citation
// https://www.geeksforgeeks.org/selection-sort/