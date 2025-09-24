// Quick Sort

#include <cstdio>
#include <vector>
#include <array>
#include <cstdint>


uint32_t Partition(std::array<int, 7> &Ar, uint32_t bg, uint32_t ed) {
	
	uint32_t pivot = ed;
	uint32_t low  = bg-1;
	
	for(uint32_t idx= bg; idx < ed; ++idx) {
		
		if(Ar.at(idx) < Ar.at(pivot)) {
			low++;
			std::swap(Ar.at(low), Ar.at(idx));
		}
	}
	
	std::swap(Ar.at(low+1), Ar.at(pivot));
	
	return (low+1);

}



void QuickSort(std::array<int, 7> &Ar, uint32_t low, uint32_t high) {

	if(low < high) {
		uint32_t pivot = Partition(Ar, low, high);
	
		QuickSort(Ar, low, pivot-1);
		QuickSort(Ar, pivot+1, high);	
	}
		
}



int main() {
	
	std::array<int, 7> nums = {2, 99, 4, 76, 13, 23, 4};
	uint32_t N = nums.size();
	
	printf("Array before sort: ");
	for(uint32_t idx = 0; idx<N; ++idx) {
		printf("%u\t", nums.at(idx));
	}
	
	
	QuickSort(nums, 0, N-1);
	
	
	printf("\nArray after sort: ");
	for(uint32_t idx = 0; idx<N; ++idx) {
		printf("%u\t", nums.at(idx));
	}
	
	
	return 0;
}