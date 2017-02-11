---
layout: page
title: Syllabus
permalink: /syllabus/
order: 100
---

## Intro to Computer Vision and Machine Learning <small>ARTTECH 3039</small>

Semester, Year
:   Spring, 2017

Meeting Times
:   Tuesday 9am-4pm

Meeting Location
:   MacLean 400

Instructor
:   [Christopher Baker](https://christopherbaker.net)

Class Forum
:   [https://ats.community/c/courses/arttech-3039](https://ats.community/c/courses/arttech-3039)

Class Website
:   [http://saic-ats.github.io/ARTTECH-3039/](http://saic-ats.github.io/ARTTECH-3039/)

Public Repository (code examples, etc)
:   [https://github.com/SAIC-ATS/ARTTECH-3039/](https://github.com/SAIC-ATS/ARTTECH-3039/)

Private Repository (assignment submission, etc)
:   [https://github.com/SAIC-ATS/ARTTECH-3039-Spring-2017-Private](https://github.com/SAIC-ATS/ARTTECH-3039-Spring-2017-Private)

TA
:   N/A

--------------------------------------------------------------------------------

### Instructor Bio
[Christopher Baker](http://christopherbaker.net) is an artist whose work engages the rich collection of social, technological and ideological networks present in the urban landscape. He creates artifacts and situations that reveal and generate relationships within and between these networks. Christopher’s work has been presented worldwide and he contributes to the open source community at [http://github.com/bakercp](http://github.com/bakercp).

## TA Bio
N/A

--------------------------------------------------------------------------------

## Course Description
Computer vision allows machines to see and understand their environment. This course will equip students with the practical skills and critical theory needed to both employ and critically engage these techniques. Real-time body tracking, facial recognition and gesture analysis using RGB+D and LiDAR sensors, artificial intelligence and machine learning will be emphasized. Students will explore and critique contemporary applications ranging from automated mass surveillance to interactive installations. A final project will build on in-class workshops, technical exercises, critical readings and discussions.

## Course Goals
- Working and applied knowledge "classical" computer vision techniques.
- Working and applied knowledge of modern computer vision techniques that leverage machine learning.

## Course Values
- Sharing / Open
    - Documentation
    - [DIWO](http://furtherfield.org/projects/diwo-do-it-others-resource)
    - Publish
    - [Cult of Done](http://www.brepettis.com/blog/2009/3/3/the-cult-of-done-manifesto.html)

## Methodology
Students will engage in individual in-lab and home assignments, class presentations, lectures, discussions, assigned readings, group and individual projects and desk critiques. Visiting artists / faculty may enhance the experience and offer additional perspectives.

## Assignments
The course may include workshops and several projects, relevant technical and theoretical reading, written online responses, technical research and outings.

## Class Text(s)
There is no official class text, though there are several books that we'll reference on occasion.

### openFrameworks
- [ofBook](https://github.com/openframeworks/ofBook)

### Computer Vision
- [Practical OpenCV](https://link.springer.com/book/10.1007%2F978-1-4302-6080-6)
- [Learning OpenCV : computer vision with the OpenCV library](https://vufind.carli.illinois.edu/vf-sai/Record/sai_123825)
- [Computer Vision: Algorithms and Applications](http://szeliski.org/Book/)

### Machine Learning
- [ML4A](https://ml4a.github.io/index/) _In progress book_

## Reading and other Resources
Posted on the course website.

## Materials
Provided by the student as needed.

## Attendance
1. Students are best served by attending all classes.
2. Missing three classes will result in a class failure. This is strictly enforced.
3. Six or more unexcused late arrivals or early departures will result in class failure.

_Tip: If you are going to be absent, late to class, or need to depart early, please contact me BEFORE class starts. This is so I can make sure you have what you need to succeed!_

## Wait Lists
Students wait-listed for classes will be admitted on a space available basis determined by instructors’ discretion (in consultation with the department chair).

## Grading Procedure/Criteria
- Grades are credit / no-credit for this course. Credit is based on several factors: 30% participation (discussions, critiques, etc), 70% projects / assignments.
- Incomplete grades will not be offered.

## Writing Assistance
[Writing Center](http://www.saic.edu/webspaces/portal/advising/write\_center.html)

## Special Needs
[Disability and Learning Resource Center](http://www.saic.edu/lifeatsaic/wellnesscenter/disabilityandlearningresourcecenter/)

## Course Schedule
_(subject to change based on incoming skills and experience)_

### Week 0 <small>31 Jan, 2017</small>
- Course Overview
  - Classic Computer Vision
  - Machine Learning
    - "What is artificial intelligence?"
    - "What is machine learning?"
- Review
  - git / github
    - Set up command line.
    - Fork, clone, add, commit, push, pull-request.
  - openFrameworks
    - Installation
      - Development version (clone `master` vs. download nightly)
    - Directory layout.
    - Project Generator
      - How to generates project files.
    - Install initial addons
      - Many addons found at [http://ofxaddons.com/](http://ofxaddons.com/).
        - Tips for finding "fresh" addons.
      - Addons we'll use
        - [ofxPS3EyeGrabber](https://github.com/bakercp/ofxPS3EyeGrabber/)
          - A driver for the cheap and versatile [PS3 Eye Camera](https://en.wikipedia.org/wiki/PlayStation_Eye).
        - ofxOpenCv _(Included with openFrameworks as a core addon)_
          - Contains the [OpenCV](http://opencv.org/) library.
          - Contains some older classes to simplify interacting with OpenCV in openFrameworks.
        - [ofxCv](https://github.com/bakercp/ofxCv) (_develop branch of @bakercp's fork is up-to-date with latest openFrameworks_)
          - Contains a lot of OpenCV examples along with a modern collection of wrappers.
    - Compiling an openFrameworks application
      - Compiling with Xcode.
      - Compiling on the command line with the `Makefile`.
    - Program Structure
  - Code Basics
    - Variables - data, memory, etc.
    - Arrays - collections of variables.
    - `for` loops, including ``
    - `if` / `else`
  - Image Representation
    - Single 1-dimensional array
    - Accessing individual elements
      - Nested for-loop for x and y
- Intro to Computer Vision
- Pixel Tracking
  - Brightness Tracking
  - Color Tracking
- Example
  - Laser Pointer Tracker

- Color Tracking
  - [Color Distance](https://en.wikipedia.org/wiki/Color_difference)

### Week 1 <small>31 Jan, 2017</small>
- Classical Computer Vision Part 0
  - Binary Images
    - Why binary images?
      - Background vs. Foreground
    - Background Subtraction
      - Importance of "helpful" auto-camera parameters
        - Auto gain, auto white balance, auto shutter speed, etc.
        - Should be fixed for many background subtraction situations.
      - Fixed Background Subtraction
        - `examples/computer_vision/opencvExample`
      - Adaptive Background Subtraction
        - `ofxCv/example-background`
    - Brightness Thresholding
      - Fixed Threshold
        - `ofxCv/example-threshold`
      - Adaptive Threshold
        - `ofxCv/example-threshold` (press mouse)
  - Image Filtering
    - Brightness, Contrast, etc.
    - Morphological Operators, Lines and Edges
      - Hough, Canny, Scharr, Sobel, Structured Forest, [etc](http://docs.opencv.org/3.1.0/d0/da5/tutorial_ximgproc_prediction.html)

  - ofPolyline Review
  - Simple Infinite Impulse Response [Low Pass Filters](https://en.wikipedia.org/wiki/Low-pass_filter#Simple_infinite_impulse_response_filter)
   > Low-pass filters provide a smoother form of a signal, removing the short-term fluctuations, and leaving the longer-term trend.

- After Lunch
  - Image Segmentation
  - Contours
  - Object Tracking
  - Motion Detection
    - Frame Differencing
      - In class Example
    - Optical Flow
      - https://en.wikipedia.org/wiki/Optical_flow

https://www.youtube.com/watch?v=a67f8P9f3EU
https://vimeo.com/106798521
https://www.youtube.com/watch?v=XNHv6VryB8o
https://vimeo.com/8525186
http://www.yesyesno.com/night-lights/
https://www.youtube.com/watch?v=0177x_ajmuU
https://www.youtube.com/watch?v=dqZyZrN3Pl0
https://youtu.be/dmmxVA5xhuo
https://vimeo.com/15136354
https://www.youtube.com/watch?v=d4DUIeXSEpk
https://www.youtube.com/watch?v=VdrujesfIBQ
http://www.tmema.org/messa/messa.html
  - http://www.tmema.org/messa/technical.html
  - http://www.tmema.org/messa/diagrams/
    - http://www.tmema.org/messa/diagrams/old/concert_2_screen/messa_optical_configurations.pdf
    - http://www.tmema.org/messa/diagrams/more_messa_diagram_2005.pdf
- https://www.youtube.com/watch?v=I5__9hq-yas
- https://www.youtube.com/watch?v=rHTttiliLz8
- https://www.youtube.com/watch?v=MPG-LYoW27E

### Week 2 <small>07 Feb, 2017</small>
- Classical Computer Vision Part 1
  - Homography and Rectification
  - Video Mapping / Quad Mapping
  - Detection
  - Recognition

### Week 3 <small>14 Feb, 2017</small>
- Contemporary Sensing with RGB+D
  - Kinect
  - 3D Segmentation
  - Skeleton Tracking
- LIDAR
- Point Clouds

### Week 4 <small>21 Feb, 2017</small>
- Machine Learning 0
  - Introduction to Machine Learning
  - Basic Training
    - MNIST
  - [t-SNE](https://lvdmaaten.github.io/tsne/), [ofxTSNE](https://github.com/genekogan/ofxTSNE)

### Week 5 <small>28 Feb, 2017</small>
- Machine Learning 1
  - Object Recognition Darknet / Yolo
    - https://github.com/mrzl/ofxDarknet
    - http://stoj.io/projects/an-algorithm-watching-a-movie-trailer/
    - https://github.com/genekogan/screengrab-caption
    - http://pjreddie.com/darknet/yolo/
    - https://github.com/TensorBox/TensorBox
  - [Multi-Person Pose Estimation](https://www.youtube.com/watch?v=pW6nZXeWlGM) and [this](https://github.com/ZheC/Realtime_Multi-Person_Pose_Estimation)

### Critique Week <small>07 Mar, 2017</small>
- No class.

### Week 6 <small>14 Mar, 2017</small>
- Machine Learning 2
  - Image Generation with [Pix2Pix](https://github.com/phillipi/pix2pix), ([example](https://github.com/brangerbriz/docker-StackGAN))

### Week 7 <small>21 Mar, 2017</small>
- Machine Learning 3
  - Adversarial Networks [GANs](https://github.com/brangerbriz/docker-StackGAN)

### Week 8 <small>28 Mar, 2017</small>
- Machine Learning 3
  - TBA

### Week 9 <small>04 April, 2017</small>
  - [Automation Show Field Trip](http://www.automateshow.com/)
    - We will be on the lookout for computer vision and machine learning technologies.
  - Open Studio

### Week 10 <small>11 April, 2017</small>
  - Open Studio

### Week 11 <small>18 April, 2017</small>
  - Open Studio

### Week 13 <small>25 April, 2017</small>
  - Open Studio

### Week 14 <small>02 May, 2017</small>
  - Final Critiques

### Week 15 <small>09 May, 2017</small>
  - Documentation Critiques

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
