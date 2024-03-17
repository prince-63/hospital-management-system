# Hospital Management System in C

## Introduction

This Hospital Management System is a console-based application developed in the C programming language. It is designed as a college project to demonstrate the basic functionalities of managing a hospital's operations efficiently. This system helps in maintaining patient records, managing appointments, and handling various administrative tasks within a hospital setting.

![Screenshot 2024-03-17 113248](https://github.com/prince-63/hospital-management-system/assets/111671729/31c52656-1c6b-4d7b-80b1-9846a7de1c73)

![Screenshot 2024-03-17 113357](https://github.com/prince-63/hospital-management-system/assets/111671729/30840ad7-0b44-44b9-8b9a-e39a3d5dafd0)


## Features

1. **Add Data:**
   - Add Patient
   - Add Doctor
   - Add Appointment
   - Add Room
   - Add Bill
   - Add Inventory
   - Add Staff
   - Add Department

2. **Display Data:**
   - Display Patient
   - Display Doctor
   - Display Appointment
   - Display Room
   - Display Bill
   - Display Inventory
   - Display Staff
   - Display Department

3. **Update Data:**
   - Update Patient
   - Update Doctor
   - Update Appointment
   - Update Room
   - Update Bill
   - Update Inventory
   - Update Staff
   - Update Department

4. **Remove Data:**
   - Remove Patient
   - Remove Doctor
   - Remove Appointment
   - Remove Room
   - Remove Bill
   - Remove Inventory
   - Remove Staff
   - Remove Department

## How to Use

1. **Compile the Code:**
   - Use a C compiler (e.g., GCC) to compile the source code.
   ```JavaScript
     gcc main.c ./controller/appointment/appointment_controller.c ./controller/bill/bill_controller.c ./controller/doctor/doctor_controller.c ./controller/patient/patient_controller.c ./controller/room/room_controller.c ./controller/inventory/inventory_controller.c ./controller/staff/staff_controller.c ./controller/department/department_controller.c ./services/appointment/appointment_service.c ./services/bill/bill_service.c ./services/department/department_service.c ./services/doctor/doctor_service.c ./services/inventory/inventory_service.c ./services/patient/patient_service.c ./services/room/room_service.c ./services/staff/staff_service.c -o main
   ```
2. **Run the Application:**
   - Execute the compiled binary.
   ```JavaScript
     ./main
   ```
