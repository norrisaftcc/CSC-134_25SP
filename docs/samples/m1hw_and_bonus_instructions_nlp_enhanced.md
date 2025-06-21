CSC 134
M1HW1 - Movie Talk (NLP Enhanced Version)

## Your Creative Programming Debut

Here's where programming becomes personally meaningful: you're about to create a program that expresses something uniquely yours. Whether you're passionate about cinema, casually enjoy movies, or prefer other forms of storytelling, this assignment will transform your interests into working code.

Notice how this feels different from previous assignments? Instead of following a specific template, you're being invited to make creative choices. This is where you'll discover that programming isn't just about syntax and logic - it's about bringing your personal perspective into digital form.

As you select your movie and craft your program, you'll naturally integrate everything you've learned about variables (strings, integers, and doubles) while expressing something that matters to you.

## The Creative Foundation: Making It Personal

**Your mission, should you choose to accept it:** Create a program that celebrates a movie you enjoy through the power of variables and output formatting.

Think of this as building a digital movie poster - but instead of images, you're using data and text to capture what makes this film special. Whether you choose a blockbuster everyone knows, an indie film that speaks to you, or that guilty pleasure you secretly love, your program will bring it to life through code.

### Setting Up Your Creative Space

**TO DO: Open repl.it, start your new C++ project, and begin with your signature header:**

```cpp
// CSC 134
// M1HW1 - Movie Talk
// Your Name  
// Today's Date
```

**TO DO: Build your foundation (notice how natural this has become):**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Your movie data will live here
    
    // Display your movie tribute here
    
    return 0;
}
```

## Crafting Your Movie Tribute: The Technical Details

Your program should create and use these three variables (thinking back to the Apple Orchard pattern):

**String variable**: The movie's title - this connects to everything you learned about text storage

**Integer variable**: The year it was released - perfect for whole numbers that won't have decimals

**Double variable**: A monetary figure (box office earnings, budget, ticket price when you saw it) - ideal for numbers that need decimal precision

**For example, with "Titanic":**
- Title: "Titanic" (string)
- Year: 1997 (integer) 
- Worldwide gross: 2.18 (representing $2.18 billion - double)

### Bringing Your Data to Life

**TO DO: Use cout statements to weave these variables into a compelling narrative about your chosen film.**

Here's the beautiful part: how you present this information is entirely up to you. You might create:
- A technical summary: "Movie X, released in YEAR, earned $AMOUNT worldwide"
- A personal reflection: "I remember when MOVIE came out in YEAR - incredible to think it made $AMOUNT"
- A dramatic announcement: "YEAR was the year MOVIE changed cinema forever, earning an amazing $AMOUNT"

Let your personality guide the presentation.

### Adding the Human Element: Quotes and Commentary

**TO DO: Include 4-5 lines of your personal commentary** - quotes from the movie, your favorite scenes, interesting trivia you discovered, or simply why this film resonates with you.

This is where your program becomes uniquely yours. Whether you write:
- Memorable dialogue from the film
- Behind-the-scenes facts that fascinate you  
- Personal memories connected to watching it
- Analysis of what makes it special

**Trust your instincts** - whatever drew you to this movie is exactly what should appear in your code.

## Handling Quotes Within Quotes: A Technical Interlude

When you want to include actual movie dialogue, you'll encounter an interesting technical challenge: how do you put quotation marks inside strings that are already using quotation marks?

C++ offers an elegant solution - the escape sequence `\"`:

```cpp
cout << "As Jack said, \"I'm the king of the world!\"" << endl;
```

The backslash tells C++ "treat this quote as regular text, not as the end of the string." It's like having a special signal that means "ignore the usual meaning of this character."

## Research as Exploration: Finding Your Data

For this one assignment, Wikipedia becomes your friend. Unlike academic research where Wikipedia might be too informal, movie facts are perfect for our purposes. IMDB is another excellent source for box office numbers and release dates.

As you research, you might discover fascinating details you never knew about your chosen film. Let that curiosity guide you - those unexpected discoveries often become the most interesting parts of your program.

## Sample Program Flow: Inspiration, Not Imitation

Here's how one student approached "The Lion King":

