class Heap {
  private:
    int size;
    int* heapArray;

    int getParentIndex();
    int getLeftChildIndex();
    int getRightChildIndex();

  public:
    Heap();
    ~Heap();

    int isEmpty();
    void push(int data);
    int pop();
    void top();
};