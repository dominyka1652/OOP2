### Program to count student grades
#### This program 


1. First version [v0.1](https://github.com/dominyka1652/OOP1/releases/tag/v0.1) or [v0.1-branch](https://github.com/dominyka1652/OOP1/tree/v0.1) allows you to enter name and surname of a student, homework grades and exam grade.
You can choose if you want to calculate final grade using median or average. There is an opportunity to generate grades randomly. Realizations are made using two containers: a dynamic array and a vector.
2. Second version [v0.2](https://github.com/dominyka1652/OOP1/releases/tag/v0.2) or [v0.2-branch](https://github.com/dominyka1652/OOP1/tree/v0.2) additionaly allows you to read data from a file and prints sorted data.
3. Third version [v0.3](https://github.com/dominyka1652/OOP1/releases/tag/v0.3) or [v0.3-branch](https://github.com/dominyka1652/OOP1/tree/v0.3) is separated into .cpp files and header file. Also some exception handling was added.
4. Fourth version [v0.4](https://github.com/dominyka1652/OOP1/releases/tag/v0.4) or [v0.4-branch](https://github.com/dominyka1652/OOP1/tree/v0.4) gives the opportunity to generate files. The program separates students into two files according to their final grades. You will be able to see how long each part of the program took.
5. Fifth version [v0.5](https://github.com/dominyka1652/OOP1/releases/tag/v0.5) or [v0.5-branch](https://github.com/dominyka1652/OOP1/tree/v0.5) has 3 realizations using different containers: vector, list and deque.
6. Final version [v1.0](https://github.com/dominyka1652/OOP1/releases/tag/v1.0) or [v1.0-branch](https://github.com/dominyka1652/OOP1/tree/v1.0) has 3 realizations using different containers: vector, list and deque. In this version the separation into two files has been changed: I copy data to a new container and delete that information from a old container.


7. New version [v1.1](https://github.com/dominyka1652/OOP2/releases/tag/v1.1). In this version i have changed my struct into class. 
8. Version [v1.2](https://github.com/dominyka1652/OOP2/releases/tag/v1.2). In this version i added rule of three and some operators.
9. Version [v1.5](https://github.com/dominyka1652/OOP2/releases/tag/v1.5). In this version i added base clase and derived class
10. Version [v2.0](https://github.com/dominyka1652/OOP2/tree/v2.0). In this version I made unit tests.

#### The explanations how to use each version are in branches.

### Usage of versions
1. If you do not have visual studio, download and install it 
2. Download the chosen release and open a project file 
3. Press the button F5 to run the program or use make file

###
1. The program asks you if you want to create files (write "s") or not (write "n")
2. If you choose yes:
    - enter the number of files you want to generate
    - enter the number of sudents
    - enter the number of homeworks
    - enter "v" if you want to get the average or enter "m" if you want to get median.   
    - if you choose more ten 1 file, then the program asks you to enter everything that is mentioned from b)
3. If you choose no:
    - enter "i" if you want to input data manually or enter "n" if you want to read from a file:
      - if you choose "i":
      - Enter the name of a input file
      - In a next step enter the number of homework marks that is written in a file
      - Then write "v" if you want to get a average of grades or "m" if you want to get median. After this a file named           "Rezultatai" will be created in the same location as your program. 
          - If you choose to enter data manually:
          - Enter the number of students 
          - Enter the answer to the question: if you know the number of homeworks type "t", if not then type "n".
a. If you choose yes:    
    - The program asks you to enter the number of marks
    - Write the surname of student
    - Then write the name of student
    - After these steps the programs asks you if you want to write marks by yourself (write "i") or to generate randomly (write "s"):
      - If you choose to enter marks by yourself write as many grades as you entered before and when you are done write the number 0 and then enter egzam rezult. After these steps input starts again with writing name of a student.
      - If you choose to generate marks randomly, they will appear on the screen and inputs start again with writing name of a student.
    - when you are done with input the program asks you if you want to get a average (enter "v") or a median (enter "m" and the output file will be created
b. If you choose no:
     - Program asks you to write the name of student
     - After this write the surname of student
     - After these steps the programs asks you if you want to write marks by yourself (write "i") or to generate randomly (write "s")
       - If you choose to enter marks by yourself write as many grades as you want and when you are done write the number 0 and then enter egzam rezult. After these steps input starts again with writing name of a student.
       - If you choose to generate marks randomly, the next step is to enter the number of grades you want to be generated. They will appear on the screen and input starts again with writing name of a student.
    - when you are done with input the program asks you if you want to get a average (enter "v") or a median (enter "m" and the output file will be created

      
 4.  - if you choose "n" enter name of the file without ".txt"</h6>
     - enter the number of marks without exam </h6>
     - write "v" if you want to get an average or "m" if you want to get a median</h6>

