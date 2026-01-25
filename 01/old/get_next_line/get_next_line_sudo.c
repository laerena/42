/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:36:58 by leilai            #+#    #+#             */
/*   Updated: 2025/12/04 16:36:58 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

sudo

static stash[MAX_FD];

/*
read(fd, buffer, BUFFER_SIZE) could return?
Number of bytes thats been read could be:
1 / BUFFER_SIZE / 0(EOF reached) / -1(error)
**return exactly BUFFER_SIZE bytes is not guaranteed** as read gives arbitrary chunks
store read content in a stash string **not assume one read = one line**
*/

func gnl(fd)
    if (fd is invalid / BUFFER_SIZE <= 0)
        return (0);
    //fetch current statsh for this fd **one stash per fd**
    current_s = stash[fd]
    //read from fd and update stash until we have enough data
    current_s = readnstash(fd, current_s)
    //if nothing was read or stash is empty - EOF or error
    if (current_s is NULL)
            stash[fd] = NULL
        return NULL
    //extract one line from stash
    line = extract_line(current_s)
    stash[fd] = current_s 
    //return just-extracted line
    return line

func readnstash(fd, stash)
    allocate a buffer with size BUFFER_SIZE + 1
    bytes_read = 1 // start with >0 to enter the loop
    while stash does NOT contain '\n' AND bytes_read > 0
        bytes_read = read up to BUFFER_SIZE bytes from fd into buffer
        if (bytes_read < 0) //read error
            free buffer
            free stash
            return NULL
        if (bytes_read == 0) //EOF reached: stop reading
            break
        add a '\0' at the end of the buffer to treat it as a string
        if (stash is NULL)
            stash = empty string //eg. by duplicating ""
        //create a new string that is stash + buffer
        temp = stash
        stash = join(tmp, buffer)
        free tmp
        if (stash is NULL )//join failed
            free buffer
            return NULL
    free buffer
    //return final stash
    //that has at least one line
    //that has remaining chars
    //that is NULL/empty if nothing ever read
    return stash

func extract_line(stash)
    if (stash is NULL or empty)
        return NULL;

    find index i of the first '\n' in stash
    if ('\n' is found)
        line_len = i + 1;
    else
        line_len = len of stash
    allocate new string "line" of size line_len + 1;

    copy the first line_len chars from stash into line
    add '\0' add the end of line
    return line

func update_s(stash)
    find index i of the first '\n' in stash

    if (no '\n' is found)
        //we never returned the last line, possibly without newline
        //no more left
        free stash
        return NULL
    
    if (something after '\n')
        start_index = i + 1
        remain_len = len_s - start_index

    if remain_len <= 0
        // nothing left after newline
        free stash
        return NULL;

    allocate new string "new_s" of size remain_len + 1
    copy from stash[start_index] to end into new_stash
    add '\0' at end
    free stash
    return new_s
