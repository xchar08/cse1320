# CSE 1320 Assignment 6

Your code must compile without any warnings and run without segmentation faults to receive credit.

This assignment will demonstrate how much easier it is to work with hash maps using the standard template library (STL) as opposed to the manual implementation we did in C. For this program, you will use a `std::unordered_map<std::string, Monster>` collection where the monster name is the key.

Modify the given code to simulate combat between two monsters. Your program should present a menu to the user allowing them to add monsters manually or through a file. The first option, `Add Monster`, should prompt the user to enter all relevant properties of a `Monster`:
- Name
- Type
- HP
- AC
- STR
- DEX
- CON

Once the `Monster` has been created, it should be added to an existing hash map.

The second option should accept a filename as input from the user. This file will be a CSV of `Monster`s and loads them into the existing map.

Option 3 will simulate combat between the monsters. The user should be prompted for two monster names. The program should continue to ask them until two valid names are entered. This input will be used to look up the `Monster` object from the hash map. Once two monsters are selected, each monster will take an attack on each other until one of them reaches 0 HP.

## Requirements

- (10 points) Implement a program with a menu featuring the options described above.
- (10 points) Implement `Add Monster` option to add a new monster to the map from user input.
- (40 points) Implement `Load Monsters from File` option to load monsters into the map from a CSV file.
- (30 points) Implement combat between two monsters that are chosen by user input as described above.
- (10 points) Reserved for code formatting.

# Example Menu

```
1. Add Monster
2. Load Monsters from CSV
3. Begin Combat
4. Exit
```