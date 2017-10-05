
Presenter
=========

Getting the sources
===================

.. code:: bash

    git clone https://github.com/nradulovic/stm32_presenter presenter
    cd presenter
    ./scripts/fetch_all.sh

Source
======

Structure
---------

The structure of source code is divided by using the following rules:

1. Hardware dependency rule. The source code can be either:

   - hardware independent code
   - hardware dependent code

2. Application specifics rule. The source code can be either:

   - application agnostic code
   - application specific code

The source consists of:

+------------------+------------------+------------------+------------------+
| Directory        | Long name        | Hardware         | Application      |
+==================+==================+==================+==================+
| ``app``          | application      | independent      | specific         |
+------------------+------------------+------------------+------------------+
| ``sys``          | system           | dependent        | specific         |
+------------------+------------------+------------------+------------------+
| ``lib``          | library          | independent      | agnostic         |
+------------------+------------------+------------------+------------------+
| ``drv``          | driver           | dependent        | agnostic         |
+------------------+------------------+------------------+------------------+

**Application directory**

This directory shall contain ``main.c`` and ``main.h`` in their respective
sub-directories.

**System directory**

This directory contains:

- start-up code
- linker scripts
- initialization code
- interrupt service routines
- driver or library callbacks

**Library directory**

Contains libraries and frameworks used by the firmware:

- ``neon``: Neon

**Driver directory**

Contains drivers and HALs used by the firmware:

- CMSIS (from STM, STM32CubeF1, v1.6.0): Cortex Microcontroller System 
  Interface Standard
- STM32F1xx_HAL_Driver (from STM, STM32CubeF1, v1.6.0): STM32 HAL

Settings
--------

Main file:

- ``app/source/main.c``

Startup file:

- ``sys/assembly/startup_stm32f103xb.S``

Linker script:

- ``sys/linker/stm32f103xb_flash.ld``

Include paths:

- ``sys/include``
- ``app/include``
- ``lib/neon/eds/include``
- ``lib/neon/lib/include``
- ``drv/CMSIS/Device/ST/STM32F1xx/Include``
- ``drv/STM32F1xx_HAL_Driver/Inc``

Macros:

- ``STM32F103xB``
- ``USE_HAL_DRIVER``

