# push_swap

The **push_swap** project challenges students to create a sorting algorithm for a specific problem: sorting a list of integers using a limited set of operations.  

## Steps:

### Step 0 - Understand the Subject  
The first step is to gain a good understanding of the subject requirements.  

### Step 1 - Learn about Algorithmic Complexity  
I began by reading about [Algorithmic Complexity](https://devopedia.org/algorithmic-complexity).  

#### Key Points:  
- What is Algorithmic Complexity?  
- Various types of algorithmic complexities.  
- What does it mean to state the best-case, worst-case, and average-case time complexity of algorithms?  
- How are these complexities represented?  

Use the link above to explore these topics. Afterward, try answering the above questions and study this image for a better understanding:  

![Complexity of sorting algorithms table](./IMGs/complexity_of_sorting_algorithms_table.jpg)  

This should be enough to get started.  

### Step 2 - Study Sorting Algorithms  
Next, I read about several sorting algorithms, such as:  
- Bubble Sort  
- Insertion Sort  
- Selection Sort  
- Quicksort  
- Mergesort  
- Radix Sort  

#### Key Insights:  
I found that most of these algorithms either cannot be used in the **push_swap** project or require significant modifications to work within the constraints of the allowed operations.  

### Step 3 - Develop Initial Ideas  
At this point, I didn’t have a complete solution, but I brainstormed some ideas for tackling the project. I also sought advice from former students who had worked on this project before. Their suggestions were incredibly helpful.  

One of the sources they shared was a [Medium Article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97), which I found particularly useful.  

### Step 4 - Merge Concepts and Create a Base Algorithm  
The article provided some excellent insights, which I combined with ideas from other sorting algorithms. This allowed me to design a basic working algorithm as a foundation for further development.  

### Step 5 - Put the General Idea on Paper  
I used a tool called [TLDraw](https://www.tldraw.com/) to create a detailed algorithm using what I call "flow cards" (I’m not sure if that’s the right term, but it works XD). You can find it here in this [Board](https://www.tldraw.com/ro/e7_fqo8dLkR8jHe5QtgyP?d=v4824.-10444.19200.9320.Ym7L05aVdUrCR4WmWzNFc).  

### Step 6 - Setup  
I created a repository and added [libft](https://github.com/ilorez/libft/tree/develop) (libft + get_next_line + ft_printf) because I needed all those functions. I also added some extra functions to libft that I’d need later, such as:  
- `ft_atol`  
- `ft_free_list_of_strs`  
- Boolean type (because I wanted it).  

### Step 7 - Start Coding  
After thoroughly understanding the project requirements, I started creating the basic functions:  
- `create_stack_a`  
- `is_valid` (for arguments)  
- `print_stack` (for debugging)  

I also created a basic header file to organize the project structure.  

### Step 8 - Create a Checker  
I implemented a simple starting point for **push_swap** that takes arguments one by one, splits them by spaces, validates the numbers, converts them to integers, and ensures there are no duplicates. I used a linked list for this purpose.  

This process took two days. At this point, I had completed the first seven steps within five days.  

### Step 9 - Coding Operations  
After completing stack A, I started coding the allowed operations one by one, testing each to ensure they worked correctly:  

- **PX**:  
  Perform `PA` and `PB` → Take the first element at the top of stack X and move it to the top of stack Y.  

- **SX**:  
  Swap the first two elements at the top of stack X(`A` || `B`). If there are fewer than two elements in the stack, do nothing.  

- **RX**:  
  Rotate stack X(`A` || `B`) → Move the first element at the top of the stack to the bottom.  

- **RR**:  
  Rotate both stacks A and B → Move the first element of both stacks to the bottom of their respective stacks.  

- **RRX**:  
  Reverse rotate stack X(`A` || `B`) → Move the last element at the bottom of the stack to the top.  

- **RRR**:  
  Reverse rotate both stacks A and B → Move the last element of both stacks to the top of their respective stacks.  

For each of these operations, I implemented them as functions and tested them individually to ensure they performed correctly in various scenarios.  

### Step 10 - Final Step  
At this stage, I applied the algorithm I created. My approach involved dividing the process into two parts:  

1. **Sort Three**  
   This function handles sorting three numbers by evaluating six possible permutations.  

2. **Sort More**  

   For sorting more than three numbers, I adapted the [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) with some modifications:  
   - **First Change:** Adjusting the Terminal State in Stack A 
      Initially, the algorithm stopped when three elements remained in stack A. These were sorted directly, and the process continued. I modified this to scale the stopping point based on input size:
        - For 500 numbers: Stop at 25 elements.
        - For 100 numbers: Stop at 5 elements.
        - For inputs larger than 400 numbers: Use a stopping point such as size / 20.
        - The minimum stopping point remains 3 elements.

      At the stopping point:
        1. Push all remaining elements in stack A directly to stack B without any additional calculations **(Using: while (size > 3) => PB())**.
        2. Use the same logic to return all elements from stack B to stack A by finding the correct position for the top number in stack B and using only RA or RRA to move the number to stack A.
     > *This adjustment reduced the average number of operations for 500 numbers by 50 to 200 operations in some cases.*  
   
   - **Second Change:**  
     I modified the calculation function. The original Turk algorithm calculates the minimum number of operations to place a number from stack A in the correct position in stack B using this formula:  
     `MIN(RA, RRA) + MIN(RB, RRB)`  

     While effective, it doesn’t explore additional scenarios. I introduced three scenarios:  
     1. **Original Scenario:**  
        `MIN(RA, RRA) + MIN(RB, RRB)`  
     2. **Combined Rotations (RR):**  
        Use `RA` and `RB` to form `RR` and minimize the remaining rotations (`RA` or `RB`).  
     3. **Combined Reverse Rotations (RRR):**  
        Use `RRA` and `RRB` to form `RRR` and minimize the remaining reverse rotations (`RRA` or `RRB`).  

     #### Example:  
     Imagine stack A requires:  
     - `1 RA` or `2 RRA`  
     And stack B requires:  
     - `3 RB` or `2 RRB`  

     Using the scenarios:  
     - **Scenario 1:**  
       `1 RA + 2 RRB = 3 operations`  
     - **Scenario 2:**  
       `1 RA + 3 RB = 3 operations`  
     - **Scenario 3:**  
       `2 RRA + 2 RRB = 2 RRR = 2 operations`  

     Replacing these small numbers with larger ones (e.g., 100, 200, 300), the performance difference becomes significant.  

This step took approximately 5 to 8 days.  

### Step 11 - Debugging and Optimization  
After completing the implementation, I focused on fixing errors and memory leaks. Here are some recommendations:  
- Use `-fsanitize` for debugging.  
- Fix Norminette errors.  
- Organize files for better structure.  

I also updated my basic Makefile to an advanced version.  

### Step 12 - Bonus  
The bonus part was straightforward. I reused several functions from the mandatory part and incorporated `get_next_line` from `libft`.  

#### Key Addition:  
I added the `get_operation` function.  
- This function reads a line, verifies if it is a valid operation, and returns it.  
- The returned operation is passed to a `run_operation` function, which executes it.  
- At the end, the program checks if stack A is sorted and stack B is empty.  

### Step 13 - Handling Errors  

1. **Invalid Arguments:**  
   - Examples:  
     - `" "`  
     - `"     "`  
     - `+`  

2. **Duplicates:**  
   - Examples:  
     - `0` and `-00000000`  

3. **Checker Behavior:**  
   - If stack B is not empty, the program should display `KO`.  
   - Invalid operations should display `Error`.  

<!--https://www.tldraw.com/r/EgvfDvK-lGUgWZVgDT-3V?d=v-2934.-2479.1530.743.Ym7L05aVdUrCR4WmWzNFc-->
