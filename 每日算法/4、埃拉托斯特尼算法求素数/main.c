int countPrimes(int n){
     if(n<=2)
     return 0;
     int count=0;
     int *array=(int *)malloc(sizeof(int)*n);  //创建数组用来储存
     if(array==NULL)  
     return 0;
     for(int i=2;i<n;i++){
        array[i]=1;         //先把所有元素都标记为1
     }
     for(int i=2;i<sqrt(n);i++){        //从2开始向后遍历到sqrt(n)
        if(array[i]==1){              //当前是1的话
            for(int j=2*i;j<n;j+=i)   //当前值的所有倍数都是合数，赋值为0
            array[j]=0;
        }
     }    
    for(int i=2;i<n;i++){
        if(array[i]==1)
        count++;
    }                              //从前往后遍历找，
         free(array);
         return count;
}
