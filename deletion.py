import random

class Node:
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next
        
class LinkedList:
    def __init__(self):
        self.head = None
        
    def insert_at_beginning(self, data):      
        node = Node(data, self.head)
        self.head = node
        
    def remove_at(self, index):
        
        if index == 0:
            self.head = self.head.next
            
        count = 0
        itr = self.head
        while itr:
            
            if count == index-1:
                itr.next = itr.next.next
            
            itr = itr.next
            count+=1
        
    def remove_greater_than_25(self):
        if self.head is None:
            print('Linked List is Empty!')
        itr = self.head
        count = 0
        while itr:
            if itr.data > 25:
                self.remove_at(count)
            count+=1
            itr = itr.next
            
    def print(self):        
        if self.head is None:
            print('Linked List is Empty!')
        itr = self.head
        while itr:
            print(f"{itr.data} -->", end=' ')
            itr = itr.next
            

ll = LinkedList()
for i in range(50):
    ll.insert_at_beginning(random.randint(1,50))
    
ll.print()
print(end='\n')
ll.remove_greater_than_25()
ll.print()