#include <stdio.h>

FILE *PatientFilePointer, *DoctorFilePointer, *AppointmentFilePointer, *RoomFilePointer, *BillFilePointer, *InventoryFilePointer, *StaffFilePointer, *DepartmentFilePointer, *TempFilePointer, *LoginFilePointer;

/* model and schemas */
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
    int patientWeight;
    int patientHeight;
    int patientContactEmergency[10];
    char patientEmergencyContactName[50];
    char patientEmergencyContactRelation[50];
    char patientEmergencyContactAddress[100];
    char patientEmergencyContactEmail[50];
} Patient;

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
    int doctorAge;
    int doctorWeight;
    int doctorHeight;
    int doctorContactEmergency[10];
    char doctorEmergencyContactName[50];
    char doctorEmergencyContactRelation[50];
    char doctorEmergencyContactAddress[100];
    char doctorEmergencyContactEmail[50];
} Doctor;

typedef struct Appointment
{
    int appointmentId;
    int patientId;
    int doctorId;
    char appointmentDate[10];
    char appointmentTime[10];
    char appointmentStatus[10];
} Appointment;

typedef struct Room
{
    int roomId;
    int roomNo;
    char roomType[10];
    char roomStatus[10];
} Room;

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

typedef struct Inventory
{
    int inventoryId;
    char inventoryName[50];
    int inventoryQuantity;
    int inventoryPrice;
    char inventoryStatus[10];
} Inventory;

typedef struct Staff
{
    int staffId;
    char staffName[50];
    char staffAddress[100];
    char staffContact[10];
    char staffEmail[50];
    char staffGender[10];
    char staffBloodGroup[5];
    char staffDesignation[50];
    char staffJoiningDate[10];
    char staffLeavingDate[10];
    int staffAge;
    int staffWeight;
    int staffHeight;
    int staffContactEmergency[10];
    char staffEmergencyContactName[50];
    char staffEmergencyContactRelation[50];
    char staffEmergencyContactAddress[100];
    char staffEmergencyContactEmail[50];
} Staff;

typedef struct Department
{
    int departmentId;
    char departmentName[50];
    char departmentHead[50];
    char departmentContact[10];
    char departmentEmail[50];
    char departmentStatus[10];
} Department;

/* global static size allocation of each schemas */
Patient patients[1000];
Doctor doctors[1000];
Appointment appointments[1000];
Room rooms[1000];
Bill bills[1000];
Inventory inventories[1000];
Staff staffs[1000];
Department departments[1000];

/* global static count of each schemas */
int patientCount = 0;
int doctorCount = 0;
int appointmentCount = 0;
int roomCount = 0;
int billCount = 0;
int inventoryCount = 0;
int staffCount = 0;
int departmentCount = 0;

/* function declaration */
int login();
int createAccount();
void addPatient();
void addDoctor();
void addAppointment();
void addRoom();
void addBill();
void addInventory();
void addStaff();
void addDepartment();
void displayPatient();
void displayDoctor();
void displayAppointment();
void displayRoom();
void displayBill();
void displayInventory();
void displayStaff();
void displayDepartment();
void updatePatient();
void updateDoctor();
void updateAppointment();
void updateRoom();
void updateBill();
void updateInventory();
void updateStaff();
void updateDepartment();
void removePatient();
void removeDoctor();
void removeAppointment();
void removeRoom();
void removeBill();
void removeInventory();
void removeStaff();
void removeDepartment();

