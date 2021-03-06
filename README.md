## Flight Simulator: Flappy Bird

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

![](flappybird.gif)

**Flight Simulator: Flappy Bird** is a parody of the popular mobile game, "Flappy Bird", and it uses the *OpenGL* library (which comes included in the *Cinder* framework) that provides graphics capabilities. This game was made as light joke in reference to the numerous references my professor made to his work with flight simulators during lecture.

---

## Setting Up The Game

As mentioned before, this game utilizes the *Cinder* framework, and you can download the latest version for your platform [here](https://libcinder.org/download). Furthermore, you must have CLion in order to compile this program otherwise linking the Cinder framework will not be as straightforward. [Here](https://www.jetbrains.com/clion/download/#section=mac) is a link to download CLion for your respective platform.

After downloading *Cinder* (v0.9.2 is the current latest version), extract it into a folder called `~/Cinder`. From here open `~/Cinder` in CLion and build it once to create `libcinder`. Then create a new directory in `~/Cinder` which can be named `flappy-bird` and clone this repository to that location. Finally, open `flight-simulatory-flappybird` in CLion, set the target to cinder-myapp and run the program.

For further reference, [here](https://courses.grainger.illinois.edu/cs126/sp2020/assignments/snake/) and [here](https://libcinder.org/docs/guides/tour/hello_cinder_chapter1.html) are basic tutorials on setting up *Cinder* in CLion.

---

## Playing Guide

This game is essentially played the same way as normal "Flappy Bird" where you can move the bird up using the `Space` or `Up` button. The goal of the game is to avoid the green pipes and traverse through the cave and points are obtained with each successive, passed pipe. The game ends when the "bird" hits a pipe leading the user to a screen which depicts their score.

---

## Additional Notes

This project utilized the library, *OpenGL* for its simple graphics and audio capabilities. Both the background and the "bird" icon itself where implemented using functions from this library and this project overall shows how helpful this library was in drawing pictures and playing sounds for the game. [Here](https://libcinder.org/docs/guides/opengl/index.html) is a link for additional reference to the library.

**Author**: Amey Venkatanarayan - [`ameyv2@illinois.edu`](mailto:example@illinois.edu)
