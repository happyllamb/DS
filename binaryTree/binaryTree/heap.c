//����С��


//���µ���
void shiftDown(int* arr, int n, int cur)
{
	//�ҵ����ӵ�λ��
	//����
	int child = cur * 2 + 1;
	//�Һ���=����+1
	while (child < n)
	{
		//�����Һ�������һ����С��
		if (child + 1 < n && arr[child + 1] < arr[child])
			child++;
		//�͵�ǰ���ݱȽ�
		//1.����: ����<��ǰ�ڵ����ֵ
		if (arr[child] < arr[cur])
		{
			//��������
			int tem = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tem;

			//����λ��,��������
			cur = child;
			child = cur * 2 + 1;
		}
		else
			//2.������������>=��ǰ�ڵ����ֵ
			break;
	}
}

//���ϵ����㷨
void shiftUp(int* arr, int n, int cur)
{
	//�ҵ����ڵ��λ��
	int parent = (cur - 1) / 2;
	while (cur > 0)   //ֻҪ���Ǹ��ڵ㣬�����븸�ڵ���бȽϣ����ϵ���
	{
		if (arr[cur] < arr[parent])
		{
			int tem = arr[parent];
			arr[parent] = arr[cur];
			arr[cur] = tem;

			//����λ��
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}