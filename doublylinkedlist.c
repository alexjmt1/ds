#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void addNode(int data) {
  Node* newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

void deleteNode(int data) {
  Node* current = head;
  while (current != NULL) {
    if (current->data == data) {
      if (current == head) {
        head = current->next;
        if (head != NULL) {
          head->prev = NULL;
        }
      } else if (current == tail) {
        tail = current->prev;
        tail->next = NULL;
      } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
      }
      free(current);
      break;
    }
    current = current->next;
  }
}

void displayList() {
  Node* current = head;
  printf("[");
  while (current != NULL) {
    printf("%d", current->data);
    if (current->next != NULL) {
      printf(", ");
    }
    current = current->next;
  }
  printf("]\n");
}

int main() {
  int r;
  while (1) {
    printf("1 for insertion, 2 for deletion, 3 for display, 0 to exit: ");
    scanf("%d", &r);

    switch (r) {
      case 1:
        printf("Enter the element to be added: ");
        int m;
        scanf("%d", &m);
        addNode(m);
        printf("List after adding nodes: ");
        displayList();
        printf("\n");
        break;

      case 2:
        printf("Enter the element to be deleted: ");
        scanf("%d", &m);
        deleteNode(m);
        printf("List after deleting %d: ", m);
        displayList();
        printf("\n");
        break;

      case 3:
        printf("List: ");
        displayList();
        printf("\n");
        break;

      case 0:
        exit(0);

      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}
