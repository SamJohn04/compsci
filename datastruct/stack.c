#include <stdlib.h>

// The functions here use void * item
// The creation and deletion of the item lies with the caller
// Caller is recommended to use malloc and free on the variables

struct StackItem {
    void * item;
    struct StackItem * next;
};

struct Stack {
    struct StackItem * top;
};

struct Stack new_stack() {
    struct Stack stack = { NULL };
    return stack;
}

int push_stack(struct Stack * stack, void * item) {
    struct StackItem * stack_item = (struct StackItem *)malloc(sizeof(struct StackItem));

    if (stack_item == NULL) {
        // malloc fails
        return 1;
    }

    stack_item->item = item;
    stack_item->next = stack->top;
    stack->top = stack_item;

    return 0;
}

void * pop_stack(struct Stack * stack) {
    struct StackItem * stack_item = stack->top;
    
    if (stack_item == NULL) {
        // stack is empty
        return NULL;
    }

    void * item = stack_item->item;
    stack->top = stack_item->next;
    free(stack_item);

    return item;
}

void delete_stack(struct Stack * stack) {
    // NOT RECOMMENDED unless stack-based items, or items have other usecases.
    // We don't need to free Stack itself since it was not created with malloc.
    // Assumes items have other usecases, or are stack-based
    while (stack->top != NULL) {
        pop_stack(stack);
    }
}
