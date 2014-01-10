/* Huffman.c 
 *   Implementing Huffman encoding and decoding using Huffman tree
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INITIALSIZE 10

typedef char data_t;
typedef int stack_data_t;

struct node {
    data_t data;
    struct node *left;
    struct node *right;
};

typedef struct node node_t; 

typedef struct entry {
    double wt;
    node_t *subtree;
} entry_t;

typedef struct stack {
    int top;
    int maxsize;
    stack_data_t* arr;
} stack_t;

void init_stack(stack_t *s) {
    s->top = -1;
    s->maxsize = INITIALSIZE;
    s->arr = (stack_data_t*) malloc(INITIALSIZE * sizeof(stack_data_t));
}

void destroy_stack(stack_t *s) {
    s->top = -1;
    free(s->arr);
}

void push(stack_t *s, stack_data_t val) {
    s->arr[++(s->top)] = val;
    if (s->top == s->maxsize - 1) {
        s->maxsize *= 2;
        s->arr = (stack_data_t*) realloc(s->arr, s->maxsize);
    }
}

void pop(stack_t *s) {
    if (s->top == -1) {
        printf("pop error: stack is empty!\n");
        exit(1);
    }
    s->top--;
}

stack_data_t top(stack_t *s) {
    if (s->top == -1) {
        printf("top error: stack is empty!\n");
        exit(1);
    }
    return s->arr[s->top];
}

void print_stack(stack_t *s) {
    int i;
    for (i = 0; i <= s->top; i++)
        printf("%d", s->arr[i]);
    printf("\n");
}

node_t *build_huffman_tree(data_t s[], double weight[], int len) {
    // First, build a one-node tree for each data_t and save in an array
    entry_t *tree_list = (entry_t*) malloc(len * sizeof(entry_t));    
    int i;
    for (i = 0; i < len; i++) {
        node_t* new_node = (node_t*) malloc(sizeof(node_t));
        new_node->data = s[i];
        new_node->left = NULL;
        new_node->right = NULL;
        tree_list[i].wt = weight[i];
        tree_list[i].subtree = new_node;
    }

    // Merge subtrees for n-1 times
    bool *used = (bool*) malloc(len * sizeof(bool));
    memset(used, 0, len * sizeof(bool));
    int final_index;
    for (i = 0; i < len - 1; i++) {
        double min1 = 2.0, min2 = 2.0;
        int index1, index2;
        int j;
        for (j = 0; j < len; j++) {
            if (!used[j] && tree_list[j].wt < min1) {
                index1 = j;
                min1 = tree_list[j].wt;
            }
        }
        used[index1] = true;
        for (j = 0; j < len; j++) {
            if (!used[j] && tree_list[j].wt < min2) {
                index2 = j;
                min2 = tree_list[j].wt;
            }
        }
            
        // Merge entry at index2 to entry at index1
        tree_list[index2].wt = min1 + min2;
        node_t *new_node = (node_t*) malloc(sizeof(node_t));
        new_node->left = tree_list[index1].subtree;
        new_node->right = tree_list[index2].subtree;
        tree_list[index2].subtree = new_node;
    
        final_index = index2;
    }

    node_t *tree = tree_list[final_index].subtree;
    free(tree_list);
    free(used);
    return tree;
}

void inorder(node_t *root, stack_t *s) {
    if (root == NULL) 
        return;
    if (root->left == NULL && root->right == NULL) {
        printf("%c: \t", root->data);
        print_stack(s);
    }
    if (root->left != NULL) {
        push(s, 0);
        inorder(root->left, s);
        pop(s);
    }
    if (root->right != NULL) {
        push(s, 1);
        inorder(root->right, s);
        pop(s);
    }
}

void print_encoding(node_t *root) {
    stack_t *code_stack = (stack_t*) malloc(sizeof(stack_t));
    init_stack(code_stack);
    
    // Recursively traverse Huffman tree and print encoding results
    inorder(root, code_stack);
    destroy_stack(code_stack);
}

data_t *decode(int code[]) {
    data_t *msg = (data_t*) malloc(1000);
    
    return msg;
}

int main(int argc, char *argv[]) {
    char c[] = "abcdef";
    double w[] = {0.3, 0.2, 0.2, 0.15, 0.1, 0.05};
    node_t *huffman_tree = build_huffman_tree(c, w, 5);
    print_encoding(huffman_tree);

    return 0;
}

