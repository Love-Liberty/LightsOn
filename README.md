# LightsOn

The input output section uses a 2 row 16 column LCD display and input buttons to allow the user to give commands to change the way the main automatic code displays the lights.

The User-Input-output---LCD-1602-+-buttons branch only handles the button pressing and the display of menu items on the LCD. This branch does not carry out any editing of the automatic system.



Arduino controlled lighting inside model buildings to vary color and brightness to simulate movement inside the rooms.

Models of buildings are enhanced if they have interiors with lights. Real buildings have occupants who move around switching some lights on or off and by moving they cause shadows and variations in the light. Also, different types of light have different colors.

This project tries to simulate that variation in lighting by using programmable LEDs and an Arduino.

The hardware & software have been installed and working in model buildings since 2021.

The next step is to add a control panel & LCD display such that the variables within the software can be altered without having to upload new software.
This update began Nov 11 2022

The layout and a simulation can be seen at Tinkercad https://www.tinkercad.com/things/aeadTduApG7-introduction. (If you look, you have to slide the switch to the ON position.

In the existing Oct 2022 software the slide switch has been replaced with a photoresistor input that turns the lights on or off depending on the room lighting.

The LCD display & menu can be seen in early stage https://wokwi.com/projects/349613619705545298 Nov 29 2022
