# implementing queue using array in python
class Queue:
    def __init__(self):
        self.arr = []

    def enqueue(self, val):
        self.arr.append(val)

    def dequeue(self):
        if self.arr:
            self.arr.pop(0)
        else:
            print("Queue Underflow")

    def front(self):
        if self.arr:
            return self.arr[0]
        raise IndexError("Queue is empty")

    def is_empty(self):
        return len(self.arr) == 0

# Example usage
q = Queue()
q.enqueue(10)
q.enqueue(20)
print("Front:", q.front())
q.dequeue()
print("Front after dequeue:", q.front())