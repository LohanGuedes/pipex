#include "pipex.h"

static int	sub_cmd(char *str, char c);
static int	count_cmds(char *str, char c);

char	**ft_splitcmd(char *s, char c)
{
	char	**final;
	int		splits;
	int		offset;
	int		substring;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	offset = 0;
	splits = count_cmds(str, c);
	final = malloc(sizeof(char *) * (splits + 1));
	if (final == NULL)
		return (NULL);
	final[splits] = NULL;
	while (offset < splits)
	{
		while (*str != '\0' && *str == c)
			str++;
		substring = sub_cmd(str, c);
		final[offset++] = ft_substr(str, 0, substring);
		str += substring;
	}
	return (final);
}

static int	count_cmds(char *str, char c)
{
	int	sublen;
	int	splitnum;

	splitnum = 0;
	while (*str != '\0')
	{
		while (*str && *str == c)
			str++;
		sublen = sub_cmd(str, c);
		str += sublen;
		if (sublen)
			splitnum++;
	}
	return (splitnum);
}

static int	sub_cmd(char *str, char c)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != c)
	{
		if(*str == 39)
		{
			str++;
			while(*str != 39)
				str++;
		}
		if(*str == '"')
		{
			str++;
			while(*str != '"')
				str++;
		}
		str++;
		len++;
	}
	return (len);
}
