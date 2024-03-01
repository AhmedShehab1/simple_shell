#include "main.h"
/**
 * _getenv - Gets An Environment Variable Value
 * @name: Name Of Varible
 *
 * Return: Value Of Environment Variable
*/
char *_getenv(const char *name)
{
	int Counter = 0, CharNo = 0, Flag;

	while (environ[Counter] != NULL)
	{
		while (environ[Counter][CharNo] != '=')
		{
			if (name[CharNo] == environ[Counter][CharNo])
			{
				Flag = 0;
			}
			else
			{
				Flag = 1;
				break;
			}
			CharNo++;
		}
		if (Flag == 0)
		break;
		Counter++;
	}
	if (Flag == 0)
	{
		return (environ[Counter] + (CharNo + 1));
	}
	return (NULL);
}
