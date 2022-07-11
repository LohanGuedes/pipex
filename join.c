#include "pipex.h"

char	*join(const char* s1, const char* s2)
{
	char*	result;

	result = malloc(strlen(s1) + strlen(s2) + 1);
	if (result)
	{
		strcpy(result, s1);
		strcat(result, s2);
	}

	return result;
}
