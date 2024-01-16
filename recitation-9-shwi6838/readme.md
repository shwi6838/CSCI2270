# CSCI 2270 – Data Structures - Recitation 9
## Overview
Welcome to CSCI 2270 recitation 9! This recitation is to get you acquainted with graphs. 

## Objectives

1. Accept the recitation from Github Classroom
2. Clone the recitation to your local work environment
3. Push your solution to your repository
4. Upload the zip file on Canvas


## Where to Start
The video covers the details of working with git, GitHub, and GitHub classroom. This will be the workflow for all of the recitations in this course. 

Getting started with git and GitHub for Students Video: https://youtu.be/7_x86HeoglQ

Having accepted your recitation in GitHub Classroom, a "private" repository has been automatically created for you. The repository can only be viewed by you and the CSCI 2270 teaching team. Other students cannot see your repo. You can view the contents of your repo by going to the link which was created for you upon accepting the recitation. Once you are ready to begin working on the recitation you will need to *clone* the repository into a suitable development environment. We recommend that you use JupyterHub as your coding environment, and the instructions are provided below. Alternatively, you can use your personal Linux/Mac/Windows machine, but you are on your own as far as setting up the environment (If you are using Windows, you should have the Windows Subsystem for Linux and Ubuntu installed.)

1. Got to JuptyerHub in your browser by navigating to https://coding.csel.io/
2. Choose the CSCI 2270 Data Structures environment
3. Select `File -> New -> Terminal`
4. Now you are ready to *clone* your repository from the remote GitHub repo to your local JupyterHub directory. You can do so by issuing the following command, replacing the SSH URL with your personal one. You can find your unique URL by clicking on the green *Code* icon on your GitHub page.  
```console
jovyan@jupyter-yourcuid:~$ git clone git@github.com:cu-csci-2270-fall-2022/recitation-X-MyGitUsername.git
```
5. At this point you can begin working with your code. We recommend that you use the VSCode editor environment. Go to `File -> New -> Launcher` and click on `VS Code IDE`. This opens a new browser tab.
6. Within VS-Code, select `File -> Open` and then find the directory you just cloned. It should be `/home/jovyan/recitation-X-username`.

## Completing the recitation
Please refer `RecitationX.pdf` for more details.

### Checking code into GitHub
**Important:** one of the main advantages of using git and GitHub is that it gives you a very convenient way to back up your changes. For now, you will only need to know how to `add`, `commit`, and `push`.  (You are encouraged to learn further git commands throughout the semester.) Any time you get to a point where you want to save your code (for example, you got a function to pass a test case), do the following in the terminal:
1. Stage your changes for a commit. This means that any changes you want to save, need to be added explicitly. (Note that you have all kinds of files that are present in your repository. You only need to add the ones you have changed and want to save.) For example, let's say we want to stage the changes we made in `functions.cpp`. 
    ```console
    $ git add functions.cpp
    ```
2. Commit the changes to our local repository:
    ```console
    $ git commit -m 'this is my first commit'
    ```
3. Finally, push the changes from your local version of the repo to the remote repo on GitHub. 
    ```console
    $ git push
    ```
You can run the above steps as many times as you want. Each time you commit/push your changes, a new commit number will be added to your repository. If ever you need to go back to a previous commit, you can fairly easily. However, further git discussion is beyond the scope of this course.

## Submission
In order to submit your recitation, you need to do:

1. Push your changes to the remote repository.
2. Go to Canvas, locate the link titled **“Recitation 9”** and upload the zipped repository with your changes. Make sure you do submit your recitation prior to the deadline specified on Canvas.

