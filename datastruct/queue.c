#include <stdlib.h>

// The functions here use void * item
// The creation and deletion of the item lies with the caller
// Caller is recommended to use malloc and free on the variables

struct QueueItem {
    void * item;
    struct QueueItem * next;
};

struct Queue {
    struct QueueItem * front;
    struct QueueItem * rear;
};

struct Queue new_queue() {
    struct Queue queue = { NULL, NULL };
    return queue;
}

int enqueue(struct Queue * queue, void * item) {
    struct QueueItem * queue_item = (struct QueueItem *)malloc(sizeof(struct QueueItem));
    
    if (queue_item == NULL) {
        // malloc fails
        return 1;
    }

    queue_item->item = item;
    queue_item->next = NULL;
    if (queue->front == NULL) {
        queue->front = queue_item;
        queue->rear = queue_item;
    } else {
        queue->rear->next = queue_item;
        queue->rear = queue_item;
    }

    return 0;
}

void * dequeue(struct Queue * queue) {
    struct QueueItem * queue_item = queue->front;

    if (queue_item == NULL) {
        // queue is empty
        return NULL;
    }

    void * item = queue_item->item;
    queue->front = queue_item->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(queue_item);

    return item;
}

void delete_queue(struct Queue * queue) {
    // NOT RECOMMENDED unless stack-based items, or items have other usecases.
    // We don't need to free Queue itself since it was not created with malloc.
    // Assumes items have other usecases, or are stack-based
    while (queue->front != NULL) {
        dequeue(queue);
    }
}
