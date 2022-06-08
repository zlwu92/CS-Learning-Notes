template <typename T>
void Insertion_Sort(T *array, size_t length) {
    if (length <= 1) {
        return;
    } else {
        for (int i = 1; i != length; i++) {
            int j = i - 1;
            T key = array[i];
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
}
/*
冒泡排序是从最底层元素开始比较,(与其上的元素比较) 小于就往上再比,大于就交换,
再用较小的往上比较,直到最高层;第一次把最小的放到最上层,第二次把第二小的放到第二层,以次类推；
*/
template <typename T>
void Bubble_Sort(T *array, size_t length) {
    for (int i = 0; i != length - 1; i++) {
        for (int j = 0; j + i != length - 1; j++) {
            if (array[j] > array[j + 1]) {
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
