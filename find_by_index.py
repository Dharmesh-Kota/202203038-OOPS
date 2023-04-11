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
        
    def get_length(self):           
        count = 0
        itr = self.head
        while itr:
            count+=1
            itr = itr.next
        return count
    
    def insert_values(self, data_list):
        self.head = None
        for data in data_list:
            self.insert_at_beginning(data)
            
    def find_element(self, data):
        if self.head is None:
            print('Linked List is Empty!')
            return
        itr = self.head
        count = 1
        while itr:
            if itr.data == data:
                print(count, end='\n')
            itr = itr.next
            count+=1
        
    def print(self):        
        if self.head is None:
            print('Linked List is Empty!')
        itr = self.head
        while itr:
            print(f"{itr.data} -->", end=' ')
            itr = itr.next
            
            

ll = LinkedList()

ll.insert_values([3,2,8,3,7,5,1])
    
ll.print()
print(end='\n')
ll.find_element(7)