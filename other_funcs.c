#include "main.h"

/**
 * _rot13 - rotate string by 13, rotation applied only on alphabets
 *
 * @s: array of characters
 * Return: number of char printed;
 */
int _rot13(char *s)
{
	int i = 0;
	char *d;

	if (s == NULL)
		return (write(1, "(null)", 6));
	d = malloc(sizeof(char *) * _strlen(s));
	if (!d)
		return (-1);
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			d[i] = (s[i] - 'a' + 13) % 26 + 'a';
		else if (s[i] >= 'A' && s[i] <= 'Z')
			d[i] = (s[i] - 'A' + 13) % 26 + 'A';
		else
			d[i] = s[i];
		i++;
	}
	return (write(1, d, i));
}
