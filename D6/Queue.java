public class Queue {

    // Maximum queue size
    private static final int MAX_SIZE = 5;

    // Array for storing elements
    private int[] elements;

    // Current number of elements
    private int size;

    // Constructor
    public Queue() {
        elements = new int[MAX_SIZE];
        size = 0;
    }

    // Destructor equivalent
    // Java does not have destructors like C++.
    // This method can be called manually when the object is no longer needed.
    public void destroy() {
        System.out.println("Queue object is being deleted.");
    }


    // Adds an element to the rear of the queue
    public void enqueue(int value) {

        if (size < MAX_SIZE) {
            elements[size] = value;
            size++;

            System.out.println(value + " was added to the queue.");
        } else {
            System.out.println("Queue is full!");
        }
    }

    // Removes an element from the front of the queue
    public int dequeue() {

        if (size == 0) {
            System.out.println("Queue is empty!");
            return -1;
        }

        int value = elements[0];

        // Move all remaining elements one position to the left
        for (int i = 0; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }

        size--;

        return value;
    }

    // Returns the current size of the queue
    public int count() {
        return size;
    }

    // Returns true if the queue is empty
    public boolean IsEmpty() {
        return size == 0;
    }
}
