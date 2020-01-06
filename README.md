# First Mile Stone

first mile stone is a project, made by Roei Ben-Zee'v and Asaf Jerbi to make the Flight Gear Simulator's Cessna airplane fly!

# How does this magic done?
first of all, one should know the simulator knows to communicate as a server, indeed, getting commands from a client and sending back responses. therefore, the magic is done in 6 primary steps:
1. Lexing the code given inside fly.txt
2. Parsing it into commands
3. Interpreting mathematical expressions
4. Doing important calculations 
5. Receiving and sending data 10 times per second to the server
6. Sending commands to control the airplane 


## Installation

In order to see the Cessna fly you must got a Cessna of your own! \
how can you do that:
1. Go to:  
http://ubuntuhandbook.org/index.php/2018/06/install-flightgear-2018-2-1-ubuntu-18-04/  
and download Flight Gear Simulator
2. After you downloaded it, please open it - you should see the main menu window.
3. On the left panel, choose the settings option.
4. There, you should scroll sown a little bit and there you will see a text box with the title: "Additional Settings".
5. Inside the additional settings window, please write this:
```bash 
--telnet=socket,in,10,127.0.0.1,5402,tcp --httpd=8080 --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small
```
(if it's possible, please write it by yourself and do not use copy-paste method (since it does some issues sometimes).

## Connecting all together
- Open the project (all the code is attached)
- Execute the code 
- The message "Server is now listening ..." should appear
- Now on the left panel of FG Simulator, please press 'Fly!'
- Please fasten you seat belt!
- Wait 2 minutes while engines are getting warming
- Enjoy the view!

## what is all about

Our project is made by us during advanced programming course at Bar-Ilan University in order to acquire the necessary features for our integration into the industry, such as:

* Code designing
* Experiment in OOP developing
* Using design patterns
* Using sockets
* Working with threads
* Working as a team
* Dealing with a massive list of demands
* Dividing complicated demands into smaller pieces
* Managing time correctly and as a team

