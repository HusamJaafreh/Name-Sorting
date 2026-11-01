# Name Sorting in C

A small C program that reads names from a text file, converts them to upper case, sorts them with an exchange (bubble-style) sort, and writes the result to a new file.

![C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)

## What it demonstrates

- File I/O with `fopen` / `fscanf` / `fprintf`
- A two-pass read: count the names first, then allocate a variable-length array
- String handling with `strcpy`, `strcmp` and `toupper`
- An O(n²) in-place exchange sort

## Run it

```bash
gcc sort_names.c -o sort_names
./sort_names            # reads names.txt → writes Sorted_Names.txt
```

Example `names.txt` (included):

```
omar
sara
ahmad
lina
```

Output in `Sorted_Names.txt`:

```
SARA
OMAR
LINA
AHMAD
```

(Names are sorted in descending order. Flip the `> 0` comparison in the sort loop to sort ascending.)

## License

[MIT](LICENSE)
