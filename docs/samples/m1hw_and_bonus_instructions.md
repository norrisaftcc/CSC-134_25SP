
M1HW1 (Movie Talk) 
For this assignment, pick a movie you enjoy (or just a movie you can easily find information about). Along the way, you will use output statements to work with the variable types int, double, and string.
Your program will use cout and variables to briefly talk about this movie. If you look at "Apple Orchard" and remove the part where it calculates the total price of all the apples, that's a pretty similar program in terms of how it operates, even though it's about apples instead of movies.
You should name and create the following variables:

    something to hold the name of the movie
    something to hold the year that it came out
    something to hold the box office gross or some other monetary figure about the movie (using a decimal point)

For example: The movie "Titanic" came out in 1997, and had a worldwide gross of around 2.18 billion dollars.
Your program should then use cout along with these variables to give a brief summary of info about the movie.
Finally, you should use cout to print a few lines that are quotes from the movie, your favorite scene, or just a bit of information that you found interesting. This should be 4-5 lines of text in total, and it should include one or more quotes.
This file should be submitted as the source code, along with a screenshot of the program running, with files named in the usual format (which is in this case M1HW1_Lastname.*)
Additional Notes
What if you want to use the quotation symbol when writing out movie quotes?
We have seen that the quotation symbol is reserved for starting and ending strings
cout << "Like this" << endl
But it's possible to actually use the quote mark itself within a string. It's done by typing \" (backslash, quote) which escapes the quote symbol so that it no longer has a special meaning in that one case.
cout << "John said, \"Like this.\" and waved."
Sources for Movie Info
This one time, you get a pass if you want to use Wikipedia. (Wikipedia isn't the best place to get 100% accurate technical information, but for movies, it should be fine.) IMDB is another option. 
Item
M1BONUS
M1BONUS item options M1BONUS
Hide Details
Currently M1BONUS does not have a grade column -- so this is 100% optional!
However, you are welcome to try any or all of these questions. If you do, please include them in your M1HW homework submission.
These exercises are not required, but are recommended. Feel free to do any or all of them.The more you complete, the larger bonus will be applied. They are all intentionally more difficult than previous programs, so don't worry if you don't "get it" at first.
For bonus assignments, the usual late penalties do not apply. If you'd like to go back during the next module and try these, you will still receive additional points for your efforts.
For assignment M1BONUS you should write all the problems together as one program. Use cout to label each question (for example, printing "Problem 1" before the first one).
These problems all use fairly simple arithmetic, and so you may find that the "Apple Orchard" program helps you figure out where to start. They all involve declaring variables, doing math with them, and printing a result.
Whenever you have output, be sure to write appropriate cout statements to explain what the output means (so don't just print a number by itself).
1. Given a rectangle with height 8 and width 10, calculate and print the area. (This one is most similar to "Apple Orchard", except these are both of type int. The formula "Area equals length times width" will be useful.)
2. Assume a product is sold for $99.99, and sales tax is 8%. Display the product price, the amount of sales tax, and then the final cost including sales tax. (For handling monetary values, and percentages, you will want to use the double type. "Percent" is "per cent", meaning a 8% sales tax in numerical terms is 0.08 )
3. Assume a pizza is 12 inches in diameter. Using the standard formula, calculate and display the area of that pizza. (You'll need to determine what common geometrical shape best fits a pizza, then look up the formula for area for that shape.)
4. If the pizza from question 3 is cut into 8 pieces, what is the area of each piece?
As usual, file should be named in the format M1BONUS_Lastname.
