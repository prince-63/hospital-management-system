# Hospital Management System

## Introduction

This Hospital Management System is a console-based application developed in the C programming language. It is designed as a college project to demonstrate the basic functionalities of managing a hospital's operations efficiently. This system helps in maintaining patient records, managing appointments, and handling various administrative tasks within a hospital setting.

## Features

### Add Data:
- **Add Patient**: Allows the addition of new patient records, including personal information such as name, age, gender, and contact details.
- **Add Doctor**: Enables the registration of doctors with their specialization, contact information, and other relevant details.
- **Add Appointment**: Facilitates scheduling appointments for patients with specific doctors, including date, time, and reason for the visit.
- **Add Room**: Provides functionality to add rooms within the hospital, specifying room numbers, types, and availability status.
- **Add Bill**: Allows for the creation of bills for patients, including details of services rendered, medications provided, and total charges.
- **Add Inventory**: Supports the addition of inventory items such as medical supplies, equipment, and medications, along with quantities and expiration dates.
- **Add Staff**: Enables the registration of hospital staff members, including administrative personnel, nurses, and technicians, with their respective roles and contact information.
- **Add Department**: Allows for the creation of departments within the hospital, defining their names, functions, and associated staff members.

### Display Data:
- **Display Patient**: Provides a view of all registered patients, along with their personal details and medical histories.
- **Display Doctor**: Shows a list of all doctors working in the hospital, along with their specializations, contact information, and schedules.
- **Display Appointment**: Displays scheduled appointments, including patient details, doctor assignments, and appointment timings.
- **Display Room**: Offers an overview of available rooms in the hospital, along with their types, occupancy status, and any assigned patients.
- **Display Bill**: Presents itemized bills for patients, showing services utilized, medications prescribed, and corresponding charges.
- **Display Inventory**: Shows the current inventory status, including available items, quantities on hand, and expiration dates.
- **Display Staff**: Provides a list of all staff members working in various roles within the hospital, along with their positions and contact details.
- **Display Department**: Offers insights into the different departments within the hospital, including their functions, staff members, and contact information.

### Update Data:
- **Update Patient**: Allows for the modification of patient information, including updates to personal details, medical records, and contact information.
- **Update Doctor**: Enables the editing of doctor details such as contact information, schedules, and specializations.
- **Update Appointment**: Facilitates changes to appointment timings, doctor assignments, and reason for visits.
- **Update Room**: Allows for updates to room information, such as occupancy status, availability, and room types.
- **Update Bill**: Provides functionality to modify bill details, including adjustments to charges, additions of new services, or corrections to existing entries.
- **Update Inventory**: Allows for updates to inventory items, including additions, deletions, quantity adjustments, and updates to expiration dates.
- **Update Staff**: Enables modifications to staff member details, including position changes, contact information updates, and role assignments.
- **Update Department**: Facilitates updates to department information, such as changes to department names, functions, or staff assignments.

### Remove Data:
- **Remove Patient**: Allows for the removal of patient records from the system, including personal details and medical histories.
- **Remove Doctor**: Enables the deletion of doctor profiles from the system, along with associated information such as schedules and specializations.
- **Remove Appointment**: Facilitates the removal of scheduled appointments from the system, including patient details and appointment timings.
- **Remove Room**: Allows for the deletion of room entries from the system, including room types, occupancy status, and associated patients.
- **Remove Bill**: Provides functionality to remove bill records from the system, including itemized details of services rendered and corresponding charges.
- **Remove Inventory**: Enables the deletion of inventory items from the system, including details such as quantities on hand and expiration dates.
- **Remove Staff**: Allows for the removal of staff member profiles from the system, including position details and contact information.
- **Remove Department**: Facilitates the deletion of department entries from the system, including department names, functions, and associated staff members.

![Screenshot 2024-03-17 113248](https://github.com/prince-63/hospital-management-system/assets/111671729/31c52656-1c6b-4d7b-80b1-9846a7de1c73)

![Screenshot 2024-03-17 113357](https://github.com/prince-63/hospital-management-system/assets/111671729/30840ad7-0b44-44b9-8b9a-e39a3d5dafd0)

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
