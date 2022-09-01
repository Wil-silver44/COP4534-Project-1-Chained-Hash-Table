# COP4534-Project-1-Chained-Hash-Table
Project 1 - Chained Hash Table

The goal of this project is to create an efficient storage and lookup scheme for userids and passwords utilizing an externally chained hash table. Programming will be object-oriented using C++. The assignment has two parts.

Part 1, Creating encrypted passwords.

We will use the names in "lastNames.txt," located with this project description, as userids. You will only need the data in the first column of the file. You will first generate random passwords for each userid and write them with the corresponding userid to a raw file, one userid, password combination per line. This file should be named "raw.txt." Note that we DO NOT want sequential passwords such as a1, a2, a3, a4, etc. Passwords should be 9 characters, comprised of random combinations of lower-case letters (admittedly crummy, but simpler for our purposes). Userids are unique, passwords do NOT need to be unique.

Next, you will read the unencrypted file, encrypt the passwords, and write this file back to a disk file named "encrypted.txt." We will use the Vigenere Cipher to create encrypted passwords:

The Vigenere Cipher is a simple cypher that solves the problem of using frequency analysis to defeat a basic encryption scheme. In this method, you first choose a key that you use to make a mapping of real letter to cypher by adjusting the alphabet according to the key:

Use jones as the key:

a b c d e f g h i j k l m n o p q r s t u v w x y z

| | | | | | | | | | | | | | | | | | | | | | | | | |

j k l m n o p q r s t u v w x y z a b c d e f g h i

a b c d e f g h i j k l m n o p q r s t u v w x y z

| | | | | | | | | | | | | | | | | | | | | | | | | |

o p q r s t u v w x y z a b c d e f g h i j k l m n

a b c d e f g h i j k l m n o p q r s t u v w x y z

| | | | | | | | | | | | | | | | | | | | | | | | | |

n o p q r s t u v w x y z a b c d e f g h i j k l m

a b c d e f g h i j k l m n o p q r s t u v w x y z

| | | | | | | | | | | | | | | | | | | | | | | | | |

e f g h i j k l m n o p q r s t u v w x y z  a b c d 

a b c d e f g h i j k l m n o p q r s t u v w x y z

| | | | | | | | | | | | | | | | | | | | | | | | | |

s t u v w x y z  a b c d e f g h i j k l m n o p q r

You would then encode data :  moge

Part 2. Testing userid/password combinations

Now we get to the hashing part. You will build an externally chained hash table of userids and passwords. You will process "encrypted.txt" to create the hash table by hashing on userid. At that appropriate location, you will store the unencrypted userid and encrypted password. Recall that an externally chained hash table is pretty easy to implement as simply a collection of linked lists:
![Proj1](https://user-images.githubusercontent.com/89366767/187961614-c0afaaad-cbb1-4921-9ff5-368ad18578c5.jpg)

Your program will then automatically test:

5 legal userids and passwords by testing the first 5 entries in "raw.txt." The idea is to hash into the table by userid, find the userid in the table, encrypt the plaintext password, and show that it matches the password on that entry.
5 legal userids and ILLEGAL passwords by testing the first 5 entries in "raw.txt." The idea is to hash into the table by userid, find the userid in the table, change one letter in the unencrypted password, encrypt the now illegal plaintext password, and show that it does not match the password on that entry.
No user interaction should be required by the program.

Output:
As described in class, print to the console indicate the five legal and illegal userid and password combinations you tried and print them to the console. The "Password" column indicates the plaintext password from raw.txt. "Attempted" indicates the plaintext password you used.

Legal:

Userid    Password  Attempted Result

SMITH     asdfvfrty asdfvfrty match

JOHNSON   okmnjuygt okmnjuygt match

WILLIAMS  yhnbgtrde yhnbgtrde match

JONES     wsxzaqwer wsxzaqwer match

BROWN     bhvfgtyui bhvfgtyui match

Illegal:

Userid      Password   Attempted  Result

SMITH       asdfvfrty  xsdfvfrty  no match

JOHNSON     okmnjuygt  xkmnjuygt  no match

WILLIAMS    yhnbgtrde  xhnbgtrde  no match

JONES       wsxzaqwer  xsxzaqwer  no match

BROWN       bhvfgtyui  xhvfgtyui  no match

About the use of GitHub:

I STRONGLY suggest that you create GitHub repos for the projects in this course and that you routinely pull the current version of your project and push updates. You should do this because:

1. You will use configuration management tools of some sort from the first day you are working in the world.
2. If any copying of assignments is detected, we can trace your record of commits to decide who copied from whom.

I suggest that you employ a test-driven development approach because:

1. You are likely to encounter a development culture in which it is encouraged or required.
2. It will force you to do incremental development and always have a running program.

I will not produce test cases to which you might code because

1. that will be your responsibility in the real world
2. test cases imply a detailed design of the project. At this level, you must be able to produce your own designs.

Deliverables

1) Makefile
2) User's manual
3) UML diagram
4) C++ Source Code (.hpp and .cpp)
5) lastNames.txt

Submission

Your project must be submitted using the instructions below to be graded.

1. Compile and run your program one last time before submitting it. Your program must run in Linux in the multiplatform lab. 

2. Place all deliverables in a single folder that is named with your last name and first name initial. For example, if your name is Katie Brodhead, the folder should be brodheadk. If you are a MacOS user, delete the _MacOS_ folder before zipping up your submission.

3. Create a "zip"  file (using WinZip or similar program) to hold your project files.

The name of your zip file should be named exactly like the single folder inside it but with the .zip extension. For instance:  brodheadk.zip.

So, this is how your submission should be structured (if your name were Katie Brodhead) for this project:

brodheadk.zip

    brodheadk              // the folder holding all your files

        file1.hpp          // with the actual names of your files,

        file1.cpp          // of course ...

        ...

        UserManual.docx

        UML.jpg            // please export .jpg from Dia
        lastNames.txt

last name data file is lastNames.txt in this repository.
