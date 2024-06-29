# Branch-Target-Buffer

## Project Overview
This project focuses on the implementation of a Branch Target Buffer (BTB) in C. A BTB is a critical hardware structure used in modern processors to enhance the performance of branch prediction by storing the target addresses of branch instructions.

## Project Description
Branch prediction is essential in modern computer architectures to minimize the cycle delays caused by branch instructions. This project demonstrates how a simple BTB can predict and store the outcome addresses of branch instructions to expedite instruction execution.

### Abstract
The BTB aids in the speculative execution of instructions by predicting the outcome addresses of branches before they are known, thus reducing the impact of branch mispredictions on performance.

### Methodology
- **Initialization:** Sets up the BTB with specified size and prepares it for entries.
- **Insertion:** Adds new entries to the BTB.
- **Lookup:** Retrieves target addresses using specific Program Counter (PC) values.

## Code Structure
The code includes detailed comments explaining the functionality of each section, focusing on the initialization, insertion, and lookup operations within the BTB.

## Usage
To run the program:
1. Compile the C code using a standard C compiler like GCC.
2. Execute the compiled program in your preferred environment.

## Output
The program outputs the results of the BTB operations, demonstrating successful predictions and error handling for full BTB scenarios or missing PCs.

## Conclusion
The project successfully implements a functional Branch Target Buffer in C, demonstrating the practical application of concepts discussed in the Computer Architecture course.

