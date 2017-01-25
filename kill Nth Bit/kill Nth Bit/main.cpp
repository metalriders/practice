#include <iostream>

int killKthBit(int n, int k) {
	return ((n >> k-1) & 1) ? n- (pow(2,k-1)) : n;
}

void main() {
	std::cout << killKthBit(37, 3);
	getchar();
}