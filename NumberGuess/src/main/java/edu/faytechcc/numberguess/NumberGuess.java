/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package edu.faytechcc.numberguess;

import javax.swing.JOptionPane;

/**
 *
 * @author norrisa8373
 */
public class NumberGuess {

    
    
    
    // Convert String into Integer (or -1 if error)
    public Integer process(String input) {
        // -1 means error in this program
        Integer value = -1;
        // try / catch
        try {
            // Convert String to Integer
            value = Integer.parseInt(input); 
        }
        catch (NumberFormatException e) {
            System.err.println(input + " is not an Integer!");
        }
        return value;
    }
    
    public static void main(String[] args) {
        // Bake the class into an object so we can use it
        NumberGuess g = new NumberGuess();
        
        // Test Case 1: Ask for a number
        Integer num1 = g.getInteger();
    }
    
    public Integer getInteger() {
        String userInput = JOptionPane.showInputDialog("Enter a whole number (like 42):");
        Integer result = this.process(userInput); // only allow ints
        // Show the answer, or a decent error message
        if (result != -1) {
            JOptionPane.showMessageDialog(null, result);
        }
        else {
            JOptionPane.showMessageDialog(null, userInput + " is not an Integer!");
        }      
        
    }
}