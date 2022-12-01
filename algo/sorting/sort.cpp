namespace sort {
    namespace {
        template<typename T> void swap(T &a, T &b) {
            T temp = a;
            a = b;
            b = temp;
        }

        unsigned long long bSwaps;
        unsigned long long qSwaps;

        template<typename T> void _qsort(T* array, int low, int high) {
            int i = low;
            int j = high;
            T pivot = array[(i + j) / 2];

            while (i < j) {
                while (array[i] < pivot)
                    i++;

                while (array[j] > pivot)
                    j--;

                if (i <= j) {
                    swap(array[i], array[j]);
                    i++;
                    j--;
                    qSwaps++;
                }
            }

            if (j > low)
                _qsort(array, low, j);

            if (i < high)
                _qsort(array, i, high);
        }
    }

    template<typename T> void bsort(T* array, const unsigned long size) {
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if (array[i] > array[j]) {
                    swap(array[i], array[j]);
                    bSwaps++;                    
                }
    }

    template<typename T> void qsort(T* array, const unsigned long size) {
	    _qsort(array, 0, size - 1);
    }
}