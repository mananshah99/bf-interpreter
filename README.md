bf-interpreter [![Build Status](https://travis-ci.org/mananshah99/bf-interpreter.svg?branch=master)](https://travis-ci.org/mananshah99/bf-interpreter)
==============

Interpreter for the instruction-pointer based esoteric language

Run: `gcc main.c -o exec && exec "filename.bf"`

| cmd | effect                          |
|-----|---------------------------------|
| +   | Increases element under pointer |
| -   | Decreases element under pointer |
| >   | Increases pointer               |
| <   | Decreases pointer               |
| [   | Starts loop, flag under pointer | 
| ]   | Indicates end of loop           |
| .   | Outputs ASCII code under pointer |
| ,   | Reads char and stores ASCII under ptr |
