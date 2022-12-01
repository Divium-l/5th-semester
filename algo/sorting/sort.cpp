namespace sort {
    namespace {
        template<typename T> void swap(T &a, T &b) {
            T temp = a;
            a = b;
            b = temp;
        }

        unsigned long long bIterations;
        unsigned long long qIterations;

        template<typename T> void _qsort(T* array, int low, int high) {
            int i = low;
            int j = high;
            T pivot = array[(i + j) / 2];

            while (i < j) {
                while (array[i] < pivot) {
                    i++;
                    qIterations++;
                }

                while (array[j] > pivot) {
                    j--;
                    qIterations++;
                }

                if (i <= j) {
                    swap(array[i], array[j]);
                    i++;
                    j--;
                    qIterations++;
                }
            }

            if (j > low) {
                _qsort(array, low, j);
                qIterations++;
            }

            if (i < high) {
                _qsort(array, i, high);
                qIterations++;
            }
        }
    }

    template<typename T> void bsort(T* array, const unsigned long size) {
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++) {
                bIterations++;
                if (array[i] > array[j])
                    swap(array[i], array[j]);
            }
    }

    template<typename T> void qsort(T* array, const unsigned long size) {
	    _qsort(array, 0, size - 1);
    }
}