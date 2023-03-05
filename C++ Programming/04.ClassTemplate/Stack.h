template <typename T>
class Stack {
    T* buf;
    int top;
    int size;

public:
    Stack(int s);
    ~Stack();

    bool isFull() const;
    bool isEmpty() const;
    void push(const T& a);
    void push(T&& a);
    T&& pop();
};