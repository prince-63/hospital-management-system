#include "./controller/appointment/appointment_controller.h"
#include "./controller/bill/bill_controller.h"
#include "./controller/department/department_controller.h"
#include "./controller/doctor/doctor_controller.h"
#include "./controller/inventory/inventory_controller.h"
#include "./controller/patient/patient_controller.h"
#include "./controller/room/room_controller.h"
#include "./controller/staff/staff_controller.h"
#include <stdio.h>

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Patient\n");
        printf("2. Doctor\n");
        printf("3. Appointment\n");
        printf("4. Room\n");
        printf("5. Bill\n");
        printf("6. Department\n");
        printf("7. Staff\n");
        printf("8. Inventory\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            patientController();
            break;
        case 2:
            doctorController();
            break;
        case 3:
            appointmentController();
            break;
        case 4:
            roomController();
            break;
        case 5:
            billController();
            break;
        case 6:
            departmentController();
            break;
        case 7:
            staffController();
            break;
        case 8:
            inventoryController();
            break;
        case 9:
            return 0;
        default:
            printf("Invalid choice\n");
        };
    }
    return 0;
}