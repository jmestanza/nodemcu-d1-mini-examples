# Analog In Read Example

In this example we will see how to read the analog input of our board.

In order to do that, we need to know what an ADC is.

ADC stands for Analog to Digital Converter, it means that given an analog value of voltage on its input, it will retrieve digital values that can be used by our microcontroller.

Basically, in the case of the ADC of our module we have:

- A full range scale of 0-3.3V
- And total levels of 1024 (2^10, 10-bit ADC, ranging from 0 to 1023)

Meaning that if you put 1V in the A0 input, the digital value asociated to that will be (assumming that 3.3V gives us a value of 1023):

3.3V\_\_\_1023

1V\_\_\_x

x = 310

1V would be associated to the number 310 in our program.
You can store the value in a variable and do same math in order to get the real value of the input.

## Run the example!

Go to `File->Examples->0.1 Basics->DigitalReadSerial` to get the example code.

- Verify
- Upload

Now connect whatever you want to measure to the A0 input (assuming that is in
range 0-3.3V).

For example, you can use a potentiometer.

![](https://qsstudy.com/wp-content/uploads/2018/01/Potentiometer.jpg)

Here in the image there is an example of how could it be connected to the board.

The VCC pin would be connected to the 3.3V pin of the board and the GND pin to the GND pin of the board. Finally, you should connect the Signal pin to the A0 input.

This circuit is known as a Voltage Divider. Depending of which side you rotate the knob to, it will provide more or less voltage between the signal and gnd pins and that is what A0 will be measuring.

Go to `Tools->Serial Monitor` and see the values change while you rotate the knob.

If all the steps went well you should see values ranging from 0 to 1023 in the Serial Monitor 🥳🎉.
