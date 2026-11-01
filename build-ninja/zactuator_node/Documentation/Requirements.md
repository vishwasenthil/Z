# ZAN-1 Rev A Requirements

## Overview

ZAN-1 is a 48V BLDC/PMSM intelligent actuator controller designed for applications such as robotic drives, robot arms, rover systems, and distributed actuator networks.

---

# Environment

- Indoor/Outdoor operation
- 48V electrical systems
- CAN-connected distributed architecture

---

# DC Bus Input

## Electrical Requirements

| Parameter | Requirement |
|---|---|
| Nominal Voltage | 48V DC |
| Operating Voltage Range | 36V - 60V DC |
| Continuous Power | 1kW |
| Peak Power | 2kW |
| Continuous Input Current | 25A |
| Peak Input Current | 45A |

---

# Motor Output

## Motor Requirements

| Parameter | Requirement |
|---|---|
| Motor Type | 3-phase BLDC/PMSM |
| Continuous Phase Current | 30A |
| Peak Phase Current | 60A |

---

# Internal Power Rails

| Rail | Purpose |
|---|---|
| 12V | Gate driver supply and auxiliary circuits |
| 5V | Encoder/sensor supply (if required) |
| 3.3V | MCU and digital logic |

---

# Feedback

## Supported Feedback

- Encoder interface (encoder type to be selected)
- Hall sensor support (future consideration)

---

# Communication

## CAN FD

### Commands

The ZAN-1 node shall receive:

- Enable/disable commands
- Position targets
- Velocity targets
- Torque targets

### Telemetry

The ZAN-1 node shall transmit:

- Position
- Velocity
- Current
- Voltage
- Temperature
- Fault status

---

# Control

## Motor Control

Required:

- Field Oriented Control (FOC)

Control modes:

- Torque control
- Velocity control
- Position control

---

# Diagnostics

The ZAN-1 node shall provide:

- Fault logging
- Voltage reporting
- Current reporting
- Temperature reporting

---

# Protection

The ZAN-1 node shall include:

## Electrical Protection

- Overcurrent protection
- Short circuit protection
- Overvoltage protection
- Undervoltage protection
- Reverse polarity protection

## Thermal Protection

- Overtemperature protection

## Communication Safety

- CAN timeout handling

## Emergency Safety

- Emergency disable input