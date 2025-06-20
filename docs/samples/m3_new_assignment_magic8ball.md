# CSC 134 - M3LAB3: Digital Magic 8-Ball

## Introduction

Remember those Magic 8-Ball toys from when you were a kid? You'd ask a question, shake the ball, and it would give you a mysterious answer like "Reply hazy, try again" or "It is certain." Well, today we're going to build our own digital version!

This assignment combines everything you've learned so far in Module 3: if/else statements for decision making and random number generation for unpredictability. But unlike rolling dice (which is pretty predictable), we're going to create something that feels a bit more magical.

(Why a Magic 8-Ball? Because it's more interesting than "Random Number Generator #4," and because it demonstrates how random numbers can be used to create engaging user experiences. Plus, you might actually want to show this one to your friends!)

## What You'll Learn

- Combining random numbers with if/else statements
- Creating categories of responses using ranges
- Building interactive programs that feel "intelligent"
- User experience design (making your program fun to use)
- String output formatting and presentation

## Background: How Magic 8-Balls Work

The original Magic 8-Ball contains a 20-sided die floating in blue liquid. Each face has a different response printed on it. When you shake it, the die settles and one response becomes visible through a window.

Our digital version will work similarly – we'll generate a random number and use if/else statements to map that number to different categories of responses. But we can do something the original can't: we can have as many responses as we want!

## Assignment Details

**TO DO: Create a new C++ project and start with your standard header:**

```cpp
// CSC 134
// M3LAB3 - Digital Magic 8-Ball
// Your Name
// Today's Date
```

Your program should:

1. Welcome the user and explain how to use the Magic 8-Ball
2. Ask the user to think of a yes/no question and press Enter
3. Generate a random number
4. Use if/else statements to select an appropriate response based on the number
5. Display the fortune with some dramatic flair
6. Ask if they want another fortune

**Response Categories**

Your Magic 8-Ball should have at least 12 different responses, divided into these categories:

**Positive Responses (about 40% of the time):**
- "It is certain"
- "Without a doubt" 
- "Yes definitely"
- "You may rely on it"
- "Signs point to yes"

**Negative Responses (about 30% of the time):**
- "Don't count on it"
- "My reply is no"
- "Very doubtful"
- "Outlook not so good"

**Neutral/Mysterious Responses (about 30% of the time):**
- "Reply hazy, try again"
- "Ask again later"
- "Cannot predict now"
- "Concentrate and ask again"

**TO DO: Set up your random number generation (building on M3T2):**

```cpp
#include <ctime>
#include <cstdlib>

// In main():
srand(time(0));
int fortune_number = rand() % 12;  // Gives 0-11 for 12 responses
```

**TO DO: Use if/else statements to map numbers to responses:**

```cpp
if (fortune_number >= 0 && fortune_number <= 4) {
    // Positive responses (0, 1, 2, 3, 4)
    if (fortune_number == 0) {
        cout << "🔮 It is certain 🔮" << endl;
    }
    else if (fortune_number == 1) {
        cout << "🔮 Without a doubt 🔮" << endl;
    }
    // ... continue for other positive responses
}
else if (fortune_number >= 5 && fortune_number <= 7) {
    // Negative responses (5, 6, 7)
    // ... your negative responses here
}
else {
    // Neutral responses (8, 9, 10, 11)
    // ... your neutral responses here
}
```

## Example Program Flow

```
🎱 Welcome to the Digital Magic 8-Ball! 🎱

Think of a yes/no question and press Enter when ready...
[User presses Enter]

🌟 The spirits are consulting... 🌟
🔮 Without a doubt 🔮

Would you like another fortune? (y/n): y

Think of a yes/no question and press Enter when ready...
[User presses Enter]

🌟 The spirits are consulting... 🌟
❓ Reply hazy, try again ❓

Would you like another fortune? (y/n): n

Thanks for consulting the Digital Magic 8-Ball! ✨
```

## Technical Requirements

1. **Random Number Generation**: Use proper seeding with `srand(time(0))`
2. **Range-Based if/else**: Use ranges to categorize your responses
3. **User Interaction**: Wait for user input before generating fortunes
4. **Repeat Functionality**: Ask if the user wants another fortune
5. **Good Formatting**: Make your output visually appealing with symbols/emojis

## Creative Extensions (Optional)

Want to make your Magic 8-Ball even more interesting? Try these additions:

**Beginner Extensions:**
- Add more responses (20+ like the original)
- Include special "rare" responses that only show up 5% of the time
- Add ASCII art for the Magic 8-Ball

**Intermediate Extensions:**
- Let users ask specific types of questions (love, career, school) and tailor responses
- Add a "confidence level" to each response
- Keep track of how many fortunes you've given in this session

**Advanced Extensions:**
- Analyze the user's question for keywords and influence the response
- Add a "fortune history" that avoids repeating recent responses
- Create different "personalities" for your Magic 8-Ball (optimistic vs pessimistic)

## Common Pitfalls to Avoid

**Random Number Issues:**
- Forgetting to seed the random number generator (your fortunes will be the same every time!)
- Using the wrong range for `rand() % n` (remember, this gives 0 to n-1)

**Logic Issues:**
- Overlapping ranges in your if/else statements
- Not handling all possible random numbers
- Forgetting the case where users enter something other than 'y' or 'n'

**User Experience Issues:**
- Not giving users enough time to think of their question
- Making the output boring or hard to read
- Not clearly explaining how to use the program

## Testing Your Program

Before you submit, test these scenarios:

1. **Normal Use**: Ask several questions and verify you get different responses
2. **Edge Cases**: What happens if you run it multiple times quickly?
3. **Input Validation**: Try entering unexpected values when asked for y/n
4. **Distribution**: Run it 20+ times – do you get a good mix of positive, negative, and neutral responses?

## Why This Assignment Matters

This might seem like "just a toy program," but you're actually learning some important concepts:

- **Random Number Applications**: Understanding how to use randomness to create engaging experiences
- **User Interface Design**: Making programs that are fun and easy to use
- **Range Management**: Using if/else statements to categorize numerical ranges
- **Program Flow Control**: Managing the interaction between user input and program response

These skills apply to game development, user interface design, simulation programming, and many other areas of computer science.

## Submitting Your Work

1. **Test thoroughly** – make sure your random responses work correctly
2. **Save your code** as `M3LAB3_Lastname.zip`
3. **Take a screenshot** showing multiple fortunes being generated
4. **Submit both files** to Canvas

**Before You Submit:**
- Does your program compile and run without errors?
- Do you get a good variety of responses when you test it multiple times?
- Is your output formatting clean and easy to read?
- Did you include proper comments explaining your logic?

## Looking Forward

Great job! You've just built a program that combines logical decision-making with unpredictability – a key concept in game programming and interactive applications. In Module 4, we'll learn about loops, which would let you ask for multiple fortunes without having to copy and paste code. Imagine building a Magic 8-Ball that could run forever, or one that could track statistics about the types of questions people ask!

The magic is in the code – and now you're the magician! 🎱✨