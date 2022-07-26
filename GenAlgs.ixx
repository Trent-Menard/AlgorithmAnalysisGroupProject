#include <iostream>
export module GenAlgs;

// Parent class for all algorithms (children) to inherit from. Essentially an interface.
// Children must abide by interface (obviously).
export class GenericAlg {

public:
	// Pure Virtual for abstraction; classes will inherit & override.
	// Returns the sorted array (doesn't modify original)
	virtual int* sort() = 0;

	// Loop through & display values. ?: used for output formatting.
	const void display() {
		std::cout << "Showing all values: " << std::endl;
		for (int i = 0; i < this->size; i++)
			(i % 10 == 0 && i != 0 ? std::cout << this->sorted[i] << "\n" : std::cout << this->sorted[i] << ", ");
	};

	// Print up to specified index.
	const void display(int countTo) {
		std::cout << "Showing first " << countTo << " values: " << std::endl;
		for (int i = 0; i < countTo; i++)
			(i % 10 == 0 && i != 0 ? std::cout << this->sorted[i] << "\n" : std::cout << this->sorted[i] << ", ");
	};

	// Required parameters for GenericAlg constructor.
	// Creates copy of original to prevent modification.
	GenericAlg(const int arraytoSort[], int size) : size(size) {
		for (int i = 0; i < size; i++)
			this->sorted[i] = arraytoSort[i];
	}

	// Accessable only to children (& parent)
protected:
	const int size;
	int* sorted = new int[size];

	// Commonality extracted from Selection Sort & Quick Sort 
	const void swap(int* a, int* b) {
		int t = *a;
		*a = *b;
		*b = t;
	}
};


// Radix Sort inheriting from GenericAlg
export class RadixSort : public GenericAlg {

public:
	// Calls parent constructor (like super in Java).
	RadixSort(const int arraytoSort[], int size) : GenericAlg(arraytoSort, size) {}

	// Declaration only; algorithms will have varying implementation.
	virtual int* sort() override;

private:
	int getMax();

	// Internal for Counting Sort
	void sort(int place);
};


// Quick Sort inheriting from GenericAlg
export class QuickSort : public GenericAlg {

public:
	// Calls parent constructor (like super in Java).
	QuickSort(const int arraytoSort[], int size) : GenericAlg(arraytoSort, size) {}

	// Declaration only; algorithms will have varying implementation.
	virtual int* sort() override;

private:
	// Internals for Quicksort
	int partition(int low, int high);
	void sort(int low, int high);
};



// Bubble Sort inheriting from GenericAlg
export class BubbleSort : public GenericAlg {

public:
	// Calls parent constructor (like super in Java).
	BubbleSort(const int arraytoSort[], int size) : GenericAlg(arraytoSort, size) {}

	// Declaration only; algorithms will have varying implementation.
	virtual int* sort() override;
};



// Selection Sort inheriting from GenericAlg
export class SelectionSort : public GenericAlg {

public:
	// Calls parent constructor (like super in Java).
	SelectionSort(const int arraytoSort[], int size) : GenericAlg(arraytoSort, size) {}

	// Declaration only; algorithms will have varying implementation.
	virtual int* sort() override;
};



// Tim Sort inheriting from GenericAlg
export class TimSort : public GenericAlg {

public:
	// Calls parent constructor (like super in Java).
	TimSort(const int arraytoSort[], int size) : GenericAlg(arraytoSort, size) {}

	// Declaration only; algorithms will have varying implementation.
	virtual int* sort() override;

private:
	// Internals for Tim Sort
	void insertionSort(int arr[], int left, int right);
	void merge(int arr[], int l, int m, int r);
};