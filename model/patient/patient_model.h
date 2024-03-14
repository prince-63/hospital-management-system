#ifndef PATIENT_MODEL_H
#define PATIENT_MODEL_H

typedef struct Patient
{
    int patientId;
    char patientName[50];
    char patientAddress[100];
    char patientContact[10];
    char patientEmail[50];
    char patientGender[10];
    char patientBloodGroup[5];
    char patientDisease[50];
    char patientAdmitDate[10];
    char patientDischargeDate[10];
    char patientRoomType[10];
    int patientRoomNo;
    int patientAge;
} Patient;

#endif