# EtchESketch
A system that will control an Etch-a-Sketch with a joystick


My 4 year old nephew was playing with an Etch-a-Sketch, and it brought me back to my days of childhood and Etch-a-Sketching. I remembered how difficult it was to draw shapes because of the unwieldly 2 dial control system and thought to myself "how can I make this easier?" The solution is here! This system controls the dials with a joystick, making it incredibly easy to draw anything. With the proper equiment, your second childhood can be so much better than your first one!

Components:
  - 1 Etch-a-Sketch (classic size)
  - 1 RaspberryPi 4B
  - 2 2 28BYJ-48 stepper motors
  - 2 ULN2003 stepper motor drivers
  - 1 joystick
  - 3 10kΩ resistors 
  - 1 ADS7830
  - 1 breadboard
  - Lots of male-to-male and female-to-male jumper wires

The process is simple: read in the input from the joystick, and translate it into coordinates for the stepper motors to draw accurately
