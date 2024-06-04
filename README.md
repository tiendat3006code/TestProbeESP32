# Test probe with ESP32 

This project create to send message to two type of probes: Windbell and Magnetic. All of the probes using MODBUS RTU RS485 protocol.

## Useage
- At the begining: 
    + Type "windbell": Start windbell probe test mode. Serial2 begin with the baudrate 2400.
    + Type "magnetic": Start magnetic probe test mode. Serial2 begin with the baudrate 9600.
- Windbell probe test:
    + Type 0 in terminal to send ask probe level request.
    + Type 1 in terminal to send ask probe average temperature.
    + Type 2 in terminal to send ask probe five temparatures.
- Magnetic probe test:
    + Type "get" to send get probe request command.
    + Type "set" to enter set probe mode. And then type address to send set probe address command with the typed address. Type "exit" to exit this mode.
    + Type "read" to enter read probe all value. And then type address to send probe read all value with the typed address. Type "exit" to exit this mode.

## Contributors
- Cao Tien Dat

## System
- ESP32 dev kit v1.
- UART communication using pin rx: 16, pin tx: 17.