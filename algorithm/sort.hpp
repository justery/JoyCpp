/**************************
 * bible sort  O(n^2)     *
 *************************/
void bible_sort(int array[], int len)
{
	for (int j = 0; j < len - 1; ++j)
	{
		for (int i = 0; i < len - 1 - j; ++i)
		{
			if (array[i] > array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + i] = temp;
			}
		}
	}
}

/**************************
 * select sort O(n^2)     *
 *************************/
void select_sort(int array[], int len)
{
	int minIndex = 0;
	for (int i = 0; i < len; ++i)
	{
		minIndex = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		// Let's swap array[i] and array[minIndex]
		{
			int temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}

/**************************
 * quick sort O(n*log2^n) *
 *************************/
int partition(int array[], int b, int e)
{
	int mid = array[b];
	while (b < e)
	{
		while (b < e && array[e] >= mid)
			--e;
		array[b] = array [e];

		while (b < e && array[b] <= mid)
			++b;
		array[e] = array[b];
	}

	array[b] = mid;
	return b;
}

//Recursive version
void quick_sort(int array[], int b, int e)
{
	if (b >= e)
		return;

	int seperator = partition(array, b, e);
	quick_sort(array, b, seperator - 1);
	quick_sort(array, seperator + 1, e);
}

//Non-recursive version of quick sort based on stack solution. 
#include <stack>
void quick_sort_non_recursivly(int array[], int b, int e)
{
	using BeginEndTag = std::pair<int, int>;
	std::stack<BeginEndTag> stack;
	stack.emplace(BeginEndTag{b, e});

	while (!stack.empty())
	{
		auto currentTag = stack.top();
		stack.pop();

		auto seperator = partition(array, currentTag.first, currentTag.second);
		if (seperator + 1 < currentTag.second)
			stack.emplace(seperator + 1, currentTag.second);

		if (currentTag.first < seperator - 1)
			stack.emplace(currentTag.first, seperator - 1);
	}
}

