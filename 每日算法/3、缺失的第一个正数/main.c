int firstMissingPositive(int* nums, int numsSize) {
      for(int i=0;i<numsSize;i++){ 
        while(nums[i]<=numsSize&&nums[i]>0&&nums[i]!=nums[nums[i]-1])
        {   //当nums[i]在符合的范围内时、把其放在正确的位置
        //同时交换的数也要符合时也要放在相同位置，直到nums[i]符合时
            int temp=nums[i];     //交换nums[i]和nums[nums[i]-1]的值
            nums[i]=nums[nums[i]-1];    //把nums[nums[i]-1]赋值给nums[i]
            nums[temp-1]=temp;  //  尤其注意此时num[i]已经改变，后面有关原始num[i]的变量都要用temp替代
            }
        }
      
      
      for(int i=0;i<numsSize;i++ ){
           if(nums[i]!=i+1)
            return i+1;
      }

      return numsSize+1;
}
