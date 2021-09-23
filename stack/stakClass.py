class Stack():
    def __init__(self):
        self.List = []
        self.top = -1

    def isEmpty(self):
        if self.top == -1:
            return True

    def push(self, element):
        self.List.append(element)
        self.top += 1

    def remove(self, element):
        if(self.isEmpty):
            print("Error: poping empty stack")
        else:
            self.List.pop()
            self.top -= 1

    def peek(self):
        return self.List[-1]           