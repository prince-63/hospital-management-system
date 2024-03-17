#ifndef DEPARTMENT_MODEL_H
#define DEPARTMENT_MODEL_H

typedef struct Department
{
    int departmentId;
    char departmentName[50];
    char departmentHead[50];
    char departmentContact[10];
    char departmentEmail[50];
    char departmentStatus[10];
} Department;

#endif