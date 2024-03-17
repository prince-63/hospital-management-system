#ifndef BILL_MODEL_H
#define BILL_MODEL_H

typedef struct Bill
{
    int billId;
    int patientId;
    int doctorId;
    int roomId;
    int appointmentId;
    int totalAmount;
    char billDate[10];
    char billStatus[10];
} Bill;

#endif