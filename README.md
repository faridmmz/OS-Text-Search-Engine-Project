# Text Search Engine

This is a simple C program that implements a text search engine using multi-threading and synchronization techniques.

## Project Description

The goal of this project is to create a text search engine that takes a file and a list of words as input and generates a file containing the search results. The search engine uses multiple threads to perform searches efficiently. To prevent race conditions, synchronization mechanisms such as mutex locks and semaphores are employed.

The output file contains the following information for each found word:
- The position of the word in the input text (line number)
- The thread number that found the word
- The timestamp when the word was found
- The time taken to write the output to the file

## Getting Started

1. Compile the program using a C compiler (e.g., `gcc -o text_search_engine main.c -lpthread`).
2. Create an input file (e.g., `test_case.txt`) containing the text to be searched.
3. Modify the `search_input` array to include the words you want to search for.
4. Run the compiled program.

## Usage

Run the compiled program:

```sh
./text_search_engine
```

## Input File Format
The input file should contain the text you want to search through.

## Output
The program generates an result_file.txt containing the search results.

## Example Test Case

### Input (test_case.txt):
```
writing for os proj .
this is a test case ,
we might need it when we present the proj .
or maybe not . nobody knows .
```
### Output (result_file.txt):
```
you searched for case and it was found in line 2 by thread 1 at 0.000954
you searched for for and it was found in line 1 by thread 2 at 0.001155
you searched for proj and it was found in line 3 by thread 2 at 0.001247
you searched for nobody and it was found in line 4 by thread 2 at 0.001284
you searched for os and it was found in line 1 by thread 3 at 0.001361
you searched for proj and it was found in line 1 by thread 4 at 0.001435
```

