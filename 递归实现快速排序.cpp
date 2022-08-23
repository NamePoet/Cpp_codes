// ����Partition���˿������ڿ��������㷨�У�����������ʵ���ڳ���Ϊn�������в��ҵ�k�������

int Partition(int data[], int length, int start, int end)
{
    if (data == nullptr || length <= 0 || start < 0 || end >= length)
        throw new std::exception("Invalid Parameters");
    
    int index = RandomInRange(start, end);           // ��������һ����start��end֮��������
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


// ��һ������Ϊn����������ֻ���start��Ϊ0�� ��end��Ϊn-1�����ú���QuickSort����
void QuickSort(int data[], int length, int start, int end)
{
    if(start == end)
        return;

    int index = Partition(data, length, start, end);
    if(index > start)
        QuickSort(data, length, start, index - 1);       // �ݹ飬ֱ��start == end
    if(index < end)
        QuickSort(data, length, index + 1, end);

} 