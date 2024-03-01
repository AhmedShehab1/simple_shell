#include "main.h"
/**
 * HandlePath - Handles The PATH
 * @CommandString: Command String
 * @A_PtrToStruct: LL
 *
 * Return: Path Of Command Or NULL If Not Found
*/
char *HandlePath(char *CommandString, PathDir *A_PtrToStruct)
{
	char *result;
	PathDir *temp;

	temp = A_PtrToStruct;
	while (temp->next != NULL)
	{
		/*Concatenate The Command And The Value*/
		result = _strcat(temp->PtrToStr, CommandString);
		/*Use Access Function to check For Existence*/
		if (!(access(result, F_OK)))
		{
			return (result);
		}
		temp = temp->next;
	}
	/*Print Error Message And Prompt New Entry $*/
	/*return NULL Indicating Not Found*/
	perror(NameOfProgram);
	return (NULL);
}
