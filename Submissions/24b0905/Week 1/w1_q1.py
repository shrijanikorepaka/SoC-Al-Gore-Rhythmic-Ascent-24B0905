# Implementing vector using array in Python
class vector:
    def _init_ (self):
        self.arr =[]

    def push_back(self, val):
        self.arr.append(val)

    def pop_back(self):
        if self.arr:
            self.arr.pop()

    def get(self, index):
        if 0 <= index < len(self.arr):
            return self.arr[index]
        raise IndexError("Index out of range")
    
    def size(self):
        return len(self.arr)
    
    def print(self):
        print(self.arr)

# Example
vec = vector()

vec.push_back(1)
vec.push_back(2)
vec.push_back(3)

vec.print()  

vec.pop_back()
vec.print()

print("Element at index 1 is:", vec.get(1))
print("Size of vector is:", vec.size())
    
