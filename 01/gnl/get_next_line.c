/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:02:25 by leilai            #+#    #+#             */
/*   Updated: 2025/12/11 11:52:23 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_n_stash(int fd, char *stash);
static char *join_n_free(char *stash, char * buffer);
static char *extract_line(char *stash);
static char *update_stash(char *stash);

/*
** get_next_line
** use a static array of stashes, one per fd
** for a given fd:
    * fill its stash with enough data
    * extract one line
    * update the stash with leftover
** return the line, or NULL on EOF/error
*/
char    *get_next_line(int fd)
{
    static char *stash[MAX_FD];
    char    *line;

    //check fd and BUFFER_SIZE validity
    //call read_n_stash(fd, stash[fd]) to fill stash[fd]
    //if stash[fd] is NULL after: return NULL
    //line = extract_line(stash[fd])
    //stash[fd] = update_stash(stash[fd])
    //return line

    if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
        return (NULL);
    stash[fd] = read_n_stash(fd, stash[fd]);
    if (!stash[fd])
        return (NULL);
    line = extract_line(stash[fd]);
    stash[fd] = update_stash(stash[fd]);
    return (line);
}

/*
** read_n_stash
** given an fd and its current stash, read from fd and append to stash until:
    * a new line is found in stash, or
    * read() returns 0 (EOF), or
    * read() returns -1 (error)
** return updated stash, or NULL on error
*/
static char *read_n_stash(int fd, char *stash)
{
    //allocate buffer
    //loop: read into buffer, append to stash, stop on '\n' or EOF or error
    char    *buffer;
    ssize_t bytes;

    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytes = 1;
    while (!ft_strchr(stash, '\n') && bytes > 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0)
            return (free(buffer), free(stash), (char *)NULL);
        if (bytes == 0)
            break ;
        buffer[bytes] = '\0';
        stash = join_n_free(stash, buffer);
        if (!stash)
        return (free(buffer), (char *)NULL);
    }
    free(buffer);
    return (stash);
}
//helper
static char *join_n_free(char *stash, char * buffer)
{
    char    *tmp;

    if (!stash)
        return (ft_strdup(buffer));
    tmp = ft_strjoin(stash, buffer);
    free(stash);
    return (tmp);
}
/*
** extract_line
** given stash, allocate and return the line to give to the caller
    * which is the part from the beginning of the stash up to and includeing 
    the first '\n' (if any), or the whole stash if there is no '\n'
*/
static char *extract_line(char *stash)
{
    //if stash empty - NULL
    //find newline index or end
    //allocate line and copy that slice
    char    *line;
    size_t  i;
    size_t  j;
    
    if (!stash || !stash[0]) 
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        line = malloc(i + 2);
    else
        line = malloc(i + 1);
    if (!line)
        return (NULL);
    j = 0;
    while (j < i)
    {
        line[j] = stash[j];
        j++;
    }
    if (stash[i] == '\n')
        line[j++] = '\n';
    line[j] = '\0';
    return (line);
}

/*
** update_stash
** after extracting a line update stash so it contains 
    only the leftover text (after the line)
** free old stash
** return new stash (or NULL if no leftover)
*/
static char *update_stash(char *stash)
{
    //find newline
    //if no newline: free stash, return NULL
    //else allocate new_stash from after newline
    //free old stash
    //return new_stash
    char    *new_stash;
    size_t  i;
    
    if(!stash)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i] || !stash[i + 1])
    {
        free(stash);
        return (NULL);
    }
    new_stash = ft_strdup(stash + i + 1);
    if (!new_stash)
    {
        free(stash);
        return (NULL);
    }
    free(stash);
    return (new_stash);
}
