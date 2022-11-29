namespace sort {

    namespace {
        void swap(int &a, int &b) {
            int temp = a;
            a = b;
            b = temp;
        }
    }

    void bsort(int* array, const unsigned long size) {
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if (array[i] > array[j])
                    swap(array[i], array[j]);
    }

    void qsort(const int* array, const unsigned long size) {
        //do nothing
    }
}