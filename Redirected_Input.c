#include "main.h"
/**
 * void_RedirectedCommandInput - Deals With Commands Redirected
 * @Str: Redirected Command String
 * @A_PtrToStruct: LL
*/
void void_RedirectedCommandInput(char *Str, PathDir *A_PtrToStruct)
{
	char **argv;
	int temp;
	pid_t Child_pid;

	argv = _strtok(Str);
	if (argv == NULL)
	return;
	if (!execBuiltInCommands(argv[0]))
	return;
	if (access(argv[0], F_OK))
	{
		argv[0] = HandlePath(argv[0], A_PtrToStruct);
	}
	if (argv[0] != NULL)
	{
		Child_pid = fork();
		if (Child_pid == 0)
		{
			temp = execve(argv[0], argv, environ);
			if (temp == -1)
			{
				perror(NameOfProgram);
				exit(97);
			}
		}
		else
		{
			wait(&temp);
		}
	}
}
