#include "main.h"
/**
 * PathDirLL - Build A LL Of Path Dir
 * @A_PtrToStruct: Head Node
 *
 * Return: LL
*/
PathDir *PathDirLL(PathDir *A_PtrToStruct)
{
	int i;
	char *str1 = NULL;
	PathDir *new, *last = NULL;

	for (i = 0, str1 = _getenv("PATH"); ; str1 = NULL, i++)
	{
		if (A_PtrToStruct == NULL)
		{
			A_PtrToStruct = malloc(sizeof(PathDir));
			A_PtrToStruct->PtrToStr = strtok(str1, " :");
			A_PtrToStruct->next = NULL;
			continue;
		}
		last = A_PtrToStruct;
		new = malloc(sizeof(PathDir));
		new->PtrToStr = strtok(str1, " :");
		new->next = NULL;
		while ((last->next) != NULL)
		{
			last = last->next;
		}
		last->next = new;
		if (new->PtrToStr == NULL)
		break;
	}
	return (A_PtrToStruct);
}
/**
 * _freeLL - Frees LL
 * @A_PtrToStruct: Head Node
 *
*/
void _freeLL(PathDir *A_PtrToStruct)
{
	PathDir *temp;

	while (A_PtrToStruct->PtrToStr != NULL)
	{
		temp = A_PtrToStruct->next;
		free(A_PtrToStruct);
		A_PtrToStruct = temp;
	}
	free(A_PtrToStruct);
}
