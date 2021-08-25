# Sudoku Solver

This is a Sudoku Solver written in **C**.

I made this because I wanted to learn **C**. One of the objectives here,
was to get **no** warnings when compiling the project.

---

#### Libraries:

The GUI version of this project requires gtk+3.0, but even if you don't have it
on your machine, you can still use the command line version which will compile.

#### How to use this project:

Download and compile:

```zsh
git clone https://github.com/execb5/Sudoku-Solver.git
cd Sudoku-Solver
make
```

This will generate two executables:

* `sudoku`
* `sudokuGUI`(see the [lib](https://github.com/execb5/Sudoku-Solver#libraries)
  section for dependencies)

`sudokuGUI` will open a graphical interface which I believe is self
explanatory.

#### Command Line:

`make sudoku` will compile only the terminal version.

After compiling the project, all you have to do is run `./sudoku` in the
terminal, which will not work because you have to pass a sudoku file as
parameter. The file should be in this format:

This is example 3 (`examples/ex3`)

```
0 0 0 2 0 0 0 6 3
3 0 0 0 0 5 4 0 1
0 0 1 0 0 3 9 8 0
0 0 0 0 0 0 0 9 0
0 0 0 5 3 8 0 0 0
0 3 0 0 0 0 0 0 0
0 2 6 3 0 0 5 0 0
5 0 3 7 0 0 0 0 8
4 7 0 0 0 1 0 0 0
```

Zeroes are blank cells on the board.

Running example 3:

```
$ ./sudoku examples/ex3
examples/ex3
 _____________________________________
|_ _|_ _|_ _||_2_|_ _|_ _||_ _|_6_|_3_|
|_3_|_ _|_ _||_ _|_ _|_5_||_4_|_ _|_1_|
|_ _|_ _|_1_||_ _|_ _|_3_||_9_|_8_|_ _|
|-----------||-----------||-----------|
|_ _|_ _|_ _||_ _|_ _|_ _||_ _|_9_|_ _|
|_ _|_ _|_ _||_5_|_3_|_8_||_ _|_ _|_ _|
|_ _|_3_|_ _||_ _|_ _|_ _||_ _|_ _|_ _|
|-----------||-----------||-----------|
|_ _|_2_|_6_||_3_|_ _|_ _||_5_|_ _|_ _|
|_5_|_ _|_3_||_7_|_ _|_ _||_ _|_ _|_8_|
|_4_|_7_|_ _||_ _|_ _|_1_||_ _|_ _|_ _|
 _____________________________________
|_8_|_5_|_4_||_2_|_1_|_9_||_7_|_6_|_3_|
|_3_|_9_|_7_||_8_|_6_|_5_||_4_|_2_|_1_|
|_2_|_6_|_1_||_4_|_7_|_3_||_9_|_8_|_5_|
|-----------||-----------||-----------|
|_7_|_8_|_5_||_1_|_2_|_6_||_3_|_9_|_4_|
|_6_|_4_|_9_||_5_|_3_|_8_||_1_|_7_|_2_|
|_1_|_3_|_2_||_9_|_4_|_7_||_8_|_5_|_6_|
|-----------||-----------||-----------|
|_9_|_2_|_6_||_3_|_8_|_4_||_5_|_1_|_7_|
|_5_|_1_|_3_||_7_|_9_|_2_||_6_|_4_|_8_|
|_4_|_7_|_8_||_6_|_5_|_1_||_2_|_3_|_9_|
Solved in 0s
-------------------------------------------
-------------------------------------------
```


There are 6 examples available and a base file to help when writing your own.
