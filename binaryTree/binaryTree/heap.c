//假设小堆


//向下调整
void shiftDown(int* arr, int n, int cur)
{
	//找到孩子的位置
	//左孩子
	int child = cur * 2 + 1;
	//右孩子=左孩子+1
	while (child < n)
	{
		//从左右孩子中找一个最小的
		if (child + 1 < n && arr[child + 1] < arr[child])
			child++;
		//和当前数据比较
		//1.调整: 孩子<当前节点的数值
		if (arr[child] < arr[cur])
		{
			//交换数据
			int tem = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tem;

			//更新位置,继续调整
			cur = child;
			child = cur * 2 + 1;
		}
		else
			//2.不调整：孩子>=当前节点的数值
			break;
	}
}