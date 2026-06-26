from min_heap import MinHeap

class PriorityQueue():
    def __init__(self):
        self.q = MinHeap()
    
    def __len__(self):
        return(len(self.q))

    def push(self, item, priority: float):
        self.q.insert((priority, item))
        
    def pop(self):
        priority, item = self.q.pop()
        return priority, item