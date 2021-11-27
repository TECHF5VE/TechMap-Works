# Task02

## 算法复杂度：

  算法复杂度分为**时间复杂度**和空间复杂度

 **1.时间复杂度**：<u>指执行算法所需要的计算工作量</u>

​       一个算法花费的时间与算法中语句的执行次数成正比例，哪个算法中语句执行次数多，它花费时间就多。一个算法中的语句执行次数称为语句频度或时间频度，记为**T(n)**。

   一般情况下，算法中基本操作重复执行的次数是问题规模n的某个函数，用T(n)表示，若有某个辅助函数f(n)，使得当n趋近于无穷大时，T(n)/f (n)的极限值为不等于零的常数，则称f(n)是T(n)的同数量级函数。记作T(n)=O(f(n))，称O(f(n)) 为算法的渐进时间复杂度，简称时间复杂度

*常见时间复杂度*：

![捕获](C:\Users\Ding Chenkai\Desktop\捕获.PNG)



*对于常见时间复杂度的大小排序：*

 ![捕获2](C:\Users\Ding Chenkai\Desktop\捕获2.PNG)



**2.空间复杂度**：<u>指执行这个算法所需要的内存空间</u>

​    算法的空间复杂度通过计算算法所需的存储空间实现，需要通过额外的辅助空间和问题规模之间的函数关系，算法空间复杂度的计算公式记作:S(n)= O(f(n))，其中，n为问题的规模，f(n)为语句关于n所占存储空间的函数。



## 十大排序：

​                                                      ![捕获3](C:\Users\Ding Chenkai\Desktop\捕获3.PNG)       



### 1.冒泡排序

```
// 冒泡排序
void bubbleSort(vector<int>& array) {
    for (size_t i = 0; i < array.size(); i++) {
        // 当前轮是否发生过交换事件标志位，若未发生交换，则表明列表已有序。
        bool isExchanged = false;
        for (size_t j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                isExchanged = true;
            }
        }
        if (!isExchanged){
            break;
        }
    }
}
```



### 2.选择排序

```
// 选择排序
void selectSort(vector<int>& array){
    for (size_t i = 0; i < array.size(); i++){
        size_t minIndex = i;
        for (size_t j = i + 1; j < array.size(); j++){
            if (array[minIndex] > array[j]){
                minIndex = j;
            }
        }
        if (minIndex != i){
            swap(array[i], array[minIndex]);
        }
    }
}
```



### 3.插入排序

```
// 插入排序
void insertionSort(vector<int>& array){
    // i 代表无序序列首元素（无序序列前为有序序列）
    size_t i = 1;
    while (i < array.size()){
        size_t j = i - 1;
        int itermToInsert = array[i];
        while (j >= 0){
            if (array[j] >= itermToInsert){
                array[j + 1] = array[j];
                j--;
            }
            else{
                break;
            }
        }
        array[j + 1] = itermToInsert;
        i++;
    }
}
```



### 4.希尔排序

```
// 希尔排序
void shellSort(vector<int>& array){
    int n = array.size();
    for (int gap = n / 2; gap >= 1; gap /= 2){
        for (int i = gap; i < n; i++){
            // 使用插入排序算法，将元素依次插入所在小组的已排序列表中
            // 待插入元素
            int itermToInsert = array[i];
            int j = i - gap;
            while (j >= 0 && array[j] >= itermToInsert){
                array[j + gap] = array[j];
                j -= gap;
            }
            array[j + gap] = itermToInsert;
        }
    }
}

```



### 5、归并排序

```
// 归并排序
// 合并两有序序列，两序列分别为array的0到mid部分和mid+1到末尾部分。
void merge(vector<int>& array, vector<int>& copyArray, int left, int right) {
	int mid = (left + right) / 2;
	int i = left, j = mid + 1, k = 0;
	while (i <= mid || j <= right) {
		if (i > mid) {
			copyArray[k] = array[j];
			j++;
		}
		else if (j > right) {
			copyArray[k] = array[i];
			i++;
		}
		else if (array[i] > array[j]) {
			copyArray[k] = array[j];
			j++;
		}
		else {
			copyArray[k] = array[i];
			i++;
		}

        k++;
        }

for (size_t i = left; i <= right; i++) {
	array[i] = copyArray[i - left];
}

}
void mergeSortHelp(vector<int>& array, vector<int>& copyArray, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSortHelp(array, copyArray, left, mid);
		mergeSortHelp(array, copyArray, mid + 1, right);
		merge(array, copyArray, left, right);
	}
}
// 归并排序 递归实现
void mergeSort(vector<int>& array) {
	vector<int> copyArray(array);
	mergeSortHelp(array, copyArray, 0, array.size() - 1);
}

```



### 6.快速排序

