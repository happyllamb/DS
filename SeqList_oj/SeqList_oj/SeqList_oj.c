//一、 原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)。
//给定 nums = [3, 2, 2, 3], val = 3,

//函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

//你不需要考虑数组中超出新长度后面的元素。
//1.两个指针遍历，不用开心的数组，在原有的数组中修改。
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int dex = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[dex] = nums[i];
            dex++;
        }
    }
    return dex;
}
//2.开辟一个新的数组，不考虑空间的时候使用。
int removeElement(int* nums, int numsSize, int val) {
    int* tem = (int*)malloc(sizeof(int) * numsSize);
    int i = 0;
    int j = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            tem[j] = nums[i];
            j++;
        }
    }
    memcpy(nums, tem, sizeof(int) * j);
    return j;
}

//二、 删除排序数组中的重复项。
// 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//给定数组 nums = [1, 1, 2],

//函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。

//三个变量，i和j用来比较数据，idx用来存放数据。
int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    int j = 1;
    int idx = 0;
    while (j < numsSize) {
        nums[idx++] = nums[i];
        if (nums[i] == nums[j]) {
            //找第一个非重复数字的位置
            while (j < numsSize && nums[i] == nums[j])
                j++;
            //把i放到j的位置
            i = j;
            //j向后移动给一个位置
            j++;
        }
        else {
            i++;
            j++;
        }
    }
    //如果最后一个数据和前面的数据不一样，把最后一个数据存到idx中 如：【1,1,2】
    if (i < numsSize) {
        nums[idx] = nums[i];
        idx++;
    }
    return idx;
}
//三、 合并两个有序数组。
//四、 旋转数组。Oj链接
//五、 数组形式的整数加法。
