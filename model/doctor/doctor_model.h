#ifndef DOCOTR_MODEL_H
#define DOCOTR_MODEL_H

typedef struct Doctor
{
    int doctorId;
    char doctorName[50];
    char doctorAddress[100];
    char doctorContact[10];
    char doctorEmail[50];
    char doctorGender[10];
    char doctorBloodGroup[5];
    char doctorSpecialization[50];
    char doctorJoiningDate[10];
    char doctorLeavingDate[10];
} Doctor;

#endif