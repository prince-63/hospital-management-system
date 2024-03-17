#include "../../model/appointment/appointemt_model.h"
#include <stdio.h>

FILE *appointment_file, *temp_file;

int add_appointment()
{
    Appointment appointment;
    appointment_file = fopen("./data/appointment.txt", "a");

    if (appointment_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter appointment id: ");
    scanf("%d", &appointment.appointmentId);
    printf("Enter patient id: ");
    scanf("%d", &appointment.patientId);
    printf("Enter doctor id: ");
    scanf("%d", &appointment.doctorId);
    printf("Enter appointment date: ");
    scanf("%s", appointment.appointmentDate);
    printf("Enter appointment time: ");
    scanf("%s", appointment.appointmentTime);
    printf("Enter appointment status: ");
    scanf("%s", appointment.appointmentStatus);

    fwrite(&appointment, sizeof(Appointment), 1, appointment_file);
    fclose(appointment_file);
    return 1;
}

void display_appointment()
{
    Appointment appointment;
    appointment_file = fopen("./data/appointment.txt", "r");
    if (appointment_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    // Print table header
    printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "Appointment Id", "Patient Id", "Doctor Id", "Appointment Date", "Appointment Time", "Appointment Status");

    while (fread(&appointment, sizeof(Appointment), 1, appointment_file))
    {
        // Print table row
        printf("%-10d %-10d %-10d %-10s %-10s %-10s\n", appointment.appointmentId, appointment.patientId, appointment.doctorId, appointment.appointmentDate, appointment.appointmentTime, appointment.appointmentStatus);
    }
    fclose(appointment_file);
}

// each update function should be able to update a single field of the appointment
int update_appointment_patient_id()
{
    Appointment appointment;
    int appointmentId;
    appointment_file = fopen("./data/appointment.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (appointment_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter appointment id to update: ");
    scanf("%d", &appointmentId);

    while (fread(&appointment, sizeof(Appointment), 1, appointment_file))
    {
        if (appointment.appointmentId == appointmentId)
        {
            printf("\nEnter new patient id: ");
            scanf("%d", &appointment.patientId);
        }
        fwrite(&appointment, sizeof(Appointment), 1, temp_file);
    }
    fclose(appointment_file);
    fclose(temp_file);
    remove("./data/appointment.txt");
    rename("./data/temp.txt", "./data/appointment.txt");
    return 1;
}

int update_appointment_doctor_id()
{
    Appointment appointment;
    int appointmentId;
    appointment_file = fopen("./data/appointment.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (appointment_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter appointment id to update: ");
    scanf("%d", &appointmentId);

    while (fread(&appointment, sizeof(Appointment), 1, appointment_file))
    {
        if (appointment.appointmentId == appointmentId)
        {
            printf("\nEnter new doctor id: ");
            scanf("%d", &appointment.doctorId);
        }
        fwrite(&appointment, sizeof(Appointment), 1, temp_file);
    }
    fclose(appointment_file);
    fclose(temp_file);
    remove("./data/appointment.txt");
    rename("./data/temp.txt", "./data/appointment.txt");
    return 1;
}

int update_appointment_date()
{
    Appointment appointment;
    int appointmentId;
    appointment_file = fopen("./data/appointment.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (appointment_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter appointment id to update: ");
    scanf("%d", &appointmentId);

    while (fread(&appointment, sizeof(Appointment), 1, appointment_file))
    {
        if (appointment.appointmentId == appointmentId)
        {
            printf("\nEnter new appointment date: ");
            scanf("%s", appointment.appointmentDate);
        }
        fwrite(&appointment, sizeof(Appointment), 1, temp_file);
    }
    fclose(appointment_file);
    fclose(temp_file);
    remove("./data/appointment.txt");
    rename("./data/temp.txt", "./data/appointment.txt");
    return 1;
}

int update_appointment_time()
{
    Appointment appointment;
    int appointmentId;
    appointment_file = fopen("./data/appointment.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (appointment_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter appointment id to update: ");
    scanf("%d", &appointmentId);

    while (fread(&appointment, sizeof(Appointment), 1, appointment_file))
    {
        if (appointment.appointmentId == appointmentId)
        {
            printf("\nEnter new appointment time: ");
            scanf("%s", appointment.appointmentTime);
        }
        fwrite(&appointment, sizeof(Appointment), 1, temp_file);
    }
    fclose(appointment_file);
    fclose(temp_file);
    remove("./data/appointment.txt");
    rename("./data/temp.txt", "./data/appointment.txt");
    return 1;
}

int update_appointment_status()
{
    Appointment appointment;
    int appointmentId;
    appointment_file = fopen("./data/appointment.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (appointment_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter appointment id to update: ");
    scanf("%d", &appointmentId);

    while (fread(&appointment, sizeof(Appointment), 1, appointment_file))
    {
        if (appointment.appointmentId == appointmentId)
        {
            printf("\nEnter new appointment status: ");
            scanf("%s", appointment.appointmentStatus);
        }
        fwrite(&appointment, sizeof(Appointment), 1, temp_file);
    }
    fclose(appointment_file);
    fclose(temp_file);
    remove("./data/appointment.txt");
    rename("./data/temp.txt", "./data/appointment.txt");
    return 1;
}

int update_appointment()
{
    int choice;
    while (1)
    {
        printf("\n1. Update patient id\n");
        printf("2. Update doctor id\n");
        printf("3. Update appointment date\n");
        printf("4. Update appointment time\n");
        printf("5. Update appointment status\n");
        printf("6. Go back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            update_appointment_patient_id();
            break;
        case 2:
            update_appointment_doctor_id();
            break;
        case 3:
            update_appointment_date();
            break;
        case 4:
            update_appointment_time();
            break;
        case 5:
            update_appointment_status();
            break;
        case 6:
            return 1;
        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
}

int delete_appointment()
{
    Appointment appointment;
    int appointmentId;
    appointment_file = fopen("./data/appointment.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (appointment_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter appointment id to delete: ");
    scanf("%d", &appointmentId);

    while (fread(&appointment, sizeof(Appointment), 1, appointment_file))
    {
        if (appointment.appointmentId != appointmentId)
        {
            fwrite(&appointment, sizeof(Appointment), 1, temp_file);
        }
    }
    fclose(appointment_file);
    fclose(temp_file);
    remove("./data/appointment.txt");
    rename("./data/temp.txt", "./data/appointment.txt");
    return 1;
}