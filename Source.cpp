#include <iostream>
#include <chrono>

import GenAlgs;
using namespace std::chrono;
// Modules introduced in C++20. Essentially replaces header files for easier API creation.
// Also speeds up compilation time by not having to copy the header files into the .cpp every time.
// See: https://docs.microsoft.com/en-us/cpp/cpp/modules-cpp?view=msvc-170 for more information.

int main() {
    // NOT RECOMMENDED FOR LARGE DATA SETS; COUT SPEED IS LIMITED!
	const bool SHOWRESULTS = true;
    // If above is enabled, number of results to display.
    const int RESULT_COUNT = 10;

	// 1 for default (same numbers each time) time(0) for "true" random.
	//srand(time(0));

    const int ARRAY_CAPACITY = 1000;
    // NOTE: Defualt Timsort capacity is 1024 elements; (32 RUN slots) but may be increased.

	// Generic Dynamically Allocated Array to be used for all algorithms.
	int* genericArray = new int[ARRAY_CAPACITY];

    if (SHOWRESULTS)
        std::cout << "Showing Original Data:" << std::endl;

	// Randomize Data for Array.
	for (int i = 0; i < ARRAY_CAPACITY; i++) {
		genericArray[i] = rand() % (ARRAY_CAPACITY * 100);

        if (SHOWRESULTS && i < RESULT_COUNT)
            (i % 10 == 0 && i != 0 ? std::cout << genericArray[i] << "\n" : std::cout << genericArray[i] << ", ");
	}

	std::cout << std::endl << std::endl;

	// Unordered Quick Sort Algorithm
	QuickSort quickSort(genericArray, ARRAY_CAPACITY);
	auto quickSortStart = steady_clock::now();
	int* quickSortResult = quickSort.sort();
	auto quickSortStop = steady_clock::now();
	auto quickSortDuration = duration_cast<microseconds>(quickSortStop - quickSortStart);
	if (SHOWRESULTS)
        quickSort.display(RESULT_COUNT);
	std::cout << "\nSorted " << ARRAY_CAPACITY << " values ascendingly in " << quickSortDuration.count() << " microseconds via Quick Sort." << "\n\n";


	// Radix Sort Algorithm
	RadixSort radixSort(genericArray, ARRAY_CAPACITY);
	auto radixSortStart = steady_clock::now();
	radixSort.sort();
	auto radixSortStop = steady_clock::now();
	auto radixSortDuration = duration_cast<microseconds>(radixSortStop - radixSortStart);
	if (SHOWRESULTS)
		radixSort.display(RESULT_COUNT);
	std::cout << "\nSorted " << ARRAY_CAPACITY << " values ascendingly in " << radixSortDuration.count() << " microseconds via Radix Sort" << "\n\n";


    // Tim Sort Algorithm
    TimSort timSort(genericArray, ARRAY_CAPACITY);
    auto timSortStart = steady_clock::now();
    timSort.sort();
    auto timSortStop = steady_clock::now();
    auto timSortDuration = duration_cast<microseconds>(timSortStop - timSortStart);
    if (SHOWRESULTS)
        timSort.display(RESULT_COUNT);
    std::cout << "\nSorted " << ARRAY_CAPACITY << " values ascendingly in " << timSortDuration.count() << " microseconds via Tim Sort" << "\n\n";


    // Bubble Sort Algorithm
    BubbleSort bubbleSort(genericArray, ARRAY_CAPACITY);
    auto bubbleSortStart = steady_clock::now();
    bubbleSort.sort();
    auto bubbleSortStop = steady_clock::now();
    auto bubbleSortDuration = duration_cast<microseconds>(bubbleSortStop - bubbleSortStart);
    if (SHOWRESULTS)
        bubbleSort.display(RESULT_COUNT);
    std::cout << "\nSorted " << ARRAY_CAPACITY << " values ascendingly in " << bubbleSortDuration.count() << " microseconds via Bubble Sort." << "\n\n";


    // Selection Sort Algorithm
    SelectionSort selectionSort(genericArray, ARRAY_CAPACITY);
    auto selectionSortStart = steady_clock::now();
    selectionSort.sort();
    auto selectionSortStop = steady_clock::now();
    auto selectionSortDuration = duration_cast<microseconds>(selectionSortStop - selectionSortStart);
    if (SHOWRESULTS)
        selectionSort.display(RESULT_COUNT);
    std::cout << "\nSorted " << ARRAY_CAPACITY << " values ascendingly in " << selectionSortDuration.count() << " microseconds via Selection Sort." << "\n\n";

    return 1;
}