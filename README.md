# Shutdown_Device
I'll start with the physical hardware then (basically the machine). for this i used: 

microcontroller
(basically a device that lets me do whatever i want aslong as i program it the right way,)

Breadboard 
(a thing that holds it all together and allows electricty to flow through it so that it works)

M/M Wires
(Wires that connect it all)

Button
(button)

I downloaded a free app called "Arduino IDE", in this i made sure so that my esp-32 is selected and connected through COM-3.

At first i had a hard time trying to set up the wiring to work but once i did that and the button worked, i coded a function that requires a custom python server to be running in order for this to work.

Once i coded the python server and set it up as start-up i checked it and it worked. 

Also i had to set up a secret key code so that it requires someone to know it (i dont even know it, which is a good thing) in order to control it. 

So yeah thats how i made it

How it works:

The ESP-32 is connected through a USB-C cable, which is plugged into my PC.

The button is connected into the GND and D27 pins on my ESP-32. When i press the button, it sends a request to the python server.

The python server then checks if the request has a secret key, if everything is correct then it tells windows to shut down.

Whats next:
I'll order a battery that will make me able to use the device whenever i want, aslong as my pc is turned on.

Ngl this will be hard to make but everything for the love of the game. 
