#include "main.h"
/**
 * execBuiltInCommands - Manage Built-In Commands
 * And Execute Them If Found
 * @A_PtrToStr: Input Command
 *
 * Return: If Found 0 Else 1
*/
int execBuiltInCommands(char *A_PtrToStr)
{
	char *BuiltInCommands[5] = {"exit", "env", NULL};
	short int i = 0;

	while (BuiltInCommands[i] != NULL)
	{
		if (!_strcmp(BuiltInCommands[i], A_PtrToStr))
		{
			switch (i)
			{
			case 0:
				_exit_();
				break;
			case 1:
				PrintEnv();
				break;
			}
			break;
		}
		i++;
	}
	if (BuiltInCommands[i] == NULL)
	return (1);
	return (0);
}
