#ifndef STAFF_MODEL_H
#define STAFF_MODEL_H

typedef struct Staff
{
    int staffId;
    char staffName[50];
    char staffGender[10];
    char staffPosition[50];
    char staffStatus[10];
} Staff;

#endif