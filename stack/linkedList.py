class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

class Stack(Node):
    def __init__(self):
        self.head = None

    #To check if Linked list is Empty 
    def IsEmpty(self):
        if(self.head==None):
            return 1
        return 0

    #push element 
    def push(self, data):        
        newNode = Node(data)
        if(self.head):
            newNode.next = self.head
            self.head = newNode
        else:
            self.head = newNode 

    #pop element
    def pop(self):
        if(self.head):
            self.head = self.head.next
    
    #print current list
    def printLL(self):
        current = self.head
        while(current):
            print(current.data)
            current = current.next



stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)
stack.printLL()
print("After invoking pop")
stack.pop()
stack.printLL()
