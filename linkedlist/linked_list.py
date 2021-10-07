class Node:
    def __init__(self, data):
        self.data=data
        self.next=None

class Linked_List(Node):
    def __init__(self, data):
        self.head = Node(data)

    def insert_head(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
        return self.head

    def insert_end(self, data):
        newNode = Node(data)
        ptr=self.head
        
        while(ptr!=None):
            print(ptr.data)
            ptr = ptr.next

        

    def print_linked_list(self, head):
        ptr=head
        while(ptr!=None):
            print(ptr.data)
            ptr = ptr.next

Ll = Linked_List(4)
head = Ll.insert_head(6)
Ll.print_linked_list(head)