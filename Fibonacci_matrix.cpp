#include <iostream>
#include <bit>

using numtype = long long int;
//just an alias for the datatype used in this program

void matmul2x2(const numtype* a, const numtype* b, numtype* res);

void matpower2x2(const numtype* a, int n, numtype* res);

//computes matrix product AB
void matmul2x2(const numtype* a, const numtype* b, numtype* res) {
	numtype buffer[4];
	//the internal buffer allows using same array for the input and the result.

	for (int i = 0; i < 4; i++) {
		buffer[i] = a[i & 2] * b[i & 1] + a[(i & 2) + 1] * b[(i & 1) + 2];
		//ugly but short way to represent each element of 2x2 matrix product
	}
	std::copy_n(buffer, 4, res);
}

void matpower2x2(const numtype* a, unsigned int n, numtype* res) {
	if (!n){
		res[0] = 1; res[1] = 0; res[2] = 0; res[3] = 1; //unit matrix
		return;
	}

	unsigned int mask = (unsigned int)(1) << (sizeof(n) * 8 - std::countl_zero(n) - 1);
	//The mask is only 1 bit at the position of the most significant non-zero bit of n initially.
	//It is then right-shifted until the mask reaches 0.
	//It helps to construct the binary tree of operations involved since n is already given in binary.

	//do the first step outside of the loop
	//set res equal to a so that res will be further multiplied by itself
	std::copy_n(a, 4, res);
	mask >>= 1;

	for(; mask; mask >>= 1) {
		matmul2x2(res, res, res);

		if(mask & n){
			matmul2x2(a, res, res);
		}
	}
}

int main(int argc, char *argv[])
{
	numtype* matrix = new numtype[4]{1, 1, 1, 0};
	numtype* result = new numtype[4];
	unsigned int n;

	//reading n
	if(argc > 1){
		n = std::atoi(argv[1]);
	}else{
		std::cin >> n;
	}

	matpower2x2(matrix, n, result);
	//the n'th Fibonacci number is just the top-left element of the result matrix
	std::cout << result[0] << std::endl;
	delete[] matrix;
	delete[] result;
	return 0;
}
