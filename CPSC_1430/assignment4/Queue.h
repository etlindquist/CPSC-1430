//Queue.h
//Eric lindquist
//11/25/2023

struct QNode{
    int val;
    QNode *next = nullptr;
};

class Queue{
    public:
    Queue();
    ~Queue();
    void enqueue(int);
    int dequeue();
    bool isEmpty();

    private:
    QNode *head = nullptr;
};
