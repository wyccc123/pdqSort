# pdqSort

这是一个自己写的综合排序的方法，涉及插入排序、快排、堆排序。

## 设计原因
上述三种排序方式在不同情况下各有各的优劣，因此根据不同情况选择合适的排序算法将会有效改善排序速度。

经数据测试可知：
* 插入排序：短序列时排序更快；
* 快速排序：在大部分情况下排序较快，少数情况排序慢；
* 堆排序：排序状况稳定，但在大部分情况下略输于快排。

因此设计如下pdq排序算法，根据不同情况下选择不同排序算法。
```
void pdqSort(vector<int>& vec, int limit) {
    if (vec.size() < 24) return insertSort(vec);
    if (limit == 0) return HeapSort(vec, vec.size() - 1);
    return quickSort(vec, 0, vec.size());
}
```
注：limit为标记点，当序列不适宜用快排时，将limit置零，使用堆排序。