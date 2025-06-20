# CSC 134 - Module 3 Assignments

Welcome to Module 3! We're going to step things up a bit and start making programs that can actually make decisions. Up until now, our programs have been pretty predictable – they do the same thing every time you run them. Now we're going to add some if statements and let our programs be a little smarter.

This module has several assignments that build on each other. Don't worry if the first one seems simple – by the end you'll be writing programs that can make complex decisions and even generate random numbers like a video game.

---

## M3T1 - Rectangle Comparison

**Introduction**

Remember back in Module 1 when we calculated the area of shapes? Well, now we're going to make our program smart enough to compare two rectangles and tell us which one is bigger. This might seem like a simple task for humans (just look at the numbers and compare), but getting a computer to make that decision is actually a big step forward in programming.

**What You'll Learn**
- Using if/else statements to make decisions
- Comparing numbers with greater than, less than, and equal to
- Working with multiple variables of the same type

**Assignment Details**

TO DO: Go to repl.it and create a new C++ project. Start with your standard comment header:

```cpp
// CSC 134
// M3T1 - Rectangle Comparison
// Your Name
// Today's Date
```

Your program should:

1. Ask the user for the length and width of the first rectangle
2. Ask the user for the length and width of the second rectangle  
3. Calculate the area of both rectangles (remember, area = length × width)
4. Display both areas
5. Use if/else statements to determine which rectangle has the larger area
6. Display an appropriate message telling the user which rectangle is larger

**Example Output:**
```
What's the length of the first rectangle? 5
What's the width of the first rectangle? 3
What's the length of the second rectangle? 4
What's the width of the second rectangle? 6
First area is: 15
Second area is: 24
The second one is larger.
```

**Important Notes:**
- Don't forget to handle the case where both rectangles have the same area!
- Use descriptive variable names like `area1` and `area2`
- Remember that the comparison operators are: `>` (greater than), `<` (less than), and `==` (equal to)

---

## M3LAB1 - Pokemon Battle Choices

**Introduction**

Time for some fun! We're going to create a simple Pokemon battle simulator. This assignment will teach you how to handle user input choices and use if/else statements to create different outcomes based on what the user chooses.

(Why Pokemon? Because it's a great example of a choice-based system that most people are familiar with. Plus, it's more interesting than "Press 1 for Addition, Press 2 for Subtraction.")

**Assignment Details**

Your program should present the user with a Pokemon battle scenario and let them choose what to do. Here's the setup:

```
You're in a pokemon battle! ⚡Pikachu vs. 💤Snorlax.
1. Fight
2. Run
3. Use Item
Type 1, 2, or 3:
```

TO DO: Create the following structure in your program:

1. Display the battle scenario and menu options
2. Get the user's choice (an integer)
3. Use if/else statements to handle each choice:
   - Choice 1 (Fight): "You chose to fight" and "Sadly, you lose."
   - Choice 2 (Run): "You chose to run" and "You live to fight another day."
   - Choice 3 (Use Item): "You use a potion." and "More here later..."
   - Invalid choice: "I'm sorry, that is not a valid choice."
4. Always end with "Thanks for playing!" regardless of their choice

**Technical Tips:**
- Use `int choice;` to store the user's selection
- The comparison `if (1 == choice)` reads more naturally than `if (choice == 1)` – both work, but putting the constant first helps prevent accidental assignment
- Each if/else block should be separate – don't chain them all together for this assignment

**Common Errors to Watch For:**
- Forgetting to include the "invalid choice" case
- Using `=` instead of `==` for comparison
- Not including the final "Thanks for playing!" message outside the if/else blocks

---

## M3LAB2 - Grade Calculator

**Introduction**

Let's build something practical – a program that converts numerical grades to letter grades. This is the kind of program that might actually be useful in real life, and it gives us good practice with multiple if statements and range checking.

**Assignment Details**

Your program should ask the user for a numerical grade (0-100) and convert it to a letter grade using this scale:

- 100: A+
- 90-99: A  
- 80-89: B
- 70-79: C
- 60-69: D
- Below 60: F

TO DO: Structure your program like this:

1. Create constants for each grade threshold:
```cpp
const int A_PLUS = 100;
const int A = 90;
const int B = 80;
const int C = 70;
const int D = 60;
const int F = 0;
```

2. Ask the user for their numerical grade
3. Use if statements to determine the letter grade
4. Display the result

**Example Output:**
```
Number grade to letter grade conversion program.
Enter the number grade: 85
The grade 85 is a B
```

