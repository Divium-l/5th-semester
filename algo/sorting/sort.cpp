namespace sort {

    namespace {
        void swap(int &a, int &b) {
            int temp = a;
            a = b;
            b = temp;
        }

        void _qsort(int* array, int low, int high) {
            int i = low;
            int j = high;
            int pivot = array[(i + j) / 2];

            while (i < j) {
                while (array[i] < pivot)
                    i++;
                while (array[j] > pivot)
                    j--;

                if (i <= j) {
                    swap(array[i], array[j]);
                    i++;
                    j--;
                }
            }

            if (j > low)
                _qsort(array, low, j);

            if (i < high)
                _qsort(array, i, high);
        }
    }

    void bsort(int* array, const unsigned long size) {
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if (array[i] > array[j])
                    swap(array[i], array[j]);
    }

    void qsort(int* array, const unsigned long size) {
	    _qsort(array, 0, size - 1);
    }
}