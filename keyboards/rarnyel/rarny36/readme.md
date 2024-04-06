# rarny36

![rarny36](https://i.imgur.com/MCGv0ZHh.jpeg)

A 36 key split monoblock ortholinear keyboard heavily inspired by the Scotto34, except with an extra 2 thumb keys, OLED display, and breakouts for solenoid and/or additional I2C peripherals.
*   Keyboard Maintainer: [Ramy](https://github.com/rarnyel)
*   Hardware Supported: RP2040
*   Hardware Availability: [Amazon](https://amazon.com)

Make example for this keyboard (after setting up your build environment):

    make rarnyel/rarny36:default

Flashing example for this keyboard:

    make rarnyel/rarny36:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available