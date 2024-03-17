#include "../../model/doctor/doctor_model.h"
#include <stdio.h>

FILE *doctor_file, *temp_file;

int add_doctor()
{
    Doctor doctor;
    doctor_file = fopen("./data/doctor.txt", "a");

    if (doctor_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter doctor id: ");
    scanf("%d", &doctor.doctorId);
    printf("Enter doctor name: ");
    scanf("%s", doctor.doctorName);
    printf("Enter doctor address: ");
    scanf("%s", doctor.doctorAddress);
    printf("Enter doctor contact: ");
    scanf("%s", doctor.doctorContact);
    printf("Enter doctor email: ");
    scanf("%s", doctor.doctorEmail);
    printf("Enter doctor blood group: ");
    scanf("%s", doctor.doctorBloodGroup);
    printf("Enter doctor specialization: ");
    scanf("%s", doctor.doctorSpecialization);
    printf("Enter doctor joining date: ");
    scanf("%s", doctor.doctorJoiningDate);
    printf("Enter doctor leaving date: ");
    scanf("%s", doctor.doctorLeavingDate);

    fwrite(&doctor, sizeof(Doctor), 1, doctor_file);
    fclose(doctor_file);
    return 1;
}

void display_doctor()
{
    Doctor doctor;
    doctor_file = fopen("./data/doctor.txt", "r");
    if (doctor_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    // Print table header
    printf("\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Doctor Id", "Doctor Name", "Doctor Address", "Doctor Contact", "Doctor Email", "Doctor Blood Group", "Doctor Specialization", "Doctor Joining Date", "Doctor Leaving Date");

    while (fread(&doctor, sizeof(Doctor), 1, doctor_file))
    {
        // Print table row
        printf("%-10d %-20s %-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", doctor.doctorId, doctor.doctorName, doctor.doctorAddress, doctor.doctorContact, doctor.doctorEmail, doctor.doctorBloodGroup, doctor.doctorSpecialization, doctor.doctorJoiningDate, doctor.doctorLeavingDate);
    }
    fclose(doctor_file);
}

void update_doctor_name()
{
    Doctor doctor;
    int doctorId;
    doctor_file = fopen("./data/doctor.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (doctor_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter doctor id: ");
    scanf("%d", &doctorId);

    while (fread(&doctor, sizeof(Doctor), 1, doctor_file))
    {
        if (doctor.doctorId == doctorId)
        {
            printf("\nEnter new doctor name: ");
            scanf("%s", doctor.doctorName);
        }
        fwrite(&doctor, sizeof(Doctor), 1, temp_file);
    }
    fclose(doctor_file);
    fclose(temp_file);
    remove("./data/doctor.txt");
    rename("./data/temp.txt", "./data/doctor.txt");
}

void update_doctor_address()
{
    Doctor doctor;
    int doctorId;
    doctor_file = fopen("./data/doctor.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (doctor_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter doctor id: ");
    scanf("%d", &doctorId);

    while (fread(&doctor, sizeof(Doctor), 1, doctor_file))
    {
        if (doctor.doctorId == doctorId)
        {
            printf("\nEnter new doctor address: ");
            scanf("%s", doctor.doctorAddress);
        }
        fwrite(&doctor, sizeof(Doctor), 1, temp_file);
    }
    fclose(doctor_file);
    fclose(temp_file);
    remove("./data/doctor.txt");
    rename("./data/temp.txt", "./data/doctor.txt");
}

void update_doctor_contact()
{
    Doctor doctor;
    int doctorId;
    doctor_file = fopen("./data/doctor.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (doctor_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter doctor id: ");
    scanf("%d", &doctorId);

    while (fread(&doctor, sizeof(Doctor), 1, doctor_file))
    {
        if (doctor.doctorId == doctorId)
        {
            printf("\nEnter new doctor contact: ");
            scanf("%s", doctor.doctorContact);
        }
        fwrite(&doctor, sizeof(Doctor), 1, temp_file);
    }
    fclose(doctor_file);
    fclose(temp_file);
    remove("./data/doctor.txt");
    rename("./data/temp.txt", "./data/doctor.txt");
}

void update_doctor_email()
{
    Doctor doctor;
    int doctorId;
    doctor_file = fopen("./data/doctor.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (doctor_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter doctor id: ");
    scanf("%d", &doctorId);

    while (fread(&doctor, sizeof(Doctor), 1, doctor_file))
    {
        if (doctor.doctorId == doctorId)
        {
            printf("\nEnter new doctor email: ");
            scanf("%s", doctor.doctorEmail);
        }
        fwrite(&doctor, sizeof(Doctor), 1, temp_file);
    }
    fclose(doctor_file);
    fclose(temp_file);
    remove("./data/doctor.txt");
    rename("./data/temp.txt", "./data/doctor.txt");
}

void update_doctor_blood_group()
{
    Doctor doctor;
    int doctorId;
    doctor_file = fopen("./data/doctor.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (doctor_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter doctor id: ");
    scanf("%d", &doctorId);

    while (fread(&doctor, sizeof(Doctor), 1, doctor_file))
    {
        if (doctor.doctorId == doctorId)
        {
            printf("\nEnter new doctor blood group: ");
            scanf("%s", doctor.doctorBloodGroup);
        }
        fwrite(&doctor, sizeof(Doctor), 1, temp_file);
    }
    fclose(doctor_file);
    fclose(temp_file);
    remove("./data/doctor.txt");
    rename("./data/temp.txt", "./data/doctor.txt");
}

void update_doctor_specialization()
{
    Doctor doctor;
    int doctorId;
    doctor_file = fopen("./data/doctor.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (doctor_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter doctor id: ");
    scanf("%d", &doctorId);

    while (fread(&doctor, sizeof(Doctor), 1, doctor_file))
    {
        if (doctor.doctorId == doctorId)
        {
            printf("\nEnter new doctor specialization: ");
            scanf("%s", doctor.doctorSpecialization);
        }
        fwrite(&doctor, sizeof(Doctor), 1, temp_file);
    }
    fclose(doctor_file);
    fclose(temp_file);
    remove("./data/doctor.txt");
    rename("./data/temp.txt", "./data/doctor.txt");
}

void update_doctor_joining_date()
{
    Doctor doctor;
    int doctorId;
    doctor_file = fopen("./data/doctor.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (doctor_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter doctor id: ");
    scanf("%d", &doctorId);

    while (fread(&doctor, sizeof(Doctor), 1, doctor_file))
    {
        if (doctor.doctorId == doctorId)
        {
            printf("\nEnter new doctor joining date: ");
            scanf("%s", doctor.doctorJoiningDate);
        }
        fwrite(&doctor, sizeof(Doctor), 1, temp_file);
    }
    fclose(doctor_file);
    fclose(temp_file);
    remove("./data/doctor.txt");
    rename("./data/temp.txt", "./data/doctor.txt");
}

void update_doctor_leaving_date()
{
    Doctor doctor;
    int doctorId;
    doctor_file = fopen("./data/doctor.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (doctor_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter doctor id: ");
    scanf("%d", &doctorId);

    while (fread(&doctor, sizeof(Doctor), 1, doctor_file))
    {
        if (doctor.doctorId == doctorId)
        {
            printf("\nEnter new doctor leaving date: ");
            scanf("%s", doctor.doctorLeavingDate);
        }
        fwrite(&doctor, sizeof(Doctor), 1, temp_file);
    }
    fclose(doctor_file);
    fclose(temp_file);
    remove("./data/doctor.txt");
    rename("./data/temp.txt", "./data/doctor.txt");
}

void update_doctor()
{
    int choice;
    while (1)
    {
        printf("\n1. Update doctor name");
        printf("\n2. Update doctor address");
        printf("\n3. Update doctor contact");
        printf("\n4. Update doctor email");
        printf("\n5. Update doctor blood group");
        printf("\n6. Update doctor specialization");
        printf("\n7. Update doctor joining date");
        printf("\n8. Update doctor leaving date");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            update_doctor_name();
            break;
        case 2:
            update_doctor_address();
            break;
        case 3:
            update_doctor_contact();
            break;
        case 4:
            update_doctor_email();
            break;
        case 5:
            update_doctor_blood_group();
            break;
        case 6:
            update_doctor_specialization();
            break;
        case 7:
            update_doctor_joining_date();
            break;
        case 8:
            update_doctor_leaving_date();
            break;
        case 9:
            return;
        default:
            printf("\nInvalid choice\n");
        }
    }
}

void delete_doctor()
{
    Doctor doctor;
    int doctorId;
    doctor_file = fopen("./data/doctor.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (doctor_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter doctor id to delete: ");
    scanf("%d", &doctorId);

    while (fread(&doctor, sizeof(Doctor), 1, doctor_file))
    {
        if (doctor.doctorId != doctorId)
        {
            fwrite(&doctor, sizeof(Doctor), 1, temp_file);
        }
    }
    fclose(doctor_file);
    fclose(temp_file);
    remove("./data/doctor.txt");
    rename("./data/temp.txt", "./data/doctor.txt");
}