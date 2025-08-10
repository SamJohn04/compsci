#include <stdlib.h>

// The functions here use void * item
// The creation and deletion of the item lies with the caller
// Caller is recommended to use malloc and free on the variables

struct DequeItem {
    void * item;
    struct DequeItem * prev;
    struct DequeItem * next;
};

struct Deque {
    struct DequeItem * front;
    struct DequeItem * rear;
};

struct Deque new_deque() {
    struct Deque deque = { NULL, NULL };
    return deque;
}

int enqueue_front(struct Deque * deque, void * item) {
    struct DequeItem * deque_item = (struct DequeItem *)malloc(sizeof(struct DequeItem));

    if (deque_item == NULL) {
        // malloc fails
        return 1;
    }

    deque_item->item = item;
    deque_item->prev = NULL;
    if (deque->front == NULL) {
        deque->front = deque_item;
        deque->rear = deque_item;
        deque_item->next = NULL;
    } else {
        deque_item->next = deque->front;
        deque->front->prev = deque_item;
        deque->front = deque_item;
    }

    return 0;
}

int enqueue_rear(struct Deque * deque, void * item) {
    struct DequeItem * deque_item = (struct DequeItem *)malloc(sizeof(struct DequeItem));

    if (deque_item == NULL) {
        // malloc fails
        return 1;
    }

    deque_item->item = item;
    deque_item->next = NULL;
    if (deque->front == NULL) {
        deque->front = deque_item;
        deque->rear = deque_item;
        deque_item->prev = NULL;
    } else {
        deque_item->prev = deque->rear;
        deque->rear->next = deque_item;
        deque->rear = deque_item;
    }

    return 0;
}

void * dequeue_front(struct Deque * deque) {
    struct DequeItem * deque_item = deque->front;

    if (deque_item == NULL) {
        // deque empty
        return NULL;
    }

    void * item = deque_item->item;
    deque->front = deque_item->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(deque_item);

    return item;
}

void * dequeue_rear(struct Deque * deque) {
    struct DequeItem * deque_item = deque->rear;

    if (deque_item == NULL) {
        // deque empty
        return NULL;
    }

    void * item = deque_item->item;
    deque->rear = deque_item->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(deque_item);

    return item;
}

void delete_deque(struct Deque * deque) {
    // NOT RECOMMENDED unless stack-based items, or items have other usecases.
    while (deque->front != NULL) {
        dequeue_front(deque);
    }
}
