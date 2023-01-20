### 1.bubble_sort（优化版）:
```
package sort;
import java.util.Scanner;
public class bubble_sort
{
	int[] a;
	public bubble_sort()
	{
		int i=0;
		int n;
		Scanner input=new Scanner(System.in);
		System.out.println("请输入数组总数：");
		n=input.nextInt();
		this.a=new int[n];
		System.out.println("请输入数组a：");
		for(i=0;i<n;i++)
		{
			this.a[i]=input.nextInt();
		}
	}
	
	public static void sort(int [] arr){
		   int t;
		   boolean flag;//是否交换的标志
		   for(int i=0; i<arr.length-1; i++){   //表示趟数，一共 arr.length-1 次
		       flag = false;      // 每次遍历标志位都要先置为false，才能判断后面的元素是否发生了交换
		       for(int j=arr.length-1; j>i; j--){ //选出该趟排序的最大值往后移动
		           if(arr[j] < arr[j-1]){
		               t = arr[j];
		               arr[j] = arr[j-1];
		               arr[j-1] = t;    //进行交换
		               flag = true;    //只要有发生了交换，flag就置为true
		           }
		       }
		       if(!flag) break;   // 判断标志位是否为false，如果为false，说明后面的元素已经有序，就直接return
		   }
		}
	
	public void list(int [] arr)
	{
			for(int i=0;i<arr.length;i++)
			{
				System.out.print(arr[i]+"  ");
			}
			System.out.println();
		}
	public static void main(String[] args) {
		bubble_sort A=new bubble_sort();
		System.out.println("输出原数组：");
		A.list(A.a);
		A.sort(A.a);
		System.out.println("输出交换后数组：");
		A.list(A.a);
	}
}
```
**时间复杂度**： ``O(N ^ 2)``	

**空间复杂度**： ``O(1)``			
## 2.insert_sort:
```
public static void  insert_sort(int array[],int lenth){
   int t;
   for(int i=0;i<lenth-1;i++){
       for(int j=i+1;j>0;j--){
           if(array[j] < array[j-1]){    //寻找该数在前面有序部分被插入的部分并插入
               temp = array[j-1];
               array[j-1] = array[j];
               array[j] = temp;
           }else{         //该数最大，不需要交换
               break;
           }
       }
   }
}
```
**平均时间复杂度**： ``O(N ^ 2)``	

**空间复杂度**： ``O(1)``	

## 3.select_sort：
```
public static void select_sort(int array[],int lenth){
   for(int i=0;i<lenth-1;i++){
       int minIndex = i;
       for(int j=i+1;j<lenth;j++){           //找到从i+1到最后的数中的最小值的下标并记录在minIndex中
          if(array[j]<array[minIndex]){
              minIndex = j;
          }
       }
       if(minIndex != i){              //将最小值与第i个数交换
           int temp = array[i];
           array[i] = array[minIndex];
           array[minIndex] = temp;
       }
   }
}
```
**平均时间复杂度**： ``O(N ^ 2)``	

**空间复杂度**： ``O(1)``		

## 4.shell_sort:
```
public static void shell_sort(int array[],int lenth){
   int temp = 0;
   int incre = lenth;
   while(true){
       incre = incre/2;
       for(int k = 0;k<incre;k++){    //根据增量分为若干子序列
           for(int i=k+incre;i<lenth;i+=incre){
               for(int j=i;j>k;j-=incre){
                   if(array[j]<array[j-incre]){   //将每个子序列排序
                       temp = array[j-incre];
                       array[j-incre] = array[j];
                       array[j] = temp;
                   }else{
                       break;
                   }
               }
           }
       }
       if(incre == 1){     //直到子序列步长为1时，数组有序退出循环
           break;
       }
   }
}
```

 **时间复杂度：**：   

shell排序的时间复杂度是根据选中的 ``增量d`` 有关的，所以分析shell排序的时间复杂度是个比较麻烦的事；

在**最优**的情况下，**时间复杂度**为``：O（N*(logN)^2 ）``   （元素已经排序好顺序）		

在**最差**的情况下，**时间复杂度**为：``O（N ^ 2）``；	


**空间复杂度**： ``O(1)``		

## 5.quicksort:
```
public static void quicksort(int a[],int l,int r){
     if(l>=r)   
       return;      
     int i = l; int j = r; int key = a[l];//选择第一个数为key     
     while(i<j){
         while(i<j && a[j]>=key)//从右向左找第一个小于key的值
             j--;
         if(i<j){
             a[i] = a[j];
             i++;
         }
         while(i<j && a[i]<key)//从左向右找第一个大于key的值
             i++;
         if(i<j){
             a[j] = a[i];
             j--;
         }
     }
     //i == j
     a[i] = key;
     quickSort(a, l, i-1);//递归调用
     quickSort(a, i+1, r);//递归调用
 }
 ```
 **平均时间复杂度**： ``O(N*logN)``	

