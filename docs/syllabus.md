---
layout: page
title: Syllabus
permalink: /syllabus/
order: 0
---

## Intro to Computer Vision and Machine Learning <small>ARTTECH 3039</small>
Semester, Year
:   {{ site.semester }}, {{ site.year }}

Meetings
:   {% for meeting in site.meetings %}{% assign section = forloop.index | prepend: '000' | slice: -3, 3 %}(-{{ section }}) {{ meeting }}{% if site.meetings.size > 0 %}{% unless forloop.last %},{% endunless %} {% endif %}{% endfor %}

Meeting Location
:   {% for location in site.locations %}{% assign section = forloop.index | prepend: '000' | slice: -3, 3 %}(-{{ section }}) {{ location }}{% if site.locations.size > 0 %}{% unless forloop.last %},{% endunless %} {% endif %}{% endfor %}

People
:   {% for person in site.people %}{{person.role}}: [{{ person.name }}]({{ person.url }}){% if site.people.size > 0 %}{% unless forloop.last %},{% endunless %} {% endif %}{% endfor %}

{% for site in site.sites %}
{{ site.name }}
:   [{{ site.url }}]({{ site.url }}) {% if site.comment %}_{{ site.comment }}_{% endif %}
{% endfor %}

--------------------------------------------------------------------------------

## Bios

{% for person in site.people %}
{{ person.bio }}
{% endfor %}

--------------------------------------------------------------------------------

## Course Description
{{ site.description }}

## Course Goals
-   Working and applied knowledge "classical" computer vision techniques.
-   Working and applied knowledge of modern computer vision techniques that leverage machine learning.

## Course Values
-   Sharing / Open
    -   Documentation
    -   [DIWO](http://furtherfield.org/projects/diwo-do-it-others-resource)
    -   Publish
    -   [Cult of Done](http://www.brepettis.com/blog/2009/3/3/the-cult-of-done-manifesto.html)

## Methodology
Students will engage in individual in-lab and home assignments, class presentations, lectures, discussions, assigned readings, group and individual projects and desk critiques. Visiting artists / faculty may enhance the experience and offer additional perspectives.

## Class Structure (Typical)
-   9:00 -  9:30 : Look at new artists, catch up on the week's CV/ML headlines.
-   9:30 - 10:15 : Lecture Part 1.
-   10:15 - 10:30 : Break
-   10:30 - 12:00 : Lecture Part 2.
-   12:00 - 01:00 : Lunch
-   01:00 - 02:30 : Hands-on Workshop.
-   02:30 - 02:45 : Break
-   02:45 - 04:00 : Open Studio (Homework, Projects, Discussion, etc).

## Assignments
The first 66% of the course will be built on well-constrained code-based assignments. These assignments have clear goals and are intended to build confidence and code competency. The last 34% of the course is focused on integrating these techniques, technologies and critical discussions with your existing creative / research practice. The final project will be part of an exhibition.

## Creative Coding Tools
We will be doing most of our work in C++ with openFrameworks. Most modern computer vision and machine learning tools are built with C++ at their core. That said, many online examples use Python to interact with the same code. We will primarily focus on well-documented libraries that well-documented and easily compatible with openFrameworks (e.g. [OpenCV](https://opencv.org/) and [dlib](http://dlib.net/)).

## Class Text(s)
There is no single class text, though there are several online books (and available for purchase) that we'll reference on occasion.

-   openFrameworks
    -   Collaboratively Written. [ofBook](https://github.com/openframeworks/ofBook)

-   Computer Vision
    -   Szeliski, Richard. [Computer Vision: Algorithms and Applications](http://szeliski.org/Book/)
    -   Brahmbhatt, Samarth. [Practical OpenCV](https://link.springer.com/book/10.1007%2F978-1-4302-6080-6)
    -   Bradski, G. & Kaehler, A. [Learning OpenCV : computer vision with the OpenCV library](http://www-cs.ccny.cuny.edu/~wolberg/capstone/opencv/LearningOpenCV.pdf)

-   Machine Learning
    -   Kogan, G.[ML4A](https://ml4a.github.io/index/)
    -   Goodfellow et al. [Deep Learning](http://www.deeplearningbook.org/)
    -   Nielsen, M. [Neural Networks and Deep Learning](http://neuralnetworksanddeeplearning.com/)

## Reading and other Resources
Posted on the course website.

## Materials
Provided by the student as needed.

## Attendance
1.  Students are best served by attending all classes.
2.  Missing three classes will result in a class failure. This is strictly enforced.
3.  Six or more unexcused late arrivals or early departures will result in class failure.

_Tip: If you are going to be absent, late to class, or need to depart early, please contact me BEFORE class starts. This is so I can make sure you have what you need to succeed!_

## Wait Lists
Students wait-listed for classes will be admitted on a space available basis determined by instructors’ discretion (in consultation with the department chair).

## Grading Procedure/Criteria
-   Grades are credit / no-credit for this course. Credit is based on several factors: 30% participation (discussions, critiques, etc), 70% projects / assignments.
-   Incomplete grades will not be offered.

## Writing Assistance
[Writing Center](http://www.saic.edu/webspaces/portal/advising/write\_center.html)

## Special Needs
[Disability and Learning Resource Center](http://www.saic.edu/lifeatsaic/wellnesscenter/disabilityandlearningresourcecenter/)

## Study Sessions
-   Students are encouraged to form a study group to meet and work on the homework.
-   The TA will be available during TA office hours (TBA).

## Class Exhibition
-   The course will culminate in a class exhibition with an opening during the second-to-last week of class.

## Course Schedule
_(subject to change based on incoming skills and experience)_

{% assign sessions = site.sessions | sort: 'name' %}
{% for session in sessions | sort: 'name' %}

### {{ session.name }} <small>{% for date in session.dates %}{% assign section = forloop.index | prepend: '000' | slice: -3, 3 %}({{ section }}: {{ date | date_to_string }}){% endfor %}</small>
-   {{ session.title }}

{% endfor %}
