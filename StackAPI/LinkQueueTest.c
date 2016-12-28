#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkQueue.h"

int main()
{
	int i = 0;
	int a[10];
	LinkQueue *queue = LinkQueue_Create();
	if (queue == NULL)
	{
		return -1;
	}

	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		LinkQueue_Append(queue, &a[i]);
	}

	printf("LinkQueue_Length:%d\n", LinkQueue_Length(queue));
	printf("LinkQueue_Header:%d\n", *((int *)LinkQueue_Header(queue)));

	while (LinkQueue_Length(queue) > 0)
	{
		int ret = *((int *)LinkQueue_Retrieve(queue));
		printf("ret:%d", ret);
	}

	LinkQueue_Destroy(queue);
	system("pause");
	return 0;
}