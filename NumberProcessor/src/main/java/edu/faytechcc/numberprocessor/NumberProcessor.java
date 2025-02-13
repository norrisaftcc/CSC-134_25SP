/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package edu.faytechcc.numberprocessor;


import javax.swing.JOptionPane;
/**
 *
 * @author norrisa8373
 */

public class NumberProcessor {
    /**
     * Processes a string input and attempts to convert it to an integer.
     * This method demonstrates basic input validation and error handling.
     * 
     * Things to consider:
     * 1. What should happen if the user enters nothing?
     * 2. What should happen if the user enters "abc"?
     * 3. What should happen if the user enters "3.14"?
     * 
     * @param input The string that should be converted to an integer
     * @return A message describing what happened during processing
     */


    public static void main(String[] args) {
        // Program will guess a number we think of from 1 to 100
        // Make an object out of this, so we can call our functions
        NumberProcessor p = new NumberProcessor();   

        // Number guessing game
        p.showMessage("This is the Number Guessing Game!");
        p.showMessage("Enter number from 1-100. I won't peek!");
        Integer userNum = p.getInteger();
        Integer guess   = 50; // start in the middle!
        Integer low     = 1;
        Integer high    = 100;
        Integer feedback; 
        final int TOO_HIGH = 1;
        final int TOO_LOW  = 2;
        final int RIGHT    = 3;
        Boolean keep_playing = true;
        // Until the computer guesses right...
        while (keep_playing) {
            // Have the computer guess
            p.showMessage("Is it " + guess + "?");
            // Find it out if it's too high, too low, or just right
            p.showMessage("Enter 1 for too high, 2 for too low, 3 if it's right.");
            feedback = p.getInteger();
            // if just right, computer wins!
            if (feedback == RIGHT) {
                keep_playing = false;
                p.showMessage("Computer Wins!");
                if (guess != userNum) {
                    p.showMessage("Wait, you let me win...");
                }
            }
            else if (feedback == TOO_HIGH) {
                // next guess is lower
                high = guess;
                guess = (low + high) / 2;
            }
            else if (feedback == TOO_LOW) {
                // next guess is higher
                low = guess;
                guess = (low + high) / 2;
            }
            else {
                // user gave bad feedback, cpu quits
                p.showMessage("That's not 1, 2, or 3, so I give up.");
                keep_playing = false;
            }
        }
    }
    
    public void showMessage(String message) {
        JOptionPane.showMessageDialog(null, message);  
    }
    
    public Integer getInteger() {
        Integer answer = -1; // the number the user types
        while (answer == -1) {
            // Process: Ask for number, validate it, move on
            // input is always a string
            String userInput = JOptionPane.showInputDialog("Enter an integer:");
            // now convert it into a number
            answer = this.process(userInput); // use ourselves (this)
            // Finally, show what we did
            if (answer == -1) {
                JOptionPane.showMessageDialog(null,"That's not an Integer, please try again.");
            }
            else {
                // Debug message
                //JOptionPane.showMessageDialog(null, "You entered: " + answer);
            }
        }
        return answer;  
    }
    
    public Integer process(String input) {
        // Convert the string into an Integer
        Integer number = -1; // or some obviously wrong value
        // If we fail, then report error
        // exception handling
        try {
            number = Integer.parseInt(input);
        }
        catch (NumberFormatException e) {
            System.err.println(input + " is not an Integer!");
        }
        return number;        
    }
}