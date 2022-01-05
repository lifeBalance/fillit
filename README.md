# fillit
Fillit is a project which involves discovering and getting acquainted with a recurrent problem in programming: the search of an optimal solution among a very large number of possibilities in a reasonable amount of time. In this project, you will arrange Tetriminos among them and determine the smallest square that can fit all of them.

![succeded with 100](graded.png "Succeded with 100")

This was the last project before we got to choose branch. It was to be done together with another student; in this repo I keep the code that I was using to develop and test my personal ideas before presenting them to my team partner.

## Really fast
At the beginning of the project, we started looking for clues in another repos, and discovered that **bitwise manipulation** allows for a significant increase in speed. Since **bitwise twiddling** was definitely in my list of things to learn about it, I decided to propose it, and my team agreed. As a result, our project runs really fast, fulfilling the evaluation test in about 0.005 seconds. For that, it was graded as **outstanding** by  our three evaluators.

### TODO
- [] add a descriptive write up of the techniques used.
- [] make it work with `eval_tests/speed.txt` (currently segfaults).