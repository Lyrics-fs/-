class ListNode:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None

class LinckedList:
    def __init__(self):
        self.head = ListNode(0)
        self.tail = ListNode(0)
        self.head.next = self.tail
        self.tail.prev = self.head

    def append(self, value):
        new_node = ListNode(value)
        temp = self.tail.prev
        temp.next = new_node
        new_node.prev = temp
        new_node.next = self.tail
        self.tail.prev = new_node

    
    def prepend(self, value):
        new_head = ListNode(value)
        new_head.next = self.head.next
        self.head.next.prev = new_head
        new_head.prev = self.head
        self.head.next = new_head

    def display(self):
        current = self.head.next
        while current is not self.tail:
            print(current.value, end='->')
            current = current.next
        print('None')

    def delete(self, value):
        current = self.head.next

        if current and current.value == value:
            self.head.next = current.next
            current.next.prev = self.head
            current = None
            return 
        
        prev = None
        while current and current.value != value:
            prev = current
            current = current.next
        
        if current is None:
            return
        
        prev.next = current.next
        current.next.prev = prev
        current = None

if __name__ == '__main__':
    ll = LinckedList()
    ll.append(1)
    ll.append(2)
    ll.append(3)
    ll.prepend(0)
    ll.delete(2)
    ll.display()
