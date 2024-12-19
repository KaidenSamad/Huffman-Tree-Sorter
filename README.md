20.9 P5: Huffman Tree from Inorder and Levelorder
Overview
You are to write a program that reads three text files given as command line parameters. The first file is an inorder traversal of a Huffman code tree and the second parameter is the levelorder traversal of the same tree. The third file is the encoded text, given as ASCII 0s and 1s.

Details
Your program should:

Compute the Huffman code tree from the two traversals.
Decode the text, writing the output to standard output (cout).
The format of the inorder and levelorder traversals will be integer values separated by whitespace. The leaves of the tree will be values < 128, representing the ASCII value of the letter. The internal nodes of the tree will be values 128 and greater.

Requirements:

You must use good object-based organization, i.e. use classes in an appropriate way.
You are allowed to use any data structure in the standard library: vector, list, stack, queue, etc.
You must use g++ -Wall -std=c++11 to compile.
Examples
An example run:

./decode inorder0.txt levelorder0.txt encoded0.txt

inorder0.txt:

66 129 76 128 77 130 65
levelorder0.txt:

130 129 65 66 128 76 77
encoded0.txt:

101010010111
Output:

ALABAMA
Another example run:

./decode inorder1.txt levelorder1.txt encoded1.txt

inorder1.txt:

10 128 33 134 121 133 117 138 114 135 106 131 71 143 100 140 32 145 101 141 89 130 108 137 99 144 111 142 116 139 120 129 98 136 104 132 46
levelorder1.txt:

145 143 144 138 140 141 142 134 135 100 32 101 137 111 139 128 133 114 131 130 99 116 136 10 33 121 117 106 71 89 108 129 132 120 98 104 46
encoded1.txt:

10100110000110110101001011110010100010011111011111010001111101001 11100111001110111100010001010010111110101010001011111100000001111
101100100110011011011110100001
Output:

You decoded the text correctly.
Good job!
This project document, including its associated files, is for your own personal use only. You may not share or post any portion of this project to an individual or online without prior written authorization.
