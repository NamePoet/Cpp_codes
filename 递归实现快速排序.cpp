// 函数Partition除了可以用在快速排序算法中，还可以用来实现在长度为n的数组中查找第k大的数字

int Partition(int data[], int length, int start, int end)
{
    if (data == nullptr || length <= 0 || start < 0 || end >= length)
        throw new std::exception("Invalid Parameters");
    
    int index = RandomInRange(start, end);           // 用来生成一个在start和end之间的随机数
    Swap(&data[index], &data[end]);

    int small = start - 1;
    for(index = start; index < end; ++index)
    {
        if(data[index] < data[end])
        {
            ++small;
            if(small != index)
                Swap(&data[index], &data[small]);
        }
    }

    ++small;
    Swap(&data[small], &data[end]);

    return small;
}


// 对一个长度为n的数组排序，只需把start设为0， 把end设为n-1，调用函数QuickSort即可
void QuickSort(int data[], int length, int start, int end)
{
    if(start == end)
        return;

    int index = Partition(data, length, start, end);
    if(index > start)
        QuickSort(data, length, start, index - 1);       // 递归，直到start == end
    if(index < end)
        QuickSort(data, length, index + 1, end);

} 