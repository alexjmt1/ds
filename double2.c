#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *HEAD = NULL;

void insert_begin(int item) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Underflow!");
    } else if (HEAD == NULL) {
        ptr->data = item;
        ptr->next = NULL;
        ptr->prev = NULL;
        HEAD = ptr;
    } else {
        ptr->data = item;
        ptr->next = HEAD;
        HEAD->prev = ptr;
        ptr->prev = NULL;
        HEAD = ptr;
    }
}

void insert_last(int item) {
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Underflow!");
    } else if (HEAD == NULL) {
        ptr->data = item;
        ptr->next = NULL;
        ptr->prev = NULL;
        HEAD = ptr;
    } else {
        temp = HEAD;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = NULL;
    }
}

void insert_specified(int item, int location) {
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Underflow!");
    } else if (HEAD == NULL) {
        ptr->data = item;
        ptr->next = NULL;
        ptr->prev = NULL;
        HEAD = ptr;
    } else {
        temp = HEAD;
        for (int i = 0; i < location; i++) {
            if (temp->next == NULL) {
                printf("Insertion is not possible, not enough elements!");
                return;
            }
            temp = temp->next;
        }
        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        ptr->next->prev = ptr;
    }
}

void delete_begin() {
    struct node *ptr;
    if (HEAD == NULL) {
        printf("Empty list, can't perform deletion");
    } else if (HEAD->next == NULL) {
        ptr = HEAD;
        HEAD = NULL;
        free(ptr);
    } else {
        ptr = HEAD;
        HEAD = HEAD->next;
        HEAD->prev = NULL;
        free(ptr);
    }
}

void delete_end() {
    struct node *ptr, *temp;
    if (HEAD == NULL) {
        printf("Empty list, can't delete element");
    } else if (HEAD->next == NULL) {
        ptr = HEAD;
        HEAD = NULL;
        free(ptr);
    } else {
        temp = HEAD;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void delete_specific_location(int location) {
    struct node *ptr, *temp;
    if (HEAD == NULL) {
        printf("Empty list, can't perform deletion");
    } else if (HEAD->next == NULL) {
        ptr = HEAD;
        HEAD = NULL;
        free(ptr);
    } else {
        temp = HEAD;
        for (int i = 0; i < location; i++) {
            if (temp->next == NULL) {
                printf("Deletion is not possible, not enough elements!");
                return;
            }
            temp = temp->next;
        }
        ptr = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(ptr);
    }
}

void display() {
    struct node *temp;
    if (HEAD == NULL) {
        printf("List is empty\n");
    } else {
        temp = HEAD;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, item, location;

    do {
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific location\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a specific location\n");
        printf("7. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                insert_begin(item);
                break;

            case 2:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                insert_last(item);
                break;

            case 3:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                printf("Enter the location: ");
                scanf("%d", &location);
                insert_specified(item, location);
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                printf("Enter the location to be deleted: ");
                scanf("%d", &location);
                delete_specific_location(location);
                break;

            case 7:
                display();
                break;

            case 0:
                printf("Exiting the program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}
/*Algorithm: Doubly Linked List Operations

1. Structure Definition:
   Define a structure 'node' with integer data, a pointer to the previous node ('prev'), and a pointer to the next node ('next').

2. Global Variables:
   Declare a global variable HEAD to store the head of the doubly linked list.

3. Function: insert_begin(item)
   a. Create a new node 'ptr'.
   b. If 'ptr' is NULL, print "Underflow!"
   c. If the list is empty (HEAD is NULL), set data, prev, and next of 'ptr' and set HEAD to 'ptr'.
   d. If the list is not empty, insert 'ptr' at the beginning.

4. Function: insert_last(item)
   a. Create a new node 'ptr'.
   b. If 'ptr' is NULL, print "Underflow!"
   c. If the list is empty (HEAD is NULL), set data, prev, and next of 'ptr' and set HEAD to 'ptr'.
   d. If the list is not empty, traverse to the end and insert 'ptr' at the last.

5. Function: insert_specified(item, location)
   a. Create a new node 'ptr'.
   b. If 'ptr' is NULL, print "Underflow!"
   c. If the list is empty (HEAD is NULL), set data, prev, and next of 'ptr' and set HEAD to 'ptr'.
   d. If the list is not empty, traverse to the specified location and insert 'ptr'.

6. Function: delete_begin()
   a. If the list is empty (HEAD is NULL), print "Empty list, can't perform deletion".
   b. If there's only one node, delete it.
   c. If there are multiple nodes, delete from the beginning.

7. Function: delete_end()
   a. If the list is empty (HEAD is NULL), print "Empty list, can't delete element".
   b. If there's only one node, delete it.
   c. If there are multiple nodes, traverse to the end and delete the last node.

8. Function: delete_specific_location(location)
   a. If the list is empty (HEAD is NULL), print "Empty list, can't perform deletion".
   b. If there's only one node, delete it.
   c. If there are multiple nodes, traverse to the specified location and delete the node.

9. Function: display()
   a. If the list is empty (HEAD is NULL), print "List is empty".
   b. If the list is not empty, traverse and display each node.

10. Main Function:
    a. Initialize variables: choice, item, location.
    b. Display a menu with options 1 to 7 and 0 to exit.
    c. Based on the user's choice, perform the corresponding operation using the functions.
    d. Repeat the process until the user chooses to exit (choice = 0).

11. End Algorithm.
*/
