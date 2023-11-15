#include "shell.h"


/**
 * _strchr - Locate char n str.
 *
 * @s: str 2 b searched.
 * @c: char 2 b located.
 *
 * Return: (f c is found) pnter 2 1st occurence, (f c is not found) NULL.
 */
char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index]; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return (NULL);
}


/**
 * _strcpy - Copies the string pointed to by src,
 * including the terminating null byte,
 * to the buffer pointed by des.
 *
 * @dest: Pntr 2 z destin o copied str.
 * @src: Pntr 2 z src o z source str.
 *
 * Return: Pntr 2 dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Concantenates 2 strings.
 *
 * @dest: Pntr 2 z destin o copied str.
 * @src: Pntr 2 z src o z source str.
 *
 * Return: Pntr 2 dest.
 */
char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

/**
 * _strncat - Concantenates 2 strs n no o bytes r cpy from source.
 *
 * @dest: Pntr 2 z destin o copied str.
 * @src: Pntr 2 z src o z source str.
 * @n: byts no 2 cpy from src.
 *
 * Return: Pntr 2 dest.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
