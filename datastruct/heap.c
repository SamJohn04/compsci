void heapsort(int *, int);

void build_max_heap(int *, int);
void max_heapify(int *, int, int);
int left_child(int);
int right_child(int);

void heapsort(int * a, int heap_size) {
    int n = heap_size;

    build_max_heap(a, heap_size);
    while (heap_size > 1) {
        a[1] ^= a[heap_size];
        a[heap_size] ^= a[1];
        a[1] ^= a[heap_size];
        heap_size--;
        max_heapify(a, heap_size, 1);
    }
}

void build_max_heap(int * a, int heap_size) {
    for (int i = heap_size/2; i >= 1; i--) {
        max_heapify(a, heap_size, i);
    }
}

void max_heapify(int * a, int heap_size, int i) {
    int largest = i, left = left_child(i), right = right_child(i);
    
    if (left <= heap_size && a[left] > a[largest]) {
        largest = left;
    }
    if (right <= heap_size && a[right] > a[largest]) {
        largest = right;
    }

    if (i == largest) {
        return;
    }
    a[i] ^= a[largest];
    a[largest] ^= a[i];
    a[i] ^= a[largest];
    max_heapify(a, heap_size, largest);
}

int left_child(int i) {
    return i * 2;
}

int right_child(int i) {
    return i * 2 + 1;
}

