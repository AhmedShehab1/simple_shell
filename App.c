#include "main.h"
/**
 * main - Simple Shell Implementation
 * @ac: Number Of Command-Line Arguments
 * @av: Pointer To Command Line Argument
 *
 * Return: Always 0
*/
int main(int ac __attribute__((unused)), char **av)
{
	char *LinePtr = malloc(BUFFER_SIZE);
	size_t LenOfLine;
	ssize_t nread;
	PathDir *Head = NULL;

	Head = PathDirLL(Head);
	NameOfProgram = av[0];
	if (!isatty(STDIN_FILENO))
	{
		nread = read(STDIN_FILENO, LinePtr, BUFFER_SIZE);
		if (nread == -1)
		{
			perror("read");
			exit(96);
		}
		if (LinePtr[0] != '\n')
		LinePtr[nread - 1] = '\0';
		else
		exit(2);
		void_RedirectedCommandInput(LinePtr, Head);
	}
	else
	{
		write(STDOUT_FILENO, "($) ", 4);
		while ((nread = getline(&LinePtr, &LenOfLine, stdin)) != -1)
		{
			if (LinePtr[0] != '\n')
			{
				LinePtr[nread - 1] = '\0';
				void_MyShell(LinePtr, Head);
			}
				write(STDOUT_FILENO, "($) ", 4);
		}
	}
	free(LinePtr);
	_freeLL(Head);
	return (0);
}
