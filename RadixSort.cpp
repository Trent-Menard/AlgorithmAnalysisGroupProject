import GenAlgs;

// Get the maximum value from the array.
int RadixSort::getMax() {

    int max = this->sorted[0];

    for (int i = 1; i < this->size; i++)
        if (this->sorted[i] > max)
            max = this->sorted[i];

    return max;
}

// Overrides parent sort
int* RadixSort::sort() {

    int max = getMax();

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        sort(place);

	return this->sorted;
}

// Internal use only
void RadixSort::sort(int place) {

    const int max = 10;
    int* output = new int[size];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < size; i++)
        count[(this->sorted[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--) {
        output[count[(this->sorted[i] / place) % 10] - 1] = this->sorted[i];
        count[(this->sorted[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        this->sorted[i] = output[i];
    }
}
// Citation
// https://www.programiz.com/dsa/radix-sort