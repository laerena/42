
### `ls | wc`
take the output of `ls`, feed it as input into `wc`
- `ls` prints all files in the current directory, except for hidden files
```bash
file1
file2
file3
```
- `wc` counts the number of lines, words, and bytes in the files specified by the file parameter
```bash
ls | wc
(count output of ls)
```
- `|` the pipe means `stdout of command 1 -> stdin of command 2`

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

Fork:
```C
pid_t pid = fork();
```
![alt text](image-1.png)

parent & child with the same underlying pipe