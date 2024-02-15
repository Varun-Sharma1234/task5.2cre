from tkinter import *
import tkinter.font
from gpiozero import LED
import RPi.GPIO as GPIO

# Set the GPIO mode
GPIO.setmode(GPIO.BCM)

# Define LED pins
Red = LED(14)
White = LED(10)
Green = LED(6)

# GUI definitions
win = Tk()
win.title("LED Control Panel")
myFont = tkinter.font.Font(family='Arial', size=12, weight="bold")

# LED Functions
def toggle_led(led, button):
    if led.is_lit:
        led.off()
        button["text"] = f"TURN {led.color} LED ON"
    else:
        led.on()
        button["text"] = f"TURN {led.color} LED OFF"

# Code for EXIT
def close():
    GPIO.cleanup()
    win.destroy()

# Create LED buttons
led_buttons = []

for led, color in [(Red, "RED"), (White, "WHITE"), (Green, "GREEN")]:
    led_button = Button(win, text=f"TURN {color} LED ON", font=myFont, command=lambda led=led, button=None: toggle_led(led, button))
    led_buttons.append(led_button)

# Arrange LED buttons in a grid
for i, led_button in enumerate(led_buttons):
    led_button.grid(row=0, column=i * 2 + 1)

# Create EXIT button
exitButton = Button(win, text="EXIT WINDOW", font=myFont, command=close, bg='red')
exitButton.grid(row=2, column=3)

# Configure window close behavior
win.protocol("WM_DELETE_WINDOW", close)

# Main loop
win.mainloop()
