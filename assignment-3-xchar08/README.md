# CSE 1320 Assignment 3

This assignment covers stacks and queues.

**Relevant Etudes**
- [8. Dice Rolling](https://github.com/ajdillhoff/C-Etudes/tree/main/8)
- [9. Dynamic Stack](https://github.com/ajdillhoff/C-Etudes/tree/main/9)
- [10. Dynamic Queue](https://github.com/ajdillhoff/C-Etudes/tree/main/10)

# Problem 1: Function Stack

Create a program which reads text data of function calls and prints out the stack history similar to the example below.

```
main()
    load_monsters_csv()
        trim()
        parse_monster()
        trim()
        parse_monster()
    print_monsters()
```

The corresponding log file is show below.

**Log file**
```
main()
load_monsters_csv()
trim()
return
parse_monster()
return
trim()
return
parse_monster()
return
return
print_monsters()
return
return
```

Whenever a function call is read, push it onto the stack and print it with the appropriate level in indentation.
When `return` is read, pop the item at the top of the stack.

## Requirements
- The program should accept a file name via command line.
- Function calls will end with `()`. Your code should verify this.
- If an invalid text file is given, print out `"Invalid log file."`
- You should store the function calls in a stack using a dynamic array.
- All stack functions should be declared and defined in separate files. For example, they will be in `stack_utils.(c|h)`. Your main program should be in `problem1.c`.
- Free each item that is popped off the stack.
- Free all data before exiting the program.

# Problem 2: Player Queue

In most table top RPG rule sets, combat order is managed by having all players and creatures roll to consider their position in the initiative order.
Those with a higher roll will go before those with a lower roll.

Create a program with the following features

## Add Player

Prompt the user to enter a player name.
The player will be stored using the following `struct` which stores the name, last initiative roll, and position in the original ordering.

```
typedef struct {
    char *name;
    int roll;
    int position;
} player_s;
```

## Roll Initiative

Create a queue based on the rolls of each player.
The player ordering is based on their roll.
If two or more players roll the same value, you can choose the relative ordering.

If the user runs this command after already calculating initiative,
warn the user that they are about to re-roll.
If they confirm, roll initiative as normal.
If they decline, go back to the main menu.

**Example**
```
1. Add Player
2. Roll Initiative
3. Next Turn
4. View Current Order
> 2
Marisha rolled a 20.
Travis rolled an 18.
Liam rolled an 18.
Ashley rolled a 17.
Sam rolled a 12.
Taliesin rolled a 9.
Laura rolled a 2.
```

## Next Turn

Option 3 will process a turn in the current ordering.
This involves dequeuing the front of the queue and printing a message indicating who is going.
Additionally, write a function named `peek` that looks at the next player in the queue, but does not remove them.
Use that to notify who is up next.

**Example**
```
1. Add Player
2. Roll Initiative
3. Next Turn
4. View Current Order
> 3
Marisha's Turn!
Ashley is on deck.
```

## View Current Order

Print the current ordering with the current player at the top of the output.
The original ordering number should be printed next to the player's name.

**Example**
```
1. Add Player
2. Roll Initiative
3. Next Turn
4. View Current Order
> 4
3. Liam
4. Marisha
5. Sam
6. Ashley
7. Laura
1. Taliesin
2. Travis
```

## Requirements
- Each player should be represented by a `struct` that is dynamically allocated.
- All logic for the main program should be in `problem2.c`.
- Implement the menu as requested. It does not have to look exactly like the example run.
- Implement the 4 sub-items as defined above.
- All queue functions should be declared and defined in separate files. For example, they will be in `queue_utils.(c|h)`.
- Free all memory before exiting the program.