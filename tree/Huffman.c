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
    s->arr = malloc(INITIALSIZE * sizeof(stack_data_t));
}

void destroy_stack(stack_t *s) {
    s->top = -1;
    free(s->arr);
}

void push(stack_t *s, stack_data_t val) {
    s->arr[++(s->top)] = val;
    if (s->top >= s->maxsize - 1) {
        s->maxsize *= 2;
        s->arr = realloc(s->arr, s->maxsize * sizeof(stack_data_t));
        if (s->arr == NULL) {
            printf("Error reallocating memory!\n");
            exit(1);
        }
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
    entry_t *tree_list = malloc(len * sizeof *tree_list);    
    int i;
    for (i = 0; i < len; i++) {
        node_t* new_node = malloc(sizeof *new_node);
        new_node->data = s[i];
        new_node->left = NULL;
        new_node->right = NULL;
        tree_list[i].wt = weight[i];
        tree_list[i].subtree = new_node;
    }

    // Merge subtrees for n-1 times
    bool *used = malloc(len * sizeof *used);
    memset(used, 0, len * sizeof *used);
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
        node_t *new_node = malloc(sizeof *new_node);
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
        printf("%c:\t", root->data);
        print_stack(s);
        return;
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
    stack_t *code_stack = malloc(sizeof *code_stack);
    init_stack(code_stack);
    
    // Recursively traverse Huffman tree and print encoding results
    inorder(root, code_stack);
    destroy_stack(code_stack);
    free(code_stack);
}

data_t *decode(int code[]) {
    data_t *msg = malloc(1000);
    
    return msg;
}

void encode_file(FILE* f) {
    int char_freq[256];
    double w[256];
    char chars_to_encode[256];
    char c;
    int file_size = 0;
    int num_chars_to_encode = 0;
    int i;

    memset(char_freq, 0, 256 * sizeof(int));
    memset(w, 0, 256 * sizeof(double));
    memset(chars_to_encode, 0, 256);
    while ((c = fgetc(f)) != EOF) {
        char_freq[(int)c]++;
        file_size++;
    }
    
    for (i = 0; i < 256; i++) {
        if (char_freq[i]) {
            chars_to_encode[num_chars_to_encode] = i;
            w[num_chars_to_encode] = char_freq[i] / (double) file_size;
            num_chars_to_encode++;
        }
    }

    printf("Weight\n");
    for (i = 0; i < num_chars_to_encode; i++)
        printf("%c:\t%f\n", chars_to_encode[i], w[i]);

    node_t *huffman_tree = build_huffman_tree(chars_to_encode, w, num_chars_to_encode);
    print_encoding(huffman_tree);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: Huffman <filename>\n");
        exit(1);
    }
    
    FILE* fp = fopen(argv[1], "r");
    encode_file(fp);
    return 0;
}

