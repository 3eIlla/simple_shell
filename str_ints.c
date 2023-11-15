#include "shell.h"



/**
 * _strlen - Returns length o str.
 *
 * @s: pontr 2 z char str.
 *
 * Return: length o char str.
 */
int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}


/**
 * _strspn - Gets the length of a prefix substring.
 *
 * @s: str 2 b searched.
 * @accept: The prefix 2 b measured.
 *
 * Return: bytes no n s which consist only o bytes from accept.
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}

/**
 * _strcmp - Compare 2 str.
 *
 * @s1: 1st str 2 b compared.
 * @s2: 2nd str 2 b compared.
 *
 * Return: (Positive difference) f s1 > s2
 *         (0) f s1 = s2
 *         (Negative difference) f s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - Compare two strings.
 *
 * @s1: Pointer 2 str.
 * @s2: Pointer 2 str.
 * @n: 1st n bytes o str 2 compare.
 *
 * Return: (Less than 0) f s1 s shorter than s2.
 *         (0) f s1 & s2 match.
 *         (Greater than 0) f s1 s longer than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
