📌 Overview

This Robot Car Project is a wireless, Arduino-based system designed for remote-controlled vehicle operation using a joystick. It utilizes the NRF24L01 transceiver module to send real-time commands from a handheld controller to the robot car. The car can move in multiple directions and is suitable for educational purposes, robotics learning, and prototype development.

🎯 Features

🎮 Wireless Control using NRF24L01 (2.4GHz) modules.

🧭 Supports forward, backward, left, right, and stop movements.

🚗 Dual Motor Control using L298N Motor Driver.

🔋 Operates on battery power for full mobility.

🔧 Fully customizable and extendable (e.g., add sensors, automation).

🔧 Hardware Components

Robot Car Side:

🧠 Arduino Nano / Uno

📡 NRF24L01 + PA + LNA SMA Antenna Module

⚙️ L298N Motor Driver

🔌 Battery Pack (7.4V or 12V)

🚙 2 DC Motors + Chassis with Wheels

🧵 Wires, Connectors, and Breadboard/PCB

Joystick Controller Side:

🧠 Arduino Nano / Uno

📡 NRF24L01 Module

🎮 2-Axis Joystick Module

🔋 Power Bank or 9V Battery

🔁 How It Works

The joystick reads directional input from the user.

The controller Arduino sends the input wirelessly via NRF24L01.

The robot car receives the signal and translates it into motor movements using the L298N driver.

The car responds in real-time to joystick movement:

Up → Move forward

Down → Move backward

Left → Turn left

Right → Turn right

Neutral → Stop

🧠 Software

Written in Arduino C++ using the RF24 library for wireless communication.

Two Arduino sketches:

robot_car.ino: runs on the car's Arduino

joystick_controller.ino: runs on the controller's Arduino

