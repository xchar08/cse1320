# CSE 1320 Assignment 5

This assignment covers hash maps, macros, and makefiles.

Your code must compile without any warnings or errors and run without segmentation faults to receive credit. Any allocated memory must be freed.

# Adding a `Makefile`

When working with larger codebases, it is easy to get overwhelmed. Any obstacles encountered, no matter how small, can seem insurmountable. Our first task is to create a `Makefile` for our project. This will make it simple to compile our project and test the different components we will be adding.

Feel free to use [the example we did in class](https://github.com/ajdillhoff/CSE1320-Examples/tree/main/make) or the cookbook from [makefiletutorial.com](https://makefiletutorial.com/#makefile-cookbook) to get started.

## Tasks

- [ ] Create a `Makefile` with the following targets:
    - `release`: Builds the full project normally. The executable should be placed in a `build` directory.
    - `debug`: Builds the project with the flags `-g -Wall`.
    - `clean`: Removes the `build` directory.
- [ ] Verify that your `Makefile` works by building the project and running it.

# Collision Resolution using Quadratic Probing

One flaw of linear probing for collision resolution is that samples tend to cluster together in different parts of the map. An alternative open addressing scheme that does not suffer from clustering is [**quadratic probing**](https://en.wikipedia.org/wiki/Quadratic_probing).

Quadratic probing computes a new index based on the result of a hash function and quadratic function. Let $h(k)$ be the original hash function. The new index is computed as

$$
h(k, i) = h(k) + c_1 i + c_2 i^2.
$$

Create a function `int quadratic_probe(int hash, int i, int c1, int c2)` that computes the function above. The input arguments are:
- `int hash` - The original hash value computed by the hash function.
- `int i` - The parameter `i` as described above.
- `int c1` - The first coefficient of the function.
- `int c2` - The second coefficient of the function.

This function will also allow you to explore the effects of changing the coefficients $c_1$ and $c_2$. In most cases, you might use a default implementation where $c_1 = c_2 = 1$. For this case, create a macro that defines a function call `default_probe(hash, i)` to call the function `quadratic_probe(hash, i, 1, 1)`.

Add these functions to `hash_map_utils.(c|h)`. The macro definition should be placed after the declaration in `hash_map_utils.h`.

## Tasks

- [ ] Implement `quadratic_probe` in `hash_map_utils.c` (declare in `hash_map_utils.h`)
- [ ] Add macro for function.
- [ ] Test the function by computing it by hand with a known input. Your implementation should produce the same value as calculated by hand.

# Monster Map

Create a program that uses a hash map with open addressing via quadratic probing and incremental rehashing.
The hash map will store `monster_s` objects using the same data format as assignment 2.

**`monster_s` struct**

```
typdef struct {
    char *name;
    char *type;
    int hp;
    int ac;
    int str;
    int dex;
    int con;
} monster_s;
```

The keys for this map will be the names of each `monster_s`.

## Adding a Monster

The program should allow users to add monsters from `stdin` as well as the ability to import from a CSV file. For the first task, implement option 1 on the main menu in `monster_map.c` by first creating a new `monster_s` object using data entered by the user and then inserting that into the hash map. There are already functions provided to do both of these things.

When adding an individual `monster_s`, make sure they are not already in the hash map. If it is, warn the user and return to the main menu. Test that your code works by compiling and running it. You should be able to add a few monsters without incident.

### Tasks

- [ ] Create a new monster using `create_monster` in `monster_utils.c`.
- [ ] Verify the monster is unique by using the `search` function.
- [ ] If it is unique, add it to the hash map.
- [ ] If it already exists, free the memory allocated for this monster.

## Bulk Import from CSV File

For option 2, the program should load data from a CSV file and insert the unique entries in the hash map. Since we know ahead of time how many samples are to be added, the map size should be reserved to accommodate all entries without rehashing.

One approach to implementing this option would be:
1. Load all monsters from a CSV file into an array (use `array_s`).
2. Determine the unique entries in the array using `search`. Remove any entries from the array that are already in the map.
3. Insert the entries into the map based on the number of unique monsters by completing the `bulk_insert` function in `monster_map.c`.

The first step should be completed by filling out the `load_monsters_csv` function in `monster_utils.c`. This will require a similar approach as in Assignment 2 problem 3.

The third step requires some consideration since the map may currently be in the process of rehashing. In that case, the current rehashing should be immediately completed. Then the map should be resized again such that all unique entries from the file can be entered without triggering another rehash.

### Tasks

- [ ] Complete `load_monsters_csv` in `monster_utils.c`
- [ ] Filter out monsters that already exist in the hash map.
- [ ] Convert the unique data to `hash_element_t` objects and store in a new `array_s` object.
- [ ] Pass the array to `bulk_insert` in `hash_map_utils.c`. You will need to complete this function following the subtasks listed in the function.
- [ ] In `hash_map_utils.h`, create a macro to calculate the bucket size of a map given the number of keys $n$ and a load factor bound $b$:

$$
k \geq \Big\lceil\frac{n}{b}\Big\rceil
$$

### Requirements

- When importing a file to add, gather a collection of unique keys to add before any hash map operations. Once the unique keys are determined (use the search function to check if they already exist), then rehash and resize with at least enough room to store the new keys without rehashing again.

- Allocated memory must be freed before the program terminates.
- Any function declarations, macros, or `struct` declarations should be in a corresponding header file.

## Searching the Map

Users should be able to search the map using a monster name. To complete option 3, ask the user to enter a monster name and use that as input to the `search` function that is already provided. If a key exists, print the monster's details out to `stdout`. Otherwise, let the user know that the monster does not exist.

For printing monster details, complete the function `print_monster` in `monster_utils.c`. This function accepts a `void *` object as input since the function will be passed as input to the print functions in `hash_map_utils.c`.

### Tasks

- [ ] Complete option 3 in `monster_map.c` as described above.
- [ ] Finish `print_monster` in `monster_utils.c` so that it prints the details of a monster.

## Cleaning Up

It is important to free any allocated data that is no longer being used. Complete the `free_monster` function in `monster_utils.c`. **Note** that this function expects a `void *` object as its first parameter as it will be used as a function pointer. The reasoning is because the hash map functions do not know exactly what type of data they will be storing, so they cannot possibly know how to free a specific data type.

This function should free the data allocated to each string as well as the data for the `monster_s` object itself.

### Tasks

- [ ] Complete the `free_monster` function in `monster_utils.c`.
- [ ] Make sure all dynamically allocated memory is freed before the program exits.

# Example Runs

**Example Output - Import Bulk Monsters**

```
1. Add Monster
2. Import CSV File
3. Search
4. Print Map
5. Exit
> 2
Enter filename: monsters.csv
10 unique entries to be added (2 duplicates) out of 12.
Rehashing...
Import complete.
```

**Example Output - Search**

```
1. Add Monster
2. Import CSV File
3. Search
4. Print Map
5. Exit
> 3
Enter a monster name: Rakshasa
Rakshasa not found in map.
```