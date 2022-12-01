# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/resource.h>
# include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
    size_t i;
    size_t j;


}

char *get_nextline(int fd)
{
    static char *stash;
    char        *line;

    if (fd <= 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = read_to_stash(stash, fd);
    if (!stash)
        return (NULL);
    line = stash_to_line(stash);
    stash = clean_stash(str);
    return (line);
}

char *read_to_stash(char *stash, int fd)
{
    char *buf;
    int readed;

    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    readed = 1;
    while (!found_new_line(stash, '\n') && readed != 0)
    {
        readed = read(fd, buf, BUFFER_SIZE)
        if (readed == -1)
        {
            free(buf)
            return (NULL);
        }
        buf[readed] = '\0';
        stash = ft_strjoin(stash, buf);
    }
    free(buf);
    return (stash);
}

char *stash_to_line(char *stash)
{
    int i;
    char *str;

    if (!stash[i])
		return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    str = malloc(sizeof(char) * i + 2);
    if (!str)
		return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        str[i] = stash[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *clean_stash(char *stash)
{
    char *str;
    int i;
    int j;

    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
    str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1))
    if (!str)
		return (NULL);
    i++;
    j = 0;
    while (stash[i])
    {
        str[j++] = stash[i++];
    }
    str[j] = '\0';
    free(stash);
    return (str);
}