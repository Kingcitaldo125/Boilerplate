#include <iostream>

struct Node {
  Node() : data(-1), next(nullptr) {}
  explicit Node(int d) : data(d), next(nullptr) {}

  int data;
  Node *next;
};

void traverse(Node *head) {
  auto h = head;

  while (h != nullptr) {
    std::cout << h->data << "\n";
    h = h->next;
  }
}

inline void LinkedListStack() {
  Node head(1);
  Node next(2);
  Node next_next(3);

  head.next = &next;
  next.next = &next_next;

  traverse(&head);
}

inline void LinkedListHeap() {
  Node *head = new Node(1);
  Node *next = new Node(2);
  Node *next_next = new Node(3);

  head->next = next;
  next->next = next_next;

  traverse(head);

  delete next_next;
  delete next;
  delete head;
}

int main() { return 0; }
