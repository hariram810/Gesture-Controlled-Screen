# Gesture-Controlled-Screen

![Screenshot (666)](https://user-images.githubusercontent.com/118633170/205702549-3584a4f0-ef92-49de-9f2c-5de11eb8e584.png)


If you have hard-time 3d printing stuff and other materials which i have provided in this project please refer the professionals for the help, [JLCPCB](https://jlcpcb.com/RNA) is one of the best company from shenzhen china they provide, PCB manufacturing, PCBA and 3D printing services to people in need, they provide good quality products in all sectors

[JLCPCB](https://jlcpcb.com/RNA)


Please use the following link to register an account in [JLCPCB](https://jlcpcb.com/RNA)

https://jlcpcb.com/RNA


Pcb Manufacturing

----------

2 layers

4 layers

6 layers

jlcpcb.com/RNA



PCBA Services

[JLCPCB](https://jlcpcb.com/RNA) have 350k+ Components In-stock. You don’t have to worry about parts sourcing, this helps you to save time and hassle, also keeps your costs down.

Moreover, you can pre-order parts and hold the inventory at [JLCPCB](https://jlcpcb.com/RNA), giving you peace-of-mind that you won't run into any last minute part shortages. jlcpcb.com/RNA


3d printing

-------------------

SLA -- MJF --SLM -- FDM -- & SLS. easy order and fast shipping makes [JLCPCB](https://jlcpcb.com/RNA) better companion among other manufactures try out [JLCPCB](https://jlcpcb.com/RNA) 3D Printing servies

[JLCPCB](https://jlcpcb.com/RNA) 3D Printing starts at $1 &Get $54 Coupons for new users

![Screenshot (676)](https://user-images.githubusercontent.com/118633170/205702603-40bb25b9-1952-4bdc-a6d6-3130aefd55fd.png)

![Screenshot (671)](https://user-images.githubusercontent.com/118633170/205702619-4b5dcc04-d549-463b-bf12-d520e3147224.png)

Human Machine Interface or HMI is a system comprising of hardware and software that helps in communication and exchange of information between the user (human operator) and the machine.

We normally use LED Indicators, Switches, Touch Screens and LCD Displays as a part of HMI devices. Another way to communicate with machines like Robots or Computers is with the help of Hand Gestures.

Instead of using a keyboard, mouse or joystick, we can use our hand gestures to control certain functions of a computer like play/pause a video, move left/right in a photo slide show, scroll up/down in a web page and many more.

In this project, we have implemented a simple Arduino based hand gesture control where you can control few functions of your web browser like switching between tabs, scrolling up and down in web pages, shift between tasks (applications), play or pause a video and increase or decrease the volume (in VLC Player) with the help of hand gestures.

![Screenshot (673)](https://user-images.githubusercontent.com/118633170/205702649-c73f3740-89ba-4c2e-9492-a8ddda48f0d9.png)


Principle behind the Project
The principle behind the Arduino based Hand Gesture Control of Computer is actually very simple. All you have to do is use two Ultrasonic Sensors with Arduino, place your hand in front of the Ultrasonic Sensor and calculate the distance between the hand and the sensor. Using this information, relevant actions in the computer can be performed.

The position of the Ultrasonic Sensors is very important. Place the two Ultrasonic Sensors on the top of a laptop screen at either end. The distance information from Arduino is collected by a Python Program and a special library called PyAutoGUI will convert the data into keyboard click actions.

The design of the circuit is very simple, but the setup of the components is very important. The Trigger and Echo Pins of the first Ultrasonic Sensor (that is placed on the left of the screen) are connected to Pins 11 and 10 of the Arduino. For the second Ultrasonic Sensor, the Trigger and Echo Pins are connected to Pins 6 and 5 of the Arduino.

Now, coming to the placement of the Sensors, place both the Ultrasonic Sensors on top of the Laptop screen, one at the left end and the other at right. You can use double sided tape to hold the sensors onto the screen

Programming Your Arduino to Detect Gestures
The important part of this project is to write a program for Arduino such that it converts the distances measured by both the sensors into the appropriate commands for controlling certain actions.

We have already seen a project called Range Sensor where you can measure the distance of an object placed in front of an Ultrasonic Sensor with the help of Arduino.

A similar concept is used here to measure the distance of your hand in front of both the Ultrasonic Sensors in this project. The fun part starts after calculating the distance.

The hand gestures in front of the Ultrasonic sensors can be calibrated so that they can perform five different tasks on your computer. Before taking a look at the gestures, let us first see the tasks that we can accomplish.

![Screenshot (672)](https://user-images.githubusercontent.com/118633170/205702658-4e37a940-2674-4063-8a61-9f5d8c3aa885.png)


Switch to Next Tab in a Web Browser
Switch to Next Tab in a Web Browser
Scroll Down in a Web Page
Scroll Up in a Web Page
Switch between two Tasks (Chrome and VLC Player)
Play/Pause Video in VLC Player
Increase Volume
Decrease Volume
The following are the 5 different hand gestures or actions that I’ve programmed for demonstration purpose.

Gesture 1: Place your hand in front of the Right Ultrasonic Sensor at a distance (between 15CM to 35CM) for a small duration and move your hand away from the sensor. This gesture will Scroll Down the Web Page or Decrease the Volume.

![Screenshot (677)](https://user-images.githubusercontent.com/118633170/205702695-53eb6aa3-0b80-4ff6-90ab-8e4c63e510df.png)


Gesture 2: Place your hand in front of the Right Ultrasonic Sensor at a distance (between 15CM to 35CM) for a small duration and move your hand towards the sensor. This gesture will Scroll up the Web Page or Increase the Volume.

Gesture 3: Swipe your hand in front of the Right Ultrasonic Sensor. This gesture will move to the Next Tab.

Gesture 4: Swipe your hand in front of the Left Ultrasonic Sensor. This gesture will move to the Previous Tab or Play/Pause the Video.

Gesture 5: Swipe your hand across both the sensors (Left Sensor first). This action will Switch between Tasks.
