#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    private:
        int items[SIZE];
        int front, rear;

    public:
        Queue() {
            front = -1;
            rear = -1;
        }

        bool isFull() {
            return rear == SIZE - 1;
        }

        bool isEmpty() {
            return front == -1 || front > rear;
        }

        void enqueue(int value) {
            if (isFull()) {
                cout << "Queue is full!" << endl;
            } else {
                if (front == -1) front = 0;  // Set front to 0 when first element is enqueued
                rear++;
                items[rear] = value;
                cout << "Inserted " << value << endl;
            }
        }

        int dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            } else {
                int item = items[front];
                front++;
                return item;
            }
        }

        void display() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
            } else {
                cout << "Queue elements: ";
                for (int i = front; i <= rear; i++) {
                    cout << items[i] << " ";
                }
                cout << endl;
            }
        }
};

class Process {
    private:
        int id, arrivalTime, burstTime;

    public:
        Process() {}

        Process(int id, int arrivalTime, int burstTime) {
            this->id = id;
            this->arrivalTime = arrivalTime;
            this->burstTime = burstTime;
        }
};

int main() {
    int n;
    int id, arrivalTime, burstTime;

    cout << "Enter number of Processes: ";
    cin >> n;

    Process* p = new Process[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time of Process " << (i + 1) << ": ";
        cin >> arrivalTime;

        cout << "Enter burst time of Process " << (i + 1) << ": ";
        cin >> burstTime;

        p[i] = Process(id, arrivalTime, burstTime);
    }

    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if (value != -1)
                    cout << "Dequeued: " << value << endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}