# CS210
Coding projects from CS210 Computer Programming
all work coded by Joe Massa
Copyright 2024 Joseph L. Massa

I selected the Savings calculator application that we coded for project 2.  This project presented challenges in formatting output, using a class to reduce the code in main, and nesting loops.  As I normally do,  I coded this project in steps. Before writing any code I wrote the project in pseudocode to keep track of how the program should function.  Once I was comfortable with how data would move through the system, I began to write code.  
First, I create and test the class setup.
Next, I tested the interest calculator.
Next came the loops, one for the Monthly calculations, this iterates 12 times before the Outer Loop, for the years, iterates. The Year loop iterates once for each year that is input from the user.  
Once all of the functionality was tested and working, I formatted the output, addressed the menu, and user input validation. 
This method of step coding has served me well in this course and has led to minimum debugging.  

The loops were the most challenging. Using figures from the example, I kept coming up with incorrect totals, but my loops were performing properly.  I realized that the problem occurred with the monthly deposits and at what point in the loop I added them to the balance.  I was adding them after the interest calculation and not before.  Once I corrected this the totals matched what was expected.
I used class functions to keep the code neat and within those functions, function-specific variables were used to control loops, Yearly Balance, and Yearly Interest amounts.  Resetting these variables at the right point in the loop iteration was also key to proper function.  Referring back to the pseudocode was also helpful.  
The process of breaking code into smaller functions coupled with the use of classes allows me to modify the program to add a second set of input parameters and provide a side-by-side comparison with a minimal amount of new code needing to be written. 
The extensive use of inline comments and clear variable naming makes this code very editable in the future with key functions clearly explained in comments. If the code needed to be modified, the comments made identifying the part of the code that needed to be updated is easy to find. 


I selected the Sales List generator program because this was the first project of this scale that involved reading and writing large amounts of data from external files.  
Once again, I started with Pseudocode to ensure that the program functionality was met.  The tricky part of the system was calculating the quantity of an item based on the frequency of an item in the text file.  
I used the MAP container feature to both store and calculate the quantity of the items.  Since the MAP container size does not need to be set before the program runs.  The size adjusts dynamically as new records are added.  As I looped through the input file, I added each line item to the MAP.  Knowing how the MAP functions, I used the .count function to determine if the input line should be added to the map( if it does not already exist) or if the value should be incremented by 1 if the key already exists.  I was pleasantly surprised how this worked.  

The trick became printing the MAP contents and writing the contents to the screen and file.  MAP containers do not iterate with an index so I created an iterator element with the following code:
map<string, int> ::iterator it = produceSalesList.begin()
This was the control variable for the while loop that cycled through MAP container.  

The successful coding of this project gives me great confidence to code more complex applications. 