**Technical Notes:**
- Use `&&` (AND) to check ranges: `if (num_grade >= B && num_grade < A)`
- You could also use `else if` statements, but for this assignment, use separate `if` statements to practice range checking
- Make sure your ranges don't overlap and that you cover all possible values

**Why Use Constants?**
Constants make your code easier to read and maintain. If the grading scale changes next semester, you only have to update the constants at the top instead of hunting through your code for magic numbers.

---

## M3T2 - Dice Rolling with Random Numbers  

**Introduction**

Now we're getting into the good stuff! Random numbers are what make games interesting – without them, every game would play out exactly the same way every time. Today we're going to simulate rolling dice and use if statements to determine if our roll is good enough to "hit" a target.

This assignment introduces you to the C++ random number generator, which is essential for any kind of game programming or simulation.

**Background: Why Random Numbers Matter**

Think about any game you've played – video games, board games, card games. Most of them use some element of chance to keep things interesting. Without randomness, Tetris would give you the same sequence of pieces every time, and that would get boring pretty quickly.

**Assignment Details**

Your program should:
1. Roll two six-sided dice
2. Display the individual rolls and the total
3. Check if the total is high enough to "hit" a target number
4. Display whether it's a hit or miss

TO DO: Set up your random number generation:

```cpp
#include <cmath>    
#include <ctime>

// In your main function:
const int SIDES = 6;
const int TO_HIT = 7;  // Change this to whatever you want

int seed = time(0);  // Use current time as seed
srand(seed);         // Initialize random number generator
```

TO DO: Generate your dice rolls:

```cpp
int roll1 = ((rand() % SIDES) + 1);  // Gives 1-6
int roll2 = ((rand() % SIDES) + 1);  // Gives 1-6
int total = roll1 + roll2;
```

**Example Output:**
```
You rolled 4 + 3 = 7
It's a hit!
```

**Technical Explanation:**
- `rand()` generates a large random number
- `rand() % SIDES` gives us remainder when divided by 6, so we get 0-5
- Adding 1 gives us the range 1-6 that we want for a die
- `time(0)` gives us the current time in seconds, which makes a good seed value
- The seed determines the sequence of "random" numbers (they're actually predictable if you know the seed)

**Experiment with It:**
Try changing the `TO_HIT` value and the number of `SIDES`. What happens if you make it a 20-sided die? What if you need to roll 15 or higher to hit?

---

## M3T3 - Multiple Dice Rolls

**Introduction**

This is a shorter assignment to give you more practice with random numbers. Sometimes you want to see multiple results in a row – like rolling initiative for all the characters in a tabletop RPG, or generating a hand of cards.

**Assignment Details**

Building on M3T2, create a program that rolls a die multiple times and displays each result. This assignment is intentionally more open-ended to let you experiment.

Your program should:
1. Set up random number generation (same as M3T2)
2. Roll a die at least 3 times
3. Display each result

**Customization Options:**
- Change the number of sides on your die (try a d20!)
- Roll more than 3 times
- Add some flavor text to make it more interesting

**Example Output:**
```
Rolling a 6-sided die three times:
Roll 1: 4
Roll 2: 1  
Roll 3: 6
```

**Advanced Challenge (Optional):**
If you're feeling ambitious, try adding up all the rolls and displaying a total. This is good practice for keeping a running total, which is a common programming pattern.

---

## Submitting Your Work

For each assignment:

1. **Save your code** using the repl.it download feature
2. **Name your files** in the format: `M3T1_Lastname.zip`, `M3LAB1_Lastname.zip`, etc.
3. **Take screenshots** showing your code and the program output
4. **Submit both** the ZIP file and screenshot to Canvas

**Before You Submit - Checklist:**
- Does your program compile without errors?
- Does it handle invalid input appropriately?  
- Are your variable names descriptive?
- Did you include proper comments and header blocks?
- Does the output match the examples (approximately)?

**If You're Having Trouble:**
Remember, programming is like learning a musical instrument – it takes practice. If you get stuck:
- Double-check your syntax (missing semicolons are common)
- Make sure your if/else statements have proper braces `{}`
- Test with simple input first, then try edge cases
- Don't be afraid to ask for help!

---

## Looking Ahead

Next module, we'll learn about loops, which will let us repeat actions without having to copy and paste code. Imagine being able to roll that die 100 times with just a few lines of code, or asking the user if they want to battle another Pokemon. That's the power of loops, and you'll be ready for it after mastering these decision-making concepts.

Keep up the great work!