# 🔐 RSA Modular Exponentiation – Hardware Design (Lustre)

This project focuses on the design, implementation, and simulation of a hardware circuit dedicated to RSA modular exponentiation:

code = m^exp mod n

The system is implemented using the Lustre synchronous language, with a structural hardware-oriented approach based on logic gates and registers.

---

## 📌 Architecture Overview

The design follows a classic Hardware/Software Co-design methodology, separating the system into:

### 🔹 Operative Part (PO)

The data path includes:

- Registers: CODE, M, EXP, N
- Multiplexers for operand selection
- A custom Arithmetic Logic Unit (ALU)
- Status flag generation (Zero, Carry, Odd)

### 🔹 Control Part (PC)

A Finite State Machine (FSM) responsible for:

- Sequencing operations
- Driving control signals
- Reacting to status flags returned by the PO

The FSM uses a 1-among-N encoding with 11 states (st[0..10]).

---

## ⚙️ Algorithmic Adaptation for Hardware

To comply with hardware constraints, the classical RSA algorithm was adapted to use only:

- Subtraction
- Multiplication
- Bit-shifting

### 🔸 Modulo via Repeated Subtraction

Instead of division-based modulo:

r = a mod n

The operation is implemented by repeatedly subtracting n from a until the result is strictly less than n.

### 🔸 Square-and-Multiply

Exponentiation is implemented using binary exponentiation:

- Check the Least Significant Bit (LSB) of exp
- Multiply when the bit is 1
- Square the base
- Right-shift the exponent (exp >> 1)

This minimizes the number of multiplications and is well-suited for hardware implementation.

---

## 🛠️ Implementation Details

### 🔹 Lustre Hardware Modeling

- Gate-level structural modeling
- Boolean variables and explicit logic
- Avoidance of high-level arithmetic constructs
- Explicit register-based state evolution

### 🔹 Custom ALU (UAL)

The ALU supports four operations encoded on 2 bits:

| Code | Operation  | Description |
|------|-----------|-------------|
| 00   | SUB       | Used for modulo via repeated subtraction |
| 01   | MUL       | Multiplication and squaring |
| 10   | SHR1      | Logical right shift (exp >> 1) |
| 11   | PASS_OP1  | Direct transfer of operand 1 |

---

## 🚀 Simulation & Validation

The design was validated using the Luciole simulator.

### 🔹 Example Test Case

Parameters:
p = 3, q = 11 → n = 33

Keys:
Public: (13, 33)
Private: (17, 33)

Input:
m = 31, exp = 13, n = 33

Result:
25

The hardware circuit correctly computes the expected modular exponentiation result.

---

## 📂 Project Structure

PO/
 ├── registre_n_bits.lus
 ├── UAL.lus
 └── (data path components)

PC/
 └── FSM control logic (11-state encoding)

top.lus
 └── Top-level integration of PC and PO

---

## 👥 Authors

- Arhan UNAY
- Utku GEMICIOGLU

---

### 🎓 Academic Context

Developed as part of the INFO3 – Architecture and Material (ArchMat) course  
Polytech Grenoble – April 2025

