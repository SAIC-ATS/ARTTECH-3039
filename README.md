ARTTECH-3039
============

_Introduction to Computer Vision and Machine Learning_

Course Website: [https://saic-ats.Github.io/ARTTECH-3039/](https://saic-ats.github.io/ARTTECH-3039/)

Installation
------------

This repository should be placed in your openFrameworks root directory. Your openFrameworks directory should look something like this:

```
openFrameworks/
├── ARTTECH-3039
│   ├── README.md
│   ├── Session_00
│   ├── docs
│   └── ...
├── CHANGELOG.md
├── CODE_OF_CONDUCT.md
├── CONTRIBUTING.md
├── LICENSE.md
├── README.md
├── addons
├── apps
├── docs
├── examples
├── export
├── libs
├── other
├── projectGenerator-osx
├── scripts
├── tests
├── tutorials
└── ...
```

### Setup Options

#### To keep an up-to-date copy of the repository

1.  In the terminal, change your working directory to the openFrameworks root:
    -   `cd MY_OPENFRAMEWORKS_DIR/`
2.  Clone the repository
    -   `git clone https://Github.com/SAIC-ATS/ARTTECH-3039.git`
3.  To update your copy to the latest ..
    -   `git pull`

#### To contribute to the repository (optional)

1.  Fork [the repository](https://Github.com/SAIC-ATS/ARTTECH-3039) on Github.
2.  In the terminal, change your working directory to the openFrameworks root:
    -   `cd MY_OPENFRAMEWORKS_DIR/`
3.  Clone the repository, filling in `YOUR_USER_NAME` with your Github user name.
    -   `git clone https://Github.com/YOUR_USER_NAME/ARTTECH-3039.git`
4.  Create a remote link to the main repository and call it _upstream_
    -   `git remote add https://Github.com/SAIC-ATS/ARTTECH-3039.git`
5.  To update your copy to the latest upstream ..
    -   `git pull upstream master`

If, when updating your fork, you get a terminal screen that looks like:

```
Merge branch 'master' of https://Github.com/SAIC-ATS/ARTTECH-3039-Spring-2017-Private

# Please enter a commit message to explain why this merge is necessary,
# especially if it merges an updated upstream into a topic branch.
#
# Lines starting with '#' will be ignored, and an empty message aborts
# the commit.
~             
~
~
~
~
```

... it means that your git wants you to issue a commit message and the default terminal text editor is set to `vim`. `vim` is a super cool [text editor](http://www.openvim.com/), but not for the faint of heart. To get out of that screen, you should use the following key sequence:

`ESCAPE`, `:`, `w`, `q`, `ENTER`

This will simply allow the merge to proceed with the default message.

If you would like to switch your default text editor to something simpler, like `nano`, configure git like this:

```
git config --global core.editor "nano"
```

If you'd like to use a GUI based text editor, you can use something like Atom.io by following [these instructions](http://stackoverflow.com/a/31389989/1518329).

To propose changes, create `git add` and `git commit` those changes, then issue a pull request on Github.
