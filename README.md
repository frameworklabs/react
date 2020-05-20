# react

A simple Blech demo for the M5StickC

## Overview

The [M5StickC](https://m5stack.com/products/stick-c) is what is sometimes called a Finger Computer. It consists of an ESP32 SoC, a tiny 80x160 color LCD screen and buttons in a small enclosure. It can be programmed with Arduino or with the ESP-IDF, which is based on FreeRTOS.

This demo is a small game on this stick programmed in the Arduino environment with the help of the [Blech](https://www.blech-lang.org/) programming languge.

The game is a reaction test: When you start the game the screen gets black for a random duration. Then it suddenly turns blue and you have to press the main button as fast as possible. The reaction time will be displayed afterwards. If you press the button before the blue screen appears, the game is lost - also, when you take too long to press the button after the blue screen. A double click on the start (home) screen will bring you to a help screen.

Blech helps to implement this game due to its way to model state-flow. Each screen in the game is a state and pressing buttons - or the passage of time - transitions into a new state. Also, animations like dimming the screen after some idle time is simplified by the fact that time is handled in a functional way in synchronous languages (as opposed to being purely a non-functional quality otherwise).

## How to build

After you set up Blech and Arduiono for this stick, you have to call the "gen.sh" script first. It runs the blechc compiler to compile "react.blc" into a "react.h" and "react.c" file which is used by the 
"react.ino" sketch. Then, open the sketch and flash the progam.
