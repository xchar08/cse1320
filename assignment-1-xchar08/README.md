# CSE 1320 Assignment 1

This assignment will review CSE1310 concepts.
Specifically, it reviews
- variables
- loops
- functions
- arrays
- file I/O

Each problem should be completed in order as they are dependent on each other.
As you complete each one, you will slowly be building a larger program.

## (20 points) Problem 1

Create a program that computes the sum of all integers, under $n$, divisible by $a$ and $b$.
Prompt the user to enter 3 integers.
The first integer will serve as $n$ with the following 2 used as $a$ and $b$, respectively.
Print the number on a new line, as shown in the example run.

Save your code as `compute_sums.c`.
Add and commit it to your local repository then push it to the remote repo.

### Grading
- (16 points) Passes tests after pushing code to the remote repo.
- (4 points) Reserved for consistent code formatting.

**Example Run**
```
Enter three integers: 10 3 5
23
```

## (20 points) Problem 2

Create a function `read_monster` that reads in information about a monster from the user and stores it in memory using arrays.
A monster has the following properties (included is the type of variable needed to store it):
- name - string (2D `char` array)
- type - string (2D `char` array)
- hit points (HP) - `int` array
- armor class (AC) - `int` array
- strength (STR) - `int` array
- dexterity (DEX) - `int` array
- constitution (CON) - `int` array

The function should take as input 8 arguments.
The first 7 are for the properties listed above.
The last argument depicts the current number of monsters loaded into memory.
This function should return an `int` depicting the number of monsters now loaded after reading the new data.
If the number of monsters given by `num_monsters` is already at the limit, return `num_monsters`.
Otherwise return `num_monsters + 1`.
Write the function definition in a file named `monster_utils.c` with the corresponding declaration in `monster_utils.h`.

Your program should support up to 32 monsters total.
Strings should be no more than 64 characters each.
These values should not be hard-coded, use `#define`.

Create a file named `read_monsters.c` which includes `monster_utils.h`.
In `main`, create 8 variables for the 8 parameters of the function above and call your function once.
After the data is read in the function call, print the values at index 0 as show in the example run below.
Add and commit your files to your local repository then push them to the remote repo.

The remaining 12 points are determined by whether or not your program passes the automatic tests.

### Grading
- (12 points) Passes tests after pushing code to the remote repo.
- (4 points) Use `#define` for max monsters and string length constants.
- (4 points) Reserved for consistent code formatting.

**Example Run**
```
Enter a name: Goblin
Enter a type: Humanoid
Enter HP: 18
Enter AC: 10
Enter STR: 5
Enter DEX: 4
Enter CON: 3
Goblin (Humanoid), 18 HP, 10 AC, 5 STR, 4 DEX, 3 CON
```

## (20 points) Problem 3

Create a program that writes monster data in memory to a CSV file.
First, create a function named `write_monsters` which takes as input 9 arguments.
The first 8 arguments are the same as the previous problem.
The last parameter of this function should be a file name (`char` array).
Write the function definition in `monster_utils.c` with the corresponding declaration in `monster_utils.h`.

The function should attempt to open a new file for writing given by the file name.
If the file cannot be opened, your function should return 1.

The function should loop through all monsters in memory and write each one as a line of CSV data to the file.
For example, if the user used the input from the example run of problem 2, this function would write
`Goblin,Humanoid,18,10,5,4,3`.

Test your program by creating a file named `write_monster.c`.
In `main`, read in data for one monster by calling the function `read_monster`.
Prompt the user to enter a file name and then pass the appropriate data to `write_monsters`.
It should then write the data to a file given by the file name.
The program should follow the formatting as seen in the example run.

Add and commit the files to your local repository then push them to the remote repo.

### Grading
- (16 points) Correctly writes input to file.
- (4 points) Reserved for consistent code formatting.

**Example Run**
```
Enter a name: Goblin
Enter a type: Humanoid
Enter HP: 18
Enter AC: 10
Enter STR: 5
Enter DEX: 4
Enter CON: 3
```

**File contents after write**
`Goblin,Humanoid,18,10,5,4,3`


## (20 points) Problem 4

In this problem, you will create a function that parses a single line of monster CSV data.
Parsing the data means you are processing it in some way.
Our task is conceptually simple, convert the comma separated values into individual strings.

Create a function named `parse_monster` in your `monster_utils.c` file.
Make sure you have a corresponding declaration in `monster_utils.h`.
The function should take as input a `char` array representing the line of CSV data, 7 arrays for the monster data following the previous 2 problems, and an `int` for the number of monsters currently loaded.
It should return an `int` specifying the number of attributes parsed from the line of CSV.
Use `strtok` to tokenize the input string based on using a comma as the delimiter.

Test your function by creating a file named `parse_monster.c` with a `main` function.
Prompt the user to enter a line of CSV data.
Call your function using the proper arguments and then print the resulting data as formatted below.
Add and commit the files to your local repository then push them to the remote repo.

### Grading
- (16 points) Passes tests after pushing code to the remote repo.
- (4 points) Reserved for consistent code formatting.

**Example Run**
```
Enter a line of CSV: Goblin,Humanoid,18,10,5,4,3
Goblin (Humanoid), 18 HP, 10 AC, 5 STR, 4 DEX, 3 CON
```

## (20 points) Problem 5

Given the data file `monsters.csv`, write a function `search_monsters` that searches for monsters based on user input.
The function should search only the names of the monsters.
The function should take as input 9 parameters.
The first 7 parameter represents the properties of the monsters currently loaded into memory with the eighth being an `int` representing the number of monsters.
The last parameter is the search term (`char` array).
Place the definition of this function in `monster_utils.c` with the corresponding declaration in `monster_utils.h`.

Test your function by creating a file named `search_monster.c` with a `main` function.
In your function, open a file named `monsters.csv`.
You can assume that this file exists and is in your program directory.
If the file cannot be opened, warn the user and return 1 from `main`.
Read in and parse all monster data using `parse_monster`.

After the call to `parse_monster`, prompt the user to enter a search term.
Pass the search term and the appropriate data arrays to `search_monsters`.

Depending on the search term, multiple monsters could be displayed.
They should be displayed in the order they are found, starting from the beginning of the file.
The output should be in the exact format as show in the example run.
Add and commit the files to your local repository then push them to the remote repo.

### Data Format

The data file contains monsters for an RPG game.
Each line of CSV data includes the following properties:
- name
- type
- hit points (HP)
- armor class (AC)
- strength (STR)
- dexterity (DEX)
- constitution (CON)

### Grading
- (16 points) Successfully returns the proper results.
- (4 points) Reserved for consistent code formatting.

**Example Run (Found Monsters)**
```
Enter search term: dragon
Adult Black Dragon (DRAGON), 195 HP, 19 AC, 11 STR, 14 DEX, 10 CON
Gold Dragon Wyrmling (DRAGON), 60 HP, 17 AC, 9 STR, 7 DEX, 8 CON
```

**Example Run (No Monsters Found)**
```
Enter search term: kobold
No monsters found
```