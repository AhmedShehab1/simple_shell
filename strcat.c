#include "main.h"
/**
 * _strcat - Concatenate Two Strings
 * @dest: String 1
 * @src: String 2
 *
 * Return: Pointer To Concatenated String
*/
char *_strcat(char const *dest, char const *src)
{
	int i = 0;
	char *result = malloc(1024);

	while (dest[i] > 0)
	{
		result[i] = dest[i];
		i++;
	}
	result[i++] = '/';
	while (*src != '\n')
	{
		result[i++] = *src;
		src++;
	}
	result[i] = '\0';
	return (result);
}
/**
 * _strcmp - Compares Two Strings
 * @A_Str1: String 1
 * @A_Str2: String 2
 *
 * Return: 0 If Same Otherwise 1
*/
int _strcmp(const char *A_Str1, const char *A_Str2)
{
	int i = 0, j = 0;

	while (A_Str1[i] > 0)
	i++;
	while (A_Str2[j] > 0)
	j++;
	if (i == j)
	{
		i = 0;
		while (A_Str1[i] == A_Str2[i] && A_Str1[i] != '\0')
		i++;
	}
	else
	return (1);
	if (i == j)
	return (0);
	return (1);
}
