# Latency Tester

Small and simple board to make testing response times easier. Its basically a nice switch, phototransistor and some LEDs with IO.

Intended to be used for measuring:

- Display input latency (switch to photon time)

- Micro/Computer communications latency (switch to serial, serial to photon, etc)

- "Whole chain" timing assessments (key-switch to photon while over communications link etc)
- Human response time tests? Press the button when the light comes on...

![render-side](/imgs/render-side.png)

## Electronics

![render-top-bottom](/imgs/render-top-bottom.png)

- Board uses an ATSAMD M0 microcontroller. Intended for use with the Adafruit Trinket bootloader/ecosystem.

- Native USB means it can enumerate as a HID device, allowing use as a mouse/keyboard etc, or USB CDC.

- Cherry MX key-switch to act as the 'stimulus'. Photo-sensor to measure display changes as required.

- Expansion IO header provides hardware UART, along with 2 IO lines primarily intended to signal the stimulus and optical detection times. This 2x4 2.54mm header can be connected directly into a Saleae Logic analyser for timing analysis.

- 2x APA102 RGB Leds can be used to indicate state etc.
- 3mm LED in MX keyswitch is connected to the `LED_BUILTIN` pin for Arduino ecosystem, indicates bootloader state and can be used as generic user LED.
- Reset switch on bottom edge.
- SWD connector on rear isn't intended to be populated.

## Enclosure

Mostly designed to try some new modelling techniques and different enclosure approach. Intended for SLA 3D printing. I used [Lexcent](http://www.lexcent.com/).

Consists of two parts. Board slides into the halves, though some minor sanding/filing might be required depending on tolerances of SMD component placement.

I'll probably paint the 'bottom' part black, with the 'diffuse white' natural plastic allowing the top section to act as an illuminated highlight strip as depicted in the render.

![render-enclosure](/imgs/render-enclosure.png)

## Firmware

TBD.



## Software

TBD