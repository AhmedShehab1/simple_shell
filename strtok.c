#include "main.h"
/**
 * _strtok - Function To Tokenize The String Into Words
 * @A_PtrToCommand: String
 *
 * Return: Array Of Tokenized Strings
*/
char **_strtok(char *A_PtrToCommand)
{
	int temp = 0;
	static char  *ArrayOfStrings[10];

	ArrayOfStrings[temp] = strtok(A_PtrToCommand, " :");
	if (ArrayOfStrings[temp] == NULL)
	{
		return (NULL);
	}
	while (ArrayOfStrings[temp] != NULL)
	{
		ArrayOfStrings[++temp] = strtok(NULL, " :");
	}
	return (ArrayOfStrings);
}
/**
 * _exit_ - Terminate The Shell
*/
void _exit_(void)
{
	int status = 0;

	_exit(status);
}
/**
 * PrintEnv - Prints Environment Variables
*/
void PrintEnv(void)
{
	short int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
