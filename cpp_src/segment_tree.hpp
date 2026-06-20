#pragma once
#include<vector>

template<typename T>
class SegmentTree{ //update in point, query on interval
private:
	int size;
	T neutral_value; //neutral value for given type
	std::vector<T> tree; //bottom nodes from size to size * 2 - 1
public:
	SegmentTree(int _size, T _neutral_val = T()) : size(1), neutral_value(_neutral_val), tree(0) {
		while(size < _size) size *= 2;
		tree.assign(2 * size, neutral_value);
	}
	void add(int _node, T _val) { 
		_node += size;
		tree[_node] += _val;
		_node /= 2;
		while(_node > 0) {
			tree[_node] = tree[_node * 2] + tree[_node * 2 + 1];
			_node /= 2;
		}
	}
	T query(int a, int b) {
		T ans = neutral_value;
		a += size;
		b += size;
		while(a <= b) {
			if(a % 2 == 1) {
				ans += tree[a];
				a++;
			}
			if(b % 2 == 0) {
				ans += tree[b];
				b--;
			}
			a /= 2;
			b /= 2;
		}
		return ans;
	}
};