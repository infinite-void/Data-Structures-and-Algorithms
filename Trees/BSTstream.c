//Author: infinite-void
#include <stdio.h>
#include <stdlib.h>

/* As various textbooks deal with duplicates in different ways. The 3 possible options are
    1. left < root < right (No duplicates)
    2. left <= root < right
    3. left < root <= right
    All 3 implementations to insert are included. Comment and uncomment as required (in insert()) 
    to get required output.
 */

// The basic unit of a tree.
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

/*  Recursive function that goes down the tree to search for given value.
    Terminates at first instance required instance.
 */
void find(Node* rootNode, int value) {
    if(rootNode == NULL) {
        fprintf(stdout, "Value %d could not be found in the BST.\n", value);
        return;
    }

    if(rootNode->data == value) {
        fprintf(stdout, "Value %d found in the BST.\n", rootNode->data);
        return;
    }

    if(rootNode->data > value) 
        return find(rootNode->left, value);

    return find(rootNode->right, value);
}
 
/*  Recursive function that inserts the value at returns rootNode at every level.
 */
Node* insert(Node* rootNode, int value) {
    if(rootNode == NULL) {
        Node* node = (Node*) malloc(sizeof(Node));

        if(node == NULL) {
            fprintf(stderr, "ERROR: Could not allocate memory.");
            exit(1);
        }
        node->data = value;
        node->right = node->left = NULL;
        return node;
    }

    // Only one case must be uncommented and other 2 must be commented or removed.
    //Case 1: Duplicates not allowed. left < root < right
    if(rootNode->data > value) 
        rootNode->left = insert(rootNode->left, value);
    else if(rootNode->data < value)
        rootNode->right = insert(rootNode->right, value);

    //Case 2: left <= root < right
    /*if(rootNode->data >= value) 
        rootNode->left = insert(rootNode->left, value);
    else
        rootNode->right = insert(rootNode->right, value);
    */

    //Case 3: left < root <= right
    /*if(rootNode->data > value) 
        rootNode->left = insert(rootNode->left, value);
    else
        rootNode->right = insert(rootNode->right, value);
    */

    return rootNode;
}

// Recursive traversal function, prints all left nodes, itself and right nodes(output is non decreasing).
void inOrder(Node* rootNode) {
    if(rootNode == NULL) 
        return;

    inOrder(rootNode->left);
    fprintf(stdout, "%d ", rootNode->data);
    inOrder(rootNode->right);
}

// Recursive traversal function, prints itself, left nodes and right nodes.
void preOrder(Node* rootNode) {
    if(rootNode == NULL) 
        return;

    fprintf(stdout, "%d ", rootNode->data);
    preOrder(rootNode->left);
    preOrder(rootNode->right);
}

// Recursive traversal function, prints left nodes, right nodes and itself.
void postOrder(Node* rootNode) {
    if(rootNode == NULL) 
        return;

    postOrder(rootNode->left);
    postOrder(rootNode->right);
    fprintf(stdout, "%d ", rootNode->data);
}



int main(int argc, char* argv[]) {
    Node* rootNode = NULL;
    int i, input, option;
    char* c_input = (char*) malloc(sizeof(char));

    if(argc > 1) {
        for(i = 1; i < argc; i++) {
            input = atoi(argv[i]);
            rootNode = insert(rootNode, input);
        }
    }
    loop:
        fprintf(stdout, "1. find.\n2. insert.\n3. exit\n Enter option : ");
        fgets(c_input, 3, stdin);
        option = atoi(c_input);
        switch(option) {
            case 1: 
                fprintf(stdout, "Enter value : ");
                fgets(c_input, 6, stdin);
                input = atoi(c_input);
                find(rootNode, input);
                break;
            case 2:
                fprintf(stdout, "Enter value : ");
                fgets(c_input, 6, stdin);
                input = atoi(c_input);
                rootNode = insert(rootNode, input);
                break;
            case 3: 
                goto End;
            default:
                fprintf(stderr, "Invalid option");
        }
        goto loop;

    End:
    fprintf(stdout, "InOrder : ");
    inOrder(rootNode);
    fprintf(stdout, "\n");

    fprintf(stdout, "PreOrder : ");
    preOrder(rootNode);
    fprintf(stdout, "\n");

    fprintf(stdout, "PostOrder : ");
    postOrder(rootNode);
    fprintf(stdout, "\n");

    return 0;
}