CSCI 3320

Program Assignment 6

Spring 2013

Due Date:
See class schedule.
Delivery
This is a multiple file program that must be archived using the tar command. Deliver
a single file named pa6.tgz (all lowercase) as an attachment to an email that you
send to the class account 3320@orion.ucdenver.edu. Put PA6 in the subject field, and
your name in the body of the email. Here is a tar command for this assignment.
tar –czvf pa6.tgz your_space_delimited_list_of_files

Problem:
Design a line-oriented text editor.

Input
A text file whose name is entered from the command line, stored in a buffer that
is part of a class named editor.
Output
A menu of commands that act upon the buffer.

Text editor requirements:

1. The text editor must be designed as a class. The buffer that stores the text file should
    be a member of the editor class and specifically, it should be a container that supports
    iterators.
2. The editor should provide the following functionality through menu commands.
    R. Read the text file into a buffer (container) and display on the screen.
    W. Write the contents of the buffer back to the file.
    I. Insert a new line. The user will also indicate the line number for the insertion.
    D. Delete a line. The user will indicate the line number of the deletion.
    F. Find and replace first occurrence of target which is entered by the user.
    V. View the entire contents of the buffer.

