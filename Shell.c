#include "main.h"
/**
 * void_MyShell - Normal Mode Of The Shell
 * @A_LinePtr: Pointer To Input String
 * @A_PtrToStruct: LL
 *
*/
void void_MyShell(char *A_LinePtr, PathDir *A_PtrToStruct)
{
	char **argv;
	int Temp;
	pid_t Child_Pid;

	argv = _strtok(A_LinePtr);
	if (argv == NULL)
	{
		return;
	}
	if (!execBuiltInCommands(argv[0]))
	return;
	if (access(argv[0], F_OK))
	{
		argv[0] = HandlePath(argv[0], A_PtrToStruct);
	}
	if (argv[0] != NULL)
	{
		Child_Pid = fork();
		if (Child_Pid == 0)
		{
			Temp = execve(argv[0], argv, environ);
			if (Temp == -1)
			{
				perror(NameOfProgram);
				exit(97);
			}
		}
		else
		{
			wait(&Temp);
		}
	}
	free(argv[0]);
}
