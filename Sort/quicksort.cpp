//
// Created by 78540 on 2020/4/20.
//

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int key = arr[left];  //比较点，这是第一个坑，将left位置的value存入key中，坑就出来了
        int i = left, j = right;
        //partion分区
        while (i < j)
        {
            while (arr[j] > key && j > i)	//arr[j] > key可以换为arr[j] >= key，但j > i不可以换为j >= i，边界问题
                j--;
            if (i < j)
                arr[i++] = arr[j];
            while (arr[i] < key && i < j)	//同理
                i++;
            if (i < j)
                arr[j--] = arr[i];
        }
        arr[i] = key;	  //此时不用纠结是arr[i] = key还是arr[j] = key，因为i = j
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}

