#include<stdio.h>
struct node {
    int data;
    struct node* next;
}node;
void func(struct node* start) {
    if(start == NULL) return;
    printf("%d ", start->data);
    if(start->next != NULL) func(start->next->next);
    printf("%d ", start->data);
}
int main() {
    struct node *root = NULL;
    struct node *cur = root;
    for(int i = 0; i < 6; i++) {
        scanf("%d", &cur->data);
        cur = cur->next;
    }
    func(root);
}