#include "../../model/patient/patient_model.h"
#include <stdio.h>

FILE *patient_file, *temp_file;

int add_patient()
{
    Patient patient;
    patient_file = fopen("./data/patient.txt", "a");

    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patient.patientId);
    printf("Enter patient name: ");
    scanf("%s", patient.patientName);
    printf("Enter patient address: ");
    scanf("%s", patient.patientAddress);
    printf("Enter patient contact: ");
    scanf("%s", patient.patientContact);
    printf("Enter patient email: ");
    scanf("%s", patient.patientEmail);
    printf("Enter patient blood group: ");
    scanf("%s", patient.patientBloodGroup);
    printf("Enter patient disease: ");
    scanf("%s", patient.patientDisease);
    printf("Enter patient admit date: ");
    scanf("%s", patient.patientAdmitDate);
    printf("Enter patient discharge date: ");
    scanf("%s", patient.patientDischargeDate);
    printf("Enter patient room type: ");
    scanf("%s", patient.patientRoomType);
    printf("Enter patient room no: ");
    scanf("%d", &patient.patientRoomNo);
    printf("Enter patient age: ");
    scanf("%d", &patient.patientAge);

    fwrite(&patient, sizeof(Patient), 1, patient_file);
    fclose(patient_file);
    return 1;
}

void display_patient()
{
    Patient patient;
    patient_file = fopen("./data/patient.txt", "r");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    // Print table header
    printf("\n%-10s %-20s %-20s %-15s %-20s %-15s %-20s %-15s %-20s %-15s %-10s %-5s\n",
           "Patient Id", "Patient Name", "Patient Address", "Patient Contact",
           "Patient Email", "Blood Group", "Patient Disease", "Admit Date",
           "Discharge Date", "Room Type", "Room No", "Age");

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        // Print table row
        printf("%-10d %-20s %-20s %-15s %-20s %-15s %-20s %-15s %-20s %-15s %-10d %-5d\n",
               patient.patientId, patient.patientName, patient.patientAddress, patient.patientContact,
               patient.patientEmail, patient.patientBloodGroup, patient.patientDisease, patient.patientAdmitDate,
               patient.patientDischargeDate, patient.patientRoomType, patient.patientRoomNo, patient.patientAge);
    }
    fclose(patient_file);
}

void update_patient_name()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId == patientId)
        {
            printf("\nEnter new patient name: ");
            scanf("%s", patient.patientName);
        }
        fwrite(&patient, sizeof(Patient), 1, temp_file);
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}

void update_patient_address()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId == patientId)
        {
            printf("\nEnter new patient address: ");
            scanf("%s", patient.patientAddress);
        }
        fwrite(&patient, sizeof(Patient), 1, temp_file);
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}

void update_patient_contact()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId == patientId)
        {
            printf("\nEnter new patient contact: ");
            scanf("%s", patient.patientContact);
        }
        fwrite(&patient, sizeof(Patient), 1, temp_file);
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}

void update_patient_email()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId == patientId)
        {
            printf("\nEnter new patient email: ");
            scanf("%s", patient.patientEmail);
        }
        fwrite(&patient, sizeof(Patient), 1, temp_file);
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}

void update_patient_blood_group()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId == patientId)
        {
            printf("\nEnter new patient blood group: ");
            scanf("%s", patient.patientBloodGroup);
        }
        fwrite(&patient, sizeof(Patient), 1, temp_file);
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}

void update_patient_disease()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId == patientId)
        {
            printf("\nEnter new patient disease: ");
            scanf("%s", patient.patientDisease);
        }
        fwrite(&patient, sizeof(Patient), 1, temp_file);
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}

void update_patient_admit_date()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId == patientId)
        {
            printf("\nEnter new patient admit date: ");
            scanf("%s", patient.patientAdmitDate);
        }
        fwrite(&patient, sizeof(Patient), 1, temp_file);
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}

void update_patient_discharge_date()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId == patientId)
        {
            printf("\nEnter new patient discharge date: ");
            scanf("%s", patient.patientDischargeDate);
        }
        fwrite(&patient, sizeof(Patient), 1, temp_file);
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}

void update_patient_room_type()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId == patientId)
        {
            printf("\nEnter new patient room type: ");
            scanf("%s", patient.patientRoomType);
        }
        fwrite(&patient, sizeof(Patient), 1, temp_file);
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}

void update_patient_room_no()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId == patientId)
        {
            printf("\nEnter new patient room no: ");
            scanf("%d", &patient.patientRoomNo);
        }
        fwrite(&patient, sizeof(Patient), 1, temp_file);
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}

void update_patient_age()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId == patientId)
        {
            printf("\nEnter new patient age: ");
            scanf("%d", &patient.patientAge);
        }
        fwrite(&patient, sizeof(Patient), 1, temp_file);
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}

void update_patient()
{
    int choice;
    while (1)
    {
        printf("\n1. Update patient name");
        printf("\n2. Update patient address");
        printf("\n3. Update patient contact");
        printf("\n4. Update patient email");
        printf("\n5. Update patient blood group");
        printf("\n6. Update patient disease");
        printf("\n7. Update patient admit date");
        printf("\n8. Update patient discharge date");
        printf("\n9. Update patient room type");
        printf("\n10. Update patient room no");
        printf("\n11. Update patient age");
        printf("\n12. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            update_patient_name();
            break;
        case 2:
            update_patient_address();
            break;
        case 3:
            update_patient_contact();
            break;
        case 4:
            update_patient_email();
            break;
        case 5:
            update_patient_blood_group();
            break;
        case 6:
            update_patient_disease();
            break;
        case 7:
            update_patient_admit_date();
            break;
        case 8:
            update_patient_discharge_date();
            break;
        case 9:
            update_patient_room_type();
            break;
        case 10:
            update_patient_room_no();
            break;
        case 11:
            update_patient_age();
            break;
        case 12:
            return;
        default:
            printf("\nInvalid choice");
        }
    }
}

void delete_patient()
{
    Patient patient;
    int patientId;
    patient_file = fopen("./data/patient.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (patient_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter patient id: ");
    scanf("%d", &patientId);

    while (fread(&patient, sizeof(Patient), 1, patient_file))
    {
        if (patient.patientId != patientId)
        {
            fwrite(&patient, sizeof(Patient), 1, temp_file);
        }
    }
    fclose(patient_file);
    fclose(temp_file);
    remove("./data/patient.txt");
    rename("./data/temp.txt", "./data/patient.txt");
}
