---
layout: page
title: Prerequisites
permalink: /prerequisites/
order: 100
published: true
---

## Prerequisites

Knowledge of basic coding tools is required for this course. This includes the following:

### Familiarity with the Command Line

- Navigate the file system using
  - `cd` Change directory using
    - `cd ../../../my_folder` relative paths names
    - `cd /Users/me/Desktop` absolute path names
  - `..` Specify the parent directory
  - `.` Specify the current directory
  - `pwd` Output the current working directory

- Modify the file system using
  - `mkdir new_directory` Make a new directory
  - `rmdir old_directory` Remove an old directory
  - `rm -rf old_directory` Recursively and forcefully remove an old directory _(be careful!)_
  - `mv old_name.txt new_name.txt` Rename files
  - `mv old_name.txt ../../` Move files

- Connect to remote machines using `ssh`
  - Creating and managing SSH keys.
  - Logging on to a remote machine via SSH.

- Find out more about command line programs by using `man`.
  - e.g. `man ls` is used to discover options for the `ls` program.
  - To exit the `man` program typq `q`.

- Resources:
  - [Learn the Linux Command Line: The Basics](https://www.lynda.com/Linux-tutorials/Learn-Linux-Command-Line-Basics/435539-2.html)
  - [Learn the Command Line](https://www.codecademy.com/learn/learn-the-command-line)
  - [Learn Enough](https://www.learnenough.com/command-line-tutorial)

### Familiarity with Git / Github

- Track work using `git` from the command line, or a GUI.
  - `git add your_file.txt` Stage a file to commit
  - `git commit -m "Your commit message."` Commit all changes with a message.
  - `git push` Push all changes to the default remote branch on github.com
  - `git pull` Retrieve all changes from a default remote branch on github.com
  - `git mv ...`, `git rm ...` to move and remove files and make sure git knows about it
- Modify existing work on github by _Forking_.
  - Forking and
- Copy a repository from github (e.g. your fork) to your working machine using `git clone`.
  - `git clone https://github.com/openframeworks/openFrameworks.git` to clone a repository to your working machine
- Resolve merge conflicts when collaborating with others.
  - Know how to resolve merge conflicts by fixing them, adding, pushing, etc.
- Control what is automatically published using `.gitignore` files.
  - Understand basic `.gitignore` syntax
- Create a new repository and publish your work online.

- Resources:
  - [Github for Poets](https://www.youtube.com/playlist?list=PLRqwX-V7Uu6ZF9C0YMKuns9sLDzK6zoiV)
  - [Up and Running with Git and GitHub](https://www.lynda.com/Git-tutorials/Up-Running-Git-GitHub/409275-2.html)
  - [Git Essential Training](https://www.lynda.com/Git-tutorials/Git-Essential-Training/100222-2.html)

### Markdown

- Write documents using markdown syntax.

- Resources:
  - [Mastering Markdown](https://guides.github.com/features/mastering-markdown/)
  - [Up and Running with Markdown](https://www.lynda.com/Web-Development-tutorials/Up-Running-Markdown/438888-2.html)
  - [Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

### Familiarity with Basic Code Concepts

- What is code?
- What is an application?
- What is a variable?
- What are arrays?
- What are _control flow statements_?
- What is an `if` / `else` statement?
- What is a `for` loop?
- What are the parts of a _function_?
  - What are _return values_?
  - What are _function parameters_?
- What do _functions_ do?
- What does a `main` function do?
- What is a `class`?
- What are the parts of a `class`?
  - What is a member variable?
  - What is a member function or method?  
- What is an instance of a class?
- What is recursion?

- Resources:
  - [Up and Running with C++](https://www.lynda.com/C-tutorials/Up-Running-C/167922-2.html)

### Data Representation

- How is binary data saved on a computer?
- How are decimal (base 10) numbers represented in binary?
- How is text represented with numbers?
- How are images represented as numbers?
- What is a "compressed" file?
- What is the difference between lossless and lossy compression?
- How do you pronounce _gif_?

- Resources:
  - [Counting in Binary](https://www.youtube.com/watch?v=apCLHmPsC68)

### Familiarity with openFrameworks and C++

#### Compiling

- How do you generate a project files with the Project Generator?
- How do you compile a program with an IDE like Xcode?

#### Program Structure

- What are the parts of a typical openFrameworks application?
  - What is the `setup()` function and how is it used?
  - What is the `update()` function and how is it used?
  - What is the `draw()` function and how is it used?
  - What is the `keyPressed(int key)` function and how is it used?
- What is an _addon_ and how do you add them to your project?

- Resources:
  - [ofBook: Animation](http://openframeworks.cc/ofBook/chapters/animation.html)

#### Objects

- What is an `ofPixels` object for?
- What is an `ofTexture` object for?
- What is an `ofImage` object for?
- How do you load am image from a file?
- How do you play a movie with `ofVideoPlayer`?
- How do you grab live video using `ofVideoGrabber`?
- How do you modify the pixels from an `ofVideoPlayer` or `ofVideoGrabber`?
- How do you display an image?

- Resources:
  - [openFrameworks Learning](http://openframeworks.cc/learning/)

### C/C++

- What is a _pointer_ and why might it be used?
- What is a _reference_ and why might it be used?
- What are _smart_ pointers and why might they be used?
  - What is a `std::unique_ptr<>`?
  - What is a `std::shared_ptr<>`?

- Resources:
  - [C++ Basics](http://openframeworks.cc/ofBook/chapters/cplusplus_basics.html)
  - [C++ Essential Training](https://www.lynda.com/C-tutorials/C-Essential-Training/182674-2.html)
