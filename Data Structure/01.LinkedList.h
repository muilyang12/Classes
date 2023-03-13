class Node {
  int data;
  Node* nextNode;
}

class LinkedList {
  private:
    Node* head;
    Node* tail;

  public:
    LinkedList();
    LinkedList(int data);

    Node* getHead();

    void appendNode(int data);
    void insertNode(int data, int sequence);
    void deleteNode(int sequence);
    void display(Node* start);
}