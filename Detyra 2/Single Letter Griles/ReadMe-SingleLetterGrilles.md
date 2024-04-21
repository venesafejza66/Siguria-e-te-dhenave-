# Grille Encryption

This program implements the grille encryption technique, which is a historical method used to encrypt text. Grille encryption involves placing characters of the text into a grid based on a predefined pattern, and then reading off the characters in a specific order to form the encrypted text.

## Overview

The program takes a text input from the user, generates a random grille pattern, and then encrypts the text using this pattern. Grille encryption has been used historically for secrecy in communication. It provides a simple yet effective way to obscure text without using complex algorithms.

## Usage

To use this program, follow these steps:

1. **Compile**: Compile the code using a C++ compiler.
2. **Run**: Run the compiled executable.
3. **Input Text**: Enter the text you want to encrypt when prompted.
4. **Generate Pattern**: The program will generate a random grille pattern and display it.
5. **Encryption**: The encrypted text will be displayed.

## Grille Patterns

A grille pattern consists of a grid of cells, typically square, where each cell may be filled or empty. In this implementation, we use single-letter grilles, where 'X' indicates a filled cell and 'O' indicates an empty cell. Single-letter grilles have historical significance in cryptographic communication due to their simplicity and ease of use.

### History of Single-Letter Grilles

Single-letter grilles have been used throughout history for various cryptographic purposes. One notable example is the use of single-letter grilles by Mary Queen of Scots and her associates in the Babington Plot of 1586. They used a single-letter grille to encrypt their messages, contributing to the intrigue and secrecy of the plot.

### Modern Applications

While single-letter grilles may seem simplistic compared to modern encryption methods, they still find applications in certain contexts. They are useful for educational purposes, demonstrating basic cryptographic principles. Additionally, they can be employed in situations where simplicity and ease of use are prioritized over advanced security features.

## Code Explanation

- The `encryptText` function takes the input text and a grille pattern as parameters and encrypts the text based on the pattern.
- The `generateRandomGrillePattern` function generates a random grille pattern consisting of 'X' and 'O'.
- In the `main` function, the user is prompted to enter the text to encrypt.
- A random grille pattern is generated using `generateRandomGrillePattern`.
- The text is encrypted using the `encryptText` function and the generated grille pattern.
- The encrypted text is then displayed to the user.

## Example
Enter the text to encrypt: Hello, world!
Generated grille pattern: OXXOXOOXXOOXOXOX
Encrypted text: Hreowol ld,lo!l

## Notes

- The grille pattern consists of 16 characters, representing a 4x4 grid.
- 'X' in the grille pattern indicates where characters from the text should be placed.
- 'O' indicates empty spaces in the grid where no characters are placed.

