#ifndef APPIONTMENT_MODEL_H
#define APPIONTMENT_MODEL_H

typedef struct Appointment
{
    int appointmentId;
    int patientId;
    int doctorId;
    char appointmentDate[10];
    char appointmentTime[10];
    char appointmentStatus[10];
} Appointment;

#endif