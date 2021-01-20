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
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 有足够的空间（空间大小等于 m + n）来保存 nums2 中的元素。

//输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3

//输出：[1, 2, 2, 3, 5, 6]

//1. 不考虑空间时，新开辟一个数组存储数据。
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* nums3 = (int*)malloc(sizeof(int) * (m + n));
    int i = 0, j = 0, idx = 0;
    //遍历两个数组
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            nums3[idx] = nums1[i];
            idx++, i++;
        }
        else {
            nums3[idx] = nums2[j];
            idx++, j++;
        }
    }
    //检查是否有剩余元素
    if (i < m) {
        memcpy(nums3 + idx, nums1 + i, sizeof(int) * (m - i));
    }
    if (j < n) {
        memcpy(nums3 + idx, nums2 + j, sizeof(int) * (n - j));
    }
    memcpy(nums1, nums3, sizeof(int) * (m + n));
    free(nums3);
}

//2. 不开辟新的空间，在nums1上进行处理
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int idx = m + n - 1;
    //同时遍历：从后向前，先存放大的元素
    while (i >= 0 && j >= 0) {
        if (nums1[i] <= nums2[j]) {
            nums1[idx] = nums2[j];
            idx--, j--;
        }
        else {
            nums1[idx] = nums1[i];
            i--, idx--;
        }
    }
    //检查是否有剩余元素
    if (j >= 0)
    {
        memcpy(nums1, nums2, sizeof(int) * (j + 1));
    }
}
//四、 旋转数组。
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数
//输入: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
//解释 :
    //向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
    //向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
    //向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]

//逆转函数
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int tem = nums[end];
        nums[end] = nums[start];
        nums[start] = tem;
        end--;
        start++;
    }
}
void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}
//五、 数组形式的整数加法。
//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1, 2, 3, 1]。

//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。
//输入：A = [1, 2, 0, 0], K = 34
//输出：[1, 2, 3, 4]
//解释：1200 + 34 = 1234

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    //获取数字k的长度
    int tem = K;
    int len = 0;
    while (tem) {
        len++;
        tem /= 10;
    }
    int arrLen = len > ASize ? len + 1 : ASize + 1;
    int* ret = (int*)malloc(sizeof(int) * arrLen);
    //从个位开始想相加
    int end = ASize - 1;
    //上一步的进位
    int step = 0;
    int idx = 0;
    while (end >= 0 || K > 0)
    {
        //每一位的结果 就是进位 + 对应位的值
        //首先加进位的值
        int curRet = step;
        if (end >= 0)
            curRet += A[end];
        if (K > 0)
            curRet += K % 10;
        //处理进位
        if (curRet > 9) {
            step = 1;
            curRet -= 10;
        }
        else
            step = 0;
        //保存当前位的结果：逆序存放
        ret[idx++] = curRet;
        end--;
        K /= 10;
    }
    //处理最高位的进位
    if (step == 1)
        ret[idx++] = 1;
    int start = 0;
    end = idx - 1;
    while (start < end) {
        tem = ret[end];
        ret[end] = ret[start];
        ret[start] = tem;
        start++, end--;
    }
    //保存结果的长度
    *returnSize = idx;
    return ret;
}


