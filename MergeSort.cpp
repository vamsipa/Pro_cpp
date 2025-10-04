#include <cstdio>
#include <array>
#include <vector>
#include <cstdint>


void Merge(std::array<int, 7>& nums, uint32_t low, uint32_t mid, uint32_t high) {
    
    uint32_t N1 = mid-low+1;
    uint32_t N2 = high-mid;

    std::vector<int> nums1;
    std::vector<int> nums2;

    for(uint32_t idx=0; idx < N1; ++idx)
    {
        nums1.push_back(nums.at(low+idx));
    }
    
    for(uint32_t idx=0; idx < N2; ++idx)
    {
        nums2.push_back(nums.at(mid+1+idx));
    }

    uint32_t idx1 = 0;
    uint32_t idx2 = 0;
    while(idx1 < N1 && idx2 < N2 ) {
        
        if(nums1[idx1] < nums2[idx2]) {
            nums[low] = nums1[idx1];
            idx1++;
        } else {
            nums[low] = nums2[idx2];
            idx2++;
        }

        low++;
    }

    while(idx1 < N1) {
        nums[low] = nums1[idx1];
        idx1++;
        low++;
    }

    while(idx2 < N2) {
        nums[low] = nums2[idx2];
        idx2++;
        low++;
    }

    return;
}


void MergeSort(std::array<int, 7>& nums, uint32_t low, uint32_t high) {
    if(low < high) {
        uint32_t mid = low + (high-low)/2;
        
        MergeSort(nums, low, mid);
        MergeSort(nums, mid+1, high);

        Merge(nums, low, mid, high);
    }
}



int main() {

    std::array<int, 7> nums = {38, 27, 43, 3, 9, 82, 10};
    uint32_t N = nums.size();

    printf("\n Array before sorting:");
    for(uint32_t idx =0; idx < N; ++idx) {
        printf("%d \t", nums.at(idx));
    }

    //sorting
    MergeSort(nums, 0, N-1);


    printf("\n Array after sorting:");
    for(uint32_t idx =0; idx < N; ++idx) {
        printf("%d \t", nums.at(idx));
    }
    
    return 0;
}
