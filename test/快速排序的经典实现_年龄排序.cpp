void SortAges(int ages[], int length)
{
    if(ages == nullptr || length <=0)
        return;

    const int oldestAge = 99;
    int timesOfAge[oldestAge + 1];         // 定义常量整型数组

    for(int i=0; i<=oldestAge; ++i)
        timesOfAge[i] = 0;

    for(int i=0; i<length; ++i)
    {
        int age = ages[i];
        if(age < 0 || age > oldestAge)
            throw new std::exception("age out of range.");
        
        ++timesOfAge[age];        // 桶排序，出现一次对应年龄序号加1
    }

    int index = 0;
    for(int i=0; i<=oldestAge; ++i)
    {
        for(int j=0; j<timesOfAge[i]; ++j)
        {
            ages[index] = i;
            ++index;
        }
    }      // 按年龄从小到大进行排序,eg: 0,0,0, 1, 1, 23,23,23, 25, 25 ,...
}