import GenAlgs;

int QuickSort::partition(int low, int high)
{
    // select the rightmost element as pivot
    int pivot = this->sorted[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (this->sorted[j] <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            this->swap(&this->sorted[i], &this->sorted[j]);

        }
    }

    // swap pivot with the greater element at i
    this->swap(&this->sorted[i + 1], &sorted[high]);

    // return the partition point
    return (i + 1);
}

// Overrides parent sort
int* QuickSort::sort(){

    int n = sizeof(this->sorted) / sizeof(this->sorted[0]);

    // perform quicksort on data
    sort(0, this->size - 1);

    return this->sorted;
}

// Internal use only
void QuickSort::sort(int low, int high){

    if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(low, high);

    // recursive call on the left of pivot
    sort(low, pi - 1);

    // recursive call on the right of pivot
    sort(pi + 1, high);
  }
}
// Citation
// https://www.programiz.com/dsa/quick-sort