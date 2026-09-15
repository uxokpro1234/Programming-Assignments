public class Program {
    public static void run() {

        Queue queue = new Queue();

        System.out.println("Queue created.");
        System.out.println("Is queue empty? " + queue.IsEmpty());

        System.out.println();

        // Add elements
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);

        System.out.println();

        System.out.println("Queue size: " + queue.count());

        System.out.println();

        // Remove elements
        System.out.println("Removed: " + queue.dequeue());
        System.out.println("Removed: " + queue.dequeue());

        System.out.println();

        System.out.println("Queue size: " + queue.count());
        System.out.println("Is queue empty? " + queue.IsEmpty());

        System.out.println();

        // Add more elements
        queue.enqueue(40);
        queue.enqueue(50);
        queue.enqueue(60);
        queue.enqueue(70);

        System.out.println();

        System.out.println("Queue size: " + queue.count());

        // Try to add when full
        queue.enqueue(80);

        System.out.println();

        // Remove everything
        while (!queue.IsEmpty()) {
            System.out.println("Removed: " + queue.dequeue());
        }

        System.out.println();

        System.out.println("Queue size: " + queue.count());
        System.out.println("Is queue empty? " + queue.IsEmpty());

        queue.destroy();
    }
}
