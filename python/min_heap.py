class MinHeap:
    def size(self):
        return len(self.heap)

    def swap_indices(self, a: int, b: int) -> None:
        self.heap[a], self.heap[b] = self.heap[b], self.heap[a]

    def left_child(self, idx: int) -> int:
        return 2 * idx + 1

    def right_child(self, idx: int) -> int:
        return 2 * idx + 2

    def parent(self, idx: int) -> int:
        return (idx - 1) // 2
    
    def heapify_up(self, idx: int) -> None:
        while idx > 0 and self.heap[idx] < self.heap[self.parent(idx)]:
            self.swap_indices(idx, self.parent(idx))
            idx = self.parent(idx)

    def heapify_down(self, idx: int) -> None:
        smallest = idx

        if self.left_child(idx) < self.size() and self.heap[self.left_child(idx)] < self.heap[smallest]:
            smallest = self.left_child(idx)
        if self.right_child(idx) < self.size() and self.heap[self.right_child(idx)] < self.heap[smallest]:
            smallest = self.right_child(idx)

        if idx != smallest:
            self.swap_indices(idx, smallest)
            self.heapify_down(smallest)
    
    def insert(self, val) -> None:
        self.heap.append(val)
        self.heapify_up(self.size() - 1)

    def pop(self) -> int:
        if(not self.heap):
            raise ValueError("Heap is empty")
        
        self.swap_indices(0, self.size() - 1)
        ret = self.heap.pop()

        if self.heap:
            self.heapify_down(0)
        return ret

    def build(self, elements: list) -> None:
        self.heap = elements[:]

        lastNonLeaf = len(elements) // 2
        for i in range(lastNonLeaf, -1, -1):
            self.heapify_down(i)

    def __init__(self, elements: list = None) -> None:
        self.heap = []
        if elements:
            self.build(elements)