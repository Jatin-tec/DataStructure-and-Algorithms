class Queue:
    def __init__(self, size):
        self.queue=[None]*size
        self.size=size
        self.head= self.tail= -1 

    def isFull(self):
        if self.head<self.tail:
            if self.tail-self.head+1==self.size:
                return True
        elif self.head>self.tail:
            if self.size-self.head+self.tail+1==self.size:
                return True
        return False
    
    def isEmpty(self):
        if self.head == self.tail:
            return True 
        return False   

    def printQueue(self):
        if self.head<self.tail:
            for i in range(self.head, self.tail+1):
                print(self.queue[i])
        else:
            for i in range(self.head, self.size):
                print(self.queue[i])    

            for i in range(0, self.tail+1):
                print(self.queue[i])        

    def inqueue(self, value):
        if not self.isFull():
            if self.head == -1 and self.tail == -1:
                self.head= self.tail= 0
                self.queue[self.tail]=value
 
            else:
                self.tail = (self.size+self.tail+1)%self.size
                self.queue[self.tail]=value
        
        else:
            print('Queue Full!!')

    def dequeue(self):
        if not self.isEmpty():    
            temp=self.queue[self.head]
            self.head = (self.size+self.head+1)%self.size
            return temp
        else:
            print('Empty Queue!!')        

q1 = Queue(3)
print((q1.isEmpty()))  
q1.inqueue(3)  
q1.inqueue(4)  
q1.inqueue(6) 
print((q1.isFull()))    
q1.printQueue() 
q1.dequeue()
q1.inqueue(8)
print('--------------------------')
print((q1.isFull()))    
q1.printQueue() 