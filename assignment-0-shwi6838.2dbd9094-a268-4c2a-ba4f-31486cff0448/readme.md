# CSCI 2270 – Data Structures - Assignment 0
## Overview
Welcome to your first CSCI 2270 assignment! This is a preview assignment to get you acquainted with the workflow of the coding assignments for this class. While the coding aspect of this assignment is trivial, it is still very important that you complete it to so you are ready to tackle the challenges of the future assignments.

## Objectives

1. Accept the assignment from Github Classroom
2. Clone the assignment to your local work environment
3. Learn the basics of committing and checking-in changes with git
4. Understand how to receive points for completing the coding problems


## Where to Start
Before proceeding with this assignment, please watch the following video carefully. The video covers the details of working with git, GitHub, and GitHub classroom. This will be the workflow for all of the assignments in this course. 

Getting started with git and GitHub for Students Video: https://youtu.be/7_x86HeoglQ

Having accepted your assignment in GitHub Classroom, a "private" repository has been automatically created for you. The repository can only be viewed by you and the CSCI 2270 teaching team. Other students cannot see your repo. You can view the contents of your repo by going to the link which was created for you upon accepting the assignment. Once you are ready to begin working on the assignment you will need to *clone* the repository into a suitable development environment. We recommend that you use JupyterHub as your coding environment, and the instructions are provided below. Alternatively, you can use your personal Linux/Mac/Windows machine, but you are on your own as far as setting up the environment (If you are using Windows, you should have the Windows Subsystem for Linux and Ubuntu installed.)

1. Got to JuptyerHub in your browser by navigating to https://coding.csel.io/
2. Choose the CSCI 2270 Data Structures environment
3. Select `File -> New -> Terminal`
4. Now you are ready to *clone* your repository from the remote GitHub repo to your local JupyterHub directory. You can do so by issuing the following command, replacing the SSH URL with your personal one. You can find your unique URL by clicking on the green *Code* icon on your GitHub page.  
```console
jovyan@jupyter-yourcuid:~$ git clone git@github.com:cu-csci-2270-fall-2022/assignment-0-MyGitUsername.git
```
5. At this point you can begin working with your code. We recommend that you use the VSCode editor environment. Go to `File -> New -> Launcher` and click on `VS Code IDE`. This opens a new browser tab.
6. Within VS-Code, select `File -> Open` and then find the directory you just cloned. It should be `/home/jovyan/Assinment-0-username`. 
7. Before we start writing any code, let's compile the starter code and see how we can run the executables.
    * Open up the terminal: `Terminal > New Terminal`
    * Navigate to `build` directory
    ```console
    jovyan@jupyter-yourcuid:~$ cd build/
    ```  
    * Run `CMake` to set up the build environment 
    ```console
    jovyan@jupyter-yourcuid:~$ cmake ..
    ``` 
    * Now compile and build the executables:
    ```console
    jovyan@jupyter-yourcuid:~$ make
    ``` 
    * Now we have two executable ready to run, `run_app_1` and `run_tests_1` (Note: in future assignments, you will sometimes have more than one `run_app` executable.) 
        * `run_app_1` is the executable that was build using your `/app_1` and `/code_1` source code files. You can use this to try a `Hello World` type of program to get familiar with the framework. 
        * `run_tests_1` is the executable containing the test cases that will be used for your assignment. Running this prior to solving any of the required problems should give you a score of 0.
        * Both executables will be located within the build directory, so run the following terminal command to execute:  
    ```console
    jovyan@jupyter-yourcuid:~$ ./run_app_1
    ``` 

## Completing the Assignment
For this assignment, we intentionally made this part trivial. In the future assignments, the initial setup steps (as described in the previous section) should only take a moment, and the bulk of your required work will be described here.  

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

### Test Cases
Open up the test code file `/tests/test_preview.cpp` to see what test cases you need to pass to get points on the assignment. 

#### Part 1
In `test_preview.cpp` scroll down until you find the test function labeled `TestFooA`. You can see that this is a unit test for the `fooA()` function. An assert is used to check the output for correctness. Go to `/code_1/functions.cpp` to see if you can implement this function to return the correct output (again, this is intentionally trivial.) Once you have written the code and you want to check your solution, run `make` (remember to stay in the `build` directory). Then run the test executable `run_tests_1` and see if you pass the first test case. *If you are happy with your code, go ahead and run through the steps described above in the Checking code into GitHub section.*

#### Part 2
Now let's take a look at the next test case, `TestApp_1`. This one actually runs your `main()` function to check whether it prints the desired results in `stdout`. Look at the test case to see what the desired result needs to be, then go into `/app_1/main_1.cpp` and add the code to get a matching result.


## Submission
In order to submit your assignment, paste your GitHub repository link into the INGInious item for Assignment-0 provided on Canvas. Make sure you submit your assignment prior to the deadline specified on Canvas. INGInious will pull the files from `code_1` and `app_1` directories and grade them using the same set of test cases as given in `test_preview.cpp`. 