**空间复杂度**： ``O(1)``		

## 6.merge_sort:
```
public static void merge_sort(int a[],int first,int last,int temp[]){
  if(first < last){
      int middle = (first + last)/2;
      merge_sort(a,first,middle,temp);//左半部分排好序
      merge_sort(a,middle+1,last,temp);//右半部分排好序
      mergeArray(a,first,middle,last,temp); //合并
  }
}
```
```
//合并算法
public static void mergeArray(int a[],int first,int middle,int end,int temp[]){    
  int i = first;
  int m = middle;
  int j = middle+1;
  int n = end;
  int k = 0;
  while(i<=m && j<=n){
      if(a[i] <= a[j]){
          temp[k] = a[i];
          k++;
          i++;
      }else{
          temp[k] = a[j];
          k++;
          j++;
      }
  }    
  while(i<=m){
      temp[k] = a[i];
      k++;
      i++;
  }    
  while(j<=n){
      temp[k] = a[j];
      k++;
      j++;
  }
  for(int ii=0;ii<k;ii++){
      a[first + ii] = temp[ii];
  }
}
```
**平均时间复杂度**：``O(NlogN)``	

归并排序的效率是比较高的，设数列长为``N``，将数列分开成小数列一共要``logN``步，每步都是一个合并有序数列的过程，时间复杂度可以记为``O(N)``，故一共为``O(N*logN)``。

**空间复杂度**： ``O(n)``		

归并排序的空间复杂度就是那个临时数组和递归时压如栈的数据占用的空间：``n + logn``。		
##  7.MinHeap_sort:
```
//从i节点开始调整,n为节点总数 从0开始计算 i节点的子节点为 2*i+1, 2*i+2  
public static void MinHeapFixdown(int a[],int i,int n){
   int j = 2*i+1; //子节点
   int temp = 0;
   while(j<n){        //在左右子节点中寻找最小的
       if(j+1<n && a[j+1]<a[j]){  
           j++;
       }
       if(a[i] <= a[j])
           break;   
	//较大节点下移
       temp = a[i];
       a[i] = a[j];
       a[j] = temp;
       i = j;
       j = 2*i+1;
   }
}
```
```
//构建最小堆
public static void MakeMinHeap(int a[], int n){
 for(int i=(n-1)/2 ; i>=0 ; i--){
     MinHeapFixdown(a,i,n);
 }
}
```
```
//堆排序算法
public static void MinHeap_sort(int a[],int n){
  int temp = 0;
  MakeMinHeap(a,n);
  for(int i=n-1;i>0;i--){
      temp = a[0];
      a[0] = a[i];
      a[i] = temp;
      MinHeapFixdown(a,0,i);
  }    
}
```
**平均时间复杂度**：``O(NlogN)``	

由于每次重新恢复堆的时间复杂度为``O(logN)``，共``N - 1``次重新恢复堆操作，再加上前面建立堆时``N / 2``次向下调整，每次调整时间复杂度也为``O(logN)``。二次操作时间相加还是``O(N * logN)``。

**空间复杂度**： ``O(1)``		

## 8.bucket_sort：
```
private void bucket_sort(int[] arr, int bucketSize) throws Exception {
        if (arr.length == 0) {
            return arr;
        }
        int minValue = arr[0];
        int maxValue = arr[0];
        for (int value : arr) {
            if (value < minValue) {
                minValue = value;
            } else if (value > maxValue) {
                maxValue = value;
            }
        }
        int bucketCount = (int) Math.floor((maxValue - minValue) / bucketSize) + 1;
        int[][] buckets = new int[bucketCount][0];
        // 利用映射函数将数据分配到各个桶中
        for (int i = 0; i < arr.length; i++) {
            int index = (int) Math.floor((arr[i] - minValue) / bucketSize);
            buckets[index] = arrAppend(buckets[index], arr[i]);
        }
        int arrIndex = 0;
        for (int[] bucket : buckets) {
            if (bucket.length <= 0) {
                continue;
            }
            // 对每个桶进行排序，这里使用了插入排序
            bucket = insertSort.sort(bucket);
            for (int value : bucket) {
                arr[arrIndex++] = value;
            }
        }
    }
    ```
