class ListNode:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinckedList:
    def __init__(self):
        self.head = None

    def append(self, value):
        if not self.head:
            self.head = ListNode(value)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = ListNode(value)
    
    def prepend(self, value):
        new_head = ListNode(value)
        new_head.next = self.head
        self.head = new_head

    def display(self):
        current = self.head
        while current:
            print(current.value, end='->')
            current = current.next
        print('None')

    def delete(self, value):
        current = self.head

        if current and current.value == value:
            self.head = current.next
            current = None
            return 
        
        prev = None
        while current and current.value != value:
            prev = current
            current = current.next
        
        if current is None:
            return
        
        prev.next = current.next
        current = None

if __name__ == '__main__':
    ll = LinckedList()
    ll.append(1)
    ll.append(2)
    ll.append(3)
    ll.display()
