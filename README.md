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
  Swap the first two elements at the top of stack X. If there are fewer than two elements in the stack, do nothing.  

- **RX**:  
  Rotate stack X → Move the first element at the top of the stack to the bottom.  

- **RR**:  
  Rotate both stacks A and B → Move the first element of both stacks to the bottom of their respective stacks.  

- **RRX**:  
  Reverse rotate stack X → Move the last element at the bottom of the stack to the top.  

- **RRR**:  
  Reverse rotate both stacks A and B → Move the last element of both stacks to the top of their respective stacks.  

For each of these operations, I implemented them as functions and tested them individually to ensure they performed correctly in various scenarios.  


<!--https://www.tldraw.com/r/EgvfDvK-lGUgWZVgDT-3V?d=v-2934.-2479.1530.743.Ym7L05aVdUrCR4WmWzNFc-->
