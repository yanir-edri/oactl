/**
 * Author: cp-algorithms.com
 * License: ???
 * Description: Compute the n'th number in gray-code, and compute n given the n'th gray code.
 * Time: $O(1)$ and $O(log(g))$ respectively.
 * Status: In cp-algorithms.com we trust <3
 */
#pragma once

int g(int n) { return n ^ (n >> 1); }
int rev_g(int g) {
	int n = 0;
	for(; g; g >>= 1) n ^= g;
	return n;
}
