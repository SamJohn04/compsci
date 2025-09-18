#include <stdio.h>

struct Node {
    int value;
    struct Node * left;
    struct Node * right;
};

void pre_order(struct Node * current) {
    if (current == NULL) {
        return;
    }
    printf("%d ", current -> value);
    pre_order(current -> left);
    pre_order(current -> right);
}

void in_order(struct Node * current) {
    if (current == NULL) {
        return;
    }
    in_order(current -> left);
    printf("%d ", current -> value);
    in_order(current -> right);
}

void post_order(struct Node * current) {
    if (current == NULL) {
        return;
    }
    post_order(current -> left);
    post_order(current -> right);
    printf("%d ", current -> value);
}