int main()
{
    int choice;
    int loginChoice;

    printf("\n\n\n\n");
    printf("     ********************************************************************\n");
    printf("     *                                                                   *\n");
    printf("     *                                                                   *\n");
    printf("     *             Welcome  TO  Hotel Management System                   *\n");
    printf("     *                                                                   *\n");
    printf("     *                                                                   *\n");
    printf("      *******************************************************************\n");
    printf("\n\n\n\n\n");

    printf("****************You Have An Already Account?****************\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &loginChoice);

    if (loginChoice == 2)
    {
        int isCreated = createAccount();

        printf("\n\n\n\n");
        printf("     *********************************************************************\n");
        printf("     *                                                                   *\n");
        printf("     *                                                                   *\n");
        printf("     *           Account Successfully Created Please Login!              *\n");
        printf("     *                                                                   *\n");
        printf("     *                                                                   *\n");
        printf("     *********************************************************************\n");
        printf("\n\n\n\n\n");

        int isTrue = login();

        if (isTrue == 0)
        {
            printf("Invalid username or password\n");
            return 0;
        }

        printf("\n\n\n\n");
        printf("     *********************************************************************\n");
        printf("     *                                                                   *\n");
        printf("     *                                                                   *\n");
        printf("     *                           Login Successfull!                      *\n");
        printf("     *                                                                   *\n");
        printf("     *                                                                   *\n");
        printf("     *********************************************************************\n");
        printf("\n\n\n\n\n");
    }
    else
    {
        int isTrue = login();

        if (isTrue == 0)
        {
            printf("Invalid username or password\n");
            return 0;
        }

        printf("\n\n\n\n");
        printf("     *********************************************************************\n");
        printf("     *                                                                   *\n");
        printf("     *                                                                   *\n");
        printf("     *                           Login Successfull!                      *\n");
        printf("     *                                                                   *\n");
        printf("     *                                                                   *\n");
        printf("     *********************************************************************\n");
        printf("\n\n\n\n\n");
    }

    while (1)
    {
        printf("\n");
        printf("1. Add Patient\n");
        printf("2. Add Doctor\n");
        printf("3. Add Appointment\n");
        printf("4. Add Room\n");
        printf("5. Add Bill\n");
        printf("6. Add Inventory\n");
        printf("7. Add Staff\n");
        printf("8. Add Department\n");
        printf("9. Display Patient\n");
        printf("10. Display Doctor\n");
        printf("11. Display Appointment\n");
        printf("12. Display Room\n");
        printf("13. Display Bill\n");
        printf("14. Display Inventory\n");
        printf("15. Display Staff\n");
        printf("16. Display Department\n");
        printf("17. Update Patient\n");
        printf("18. Update Doctor\n");
        printf("19. Update Appointment\n");
        printf("20. Update Room\n");
        printf("21. Update Bill\n");
        printf("22. Update Inventory\n");
        printf("23. Upda4te Staff\n");
        printf("24. Update Department\n");
        printf("25. Remove Patient\n");
        printf("26. Remove Doctor\n");
        printf("27. Remove Appointment\n");
        printf("28. Remove Room\n");
        printf("29. Remove Bill\n");
        printf("30. Remove Inventory\n");
        printf("31. Remove Staff\n");
        printf("32. Remove Department\n");
        printf("33. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            addDoctor();
            break;
        case 3:
            addAppointment();
            break;
        case 4:
            addRoom();
            break;
        case 5:
            addBill();
            break;
        case 6:
            addInventory();
            break;
        case 7:
            addStaff();
            break;
        case 8:
            addDepartment();
            break;
        case 9:
            displayPatient();
            break;
        case 10:
            displayDoctor();
            break;
        case 11:
            displayAppointment();
            break;
        case 12:
            displayRoom();
            break;
        case 13:
            displayBill();
            break;
        case 14:
            displayInventory();
            break;
        case 15:
            displayStaff();
            break;
        case 16:
            displayDepartment();
            break;
        case 17:
            updatePatient();
            break;
        case 18:
            updateDoctor();
            break;
        case 19:
            updateAppointment();
            break;
        case 20:
            updateRoom();
            break;
        case 21:
            updateBill();
            break;
        case 22:
            updateInventory();
            break;
        case 23:
            updateStaff();
            break;
        case 24:
            updateDepartment();
            break;
        case 25:
            removePatient();
            break;
        case 26:
            removeDoctor();
            break;
        case 27:
            removeAppointment();
            break;
        case 28:
            removeRoom();
            break;
        case 29:
            removeBill();
            break;
        case 30:
            removeInventory();
            break;
        case 31:
            removeStaff();
            break;
        case 32:
            removeDepartment();
            break;
        case 33:
            return 0;
        default:
            printf("Please enter right choice\n");
            break;
        }
    }

    return 0;
}

int createAccount()
{
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    LoginFilePointer = fopen("./data/login.txt", "a");

    if (LoginFilePointer == NULL)
    {
        printf("Error!");
        return 0;
    }

    fprintf(LoginFilePointer, " %s %s", username, password);

    fclose(LoginFilePointer);

    return 1;
}

int login()
{
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    LoginFilePointer = fopen("./data/login.txt", "r");

    if (LoginFilePointer == NULL)
    {
        printf("Error!");
        return 0;
    }

    while (fscanf(LoginFilePointer, " %s %s", username, password) != EOF)
    {
        if (username == username && password == password)
        {
            return 1;
        }
    }

    fclose(LoginFilePointer);

    return 0;
}

void addPatient()
{
    printf("\n--------------------Add New Patient Details--------------------\n");
    printf("\n");
    printf("Enter patient id: ");
    scanf("%d", &patients[patientCount].patientId);
    printf("Enter patient name: ");
    scanf("%s", patients[patientCount].patientName);
    printf("Enter patient address: ");
    scanf("%s", patients[patientCount].patientAddress);
    printf("Enter patient contact: ");
    scanf("%s", patients[patientCount].patientContact);
    printf("Enter patient email: ");
    scanf("%s", patients[patientCount].patientEmail);
    printf("Enter patient gender: ");
    scanf("%s", patients[patientCount].patientGender);
    printf("Enter patient blood group: ");
    scanf("%s", patients[patientCount].patientBloodGroup);
    printf("Enter patient disease: ");
    scanf("%s", patients[patientCount].patientDisease);
    printf("Enter patient admit date: ");
    scanf("%s", patients[patientCount].patientAdmitDate);
    printf("Enter patient discharge date: ");
    scanf("%s", patients[patientCount].patientDischargeDate);
    printf("Enter patient room type: ");
    scanf("%s", patients[patientCount].patientRoomType);
    printf("Enter patient room no: ");
    scanf("%d", &patients[patientCount].patientRoomNo);
    printf("Enter patient age: ");
    scanf("%d", &patients[patientCount].patientAge);
    printf("Enter patient weight: ");
    scanf("%d", &patients[patientCount].patientWeight);
    printf("Enter patient height: ");
    scanf("%d", &patients[patientCount].patientHeight);
    printf("Enter patient emergency contact name: ");
    scanf("%s", patients[patientCount].patientEmergencyContactName);
    printf("Enter patient emergency contact relation: ");
    scanf("%s", patients[patientCount].patientEmergencyContactRelation);
    printf("Enter patient emergency contact address: ");
    scanf("%s", patients[patientCount].patientEmergencyContactAddress);
    printf("Enter patient emergency contact email: ");
    scanf("%s", patients[patientCount].patientEmergencyContactEmail);

    PatientFilePointer = fopen("./data/patient.txt", "a");

    if (PatientFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    fprintf(PatientFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %d %s %s %s %s", patients[patientCount].patientId, patients[patientCount].patientName, patients[patientCount].patientAddress, patients[patientCount].patientContact, patients[patientCount].patientEmail, patients[patientCount].patientGender, patients[patientCount].patientBloodGroup, patients[patientCount].patientDisease, patients[patientCount].patientAdmitDate, patients[patientCount].patientDischargeDate, patients[patientCount].patientRoomNo, patients[patientCount].patientAge, patients[patientCount].patientWeight, patients[patientCount].patientHeight, patients[patientCount].patientEmergencyContactName, patients[patientCount].patientEmergencyContactRelation, patients[patientCount].patientEmergencyContactAddress, patients[patientCount].patientEmergencyContactEmail);

    fclose(PatientFilePointer);

    patientCount++;
};

void addDoctor()
{
    printf("\n--------------------Add New Doctor Details--------------------\n");
    printf("\n");
    printf("Enter doctor id: ");
    scanf("%d", &doctors[doctorCount].doctorId);
    printf("Enter doctor name: ");
    scanf("%s", doctors[doctorCount].doctorName);
    printf("Enter doctor address: ");
    scanf("%s", doctors[doctorCount].doctorAddress);
    printf("Enter doctor contact: ");
    scanf("%s", doctors[doctorCount].doctorContact);
    printf("Enter doctor email: ");
    scanf("%s", doctors[doctorCount].doctorEmail);
    printf("Enter doctor gender: ");
    scanf("%s", doctors[doctorCount].doctorGender);
    printf("Enter doctor blood group: ");
    scanf("%s", doctors[doctorCount].doctorBloodGroup);
    printf("Enter doctor specialization: ");
    scanf("%s", doctors[doctorCount].doctorSpecialization);
    printf("Enter doctor joining date: ");
    scanf("%s", doctors[doctorCount].doctorJoiningDate);
    printf("Enter doctor leaving date: ");
    scanf("%s", doctors[doctorCount].doctorLeavingDate);
    printf("Enter doctor age: ");
    scanf("%d", &doctors[doctorCount].doctorAge);
    printf("Enter doctor weight: ");
    scanf("%d", &doctors[doctorCount].doctorWeight);
    printf("Enter doctor height: ");
    scanf("%d", &doctors[doctorCount].doctorHeight);
    printf("Enter doctor emergency contact name: ");
    scanf("%s", doctors[doctorCount].doctorEmergencyContactName);
    printf("Enter doctor emergency contact relation: ");
    scanf("%s", doctors[doctorCount].doctorEmergencyContactRelation);
    printf("Enter doctor emergency contact address: ");
    scanf("%s", doctors[doctorCount].doctorEmergencyContactAddress);
    printf("Enter doctor emergency contact email: ");
    scanf("%s", doctors[doctorCount].doctorEmergencyContactEmail);

    DoctorFilePointer = fopen("./data/doctor.txt", "a");

    if (DoctorFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    fprintf(DoctorFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", doctors[doctorCount].doctorId, doctors[doctorCount].doctorName, doctors[doctorCount].doctorAddress, doctors[doctorCount].doctorContact, doctors[doctorCount].doctorEmail, doctors[doctorCount].doctorGender, doctors[doctorCount].doctorBloodGroup, doctors[doctorCount].doctorSpecialization, doctors[doctorCount].doctorJoiningDate, doctors[doctorCount].doctorLeavingDate, doctors[doctorCount].doctorAge, doctors[doctorCount].doctorWeight, doctors[doctorCount].doctorHeight, doctors[doctorCount].doctorEmergencyContactName, doctors[doctorCount].doctorEmergencyContactRelation, doctors[doctorCount].doctorEmergencyContactAddress, doctors[doctorCount].doctorEmergencyContactEmail);

    fclose(DoctorFilePointer);

    doctorCount++;
}

void addAppointment()
{
    printf("\n--------------------Book Appointment--------------------\n");
    printf("\n");
    printf("Enter appointment id: ");
    scanf("%d", &appointments[appointmentCount].appointmentId);
    printf("Enter patient id: ");
    scanf("%d", &appointments[appointmentCount].patientId);
    printf("Enter doctor id: ");
    scanf("%d", &appointments[appointmentCount].doctorId);
    printf("Enter appointment date: ");
    scanf("%s", appointments[appointmentCount].appointmentDate);
    printf("Enter appointment time: ");
    scanf("%s", appointments[appointmentCount].appointmentTime);
    printf("Enter appointment status: ");
    scanf("%s", appointments[appointmentCount].appointmentStatus);

    AppointmentFilePointer = fopen("./data/appointment.txt", "a");

    if (AppointmentFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    fprintf(AppointmentFilePointer, " %d %d %d %s %s %s", appointments[appointmentCount].appointmentId, appointments[appointmentCount].patientId, appointments[appointmentCount].doctorId, appointments[appointmentCount].appointmentDate, appointments[appointmentCount].appointmentTime, appointments[appointmentCount].appointmentStatus);

    fclose(AppointmentFilePointer);

    appointmentCount++;
}

void addRoom()
{
    printf("\n--------------------Add New Room Details--------------------\n");
    printf("\n");
    printf("Enter room id: ");
    scanf("%d", &rooms[roomCount].roomId);
    printf("Enter room no: ");
    scanf("%d", &rooms[roomCount].roomNo);
    printf("Enter room type: ");
    scanf("%s", rooms[roomCount].roomType);
    printf("Enter room status: ");
    scanf("%s", rooms[roomCount].roomStatus);

    RoomFilePointer = fopen("./data/room.txt", "a");

    if (RoomFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    fprintf(RoomFilePointer, " %d %d %s %s", rooms[roomCount].roomId, rooms[roomCount].roomNo, rooms[roomCount].roomType, rooms[roomCount].roomStatus);

    fclose(RoomFilePointer);

    roomCount++;
}

void addBill()
{
    printf("\n--------------------Create A New Bill--------------------\n");
    printf("\n");
    printf("Enter bill id: ");
    scanf("%d", &bills[billCount].billId);
    printf("Enter patient id: ");
    scanf("%d", &bills[billCount].patientId);
    printf("Enter doctor id: ");
    scanf("%d", &bills[billCount].doctorId);
    printf("Enter room id: ");
    scanf("%d", &bills[billCount].roomId);
    printf("Enter appointment id: ");
    scanf("%d", &bills[billCount].appointmentId);
    printf("Enter total amount: ");
    scanf("%d", &bills[billCount].totalAmount);
    printf("Enter bill date: ");
    scanf("%s", bills[billCount].billDate);
    printf("Enter bill status: ");
    scanf("%s", bills[billCount].billStatus);

    BillFilePointer = fopen("./data/bill.txt", "a");

    if (BillFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    fprintf(BillFilePointer, " %d %d %d %d %d %d %s %s", bills[billCount].billId, bills[billCount].patientId, bills[billCount].doctorId, bills[billCount].roomId, bills[billCount].appointmentId, bills[billCount].totalAmount, bills[billCount].billDate, bills[billCount].billStatus);

    fclose(BillFilePointer);

    billCount++;
}

void addInventory()
{
    printf("\n--------------------Add New Inventory Details--------------------\n");
    printf("\n");
    printf("Enter inventory id: ");
    scanf("%d", &inventories[inventoryCount].inventoryId);
    printf("Enter inventory name: ");
    scanf("%s", inventories[inventoryCount].inventoryName);
    printf("Enter inventory quantity: ");
    scanf("%d", &inventories[inventoryCount].inventoryQuantity);
    printf("Enter inventory price: ");
    scanf("%d", &inventories[inventoryCount].inventoryPrice);
    printf("Enter inventory status: ");
    scanf("%s", inventories[inventoryCount].inventoryStatus);

    InventoryFilePointer = fopen("./data/inventory.txt", "a");

    if (InventoryFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    fprintf(InventoryFilePointer, " %d %s %d %d %s", inventories[inventoryCount].inventoryId, inventories[inventoryCount].inventoryName, inventories[inventoryCount].inventoryQuantity, inventories[inventoryCount].inventoryPrice, inventories[inventoryCount].inventoryStatus);

    fclose(InventoryFilePointer);

    inventoryCount++;
}

void addStaff()
{
    printf("\n--------------------Add New Staff Details--------------------\n");
    printf("\n");
    printf("Enter staff id: ");
    scanf("%d", &staffs[staffCount].staffId);
    printf("Enter staff name: ");
    scanf("%s", staffs[staffCount].staffName);
    printf("Enter staff address: ");
    scanf("%s", staffs[staffCount].staffAddress);
    printf("Enter staff contact: ");
    scanf("%s", staffs[staffCount].staffContact);
    printf("Enter staff email: ");
    scanf("%s", staffs[staffCount].staffEmail);
    printf("Enter staff gender: ");
    scanf("%s", staffs[staffCount].staffGender);
    printf("Enter staff blood group: ");
    scanf("%s", staffs[staffCount].staffBloodGroup);
    printf("Enter staff designation: ");
    scanf("%s", staffs[staffCount].staffDesignation);
    printf("Enter staff joining date: ");
    scanf("%s", staffs[staffCount].staffJoiningDate);
    printf("Enter staff leaving date: ");
    scanf("%s", staffs[staffCount].staffLeavingDate);
    printf("Enter staff age: ");
    scanf("%d", &staffs[staffCount].staffAge);
    printf("Enter staff weight: ");
    scanf("%d", &staffs[staffCount].staffWeight);
    printf("Enter staff height: ");
    scanf("%d", &staffs[staffCount].staffHeight);
    printf("Enter staff emergency contact name: ");
    scanf("%s", staffs[staffCount].staffEmergencyContactName);
    printf("Enter staff emergency contact relation: ");
    scanf("%s", staffs[staffCount].staffEmergencyContactRelation);
    printf("Enter staff emergency contact address: ");
    scanf("%s", staffs[staffCount].staffEmergencyContactAddress);
    printf("Enter staff emergency contact email: ");
    scanf("%s", staffs[staffCount].staffEmergencyContactEmail);

    StaffFilePointer = fopen("./data/staff.txt", "a");

    if (StaffFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    fprintf(StaffFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", staffs[staffCount].staffId, staffs[staffCount].staffName, staffs[staffCount].staffAddress, staffs[staffCount].staffContact, staffs[staffCount].staffEmail, staffs[staffCount].staffGender, staffs[staffCount].staffBloodGroup, staffs[staffCount].staffDesignation, staffs[staffCount].staffJoiningDate, staffs[staffCount].staffLeavingDate, staffs[staffCount].staffAge, staffs[staffCount].staffWeight, staffs[staffCount].staffHeight, staffs[staffCount].staffEmergencyContactName, staffs[staffCount].staffEmergencyContactRelation, staffs[staffCount].staffEmergencyContactAddress, staffs[staffCount].staffEmergencyContactEmail);

    fclose(StaffFilePointer);

    staffCount++;
}

void addDepartment()
{
    printf("\n--------------------Add New Department Details--------------------\n");
    printf("\n");
    printf("Enter department id: ");
    scanf("%d", &departments[departmentCount].departmentId);
    printf("Enter department name: ");
    scanf("%s", departments[departmentCount].departmentName);
    printf("Enter department head: ");
    scanf("%s", departments[departmentCount].departmentHead);
    printf("Enter department contact: ");
    scanf("%s", departments[departmentCount].departmentContact);
    printf("Enter department email: ");
    scanf("%s", departments[departmentCount].departmentEmail);
    printf("Enter department status: ");
    scanf("%s", departments[departmentCount].departmentStatus);

    DepartmentFilePointer = fopen("./data/department.txt", "a");

    if (DepartmentFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    fprintf(DepartmentFilePointer, " %d %s %s %s %s %s", departments[departmentCount].departmentId, departments[departmentCount].departmentName, departments[departmentCount].departmentHead, departments[departmentCount].departmentContact, departments[departmentCount].departmentEmail, departments[departmentCount].departmentStatus);

    fclose(DepartmentFilePointer);

    departmentCount++;
}

void displayPatient()
{
    int count = 0;
    printf("\n--------------------All Patient Details--------------------\n");
    printf("\n");

    PatientFilePointer = fopen("./data/patient.txt", "r");

    if (PatientFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(PatientFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %d %s %s %s %s", &patients[count].patientId, patients[count].patientName, patients[count].patientAddress, patients[count].patientContact, patients[count].patientEmail, patients[count].patientGender, patients[count].patientBloodGroup, patients[count].patientDisease, patients[count].patientAdmitDate, patients[count].patientDischargeDate, &patients[count].patientRoomNo, &patients[count].patientAge, &patients[count].patientWeight, &patients[count].patientHeight, patients[count].patientEmergencyContactName, patients[count].patientEmergencyContactRelation, patients[count].patientEmergencyContactAddress, patients[count].patientEmergencyContactEmail) != EOF)
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Patient Id: %d\n", patients[i].patientId);
        printf("Patient Name: %s\n", patients[i].patientName);
        printf("Patient Address: %s\n", patients[i].patientAddress);
        printf("Patient Contact: %s\n", patients[i].patientContact);
        printf("Patient Email: %s\n", patients[i].patientEmail);
        printf("Patient Gender: %s\n", patients[i].patientGender);
        printf("Patient Blood Group: %d\n", patients[i].patientBloodGroup);
        printf("Patient Disease: %s\n", patients[i].patientDisease);
        printf("Patient Admit Date: %s\n", patients[i].patientAdmitDate);
        printf("Patient Discharge Date: %s\n", patients[i].patientDischargeDate);
        printf("Patient Room Type: %s\n", patients[i].patientRoomType);
        printf("Patient Room No: %d\n", patients[i].patientRoomNo);
        printf("Patient Age: %d\n", patients[i].patientAge);
        printf("Patient Weight: %d\n", patients[i].patientWeight);
        printf("Patient Height: %d\n", patients[i].patientHeight);
        printf("Patient Emergency Contact Name: %s\n", patients[i].patientEmergencyContactName);
        printf("Patient Emergency Contact Relation: %s\n", patients[i].patientEmergencyContactRelation);
        printf("Patient Emergency Contact Address: %s\n", patients[i].patientEmergencyContactAddress);
        printf("Patient Emergency Contact Email: %s\n", patients[i].patientEmergencyContactEmail);
        printf("\n");
    };

    fclose(PatientFilePointer);
};

void displayDoctor()
{
    int count = 0;
    printf("\n--------------------All Doctor Details--------------------\n");
    printf("\n");

    DoctorFilePointer = fopen("./data/doctor.txt", "r");

    if (DoctorFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(DoctorFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", &doctors[count].doctorId, doctors[count].doctorName, doctors[count].doctorAddress, doctors[count].doctorContact, doctors[count].doctorEmail, doctors[count].doctorGender, doctors[count].doctorBloodGroup, doctors[count].doctorSpecialization, doctors[count].doctorJoiningDate, doctors[count].doctorLeavingDate, &doctors[count].doctorAge, &doctors[count].doctorWeight, &doctors[count].doctorHeight, doctors[count].doctorEmergencyContactName, doctors[count].doctorEmergencyContactRelation, doctors[count].doctorEmergencyContactAddress, doctors[count].doctorEmergencyContactEmail) != EOF)
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Doctor Id: %d\n", doctors[i].doctorId);
        printf("Doctor Name: %s\n", doctors[i].doctorName);
        printf("Doctor Address: %s\n", doctors[i].doctorAddress);
        printf("Doctor Contact: %s\n", doctors[i].doctorContact);
        printf("Doctor Email: %s\n", doctors[i].doctorEmail);
        printf("Doctor Gender: %s\n", doctors[i].doctorGender);
        printf("Doctor Blood Group: %s", doctors[i].doctorBloodGroup);
        printf("Doctor Specialization: %s\n", doctors[i].doctorSpecialization);
        printf("Doctor Joining Date: %s\n", doctors[i].doctorJoiningDate);
        printf("Doctor Leaving Date: %s\n", doctors[i].doctorLeavingDate);
        printf("Doctor Age: %d\n", doctors[i].doctorAge);
        printf("Doctor Weight: %d\n", doctors[i].doctorWeight);
        printf("Doctor Height: %d\n", doctors[i].doctorHeight);
        printf("Doctor Emergency Contact Name: %s\n", doctors[i].doctorEmergencyContactName);
        printf("Doctor Emergency Contact Relation: %s\n", doctors[i].doctorEmergencyContactRelation);
        printf("Doctor Emergency Contact Address: %s\n", doctors[i].doctorEmergencyContactAddress);
        printf("Doctor Emergency Contact Email: %s\n", doctors[i].doctorEmergencyContactEmail);
        printf("\n");
    };

    fclose(DoctorFilePointer);
};

void displayAppointment()
{
    int count = 0;
    printf("\n--------------------All Appointment Details--------------------\n");
    printf("\n");

    AppointmentFilePointer = fopen("./data/appointment.txt", "r");

    if (AppointmentFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(AppointmentFilePointer, " %d %d %d %s %s %s", &appointments[count].appointmentId, &appointments[count].patientId, &appointments[count].doctorId, appointments[count].appointmentDate, appointments[count].appointmentTime, appointments[count].appointmentStatus) != EOF)
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Appointment Id: %d\n", appointments[i].appointmentId);
        printf("Patient Id: %d\n", appointments[i].patientId);
        printf("Doctor Id: %d\n", appointments[i].doctorId);
        printf("Appointment Date: %s\n", appointments[i].appointmentDate);
        printf("Appointment Time: %s\n", appointments[i].appointmentTime);
        printf("Appointment Status: %s\n", appointments[i].appointmentStatus);
        printf("\n");
    };

    fclose(AppointmentFilePointer);
};

void displayRoom()
{
    int count = 0;
    printf("\n--------------------All Room Details--------------------\n");
    printf("\n");
    RoomFilePointer = fopen("./data/room.txt", "r");

    if (RoomFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(RoomFilePointer, " %d %d %s %s", &rooms[count].roomId, &rooms[count].roomNo, rooms[count].roomType, rooms[count].roomStatus) != EOF)
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Room Id: %d\n", rooms[i].roomId);
        printf("Room No: %d\n", rooms[i].roomNo);
        printf("Room Type: %s\n", rooms[i].roomType);
        printf("Room Status: %s\n", rooms[i].roomStatus);
        printf("\n");
    };

    fclose(RoomFilePointer);
};

void displayBill()
{
    int count = 0;
    printf("\n--------------------All Bills Details--------------------\n");
    printf("\n");

    BillFilePointer = fopen("./data/bill.txt", "r");

    if (BillFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(BillFilePointer, " %d %d %d %d %d %d %s %s", &bills[count].billId, &bills[count].patientId, &bills[count].doctorId, &bills[count].roomId, &bills[count].appointmentId, &bills[count].totalAmount, bills[count].billDate, bills[count].billStatus) != EOF)
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Bill Id: %d\n", bills[i].billId);
        printf("Patient Id: %d\n", bills[i].patientId);
        printf("Doctor Id: %d\n", bills[i].doctorId);
        printf("Room Id: %d\n", bills[i].roomId);
        printf("Appointment Id: %d\n", bills[i].appointmentId);
        printf("Total Amount: %d\n", bills[i].totalAmount);
        printf("Bill Date: %s\n", bills[i].billDate);
        printf("Bill Status: %s\n", bills[i].billStatus);
        printf("\n");
    };

    fclose(BillFilePointer);
};

void displayInventory()
{
    int count = 0;
    printf("\n--------------------All Inventory Details--------------------\n");
    printf("\n");

    InventoryFilePointer = fopen("./data/inventory.txt", "r");

    if (InventoryFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(InventoryFilePointer, " %d %s %d %d %s", &inventories[count].inventoryId, inventories[count].inventoryName, &inventories[count].inventoryQuantity, &inventories[count].inventoryPrice, inventories[count].inventoryStatus) != EOF)
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Inventory Id: %d\n", inventories[i].inventoryId);
        printf("Inventory Name: %s\n", inventories[i].inventoryName);
        printf("Inventory Quantity: %d\n", inventories[i].inventoryQuantity);
        printf("Inventory Price: %d\n", inventories[i].inventoryPrice);
        printf("Inventory Status: %s\n", inventories[i].inventoryStatus);
        printf("\n");
    };

    fclose(InventoryFilePointer);
};

void displayStaff()
{
    int count = 0;
    printf("\n--------------------All Staff Details--------------------\n");
    printf("\n");

    StaffFilePointer = fopen("./data/staff.txt", "r");

    if (StaffFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(StaffFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", &staffs[count].staffId, staffs[count].staffName, staffs[count].staffAddress, staffs[count].staffContact, staffs[count].staffEmail, staffs[count].staffGender, staffs[count].staffBloodGroup, staffs[count].staffDesignation, staffs[count].staffJoiningDate, staffs[count].staffLeavingDate, &staffs[count].staffAge, &staffs[count].staffWeight, &staffs[count].staffHeight, staffs[count].staffEmergencyContactName, staffs[count].staffEmergencyContactRelation, staffs[count].staffEmergencyContactAddress, staffs[count].staffEmergencyContactEmail) != EOF)
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Staff Id: %d\n", staffs[i].staffId);
        printf("Staff Name: %s\n", staffs[i].staffName);
        printf("Staff Address: %s\n", staffs[i].staffAddress);
        printf("Staff Contact: %s\n", staffs[i].staffContact);
        printf("Staff Email: %s\n", staffs[i].staffEmail);
        printf("Staff Gender: %s\n", staffs[i].staffGender);
        printf("Staff Blood Group: %s\n", staffs[i].staffBloodGroup);
        printf("Staff Designation: %s\n", staffs[i].staffDesignation);
        printf("Staff Joining Date: %s\n", staffs[i].staffJoiningDate);
        printf("Staff Leaving Date: %s\n", staffs[i].staffLeavingDate);
        printf("Staff Age: %d\n", staffs[i].staffAge);
        printf("Staff Weight: %d\n", staffs[i].staffWeight);
        printf("Staff Height: %d\n", staffs[i].staffHeight);
        printf("Staff Emergency Contact Name: %s\n", staffs[i].staffEmergencyContactName);
        printf("Staff Emergency Contact Relation: %s\n", staffs[i].staffEmergencyContactRelation);
        printf("Staff Emergency Contact Address: %s\n", staffs[i].staffEmergencyContactAddress);
        printf("Staff Emergency Contact Email: %s\n", staffs[i].staffEmergencyContactEmail);
        printf("\n");
    };

    fclose(StaffFilePointer);
};

void displayDepartment()
{
    int count = 0;
    printf("\n--------------------All Department Details--------------------\n");
    printf("\n");

    DepartmentFilePointer = fopen("./data/department.txt", "r");

    if (DepartmentFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(DepartmentFilePointer, " %d %s %s %s %s %s", &departments[count].departmentId, departments[count].departmentName, departments[count].departmentHead, departments[count].departmentContact, departments[count].departmentEmail, departments[count].departmentStatus) != EOF)
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Department Id: %d\n", departments[i].departmentId);
        printf("Department Name: %s\n", departments[i].departmentName);
        printf("Department Head: %s\n", departments[i].departmentHead);
        printf("Department Contact: %s\n", departments[i].departmentContact);
        printf("Department Email: %s\n", departments[i].departmentEmail);
        printf("Department Status: %s\n", departments[i].departmentStatus);
        printf("\n");
    };

    fclose(DepartmentFilePointer);
};

void updatePatient()
{
    int count = 0;
    printf("\n--------------------Update Patient Details--------------------\n");
    printf("\n");

    PatientFilePointer = fopen("./data/patient.txt", "r");

    if (PatientFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(PatientFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %d %s %s %s %s", &patients[count].patientId, patients[count].patientName, patients[count].patientAddress, patients[count].patientContact, patients[count].patientEmail, patients[count].patientGender, patients[count].patientBloodGroup, patients[count].patientDisease, patients[count].patientAdmitDate, patients[count].patientDischargeDate, &patients[count].patientRoomNo, &patients[count].patientAge, &patients[count].patientWeight, &patients[count].patientHeight, patients[count].patientEmergencyContactName, patients[count].patientEmergencyContactRelation, patients[count].patientEmergencyContactAddress, patients[count].patientEmergencyContactEmail) != EOF)
    {
        count++;
    }

    int patientId;
    int choice;
    printf("Enter patient id: ");
    scanf("%d", &patientId);
    for (int i = 0; i < count; i++)
    {
        if (patients[i].patientId == patientId)
        {
            printf("1. Update patient name\n");
            printf("2. Update patient address\n");
            printf("3. Update patient contact\n");
            printf("4. Update patient email\n");
            printf("5. Update patient gender\n");
            printf("6. Update patient blood group\n");
            printf("7. Update patient disease\n");
            printf("8. Update patient admit date\n");
            printf("9. Update patient discharge date\n");
            printf("10. Update patient room type\n");
            printf("11. Update patient room no\n");
            printf("12. Update patient age\n");
            printf("13. Update patient weight\n");
            printf("14. Update patient height\n");
            printf("15. Update patient emergency contact name\n");
            printf("16. Update patient emergency contact relation\n");
            printf("17. Update patient emergency contact address\n");
            printf("18. Update patient emergency contact email\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter patient name: ");
                scanf("%s", patients[i].patientName);
                break;
            case 2:
                printf("Enter patient address: ");
                scanf("%s", patients[i].patientAddress);
                break;
            case 3:
                printf("Enter patient contact: ");
                scanf("%s", patients[i].patientContact);
                break;
            case 4:
                printf("Enter patient email: ");
                scanf("%s", patients[i].patientEmail);
                break;
            case 5:
                printf("Enter patient gender: ");
                scanf("%s", patients[i].patientGender);
                break;
            case 6:
                printf("Enter patient blood group: ");
                scanf("%s", patients[i].patientBloodGroup);
                break;
            case 7:
                printf("Enter patient disease: ");
                scanf("%s", patients[i].patientDisease);
                break;
            case 8:
                printf("Enter patient admit date: ");
                scanf("%s", patients[i].patientAdmitDate);
                break;
            case 9:
                printf("Enter patient discharge date: ");
                scanf("%s", patients[i].patientDischargeDate);
                break;
            case 10:
                printf("Enter patient room type: ");
                scanf("%s", patients[i].patientRoomType);
                break;
            case 11:
                printf("Enter patient room no: ");
                scanf("%d", &patients[i].patientRoomNo);
                break;
            case 12:
                printf("Enter patient age: ");
                scanf("%d", &patients[i].patientAge);
                break;
            case 13:
                printf("Enter patient weight: ");
                scanf("%d", &patients[i].patientWeight);
                break;
            case 14:
                printf("Enter patient height: ");
                scanf("%d", &patients[i].patientHeight);
                break;
            case 15:
                printf("Enter patient emergency contact name: ");
                scanf("%s", patients[i].patientEmergencyContactName);
                break;
            case 16:
                printf("Enter patient emergency contact relation: ");
                scanf("%s", patients[i].patientEmergencyContactRelation);
                break;
            case 17:
                printf("Enter patient emergency contact address: ");
                scanf("%s", patients[i].patientEmergencyContactAddress);
                break;
            case 18:
                printf("Enter patient emergency contact email: ");
                scanf("%s", patients[i].patientEmergencyContactEmail);
                break;
            default:
                printf("Please enter right choice\n");
                break;
            };

            TempFilePointer = fopen("./data/patient.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count; i++)
            {
                fprintf(TempFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %d %s %s %s %s", patients[i].patientId, patients[i].patientName, patients[i].patientAddress, patients[i].patientContact, patients[i].patientEmail, patients[i].patientGender, patients[i].patientBloodGroup, patients[i].patientDisease, patients[i].patientAdmitDate, patients[i].patientDischargeDate, patients[i].patientRoomNo, patients[i].patientAge, patients[i].patientWeight, patients[i].patientHeight, patients[i].patientEmergencyContactName, patients[i].patientEmergencyContactRelation, patients[i].patientEmergencyContactAddress, patients[i].patientEmergencyContactEmail);
            };

            fclose(TempFilePointer);

            fclose(PatientFilePointer);

            return;
        };
    };

    fclose(PatientFilePointer);

    printf("Patient Details not found\n");
};

void updateDoctor()
{
    int count = 0;
    printf("\n--------------------Update Doctor Details--------------------\n");
    printf("\n");

    DoctorFilePointer = fopen("./data/doctor.txt", "r");

    if (DoctorFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(DoctorFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", &doctors[count].doctorId, doctors[count].doctorName, doctors[count].doctorAddress, doctors[count].doctorContact, doctors[count].doctorEmail, doctors[count].doctorGender, doctors[count].doctorBloodGroup, doctors[count].doctorSpecialization, doctors[count].doctorJoiningDate, doctors[count].doctorLeavingDate, &doctors[count].doctorAge, &doctors[count].doctorWeight, &doctors[count].doctorHeight, doctors[count].doctorEmergencyContactName, doctors[count].doctorEmergencyContactRelation, doctors[count].doctorEmergencyContactAddress, doctors[count].doctorEmergencyContactEmail) != EOF)
    {
        count++;
    }

    int doctorId;
    int choice;
    printf("Enter doctor id: ");
    scanf("%d", &doctorId);
    for (int i = 0; i < count; i++)
    {
        if (doctors[i].doctorId == doctorId)
        {
            printf("1. Update doctor name\n");
            printf("2. Update doctor address\n");
            printf("3. Update doctor contact\n");
            printf("4. Update doctor email\n");
            printf("5. Update doctor gender\n");
            printf("6. Update doctor blood group\n");
            printf("7. Update doctor specialization\n");
            printf("8. Update doctor joining date\n");
            printf("9. Update doctor leaving date\n");
            printf("10. Update doctor age\n");
            printf("11. Update doctor weight\n");
            printf("12. Update doctor height\n");
            printf("13. Update doctor emergency contact name\n");
            printf("14. Update doctor emergency contact relation\n");
            printf("15. Update doctor emergency contact address\n");
            printf("16. Update doctor emergency contact email\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter doctor name: ");
                scanf("%s", doctors[i].doctorName);
                break;
            case 2:
                printf("Enter doctor address: ");
                scanf("%s", doctors[i].doctorAddress);
                break;
            case 3:
                printf("Enter doctor contact: ");
                scanf("%s", doctors[i].doctorContact);
                break;
            case 4:
                printf("Enter doctor email: ");
                scanf("%s", doctors[i].doctorEmail);
                break;
            case 5:
                printf("Enter doctor gender: ");
                scanf("%s", doctors[i].doctorGender);
                break;
            case 6:
                printf("Enter doctor blood group: ");
                scanf("%s", doctors[i].doctorBloodGroup);
                break;
            case 7:
                printf("Enter doctor specialization: ");
                scanf("%s", doctors[i].doctorSpecialization);
                break;
            case 8:
                printf("Enter doctor joining date: ");
                scanf("%s", doctors[i].doctorJoiningDate);
                break;
            case 9:
                printf("Enter doctor leaving date: ");
                scanf("%s", doctors[i].doctorLeavingDate);
                break;
            case 10:
                printf("Enter doctor age: ");
                scanf("%d", &doctors[i].doctorAge);
                break;
            case 11:
                printf("Enter doctor weight: ");
                scanf("%d", &doctors[i].doctorWeight);
                break;
            case 12:
                printf("Enter doctor height: ");
                scanf("%d", &doctors[i].doctorHeight);
                break;
            case 13:
                printf("Enter doctor emergency contact name: ");
                scanf("%s", doctors[i].doctorEmergencyContactName);
                break;
            case 14:
                printf("Enter doctor emergency contact relation: ");
                scanf("%s", doctors[i].doctorEmergencyContactRelation);
                break;
            case 15:
                printf("Enter doctor emergency contact address: ");
                scanf("%s", doctors[i].doctorEmergencyContactAddress);
                break;
            case 16:
                printf("Enter doctor emergency contact email: ");
                scanf("%s", doctors[i].doctorEmergencyContactEmail);
                break;
            default:
                printf("Please enter right choice\n");
                break;
            };

            TempFilePointer = fopen("./data/doctor.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count; i++)
            {
                fprintf(TempFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", doctors[i].doctorId, doctors[i].doctorName, doctors[i].doctorAddress, doctors[i].doctorContact, doctors[i].doctorEmail, doctors[i].doctorGender, doctors[i].doctorBloodGroup, doctors[i].doctorSpecialization, doctors[i].doctorJoiningDate, doctors[i].doctorLeavingDate, doctors[i].doctorAge, doctors[i].doctorWeight, doctors[i].doctorHeight, doctors[i].doctorEmergencyContactName, doctors[i].doctorEmergencyContactRelation, doctors[i].doctorEmergencyContactAddress, doctors[i].doctorEmergencyContactEmail);
            };

            fclose(TempFilePointer);
            fclose(DoctorFilePointer);

            return;
        };
    };

    fclose(DoctorFilePointer);
    printf("Doctor Details not found\n");
};

void updateAppointment()
{
    int count = 0;
    printf("\n--------------------Update Appointment Details--------------------\n");
    printf("\n");

    AppointmentFilePointer = fopen("./data/appointment.txt", "r");

    if (AppointmentFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(AppointmentFilePointer, " %d %d %d %s %s %s", &appointments[count].appointmentId, &appointments[count].patientId, &appointments[count].doctorId, appointments[count].appointmentDate, appointments[count].appointmentTime, appointments[count].appointmentStatus) != EOF)
    {
        count++;
    }

    int appointmentId;
    int choice;
    printf("Enter appointment id: ");
    scanf("%d", &appointmentId);
    for (int i = 0; i < count; i++)
    {
        if (appointments[i].appointmentId == appointmentId)
        {
            printf("1. Update appointment id\n");
            printf("2. Update patient id\n");
            printf("3. Update doctor id\n");
            printf("4. Update appointment date\n");
            printf("5. Update appointment time\n");
            printf("6. Update appointment status\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter appointment id: ");
                scanf("%d", &appointments[i].appointmentId);
                break;
            case 2:
                printf("Enter patient id: ");
                scanf("%d", &appointments[i].patientId);
                break;
            case 3:
                printf("Enter doctor id: ");
                scanf("%d", &appointments[i].doctorId);
                break;
            case 4:
                printf("Enter appointment date: ");
                scanf("%s", appointments[i].appointmentDate);
                break;
            case 5:
                printf("Enter appointment time: ");
                scanf("%s", appointments[i].appointmentTime);
                break;
            case 6:
                printf("Enter appointment status: ");
                scanf("%s", appointments[i].appointmentStatus);
                break;
            default:
                printf("Please enter right choice\n");
                break;
            };

            TempFilePointer = fopen("./data/appointment.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count; i++)
            {
                fprintf(TempFilePointer, " %d %d %d %s %s %s", appointments[i].appointmentId, appointments[i].patientId, appointments[i].doctorId, appointments[i].appointmentDate, appointments[i].appointmentTime, appointments[i].appointmentStatus);
            };

            fclose(TempFilePointer);
            fclose(AppointmentFilePointer);

            return;
        };
    };

    fclose(AppointmentFilePointer);
    printf("Appointment Details not found\n");
};

void updateRoom()
{
    int count = 0;
    printf("\n--------------------Update Room Details--------------------\n");
    printf("\n");

    RoomFilePointer = fopen("./data/room.txt", "r");

    if (RoomFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(RoomFilePointer, " %d %d %s %s", &rooms[count].roomId, &rooms[count].roomNo, rooms[count].roomType, rooms[count].roomStatus) != EOF)
    {
        count++;
    }

    int roomId;
    int choice;
    printf("Enter room id: ");
    scanf("%d", &roomId);
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].roomId == roomId)
        {
            printf("1. Update room id\n");
            printf("2. Update room no\n");
            printf("3. Update room type\n");
            printf("4. Update room status\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter room id: ");
                scanf("%d", &rooms[i].roomId);
                break;
            case 2:
                printf("Enter room no: ");
                scanf("%d", &rooms[i].roomNo);
                break;
            case 3:
                printf("Enter room type: ");
                scanf("%s", rooms[i].roomType);
                break;
            case 4:
                printf("Enter room status: ");
                scanf("%s", rooms[i].roomStatus);
                break;
            default:
                printf("Please enter right choice\n");
                break;
            };

            TempFilePointer = fopen("./data/room.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count; i++)
            {
                fprintf(TempFilePointer, " %d %d %s %s", rooms[i].roomId, rooms[i].roomNo, rooms[i].roomType, rooms[i].roomStatus);
            };

            fclose(TempFilePointer);

            fclose(RoomFilePointer);

            return;
        };
    };

    fclose(RoomFilePointer);

    printf("Room Details not found\n");
};

void updateBill()
{
    int count = 0;
    printf("\n--------------------Update Bill Details--------------------\n");
    printf("\n");

    BillFilePointer = fopen("./data/bill.txt", "r");

    if (BillFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(BillFilePointer, " %d %d %d %d %d %d %s %s", &bills[count].billId, &bills[count].patientId, &bills[count].doctorId, &bills[count].roomId, &bills[count].appointmentId, &bills[count].totalAmount, bills[count].billDate, bills[count].billStatus) != EOF)
    {
        count++;
    }

    int billId;
    int choice;
    printf("Enter bill id: ");
    scanf("%d", &billId);
    for (int i = 0; i < count; i++)
    {
        if (bills[i].billId == billId)
        {
            printf("1. Update bill id\n");
            printf("2. Update patient id\n");
            printf("3. Update doctor id\n");
            printf("4. Update room id\n");
            printf("5. Update appointment id\n");
            printf("6. Update total amount\n");
            printf("7. Update bill date\n");
            printf("8. Update bill status\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter bill id: ");
                scanf("%d", &bills[i].billId);
                break;
            case 2:
                printf("Enter patient id: ");
                scanf("%d", &bills[i].patientId);
                break;
            case 3:
                printf("Enter doctor id: ");
                scanf("%d", &bills[i].doctorId);
                break;
            case 4:
                printf("Enter room id: ");
                scanf("%d", &bills[i].roomId);
                break;
            case 5:
                printf("Enter appointment id: ");
                scanf("%d", &bills[i].appointmentId);
                break;
            case 6:
                printf("Enter total amount: ");
                scanf("%d", &bills[i].totalAmount);
                break;
            case 7:
                printf("Enter bill date: ");
                scanf("%s", bills[i].billDate);
                break;
            case 8:
                printf("Enter bill status: ");
                scanf("%s", bills[i].billStatus);
                break;
            default:
                printf("Please enter right choice\n");
                break;
            };

            TempFilePointer = fopen("./data/bill.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count; i++)
            {
                fprintf(TempFilePointer, " %d %d %d %d %d %d %s %s", bills[i].billId, bills[i].patientId, bills[i].doctorId, bills[i].roomId, bills[i].appointmentId, bills[i].totalAmount, bills[i].billDate, bills[i].billStatus);
            };

            fclose(TempFilePointer);
            fclose(BillFilePointer);

            return;
        };
    };

    fclose(BillFilePointer);

    printf("Bill Details not found\n");
};

void updateInventory()
{
    int count = 0;
    printf("\n--------------------Update Inventory Details--------------------\n");
    printf("\n");

    InventoryFilePointer = fopen("./data/inventory.txt", "r");

    if (InventoryFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(InventoryFilePointer, " %d %s %d %d %s", &inventories[count].inventoryId, inventories[count].inventoryName, &inventories[count].inventoryQuantity, &inventories[count].inventoryPrice, inventories[count].inventoryStatus) != EOF)
    {
        count++;
    }

    int inventoryId;
    int choice;
    printf("Enter inventory id: ");
    scanf("%d", &inventoryId);
    for (int i = 0; i < count; i++)
    {
        if (inventories[i].inventoryId == inventoryId)
        {
            printf("1. Update inventory id\n");
            printf("2. Update inventory name\n");
            printf("3. Update inventory quantity\n");
            printf("4. Update inventory price\n");
            printf("5. Update inventory status\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter inventory id: ");
                scanf("%d", &inventories[i].inventoryId);
                break;
            case 2:
                printf("Enter inventory name: ");
                scanf("%s", inventories[i].inventoryName);
                break;
            case 3:
                printf("Enter inventory quantity: ");
                scanf("%d", &inventories[i].inventoryQuantity);
                break;
            case 4:
                printf("Enter inventory price: ");
                scanf("%d", &inventories[i].inventoryPrice);
                break;
            case 5:
                printf("Enter inventory status: ");
                scanf("%s", inventories[i].inventoryStatus);
                break;
            default:
                printf("Please enter right choice\n");
                break;
            };

            TempFilePointer = fopen("./data/inventory.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count; i++)
            {
                fprintf(TempFilePointer, " %d %s %d %d %s", inventories[i].inventoryId, inventories[i].inventoryName, inventories[i].inventoryQuantity, inventories[i].inventoryPrice, inventories[i].inventoryStatus);
            };

            fclose(TempFilePointer);
            fclose(InventoryFilePointer);
            return;
        };
    };

    fclose(InventoryFilePointer);

    printf("Inventory Details not found\n");
};

void updateStaff()
{
    int count = 0;
    printf("\n--------------------Update Staff Details--------------------\n");
    printf("\n");

    StaffFilePointer = fopen("./data/staff.txt", "r");

    if (StaffFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(StaffFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", &staffs[count].staffId, staffs[count].staffName, staffs[count].staffAddress, staffs[count].staffContact, staffs[count].staffEmail, staffs[count].staffGender, staffs[count].staffBloodGroup, staffs[count].staffDesignation, staffs[count].staffJoiningDate, staffs[count].staffLeavingDate, &staffs[count].staffAge, &staffs[count].staffWeight, &staffs[count].staffHeight, staffs[count].staffEmergencyContactName, staffs[count].staffEmergencyContactRelation, staffs[count].staffEmergencyContactAddress, staffs[count].staffEmergencyContactEmail) != EOF)
    {
        count++;
    }

    int staffId;
    int choice;
    printf("Enter staff id: ");
    scanf("%d", &staffId);
    for (int i = 0; i < count; i++)
    {
        if (staffs[i].staffId == staffId)
        {
            printf("1. Update staff id\n");
            printf("2. Update staff name\n");
            printf("3. Update staff address\n");
            printf("4. Update staff contact\n");
            printf("5. Update staff email\n");
            printf("6. Update staff gender\n");
            printf("7. Update staff blood group\n");
            printf("8. Update staff designation\n");
            printf("9. Update staff joining date\n");
            printf("10. Update staff leaving date\n");
            printf("11. Update staff age\n");
            printf("12. Update staff weight\n");
            printf("13. Update staff height\n");
            printf("14. Update staff emergency contact name\n");
            printf("15. Update staff emergency contact relation\n");
            printf("16. Update staff emergency contact address\n");
            printf("17. Update staff emergency contact email\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter staff id: ");
                scanf("%d", &staffs[i].staffId);
                break;
            case 2:
                printf("Enter staff name: ");
                scanf("%s", staffs[i].staffName);
                break;
            case 3:
                printf("Enter staff address: ");
                scanf("%s", staffs[i].staffAddress);
                break;
            case 4:
                printf("Enter staff contact: ");
                scanf("%s", staffs[i].staffContact);
                break;
            case 5:
                printf("Enter staff email: ");
                scanf("%s", staffs[i].staffEmail);
                break;
            case 6:
                printf("Enter staff gender: ");
                scanf("%s", staffs[i].staffGender);
                break;
            case 7:
                printf("Enter staff blood group: ");
                scanf("%s", staffs[i].staffBloodGroup);
                break;
            case 8:
                printf("Enter staff designation: ");
                scanf("%s", staffs[i].staffDesignation);
                break;
            case 9:
                printf("Enter staff joining date: ");
                scanf("%s", staffs[i].staffJoiningDate);
                break;
            case 10:
                printf("Enter staff leaving date: ");
                scanf("%s", staffs[i].staffLeavingDate);
                break;
            case 11:
                printf("Enter staff age: ");
                scanf("%d", &staffs[i].staffAge);
                break;
            case 12:
                printf("Enter staff weight: ");
                scanf("%d", &staffs[i].staffWeight);
                break;
            case 13:
                printf("Enter staff height: ");
                scanf("%d", &staffs[i].staffHeight);
                break;
            case 14:
                printf("Enter staff emergency contact name: ");
                scanf("%s", staffs[i].staffEmergencyContactName);
                break;
            case 15:
                printf("Enter staff emergency contact relation: ");
                scanf("%s", staffs[i].staffEmergencyContactRelation);
                break;
            case 16:
                printf("Enter staff emergency contact address: ");
                scanf("%s", staffs[i].staffEmergencyContactAddress);
                break;
            case 17:
                printf("Enter staff emergency contact email: ");
                scanf("%s", staffs[i].staffEmergencyContactEmail);
                break;
            default:
                printf("Please enter right choice\n");
                break;
            };

            TempFilePointer = fopen("./data/staff.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count; i++)
            {
                fprintf(TempFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", staffs[i].staffId, staffs[i].staffName, staffs[i].staffAddress, staffs[i].staffContact, staffs[i].staffEmail, staffs[i].staffGender, staffs[i].staffBloodGroup, staffs[i].staffDesignation, staffs[i].staffJoiningDate, staffs[i].staffLeavingDate, staffs[i].staffAge, staffs[i].staffWeight, staffs[i].staffHeight, staffs[i].staffEmergencyContactName, staffs[i].staffEmergencyContactRelation, staffs[i].staffEmergencyContactAddress, staffs[i].staffEmergencyContactEmail);
            };

            fclose(TempFilePointer);
            fclose(StaffFilePointer);

            return;
        };
    };

    fclose(StaffFilePointer);

    printf("Staff Details not found\n");
};

void updateDepartment()
{
    int count = 0;
    printf("\n--------------------Update Department Details--------------------\n");
    printf("\n");

    DepartmentFilePointer = fopen("./data/department.txt", "r");

    if (DepartmentFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(DepartmentFilePointer, " %d %s %s %s %s %s", &departments[count].departmentId, departments[count].departmentName, departments[count].departmentHead, departments[count].departmentContact, departments[count].departmentEmail, departments[count].departmentStatus) != EOF)
    {
        count++;
    }

    int departmentId;
    int choice;
    printf("Enter department id: ");
    scanf("%d", &departmentId);
    for (int i = 0; i < count; i++)
    {
        if (departments[i].departmentId == departmentId)
        {
            printf("1. Update department id\n");
            printf("2. Update department name\n");
            printf("3. Update department head\n");
            printf("4. Update department contact\n");
            printf("5. Update department email\n");
            printf("6. Update department status\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter department id: ");
                scanf("%d", &departments[i].departmentId);
                break;
            case 2:
                printf("Enter department name: ");
                scanf("%s", departments[i].departmentName);
                break;
            case 3:
                printf("Enter department head: ");
                scanf("%s", departments[i].departmentHead);
                break;
            case 4:
                printf("Enter department contact: ");
                scanf("%s", departments[i].departmentContact);
                break;
            case 5:
                printf("Enter department email: ");
                scanf("%s", departments[i].departmentEmail);
                break;
            case 6:
                printf("Enter department status: ");
                scanf("%s", departments[i].departmentStatus);
                break;
            default:
                printf("Please enter right choice\n");
                break;
            };

            TempFilePointer = fopen("./data/department.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count; i++)
            {
                fprintf(TempFilePointer, " %d %s %s %s %s %s", departments[i].departmentId, departments[i].departmentName, departments[i].departmentHead, departments[i].departmentContact, departments[i].departmentEmail, departments[i].departmentStatus);
            };

            fclose(TempFilePointer);
            fclose(DepartmentFilePointer);

            return;
        };
    };

    fclose(DepartmentFilePointer);

    printf("Department Details not found\n");
};

void removePatient()
{
    int count = 0;
    printf("\n--------------------Remove Patient Details--------------------\n");
    printf("\n");

    PatientFilePointer = fopen("./data/patient.txt", "r");

    if (PatientFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(PatientFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %d %s %s %s %s", &patients[count].patientId, patients[count].patientName, patients[count].patientAddress, patients[count].patientContact, patients[count].patientEmail, patients[count].patientGender, patients[count].patientBloodGroup, patients[count].patientDisease, patients[count].patientAdmitDate, patients[count].patientDischargeDate, &patients[count].patientRoomNo, &patients[count].patientAge, &patients[count].patientWeight, &patients[count].patientHeight, patients[count].patientEmergencyContactName, patients[count].patientEmergencyContactRelation, patients[count].patientEmergencyContactAddress, patients[count].patientEmergencyContactEmail) != EOF)
    {
        count++;
    }

    if (count == 0)
    {
        printf("No patient details found\n");
        return;
    }

    if (count == 1)
    {
        TempFilePointer = fopen("./data/patient.txt", "w");
        return;
    }

    int patientId;
    printf("Enter patient id: ");
    scanf("%d", &patientId);
    for (int i = 0; i < count; i++)
    {
        if (patients[i].patientId == patientId)
        {
            for (int j = i; j < patientCount - 1; j++)
            {
                patients[j] = patients[j + 1];
            };

            TempFilePointer = fopen("./data/patient.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count - 1; i++)
            {
                fprintf(TempFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %d %s %s %s %s", patients[i].patientId, patients[i].patientName, patients[i].patientAddress, patients[i].patientContact, patients[i].patientEmail, patients[i].patientGender, patients[i].patientBloodGroup, patients[i].patientDisease, patients[i].patientAdmitDate, patients[i].patientDischargeDate, patients[i].patientRoomNo, patients[i].patientAge, patients[i].patientWeight, patients[i].patientHeight, patients[i].patientEmergencyContactName, patients[i].patientEmergencyContactRelation, patients[i].patientEmergencyContactAddress, patients[i].patientEmergencyContactEmail);
            };

            fclose(TempFilePointer);
            fclose(PatientFilePointer);

            return;
        };
    };

    fclose(PatientFilePointer);

    printf("Patient Details not found\n");
};

void removeDoctor()
{
    int count = 0;
    printf("\n--------------------Remove Doctor Details--------------------\n");
    printf("\n");

    DoctorFilePointer = fopen("./data/doctor.txt", "r");

    if (DoctorFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(DoctorFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", &doctors[count].doctorId, doctors[count].doctorName, doctors[count].doctorAddress, doctors[count].doctorContact, doctors[count].doctorEmail, doctors[count].doctorGender, doctors[count].doctorBloodGroup, doctors[count].doctorSpecialization, doctors[count].doctorJoiningDate, doctors[count].doctorLeavingDate, &doctors[count].doctorAge, &doctors[count].doctorWeight, &doctors[count].doctorHeight, doctors[count].doctorEmergencyContactName, doctors[count].doctorEmergencyContactRelation, doctors[count].doctorEmergencyContactAddress, doctors[count].doctorEmergencyContactEmail) != EOF)
    {
        count++;
    }

    if (count == 0)
    {
        printf("No doctor details found\n");
        return;
    }

    if (count == 1)
    {
        TempFilePointer = fopen("./data/doctor.txt", "w");
        return;
    }

    int doctorId;
    printf("Enter doctor id: ");
    scanf("%d", &doctorId);
    for (int i = 0; i < count; i++)
    {
        if (doctors[i].doctorId == doctorId)
        {
            for (int j = i; j < doctorCount - 1; j++)
            {
                doctors[j] = doctors[j + 1];
            };

            TempFilePointer = fopen("./data/doctor.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count - 1; i++)
            {
                fprintf(TempFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", doctors[i].doctorId, doctors[i].doctorName, doctors[i].doctorAddress, doctors[i].doctorContact, doctors[i].doctorEmail, doctors[i].doctorGender, doctors[i].doctorBloodGroup, doctors[i].doctorSpecialization, doctors[i].doctorJoiningDate, doctors[i].doctorLeavingDate, doctors[i].doctorAge, doctors[i].doctorWeight, doctors[i].doctorHeight, doctors[i].doctorEmergencyContactName, doctors[i].doctorEmergencyContactRelation, doctors[i].doctorEmergencyContactAddress, doctors[i].doctorEmergencyContactEmail);
            };

            fclose(TempFilePointer);
            fclose(DoctorFilePointer);

            return;
        };
    };

    fclose(DoctorFilePointer);

    printf("Doctor Details not found\n");
};

void removeAppointment()
{
    int count = 0;
    printf("\n--------------------Remove Appointment Details--------------------\n");
    printf("\n");

    AppointmentFilePointer = fopen("./data/appointment.txt", "r");

    if (AppointmentFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(AppointmentFilePointer, " %d %d %d %s %s %s", &appointments[count].appointmentId, &appointments[count].patientId, &appointments[count].doctorId, appointments[count].appointmentDate, appointments[count].appointmentTime, appointments[count].appointmentStatus) != EOF)
    {
        count++;
    }

    if (count == 0)
    {
        printf("No appointment details found\n");
        return;
    }

    if (count == 1)
    {
        TempFilePointer = fopen("./data/appointment.txt", "w");
        return;
    }

    int appointmentId;
    printf("Enter appointment id: ");
    scanf("%d", &appointmentId);
    for (int i = 0; i < count; i++)
    {
        if (appointments[i].appointmentId == appointmentId)
        {
            for (int j = i; j < appointmentCount - 1; j++)
            {
                appointments[j] = appointments[j + 1];
            };

            TempFilePointer = fopen("./data/appointment.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count - 1; i++)
            {
                fprintf(TempFilePointer, " %d %d %d %s %s %s", appointments[i].appointmentId, appointments[i].patientId, appointments[i].doctorId, appointments[i].appointmentDate, appointments[i].appointmentTime, appointments[i].appointmentStatus);
            };

            fclose(TempFilePointer);
            fclose(AppointmentFilePointer);

            return;
        };
    };

    fclose(AppointmentFilePointer);

    printf("Appointment Details not found\n");
};

void removeRoom()
{
    int count = 0;
    printf("\n--------------------Remove Room Details--------------------\n");
    printf("\n");

    RoomFilePointer = fopen("./data/room.txt", "r");

    if (RoomFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(RoomFilePointer, " %d %d %s %s", &rooms[count].roomId, &rooms[count].roomNo, rooms[count].roomType, rooms[count].roomStatus) != EOF)
    {
        count++;
    }

    if (count == 0)
    {
        printf("No room details found\n");
        return;
    }

    if (count == 1)
    {
        TempFilePointer = fopen("./data/room.txt", "w");
        return;
    }

    int roomId;
    printf("Enter room id: ");
    scanf("%d", &roomId);
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].roomId == roomId)
        {
            for (int j = i; j < roomCount - 1; j++)
            {
                rooms[j] = rooms[j + 1];
            };

            TempFilePointer = fopen("./data/room.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count - 1; i++)
            {
                fprintf(TempFilePointer, " %d %d %s %s", rooms[i].roomId, rooms[i].roomNo, rooms[i].roomType, rooms[i].roomStatus);
            };

            fclose(TempFilePointer);
            fclose(RoomFilePointer);

            return;
        };
    };

    fclose(RoomFilePointer);

    printf("Room Details not found\n");
};

void removeBill()
{
    int count = 0;
    printf("\n--------------------Remove Bill Details--------------------\n");
    printf("\n");

    BillFilePointer = fopen("./data/bill.txt", "r");

    if (BillFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(BillFilePointer, " %d %d %d %d %d %d %s %s", &bills[count].billId, &bills[count].patientId, &bills[count].doctorId, &bills[count].roomId, &bills[count].appointmentId, &bills[count].totalAmount, bills[count].billDate, bills[count].billStatus) != EOF)
    {
        count++;
    }

    if (count == 0)
    {
        printf("No bill details found\n");
        return;
    }

    if (count == 1)
    {
        TempFilePointer = fopen("./data/bill.txt", "w");
        return;
    }

    int billId;
    printf("Enter bill id: ");
    scanf("%d", &billId);
    for (int i = 0; i < count; i++)
    {
        if (bills[i].billId == billId)
        {
            for (int j = i; j < billCount - 1; j++)
            {
                bills[j] = bills[j + 1];
            };

            TempFilePointer = fopen("./data/bill.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count - 1; i++)
            {
                fprintf(TempFilePointer, " %d %d %d %d %d %d %s %s", bills[i].billId, bills[i].patientId, bills[i].doctorId, bills[i].roomId, bills[i].appointmentId, bills[i].totalAmount, bills[i].billDate, bills[i].billStatus);
            };

            fclose(TempFilePointer);
            fclose(BillFilePointer);

            return;
        };
    };

    fclose(BillFilePointer);

    printf("Bill Details not found\n");
};

void removeInventory()
{
    int count = 0;
    printf("\n--------------------Remove Inventory Details--------------------\n");
    printf("\n");

    InventoryFilePointer = fopen("./data/inventory.txt", "r");

    if (InventoryFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(InventoryFilePointer, " %d %s %d %d %s", &inventories[count].inventoryId, inventories[count].inventoryName, &inventories[count].inventoryQuantity, &inventories[count].inventoryPrice, inventories[count].inventoryStatus) != EOF)
    {
        count++;
    }

    if (count == 0)
    {
        printf("No inventory details found\n");
        return;
    }

    if (count == 1)
    {
        TempFilePointer = fopen("./data/inventory.txt", "w");
        return;
    }

    int inventoryId;
    printf("Enter inventory id: ");
    scanf("%d", &inventoryId);
    for (int i = 0; i < count; i++)
    {
        if (inventories[i].inventoryId == inventoryId)
        {
            for (int j = i; j < inventoryCount - 1; j++)
            {
                inventories[j] = inventories[j + 1];
            };

            TempFilePointer = fopen("./data/inventory.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count - 1; i++)
            {
                fprintf(TempFilePointer, " %d %s %d %d %s", inventories[i].inventoryId, inventories[i].inventoryName, inventories[i].inventoryQuantity, inventories[i].inventoryPrice, inventories[i].inventoryStatus);
            };

            fclose(TempFilePointer);
            fclose(InventoryFilePointer);

            return;
        };
    };

    fclose(InventoryFilePointer);

    printf("Inventory Details not found\n");
};

void removeStaff()
{
    int count = 0;
    printf("\n--------------------Remove Staff Details--------------------\n");
    printf("\n");

    StaffFilePointer = fopen("./data/staff.txt", "r");

    if (StaffFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(StaffFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", &staffs[count].staffId, staffs[count].staffName, staffs[count].staffAddress, staffs[count].staffContact, staffs[count].staffEmail, staffs[count].staffGender, staffs[count].staffBloodGroup, staffs[count].staffDesignation, staffs[count].staffJoiningDate, staffs[count].staffLeavingDate, &staffs[count].staffAge, &staffs[count].staffWeight, &staffs[count].staffHeight, staffs[count].staffEmergencyContactName, staffs[count].staffEmergencyContactRelation, staffs[count].staffEmergencyContactAddress, staffs[count].staffEmergencyContactEmail) != EOF)
    {
        count++;
    }

    if (count == 0)
    {
        printf("No staff details found\n");
        return;
    }

    if (count == 1)
    {
        TempFilePointer = fopen("./data/staff.txt", "w");
        return;
    }

    int staffId;
    printf("Enter staff id: ");
    scanf("%d", &staffId);
    for (int i = 0; i < count; i++)
    {
        if (staffs[i].staffId == staffId)
        {
            for (int j = i; j < staffCount - 1; j++)
            {
                staffs[j] = staffs[j + 1];
            };

            TempFilePointer = fopen("./data/staff.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count - 1; i++)
            {
                fprintf(TempFilePointer, " %d %s %s %s %s %s %s %s %s %s %d %d %d %s %s %s %s", staffs[i].staffId, staffs[i].staffName, staffs[i].staffAddress, staffs[i].staffContact, staffs[i].staffEmail, staffs[i].staffGender, staffs[i].staffBloodGroup, staffs[i].staffDesignation, staffs[i].staffJoiningDate, staffs[i].staffLeavingDate, staffs[i].staffAge, staffs[i].staffWeight, staffs[i].staffHeight, staffs[i].staffEmergencyContactName, staffs[i].staffEmergencyContactRelation, staffs[i].staffEmergencyContactAddress, staffs[i].staffEmergencyContactEmail);
            };

            fclose(TempFilePointer);
            fclose(StaffFilePointer);
            return;
        };
    };

    fclose(StaffFilePointer);

    printf("Staff Details not found\n");
};

void removeDepartment()
{
    int count = 0;
    printf("\n--------------------Remove Department Details--------------------\n");
    printf("\n");

    DepartmentFilePointer = fopen("./data/department.txt", "r");

    if (DepartmentFilePointer == NULL)
    {
        printf("Error!");
        return;
    }

    while (fscanf(DepartmentFilePointer, " %d %s %s %s %s %s", &departments[count].departmentId, departments[count].departmentName, departments[count].departmentHead, departments[count].departmentContact, departments[count].departmentEmail, departments[count].departmentStatus) != EOF)
    {
        count++;
    }

    if (count == 0)
    {
        printf("No department details found\n");
        return;
    }

    if (count == 1)
    {
        TempFilePointer = fopen("./data/department.txt", "w");
        return;
    }

    int departmentId;
    printf("Enter department id: ");
    scanf("%d", &departmentId);
    for (int i = 0; i < count; i++)
    {
        if (departments[i].departmentId == departmentId)
        {
            for (int j = i; j < departmentCount - 1; j++)
            {
                departments[j] = departments[j + 1];
            };

            TempFilePointer = fopen("./data/department.txt", "w");

            if (TempFilePointer == NULL)
            {
                printf("Error!");
                return;
            }

            for (int i = 0; i < count - 1; i++)
            {
                fprintf(TempFilePointer, " %d %s %s %s %s %s", departments[i].departmentId, departments[i].departmentName, departments[i].departmentHead, departments[i].departmentContact, departments[i].departmentEmail, departments[i].departmentStatus);
            };

            fclose(TempFilePointer);
            fclose(DepartmentFilePointer);

            return;
        };
    };

    fclose(DepartmentFilePointer);

    printf("Department Details not found\n");
};
