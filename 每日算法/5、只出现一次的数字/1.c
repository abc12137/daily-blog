int singleNumber(int* nums, int numsSize) {
    int num=nums[0];
    for(int i=0;i<numsSize-1;i++){
       num=num^nums[i+1];
    }
    return num;
}
