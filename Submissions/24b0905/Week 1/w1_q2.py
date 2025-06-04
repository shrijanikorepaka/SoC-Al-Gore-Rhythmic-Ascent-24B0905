# Implementing stack using array in Python

class stack:
    def _init_(self):
        self.arr =[]
    
    def push(self, val):
        self.arr.append(val)
    
    def pop(self):
        if self.arr:
            return self.arr.pop()
        else:
            print("stack is empty")

    def top(self):
        if self.arr:
            return self.arr[-1]
        raise IndexError("stack is empty")
    
    def is_empty(self):
        return len(self.arr) == 0
    
# Example

s = stack()
s.push(1)
s.push(2)
s.push(3)

print("top: ", s.top()) # Output: top: 3
s.pop()
print("top after pop: ", s.top()) # Output: top: 2