```
// 快速排序（递归）
// 选则最左端、最右端和中间位置3元素的中值作为基准值，并将3元素排序，返回基准值
int medianPovit(vector<int>& array, int left, int mid, int right){
    if (array[left] > array[mid]){
        swap(array[mid], array[left]);
    }
    if (array[left] > array[right]){
        swap(array[left], array[right]);
    }
    if (array[mid] > array[right]){
        swap(array[mid], array[right]);
    }
    return array[mid];
}
// 分区,返回基准索引
int partition(vector<int>& array, int left, int right) {
    // 中间位置索引
    int mid = (left + right) / 2;
    // 基准值（此时基准值对应索引为mid）
    int povit = medianPovit(array, left, mid, right);
    // 将基准值与倒数第二个元素交换
    array[mid] = array[right - 1];
    array[right - 1] = povit;

    int i = left, j = right - 1;
    while (i < j) {
        if (array[i] < povit) {
            i++;
        }
        else if (array[j] >= povit) {
            j--;
        }
        else {
            swap(array[i], array[j]);
        }
    }
    // 交换基准值和i位置元素
    swap(array[i], array[right - 1]);
    return i;

}
void quickSortHelp(vector<int>& array, int left, int right) {
    if (left < right) {
        int pivotLoction = partition(array, left, right);
        quickSortHelp(array, left, pivotLoction - 1);
        quickSortHelp(array, pivotLoction + 1, right);
    }
}
// 快速排序
void quickSort(vector<int>& array) {
    quickSortHelp(array, 0, array.size() - 1);
}
```



### 7、堆排序

```
// 堆排序
// 调整堆，根元素沿树向下移动，直至其合适位置，first和last分别为堆顶和堆底在数组array中的索引
void moveDown(vector<int>& array, int first, int last){
    // first的左子节点索引
    int curIndex = first * 2 + 1;
    while (curIndex <= last){
        // 若first有2子节点，令curIndex为其值最大子节点索引
        if (curIndex < last && array[curIndex] < array[curIndex + 1]){
            curIndex++;
        }
        // 若根节点值小于子节点值，则交换
        if (array[first] < array[curIndex]){
            swap(array[first], array[curIndex]);
            first = curIndex;
            curIndex = first * 2 + 1;
        }
        else{
            break;
        }
    }
}
// 用数组实现堆
void buildHeap(vector<int>& array){
    // 最后一个非叶节点的节点索引
    int i = array.size() / 2 - 1;
    while (i >= 0){
        moveDown(array, i, array.size() - 1);
        i--;
    }
}
// 堆排序
void heapSort(vector<int>& array){
    // 生成堆
    buildHeap(array);
    // 堆顶、底索引
    int first = 0, last = array.size() - 1;
    while (first <= last){
        swap(array[first], array[last]);
        last--;
        moveDown(array, first, last);
    }
}
```



### 8.计数排序

```
// 计数排序
void countSort(vector<int>& array){
    if (array.empty()){
        return;
    }
    //找出最大最小值
    int min = array.front(),max = array.front();
    for (int i = 1; i < array.size(); i++){
        if (min > array[i]){
            min = array[i];
        }
        else if (max < array[i]){
            max = array[i];
        }
    }

    // 记录各元素出现次数
    vector<int> counts(max - min + 1);
    for (int i = 0; i < array.size(); i++){
        counts[array[i] - min]++;
    }
    
    // 根据记录的次数输出对应元素
    int index = 0;
    for (int j = 0; j < counts.size(); j++){
        int n = counts[j];
        while (n--){
            array[index] = j + min;
            index++;
        }
    }

}
```



### 9.桶排序

```
// 桶排序
void bucketSort (vector<int>& array, int bucketCount){
    if (array.empty()){
        return;
    }
    // 找出最大最小值
    int max = array.front(), min = array.front();
    for (int i = 1; i < array.size(); i++){
        if (min > array[i]){
            min = array[i];
        }
        else if (max < array[i]){
            max = array[i];
        }
    }

    // 将待排序的各元素分入对应桶中
    vector<vector<int>> buckets(bucketCount);
    int bucketSize = ceil((double)(max - min + 1) / bucketCount);
    for (int i = 0; i < array.size(); i++){
        int bucketIndex = (array[i] - min) / bucketSize;
        buckets[bucketIndex].push_back(array[i]);
    }
    
    // 对各桶中元素进行选择排序
    int index = 0;
    for (vector<int> bucket : buckets){
        if (!bucket.empty()){
            // 使用选择排序算法对桶内元素进行排序
            selectSort(bucket);
            for (int value : bucket){
                array[index] = value;
                index++;
            }
        }
    }

}
// 桶排序
void bucketSort (vector<int>& array){    bucketSort (array, array.size() / 2); }
```



### 10.基数排序

```
// 基数排序 （只适用于正数，此处不适用）
void radixSort(vector<int>& array){
    // 当前位数
    int curdigit = 10;
    // 当前位是否已超过最高为
    bool isOverHighest = false;
    while (!isOverHighest){
        isOverHighest = true;
        // 利用分桶的思想来实现按各位进行排序
        vector<vector<int>> buckets(10);
        for (int curVal : array){
            int bucketIndex = curVal % curdigit - curVal % (curdigit / 10);
            buckets[bucketIndex].push_back(curVal);
            if (isOverHighest && curVal / curdigit){
                isOverHighest = false;
            }
        }
        // 按照桶的顺序，将各桶内元素拼接起来
        int index = 0;
        for (vector<int> bucket : buckets){
            for (int value : bucket){
                array[index] = value;
                index++;
            }
        }
        curdigit *= 10;
    }
}
```

