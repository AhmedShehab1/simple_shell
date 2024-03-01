#include "main.h"
/**
 * _freeLL - Frees Linked List
 * @A_PtrToStruct: Linked List To Be Freed
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
