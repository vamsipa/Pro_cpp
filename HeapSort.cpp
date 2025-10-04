#include <cstdio>
#include <array>
#include <cstdint>
#include <algorithm>

void heapify(std::array<int32_t, 7>& ar, uint32_t N, uint32_t node) {
	uint32_t larg = node;
	uint32_t left = 2*(node) +1;
	uint32_t right = 2*(node) +2;
	
	if(left < N && ar[left] > ar[larg]) {
		larg = left;
	}
	
	if(right < N && ar[right] > ar[larg]) {
		larg = right;
	}
	
	if(larg != node) {
		std::swap(ar[larg], ar[node]);
		//heapify effected node
        heapify(ar, N, larg);
	}
	
}


void heapSort(std::array<int32_t, 7>& ar, uint32_t N) {
	//Build max Heap
	for(int32_t idx= N/2-1; idx>=0; --idx)	{
		heapify(ar, N, idx);
	}
	
    // Extract max elemen and swap it to last of array and reduce array size to find next max and so on..
    for(uint32_t idx= N-1; idx>0; --idx) {
        //move max element at root of max heap to end of array
	    std::swap(ar[0], ar[idx]);
	
	    heapify(ar, idx, 0);
    }
	
}


int main() {
	std::array<int32_t,7> ar = {32, 0, 2, 99, 5, 87, 77};
	uint32_t N = ar.size();
	
	printf("\nArray before sorting:");
	for(uint32_t idx=0; idx<N; ++idx) {
		printf("\t%d", ar[idx]);
	}
    heapSort(ar, N);
    printf("\nArray after sorting:");
	for(uint32_t idx=0; idx<N; ++idx) {
		printf("\t%d", ar[idx]);
	}
	

	return 0;
}