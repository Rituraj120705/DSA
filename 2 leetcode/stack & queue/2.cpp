class myQueue {

  public:
    int *arr;
    int front;
    int rear;
    int size;
    myQueue(int n) {
        size = n;
        
    }

    bool isEmpty() {
        // check if the queue is empty
    }

    bool isFull() {
        // check if the queue is full
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
    }

    void dequeue() {
        // Removes the front element of the queue.
    }

    int getFront() {
        // Returns the front element of the queue.
    }

    int getRear() {
        // Return the last element of queue
    }
};