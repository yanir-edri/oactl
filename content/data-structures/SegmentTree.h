/**
 * Author: Noam Gutterman
 * Date: 2024-09-13
 * License: CC0
 * Source: own
 * Description: A generic segment tree, 0-indexed, ranges inclusive.
 * Time: O(\log N)
 */

/*
* the struct 'T' must have:
* neutral element (as default constructor)
* operator *, to combine with a right operand and return the result
*/
template<typename T>
struct segtree {
	int n;
	vector<T> t;
	segtree(int sz = 0) : n(max(2, sz)), t(2 * n) {}
	// OPTIONAL FUNCTION: constructor from vector in O(n).
	segtree(const vector<T>& a) : n(max(2, (int)a.size())), t(2 * n) {
		for (int i = 0; i < a.size(); i++) t[i + n] = a[i];
		for (int i = n - 1; i; i--) t[i] = t[2 * i] * t[2 * i + 1];
	}
	void update(int pos, T val) {
		for (t[pos += n] = val; pos /= 2;)
			t[pos] = t[2 * pos] * t[2 * pos + 1];
	}
	T query(int l, int r) { // inclusive [l, r]
		if (l > r) return T();
		T L, R;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) L = L * t[l++];
			if (!(r & 1)) R = t[r--] * R;
		}
		if (l == r) L = L * t[l];
		return L * R;
	}
};
// EXAMPLE: maximum
struct element {
	int val;
	element(int val = -inf) : val(val) {} // val -inf = no effect on max
	element operator * (const element& other) {
		return element(max(val, other.val));
	}
};
