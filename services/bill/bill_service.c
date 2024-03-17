#include "../../model/bill/bill_model.h"
#include <stdio.h>

FILE *bill_file, *temp_file;

int add_bill()
{
    Bill bill;
    bill_file = fopen("./data/bill.txt", "a");

    if (bill_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter bill id: ");
    scanf("%d", &bill.billId);
    printf("Enter patient id: ");
    scanf("%d", &bill.patientId);
    printf("Enter doctor id: ");
    scanf("%d", &bill.doctorId);
    printf("Enter room id: ");
    scanf("%d", &bill.roomId);
    printf("Enter appointment id: ");
    scanf("%d", &bill.appointmentId);
    printf("Enter total amount: ");
    scanf("%d", &bill.totalAmount);
    printf("Enter bill date: ");
    scanf("%s", bill.billDate);
    printf("Enter bill status: ");
    scanf("%s", bill.billStatus);

    fwrite(&bill, sizeof(Bill), 1, bill_file);
    fclose(bill_file);
    return 1;
}

void display_bill()
{
    Bill bill;
    bill_file = fopen("./data/bill.txt", "r");
    if (bill_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    // Print table header
    printf("\n%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Bill Id", "Patient Id", "Doctor Id", "Room Id", "Appointment Id", "Total Amount", "Bill Date", "Bill Status");

    while (fread(&bill, sizeof(Bill), 1, bill_file))
    {
        // Print table row
        printf("%-10d %-10d %-10d %-10d %-10d %-10d %-10s %-10s\n", bill.billId, bill.patientId, bill.doctorId, bill.roomId, bill.appointmentId, bill.totalAmount, bill.billDate, bill.billStatus);
    }
    fclose(bill_file);
}

int update_bill_patient_id()
{
    Bill bill;
    int billId;
    bill_file = fopen("./data/bill.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (bill_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter bill id: ");
    scanf("%d", &billId);

    while (fread(&bill, sizeof(Bill), 1, bill_file))
    {
        if (bill.billId == billId)
        {
            printf("\nEnter new patient id: ");
            scanf("%d", &bill.patientId);
        }
        fwrite(&bill, sizeof(Bill), 1, temp_file);
    }
    fclose(bill_file);
    fclose(temp_file);
    remove("./data/bill.txt");
    rename("./data/temp.txt", "./data/bill.txt");
    return 1;
}

int update_bill_doctor_id()
{
    Bill bill;
    int billId;
    bill_file = fopen("./data/bill.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (bill_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter bill id: ");
    scanf("%d", &billId);

    while (fread(&bill, sizeof(Bill), 1, bill_file))
    {
        if (bill.billId == billId)
        {
            printf("\nEnter new doctor id: ");
            scanf("%d", &bill.doctorId);
        }
        fwrite(&bill, sizeof(Bill), 1, temp_file);
    }
    fclose(bill_file);
    fclose(temp_file);
    remove("./data/bill.txt");
    rename("./data/temp.txt", "./data/bill.txt");
    return 1;
}

int update_bill_room_id()
{
    Bill bill;
    int billId;
    bill_file = fopen("./data/bill.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (bill_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter bill id: ");
    scanf("%d", &billId);

    while (fread(&bill, sizeof(Bill), 1, bill_file))
    {
        if (bill.billId == billId)
        {
            printf("\nEnter new room id: ");
            scanf("%d", &bill.roomId);
        }
        fwrite(&bill, sizeof(Bill), 1, temp_file);
    }
    fclose(bill_file);
    fclose(temp_file);
    remove("./data/bill.txt");
    rename("./data/temp.txt", "./data/bill.txt");
    return 1;
}

int update_bill_appointment_id()
{
    Bill bill;
    int billId;
    bill_file = fopen("./data/bill.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (bill_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter bill id: ");
    scanf("%d", &billId);

    while (fread(&bill, sizeof(Bill), 1, bill_file))
    {
        if (bill.billId == billId)
        {
            printf("\nEnter new appointment id: ");
            scanf("%d", &bill.appointmentId);
        }
        fwrite(&bill, sizeof(Bill), 1, temp_file);
    }
    fclose(bill_file);
    fclose(temp_file);
    remove("./data/bill.txt");
    rename("./data/temp.txt", "./data/bill.txt");
    return 1;
}

int update_bill_total_amount()
{
    Bill bill;
    int billId;
    bill_file = fopen("./data/bill.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (bill_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter bill id: ");
    scanf("%d", &billId);

    while (fread(&bill, sizeof(Bill), 1, bill_file))
    {
        if (bill.billId == billId)
        {
            printf("\nEnter new total amount: ");
            scanf("%d", &bill.totalAmount);
        }
        fwrite(&bill, sizeof(Bill), 1, temp_file);
    }
    fclose(bill_file);
    fclose(temp_file);
    remove("./data/bill.txt");
    rename("./data/temp.txt", "./data/bill.txt");
    return 1;
}

int update_bill_date()
{
    Bill bill;
    int billId;
    bill_file = fopen("./data/bill.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (bill_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter bill id: ");
    scanf("%d", &billId);

    while (fread(&bill, sizeof(Bill), 1, bill_file))
    {
        if (bill.billId == billId)
        {
            printf("\nEnter new bill date: ");
            scanf("%s", bill.billDate);
        }
        fwrite(&bill, sizeof(Bill), 1, temp_file);
    }
    fclose(bill_file);
    fclose(temp_file);
    remove("./data/bill.txt");
    rename("./data/temp.txt", "./data/bill.txt");
    return 1;
}

int update_bill_status()
{
    Bill bill;
    int billId;
    bill_file = fopen("./data/bill.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (bill_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter bill id: ");
    scanf("%d", &billId);

    while (fread(&bill, sizeof(Bill), 1, bill_file))
    {
        if (bill.billId == billId)
        {
            printf("\nEnter new bill status: ");
            scanf("%s", bill.billStatus);
        }
        fwrite(&bill, sizeof(Bill), 1, temp_file);
    }
    fclose(bill_file);
    fclose(temp_file);
    remove("./data/bill.txt");
    rename("./data/temp.txt", "./data/bill.txt");
    return 1;
}

int update_bill()
{
    int choice;
    while (1)
    {
        printf("\n1. Update patient id\n");
        printf("2. Update doctor id\n");
        printf("3. Update room id\n");
        printf("4. Update appointment id\n");
        printf("5. Update total amount\n");
        printf("6. Update bill date\n");
        printf("7. Update bill status\n");
        printf("8. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            update_bill_patient_id();
            break;
        case 2:
            update_bill_doctor_id();
            break;
        case 3:
            update_bill_room_id();
            break;
        case 4:
            update_bill_appointment_id();
            break;
        case 5:
            update_bill_total_amount();
            break;
        case 6:
            update_bill_date();
            break;
        case 7:
            update_bill_status();
            break;
        case 8:
            return 1;
        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
}

int delete_bill()
{
    Bill bill;
    int billId;
    bill_file = fopen("./data/bill.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (bill_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter bill id: ");
    scanf("%d", &billId);

    while (fread(&bill, sizeof(Bill), 1, bill_file))
    {
        if (bill.billId != billId)
        {
            fwrite(&bill, sizeof(Bill), 1, temp_file);
        }
    }
    fclose(bill_file);
    fclose(temp_file);
    remove("./data/bill.txt");
    rename("./data/temp.txt", "./data/bill.txt");
    return 1;
}