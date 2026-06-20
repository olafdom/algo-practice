import pytest 
from python_src.min_heap import MinHeap

def test_empty_heap_initialization():
    heap = MinHeap()
    assert heap.size == 0
    assert heap.heap == []

def test_insert_elements():
    heap = MinHeap()
    heap.insert(5)
    heap.insert(3)
    heap.insert(7)

    assert heap.size == 3
    assert heap.heap[0] == 3

def test_pop_elements():
    heap = MinHeap()
    for val in [10, 4, 15, 20, 0]:
        heap.insert(val)
        
    assert heap.pop() == 0
    assert heap.pop() == 4
    assert heap.pop() == 10
    assert heap.size == 2

def test_pop_from_empty_heap_raises_error():
    heap = MinHeap()
    with pytest.raises(ValueError, match="Heap is empty"):
        heap.pop()