```cpp
#include <iostream>
using namespace std;

int main() {
    string movie = "The Lion King";
    int year = 1994;
    double boxOffice = 968.5; // millions
    
    cout << "Movie Spotlight: " << movie << endl;
    cout << "Released: " << year << endl;
    cout << "Box Office: $" << boxOffice << " million worldwide" << endl;
    cout << endl;
    cout << "Why this movie matters to me:" << endl;
    cout << "\"Hakuna Matata\" taught me that some worries aren't worth carrying." << endl;
    cout << "The animation still looks incredible decades later." << endl;
    cout << "Mufasa's wisdom about the Circle of Life shapes how I see nature." << endl;
    cout << "It's a movie that works for kids and adults simultaneously." << endl;
    
    return 0;
}
```

Notice how this student made the data personal while demonstrating technical proficiency? That's exactly the balance you're aiming for.

## M1BONUS: For the Adventurous Spirits

*This section is completely optional - a playground for those who enjoy extra challenges.*

If you're feeling inspired to push further, consider these mathematical programming exercises. Each one builds on the Apple Orchard concepts while exploring different types of calculations:

**Problem 1: Rectangle Area Calculator**
- Variables: height (8), width (10) - both integers
- Calculation: area = height × width
- This mirrors real-world programming where you calculate areas for graphics, layouts, or physical spaces

**Problem 2: Sales Tax Simulator**  
- Variables: price ($99.99), tax rate (8% = 0.08) - both doubles
- Calculations: tax amount = price × tax rate, total = price + tax
- This reflects e-commerce programming where accurate financial calculations are crucial

**Problem 3: Pizza Geometry**
- Variables: diameter (12 inches) - double
- Calculation: area = π × radius² (where radius = diameter ÷ 2)
- You'll need to research the value of π and decide how to handle it in C++

**Problem 4: Pizza Division Logic**
- Using the pizza from Problem 3, calculate area per slice if cut into 8 pieces
- This combines the results from Problem 3 with additional division

### Organizing Multiple Solutions

**TO DO: If you attempt the bonus problems, create one program that addresses all questions using cout statements to clearly label each section:**

```cpp
cout << "Problem 1: Rectangle Area" << endl;
// Your rectangle solution here
cout << endl;

cout << "Problem 2: Sales Tax Calculator" << endl;  
// Your sales tax solution here
cout << endl;
```

This organization demonstrates professional programming practices - clear labeling and logical structure.

## Quality Assurance: Your Professional Standards

Before submitting your creative work:

**Technical Verification:**
- Does your program compile without errors?
- Are all three variable types (string, int, double) used meaningfully?
- Do your calculations produce correct results?
- Is your output clearly formatted and easy to read?

**Creative Assessment:**
- Does your program reflect your genuine interest in the chosen movie?
- Would someone reading your code understand why this film matters to you?
- Have you balanced technical requirements with personal expression?

**Professional Presentation:**
- Is your comment header complete and accurate?
- Are your variable names descriptive and appropriate?
- Is your code organized logically from data declaration through output?

## What This Assignment Reveals About Your Growth

You might think you "just wrote about a movie," but notice what you've actually accomplished:

- **You've integrated technical skills with personal expression** - a hallmark of creative programming
- **You've made autonomous creative decisions** while meeting technical specifications
- **You've researched and incorporated real-world data** into functional code
- **You've demonstrated the three fundamental data types** in meaningful context
- **You've experienced how programming can be personally meaningful**, not just technically correct

Most importantly, you've discovered that programming doesn't require you to abandon your interests - it amplifies them.

## File Management: Preserving Your Creative Work

**TO DO: Save your movie program as `M1HW1_Lastname.zip`**

**TO DO: If you completed bonus problems, save that work as `M1BONUS_Lastname.zip`**

**TO DO: Take screenshots showing your programs running successfully**

**TO DO: Submit all files to Canvas with the satisfaction of having created something uniquely yours**

## The Creative Programming Path Forward

You've just experienced something profound: the intersection of technical skill and personal expression. This balance - between meeting specifications and exercising creativity - defines much of professional programming.

In your next module, you'll learn how to make programs that respond differently based on conditions. Imagine a movie recommendation program that could suggest films based on your preferences, or a program that could analyze different aspects of movies and make intelligent comparisons.

Every variable you've declared, every output stream you've crafted, every creative decision you've made is preparing you for programs that can think, decide, and adapt. The technical foundation is solid; now your creative confidence is growing too.

Whether you spent time on the bonus problems or focused entirely on your movie tribute, you've proven something important: you can transform personal interests into working code. That's not just programming - that's digital storytelling.

Feel proud of what you've created. Your program isn't just technically correct - it's authentically yours.