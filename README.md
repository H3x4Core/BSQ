# BSQ

## Tests results

The map creating issue with the software are located in `ìssue_map` folder

|Prefix|meaning			|
|------|----------------|
|ref_* |ref result		|
|res_* |current result	|
|map_* |map				|

----

### Algo issue
3) results/multi_arg_01.txt
	- Algo issue
	- -> test_100
5) results/stdin_04.txt
	- Algo issue
	- -> test_100
	- same as 3)
7) results/test_100_big_sol.txt
	- Algo issue
9) results/test_100.txt
	- Algo issue
	- Same issue than 3)
13) results/test_500.txt
	- Algo issue
	- missing top & left

### Parsing issue
#### Matrix
1) results/bad_2.txt
	- Matrix - Width check
	- Bad length check on last line, before the \0
2) results/bad_6.txt
	- Matrix - Height check
	- Bad height check, if the map has more than the announced lines.
4) results/stdin_01.txt
	- Matrix - EOF
	- parsing issue on stdin, there is no new line/table. Check for \0
10) results/test_1_full.txt
	- Parsing issue only one line, 1 char.
11) results/test_1.txt
	- Parsing issue, same as 10)
15) results/test_hor2.txt
	- matrix
	- -> only one line
16) results/test_hor.txt
	- matrix
	- -> only one line

#### Charset
14) results/test_charset.txt
	- Charset parsing
	- -> only numbers

#### Size issue
6) results/test_10000.txt
	- Buffer/Str Size
	- Variable to store not large enough to store ? (10k x 10k)
12) results/test_5000.txt
	- TOO BIG

#### Unknown need DEBUG
8) results/test_100_empty.txt
	- Parsing issue, I guess.... ? :/ (output is empty)
17) results/test_last_row2.txt
	- matrix
	- ??
	- -> DEBUG
18) results/test_last_row4.txt
	- matrix
	- ??
	- -> DEBUG
19) results/test_vert2.txt
	- matrix
	- only one row
	- -> DEBUG
20) results/test_vert.txt
	- matrix
	- only one row
	- -> DEBUG
 
## Check Leaks !
```shell
==55555== HEAP SUMMARY:
==55555==     in use at exit: 0 bytes in 0 blocks
==55555==   total heap usage: 49 allocs, 49 frees, 1,642 bytes allocated
==55555== 
==55555== All heap blocks were freed -- no leaks are possible
```
