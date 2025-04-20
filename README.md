# Multithreaded Sudoku Validator

This project is a multithreaded C++ program designed to validate a completed 9x9 Sudoku puzzle.  
It checks whether the Sudoku board satisfies the game's rules across rows, columns, and 3×3 subgrids, using multiple threads for concurrent validation.

---

## 🚀 Features

- Validates Sudoku rows and columns using separate threads.
- Checks each 3×3 subgrid with individual threads.
- Utilizes POSIX threads (`pthread`) for multithreading.
- Protects shared resources with mutex locks.
- Optimized for speed by parallelizing validation tasks.

---

## 🛠️ Technologies Used

- C++ (11 and later)
- POSIX Threads (pthreads)
- Linux / Unix-based systems

---

## 📥 How to Run

### 1. Clone the repository:

```bash
git clone https://github.com/your-username/Sudoku-Solution-Validator
cd Sudoku-Solution-Validator
```

### 2. Compile the program:

```bash
g++ sudoku_validator.cpp -o sudoku_validator -pthread
```

### 3. Run the program:

```bash
./sudoku_validator
```

### 4. Input a 9×9 completed Sudoku board manually.

---

## 📋 Example Input

```
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```

### Expected Output

```
1
```
(1 = Valid Sudoku)

---

## 💬 About the Project

This project was created as part of my operating systems coursework, focusing on practical multithreading concepts.  
The goal was to develop a fast, concurrent Sudoku validator, managing synchronization challenges between threads.  
Each validation task (rows, columns, and each 3×3 subgrid) runs in its own independent thread to achieve maximum concurrency.

---
