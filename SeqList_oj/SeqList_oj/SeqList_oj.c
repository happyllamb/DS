//һ�� ԭ���Ƴ����������е�Ԫ��val��Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)��
//���� nums = [3, 2, 2, 3], val = 3,

//����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��

//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//1.����ָ����������ÿ��ĵ����飬��ԭ�е��������޸ġ�
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
//2.����һ���µ����飬�����ǿռ��ʱ��ʹ�á�
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

//���� ɾ�����������е��ظ��
// ����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
//�������� nums = [1, 1, 2],

//����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2��

//����������i��j�����Ƚ����ݣ�idx����������ݡ�
int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    int j = 1;
    int idx = 0;
    while (j < numsSize) {
        nums[idx++] = nums[i];
        if (nums[i] == nums[j]) {
            //�ҵ�һ�����ظ����ֵ�λ��
            while (j < numsSize && nums[i] == nums[j])
                j++;
            //��i�ŵ�j��λ��
            i = j;
            //j����ƶ���һ��λ��
            j++;
        }
        else {
            i++;
            j++;
        }
    }
    //������һ�����ݺ�ǰ������ݲ�һ���������һ�����ݴ浽idx�� �磺��1,1,2��
    if (i < numsSize) {
        nums[idx] = nums[i];
        idx++;
    }
    return idx;
}
//���� �ϲ������������顣
//�ġ� ��ת���顣Oj����
//�塢 ������ʽ�������ӷ���
