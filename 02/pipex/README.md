
### `ls | wc`
take the output of `ls`, feed it as input into `wc`

- `ls` prints all files in the current directory, except for hidden files
```bash
file1
file2
file3
```

- the pipe `|` means:
```bash
stdout of command 1 -> stdin of command 2
```

- `wc` counts the number of lines, words, and bytes in the files specified by the file parameter
```bash
ls | wc
(wc counts output of ls)
```

---


### `pfd[0]` vs `pfd[1]`
When you call: 
```C
int pfd[2];
pipe(pfd);
```
- `pfd[0]` -> read end
- `pfd[1]` -> write end

```plain text
write here ---> [ PIPE ] ---> read here
   pfd[1]                      pfd[0]
```

`fork()`
```C
pid_t pid = fork();
```
parent & child with the same underlying pipe:
![alt text](image-1.png)

`dup2()` make newfd point to the same thing as oldfd
```C
dup2(oldfd, newfd);
```

`execve()` replaces the current process with a new program
```C
execve(path, args, envp);
```
