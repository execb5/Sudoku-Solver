# Sudoku Solver

This is a Sudoku Solver written in **C**.

I made this ~~to conquer the **world**!~~ because I wanted to train myself more
in the use of **C**. One of the objectives here, is to get **no** warnings when
compiling the project.

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

After compiling the project, all you have to do is to run `./sudoku` in the
terminal, which will not work because you have to pass a sudoku file as
parameter. This file should be in this format:

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

There are 6 examples available and a base file for helping when writing your own
sudoku. Example 2 is the hardest available, taking 19-20s to solve on my
machine. 
