// Bubble sort in C++
import GenAlgs;

int* BubbleSort::sort() {
    // loop to access each array element
    for (int step = 0; step < this->size; ++step) {

        // loop to compare array elements
        for (int i = 0; i < this->size - step; ++i) {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (this->sorted[i] > this->sorted[i + 1] && i + 1 < this->size) {

                // swapping elements if elements
                // are not in the intended order
                int temp = this->sorted[i];
                this->sorted[i] = this->sorted[i + 1];
                this->sorted[i + 1] = temp;
            }
        }
    }
    return this->sorted;
}