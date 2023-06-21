# CSE 1320 Assignment 4

To see how array operations perform versus linked list operations, this assignment will provide a chance to benchmark them.
By simulating the size of each data sample along with the number of samples, you will gain some intuition on the efficiency of inserting elements into each data structure.

# Benchmarking Arrays

The provided code already establishes tests to benchmark both sequential and random inserts into an array.
Sequential inserts to the end of an array are the most efficient since no data needs to be shifted.

# Benchmarking Linked Lists

Create a new file named `linked_list_tests.c` with a corresponding header file.
This file should contain three functions:
1. `void linked_list_insert_sequential_start(int num_samples, int sample_size)`
2. `void linked_list_insert_sequential_end(int num_samples, int sample_size)`
3. `void linked_list_insert_random(int num_samples, int sample_size)`

## Sequential Insert

The first test should create a new sample of size `sample_size`.
Similar to the testing functions used for arrays, you can simulate this using a `void *` object and allocating `sample_size` bytes to it.
Insert the new pointer at the beginning of the linked list.

The second test will be almost identical to the first one you created, except you should add each sample to the end of the list.
Since you are simulating a standard, singly-linked list, you should expect that this version will perform slower inserting at the beginning of the list.

## Random Insert

The third and final test should insert the samples at a random position based on the current number of samples.
Reference the random tests in `array_tests.c` to see how the random values are generated.

After implementing all three functions, include the header file in `run_tests.c` and create a function named `void linked_list_tests(int num_samples, int sample_size)`.
This function should call each individual test you created previously.
Use `array_tests` as a reference to what this should look like.

# Running the Tests

The provided `Makefile` will compile and run the tests automatically.
If you implement the functions as requested correctly, this will also work for your new tests.
Once you have implemented the new tests, run the test by calling `make`.

The output should clearly show which test is being performed followed by the time (in ms) that it took to execute the test.
Feel free to model your benchmark function after the array tests already provided.
If the tests run properly, you're done!
