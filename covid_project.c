#define COVAXIN 150
#define COVISHIELD 160
#define SPUTNIK 170
#define ZYDUS 180
#define PFIZER 190
#define MODERNA 200
////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <sys/stat.h>
#include <windows.h>
	////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	int day;
	int month;
	int year;
}

DAT;
struct citizen
{
	int id;
	char fullName[20];
	char Gender;
	int BirthYear;
	int No_dose;
	int V_type;
	int C_id;
	int appot;	//include date lib and compare dates;
	int dose1;
	int dose2;
	DAT appotDate;
};

typedef struct
{
	int price;
	int quant;
}

V_name;

typedef struct
{
	V_name covaxin;	// (covaxin/covishield/sputnik/zydus/Pfizer/moderna)
	V_name covishield;
	V_name sputnik;
	V_name zydus;
	V_name Pfizer;
	V_name moderna;
}

V_type;

struct center
{
	int id;
	char Address[50];
	char District[20];
	int Pin;
	int C_type;	//0=Govt. 1=Private
	V_type vaccine;	// (covaxin/covishield/sputnik/zydus/Pfizer/moderna)
	int V_quantity;
	int income;
	int No_appoint;
};
/////////////////////////////////////////////////////////////////////////////////////////////
int noBeneficiary();
int noCenter();
int isEmpty();
int generateID();
void addNewBeneficiary();
void display_All_Beneficiary();
void addNewCenter();
void EnlistSortedCenters();
void getCenter();
void BookAppointment();
void CancelAppointment();
void removeBeneficiary();
void removeCenter();
void UpdateBeneficiaryInfo();
void UpdateCenterInfo();
void MaxIncomeCenter();
void VaccineAvailabilityReport();
void DistrictReport();
void SeniorCitizenIntersection();
////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int choice;
	printf("\t\t\t\t\tBT20CSE017");
	printf("\n\t\t\t\t\t------------------");
	printf("\n\n\t\t\t\t\t\t[Choice]");
	printf("\n\n\t\t\t\t\t[-1] DisplayBeneficiary");
	printf("\n\t\t\t\t\t[0] Exit");
	printf("\n\t\t\t\t\t[1] AddNewBeneficiary");
	printf("\n\t\t\t\t\t[2] AddNewCenter");
	printf("\n\t\t\t\t\t[3] EnlistSortedCenters");
	printf("\n\t\t\t\t\t[4] getCenter");
	printf("\n\t\t\t\t\t[5] BookAppointment");
	printf("\n\t\t\t\t\t[6] CancelAppointment");
	printf("\n\t\t\t\t\t[7] removeBeneficiary");
	printf("\n\t\t\t\t\t[8] removeCenter");
	printf("\n\t\t\t\t\t[9] UpdateBeneficiaryInfo");
	printf("\n\t\t\t\t\t[10] UpdateCenterInfo");
	printf("\n\t\t\t\t\t[11] MaxIncomeCenter");
	printf("\n\t\t\t\t\t[12] VaccineAvialabilityReport");
	printf("\n\t\t\t\t\t[13] DistrictReport");
	printf("\n\t\t\t\t\t[14] SeniorCitizenIntersection");

	printf("\n\n====================================================================================================================================");
	printf("\nMaximize the window for better resolution");
	printf("\n\n\n\t\t\t\tEnter Choice Number : ");
	scanf("%d", &choice);
	
	if (choice == 0)
	{
		return 0;
	}
	else if (choice == -1)
	{
		if (noBeneficiary() == 0)
		{
			display_All_Beneficiary();
		}
		else
		{
			printf("No Record Found !");
		}
	}
	else if (choice == 1)
	{
		addNewBeneficiary();
	}
	else if (choice == 2)
	{
		addNewCenter();
	}
	else if (choice == 3)
	{
		if (noCenter() == 0)
		{
			EnlistSortedCenters();
		}
		else
		{
			printf("No Record Found !");
		}
	}
	else if (choice == 4)
	{
		if (noCenter() == 0)
		{
			getCenter();
		}
		else
		{
			printf("No Record Found !");
		}
	}
	else if (choice == 5)
	{
		BookAppointment();
	}
	else if (choice == 6)
	{
		CancelAppointment();
	}
	else if (choice == 7)
	{
		removeBeneficiary();
	}
	else if (choice == 8)
	{
		removeCenter();
	}
	else if (choice == 9)
	{
		UpdateBeneficiaryInfo();
	}
	else if (choice == 10)
	{
		UpdateCenterInfo();
	}
	else if (choice == 11)
	{
		MaxIncomeCenter();
	}
	else if (choice == 12)
	{
		VaccineAvailabilityReport();
	}
	else if (choice == 13)
	{
		DistrictReport();
	}
	else if (choice == 14)
	{
		SeniorCitizenIntersection();
	}
	else
	{
		printf("\n\t\tINVALID CHOICE");
	}

	printf("\n\n\t\tPress ESC to terminate Program !");
	printf("\n\n\t\tPress ANY key to return to Main Menu ! \n");
	if (getche() == '\e')
	{
		return 0;
	}
	else
	{
		system("cls");
		main();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
int noBeneficiary()
{
	int retval = 1;
	FILE * fp;
	fp = fopen("citizen.bin", "ab");
	fclose(fp);
	struct stat filestat2;
	stat("citizen.bin", &filestat2);

	if (filestat2.st_size != 0)
	{
		retval = 0;
	}

	return retval;
}

int noCenter()
{
	int retval = 1;
	FILE * fp;
	fp = fopen("center.bin", "ab");
	fclose(fp);
	struct stat filestat3;
	stat("center.bin", &filestat3);

	if (filestat3.st_size != 0)
	{
		retval = 0;
	}

	return retval;
}

int isEmpty()
{
	int retval;
	FILE * fpr;
	struct stat filestat;
	stat("citizen.bin", &filestat);

	if (filestat.st_size != 0)
	{
		retval = 0;
	}
	else
	{
		retval = 1;
	}

	return retval;
}

int generateID()
{
	FILE * fp;
	struct citizen t;
	int new_id;

	fp = fopen("citizen.bin", "rb");

	if (isEmpty())
	{
		new_id = 10000;
	}
	else
	{
		while (1)
		{
			fread(&t, sizeof(t), 1, fp);
			if (feof(fp))
			{
				break;
			}

			new_id = t.id + 1;
		}
	}

	return new_id;
}

void addNewBeneficiary()
{
	FILE * fp;
	struct citizen t1;

	fp = fopen("citizen.bin", "ab");

	t1.id = generateID();
	printf("\nBeneficiary ID : %d", t1.id);
	printf("\nEnter Beneficiary name : ");
	fflush(stdin);
	gets(t1.fullName);
	printf("Enter Gender (M / F / N) : ");
	scanf("%c", &t1.Gender);
	printf("Enter Birth Year : ");
	scanf("%d", &t1.BirthYear);
	t1.No_dose = 0;
	t1.dose1 = 0;
	t1.dose2 = 0;
	t1.appot = 0;
	t1.appotDate.day = 0;
	t1.appotDate.month = 0;
	t1.appotDate.year = 0;
	fwrite(&t1, sizeof(t1), 1, fp);
	printf("\n\t\tBeneficiary Added Successfully !");

	fclose(fp);
}

void display_All_Beneficiary()
{
	//Modify : check if the file is empty.
	FILE * fp;
	struct citizen t;

	fp = fopen("citizen.bin", "rb");

	printf("\n=======================================================================================================================================================");
	printf("\n\t\t\t\t\t\t\t\tBeneficiary Detail");
	printf("\n=======================================================================================================================================================");

	printf("\n  B_ID\t                Name\tGender\tBirth\tDoses\tAppot_Date");

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);

		if (feof(fp))
		{
			break;
		}

		printf("\n%6d\t", t.id);
		printf("%20s\t", t.fullName);
		printf("%c\t", t.Gender);
		printf("%d\t", t.BirthYear);
		printf("%d\t", t.No_dose);
		printf("%d-%d-%d", t.appotDate.day, t.appotDate.month, t.appotDate.year);
	}
}

void addNewCenter()
{
	FILE * fp;
	struct center t;

	fp = fopen("center.bin", "ab");

	printf("\nEnter Center ID : ");
	scanf("%d", &t.id);
	printf("Enter Address : ");
	fflush(stdin);
	gets(t.Address);
	printf("Enter District : ");
	scanf("%s", &t.District);
	printf("Enter PIN code : ");
	scanf("%d", &t.Pin);
	printf("Enter Center Type (0 for Govt, 1 for Private) : ");
	scanf("%d", &t.C_type);
	printf("Quantity of COVAXIN : ");	//(covaxin/covishield/sputnik/zydus/Pfizer/moderna)
	scanf("%d", &t.vaccine.covaxin.quant);
	printf("Quantity of COVISHIELD : ");
	scanf("%d", &t.vaccine.covishield.quant);
	printf("Quantity of SPUTNIK : ");
	scanf("%d", &t.vaccine.sputnik.quant);
	printf("Quantity of ZYDUS : ");
	scanf("%d", &t.vaccine.zydus.quant);
	printf("Quantity of PFIZER : ");
	scanf("%d", &t.vaccine.Pfizer.quant);
	printf("Quantity of MODERNA : ");
	scanf("%d", &t.vaccine.moderna.quant);
	t.income = 0;
	t.No_appoint = 0;
	t.V_quantity = t.vaccine.covaxin.quant + t.vaccine.covishield.quant + t.vaccine.sputnik.quant + t.vaccine.zydus.quant + t.vaccine.Pfizer.quant + t.vaccine.moderna.quant;

	fwrite(&t, sizeof(t), 1, fp);

	fclose(fp);

	printf("\nRecord has been added");
}

void EnlistSortedCenters()
{
	int choice;
	printf("\nChoose from the following :\n[1]Center ID\n[2]PIN code\n[3]District\nEnter the Number : ");
	scanf("%d", &choice);
	if (choice == 1)
	{
		FILE * fp;
		struct center t;

		fp = fopen("center.bin", "rb");

		printf("\n=======================================================================================================================================================");
		printf("\n\t\t\t\t\t\t\t\tList based on Center ID");
		printf("\n=======================================================================================================================================================");
		printf("\n       ID\t                  ADDRESS\t       DISTRICT\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp);

			if (feof(fp))
			{
				break;
			}

			printf("\n%9d\t", t.id);
			printf("%25s\t", t.Address);
			printf("%15s\t", t.District);
			printf("%10d\t", t.Pin);
			(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
			printf("%7d\t", t.vaccine.covaxin.quant);
			printf("%10d\t", t.vaccine.covishield.quant);
			printf("%7d\t", t.vaccine.sputnik.quant);
			printf("%5d\t", t.vaccine.zydus.quant);
			printf("%6d\t", t.vaccine.Pfizer.quant);
			printf("%7d\t", t.vaccine.moderna.quant);

		}

		fclose(fp);

	}
	else if (choice == 2)
	{
		FILE * fp;
		struct center t;

		fp = fopen("center.bin", "rb");

		printf("\n=======================================================================================================================================================");
		printf("\n\t\t\t\t\t\t\t\tList based on PIN Codes");
		printf("\n=======================================================================================================================================================");
		printf("\n       PIN\t       ID\t       ADDRESS\t       DISTRICT\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp);

			if (feof(fp))
			{
				break;
			}

			printf("\n%10d\t", t.Pin);
			printf("%9d\t", t.id);
			printf("%14s\t", t.Address);
			printf("%15s\t", t.District);
			(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
			printf("%7d\t", t.vaccine.covaxin.quant);
			printf("%10d\t", t.vaccine.covishield.quant);
			printf("%7d\t", t.vaccine.sputnik.quant);
			printf("%5d\t", t.vaccine.zydus.quant);
			printf("%6d\t", t.vaccine.Pfizer.quant);
			printf("%7d\t", t.vaccine.moderna.quant);
		
		}

		fclose(fp);
	}
	else if (choice == 3)
	{
		FILE * fp;
		struct center t;

		fp = fopen("center.bin", "rb");

		printf("\n=======================================================================================================================================================");
		printf("\n\t\t\t\t\t\t\t\tList based on District Names");
		printf("\n=======================================================================================================================================================");
		printf("\n       DISTRICT\t       ID\t       ADDRESS\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp);

			if (feof(fp))
			{
				break;
			}

			printf("\n%15s\t", t.District);
			printf("%9d\t", t.id);
			printf("%14s\t", t.Address);
			printf("%10d\t", t.Pin);
			(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
			printf("%7d\t", t.vaccine.covaxin.quant);
			printf("%10d\t", t.vaccine.covishield.quant);
			printf("%7d\t", t.vaccine.sputnik.quant);
			printf("%5d\t", t.vaccine.zydus.quant);
			printf("%6d\t", t.vaccine.Pfizer.quant);
			printf("%7d\t", t.vaccine.moderna.quant);
			
		}

		fclose(fp);
	}
	else
	{
		printf("\n\t\tINCORRECT CHOICE");
	}
}

void getCenter()
{
	int choice, ID, PIN, c_type, found;
	char Dist[20], v_type[20];
	printf("\nChoose from the following :\n[1]Center ID\n[2]PIN code\n[3]District\n[4]Center Type\n[5]Vaccine Type\n Enter the Number : ");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("\nEnter Center ID : ");
		scanf("%d", &ID);

		FILE * fp;
		struct center t;
		found = 0;

		fp = fopen("center.bin", "rb");

		printf("\n=======================================================================================================================================================");
		printf("\n\t\t\t\t\t\t\t\tList based on Center ID");
		printf("\n=======================================================================================================================================================");
		printf("\n       ID\t       ADDRESS\t       DISTRICT\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp);

			if (feof(fp))
			{
				break;
			}

			if (t.id == ID)
			{
				found = 1;
				printf("\n%9d\t", t.id);
				printf("%14s\t", t.Address);
				printf("%15s\t", t.District);
				printf("%10d\t", t.Pin);
				(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
				printf("%7d\t", t.vaccine.covaxin.quant);
				printf("%10d\t", t.vaccine.covishield.quant);
				printf("%7d\t", t.vaccine.sputnik.quant);
				printf("%5d\t", t.vaccine.zydus.quant);
				printf("%6d\t", t.vaccine.Pfizer.quant);
				printf("%7d\t", t.vaccine.moderna.quant);
				
			}
		}

		(found == 0) ? printf("\n\n\t\t\t\t\tNO CENTER ID FOUND"): 0;

	}
	else if (choice == 2)
	{
		printf("\nEnter PIN code : ");
		scanf("%d", &PIN);

		FILE * fp;
		struct center t;
		found = 0;

		fp = fopen("center.bin", "rb");

		printf("\n=======================================================================================================================================================");
		printf("\n\t\t\t\t\t\t\t\tList based on PIN Code");
		printf("\n=======================================================================================================================================================");
		printf("\n       ID\t       ADDRESS\t       DISTRICT\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp);

			if (feof(fp))
			{
				break;
			}

			if (t.Pin == PIN)
			{
				found = 1;
				printf("\n%9d\t", t.id);
				printf("%14s\t", t.Address);
				printf("%15s\t", t.District);
				printf("%10d\t", t.Pin);
				(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
				printf("%7d\t", t.vaccine.covaxin.quant);
				printf("%10d\t", t.vaccine.covishield.quant);
				printf("%7d\t", t.vaccine.sputnik.quant);
				printf("%5d\t", t.vaccine.zydus.quant);
				printf("%6d\t", t.vaccine.Pfizer.quant);
				printf("%7d\t", t.vaccine.moderna.quant);
				
			}
		}

		(found == 0) ? printf("\n\n\t\t\t\t\tNO PIN CODE FOUND"): 0;
	}
	else if (choice == 3)
	{
		printf("\nEnter District name (in small caps) : ");
		scanf("%s", &Dist);

		FILE * fp;
		struct center t;
		found = 0;

		fp = fopen("center.bin", "rb");

		printf("\n=======================================================================================================================================================");
		printf("\n\t\t\t\t\t\t\t\tList based on District Names");
		printf("\n=======================================================================================================================================================");
		printf("\n       ID\t       ADDRESS\t       DISTRICT\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp);

			if (feof(fp))
			{
				break;
			}

			if (strcmp(t.District, Dist) == 0)
			{
				found = 1;
				printf("\n%9d\t", t.id);
				printf("%14s\t", t.Address);
				printf("%15s\t", t.District);
				printf("%10d\t", t.Pin);
				(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
				printf("%7d\t", t.vaccine.covaxin.quant);
				printf("%10d\t", t.vaccine.covishield.quant);
				printf("%7d\t", t.vaccine.sputnik.quant);
				printf("%5d\t", t.vaccine.zydus.quant);
				printf("%6d\t", t.vaccine.Pfizer.quant);
				printf("%7d\t", t.vaccine.moderna.quant);
			
			}
		}

		(found == 0) ? printf("\n\n\t\t\t\t\tNO DISTRICR FOUND"): 0;
	}
	else if (choice == 4)
	{
		printf("\nEnter Center type (Govt. = 0, Pvt. = 1) : ");
		scanf("%d", &c_type);

		FILE * fp;
		struct center t;
		found = 0;

		fp = fopen("center.bin", "rb");

		printf("\n=======================================================================================================================================================");
		printf("\n\t\t\t\t\t\t\t\tList based on District Names");
		printf("\n=======================================================================================================================================================");
		printf("\n       ID\t       ADDRESS\t       DISTRICT\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp);

			if (feof(fp))
			{
				break;
			}

			if (t.C_type == c_type)
			{
				found = 1;
				printf("\n%9d\t", t.id);
				printf("%14s\t", t.Address);
				printf("%15s\t", t.District);
				printf("%10d\t", t.Pin);
				(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
				printf("%7d\t", t.vaccine.covaxin.quant);
				printf("%10d\t", t.vaccine.covishield.quant);
				printf("%7d\t", t.vaccine.sputnik.quant);
				printf("%5d\t", t.vaccine.zydus.quant);
				printf("%6d\t", t.vaccine.Pfizer.quant);
				printf("%7d\t", t.vaccine.moderna.quant);
			
			}
		}

		(found == 0) ? printf("\n\n\t\t\t\t\tNo MATCH FOUND"): 0;
	}
	else if (choice == 5)
	{
		int type;
		printf("\nChoose from the following :\n[1] Covaxin\n[2] Covishield\n[3] Sputnik\n[4] Zydus\n[5] Pfizer\n[6] Moderna\nEnter Type Number : ");
		scanf("%d", &type);
		if (type == 1)
		{
			FILE * fp;
			struct center t;
			found = 0;

			fp = fopen("center.bin", "rb");

			printf("\n=======================================================================================================================================================");
			printf("\n\t\t\t\t\t\t\t\tList based on Covaxin");
			printf("\n=======================================================================================================================================================");
			printf("\n       ID\t       ADDRESS\t       DISTRICT\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

			while (1)
			{
				fread(&t, sizeof(t), 1, fp);

				if (feof(fp))
				{
					break;
				}

				if (t.vaccine.covaxin.quant > 0)
				{
					found = 1;
					printf("\n%9d\t", t.id);
					printf("%14s\t", t.Address);
					printf("%15s\t", t.District);
					printf("%10d\t", t.Pin);
					(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
					printf("%7d\t", t.vaccine.covaxin.quant);
					printf("%10d\t", t.vaccine.covishield.quant);
					printf("%7d\t", t.vaccine.sputnik.quant);
					printf("%5d\t", t.vaccine.zydus.quant);
					printf("%6d\t", t.vaccine.Pfizer.quant);
					printf("%7d\t", t.vaccine.moderna.quant);
				
				}
			}

			(found == 0) ? printf("\n\n\t\t\t\t\tNo Covaxin Vaccine Aviavlable"): 0;
		}
		else if (type == 2)
		{
			FILE * fp;
			struct center t;
			found = 0;

			fp = fopen("center.bin", "rb");

			printf("\n=======================================================================================================================================================");
			printf("\n\t\t\t\t\t\t\t\tList based on Covaxin");
			printf("\n=======================================================================================================================================================");
			printf("\n       ID\t       ADDRESS\t       DISTRICT\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

			while (1)
			{
				fread(&t, sizeof(t), 1, fp);

				if (feof(fp))
				{
					break;
				}

				if (t.vaccine.covishield.quant > 0)
				{
					found = 1;
					printf("\n%9d\t", t.id);
					printf("%14s\t", t.Address);
					printf("%15s\t", t.District);
					printf("%10d\t", t.Pin);
					(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
					printf("%7d\t", t.vaccine.covaxin.quant);
					printf("%10d\t", t.vaccine.covishield.quant);
					printf("%7d\t", t.vaccine.sputnik.quant);
					printf("%5d\t", t.vaccine.zydus.quant);
					printf("%6d\t", t.vaccine.Pfizer.quant);
					printf("%7d\t", t.vaccine.moderna.quant);
				
				}
			}

			(found == 0) ? printf("\n\n\t\t\t\t\tNo Covishield Vaccine Aviavlable"): 0;
		}
		else if (type == 3)
		{
			FILE * fp;
			struct center t;
			found = 0;

			fp = fopen("center.bin", "rb");

			printf("\n=======================================================================================================================================================");
			printf("\n\t\t\t\t\t\t\t\tList based on Covaxin");
			printf("\n=======================================================================================================================================================");
			printf("\n       ID\t       ADDRESS\t       DISTRICT\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

			while (1)
			{
				fread(&t, sizeof(t), 1, fp);

				if (feof(fp))
				{
					break;
				}

				if (t.vaccine.sputnik.quant > 0)
				{
					found = 1;
					printf("\n%9d\t", t.id);
					printf("%14s\t", t.Address);
					printf("%15s\t", t.District);
					printf("%10d\t", t.Pin);
					(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
					printf("%7d\t", t.vaccine.covaxin.quant);
					printf("%10d\t", t.vaccine.covishield.quant);
					printf("%7d\t", t.vaccine.sputnik.quant);
					printf("%5d\t", t.vaccine.zydus.quant);
					printf("%6d\t", t.vaccine.Pfizer.quant);
					printf("%7d\t", t.vaccine.moderna.quant);
				
				}
			}

			(found == 0) ? printf("\n\n\t\t\t\t\tNo Sputnik Vaccine Aviavlable"): 0;
		}
		else if (type == 4)
		{
			FILE * fp;
			struct center t;
			found = 0;

			fp = fopen("center.bin", "rb");

			printf("\n=======================================================================================================================================================");
			printf("\n\t\t\t\t\t\t\t\tList based on Covaxin");
			printf("\n=======================================================================================================================================================");
			printf("\n       ID\t       ADDRESS\t       DISTRICT\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

			while (1)
			{
				fread(&t, sizeof(t), 1, fp);

				if (feof(fp))
				{
					break;
				}

				if (t.vaccine.zydus.quant > 0)
				{
					found = 1;
					printf("\n%9d\t", t.id);
					printf("%14s\t", t.Address);
					printf("%15s\t", t.District);
					printf("%10d\t", t.Pin);
					(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
					printf("%7d\t", t.vaccine.covaxin.quant);
					printf("%10d\t", t.vaccine.covishield.quant);
					printf("%7d\t", t.vaccine.sputnik.quant);
					printf("%5d\t", t.vaccine.zydus.quant);
					printf("%6d\t", t.vaccine.Pfizer.quant);
					printf("%7d\t", t.vaccine.moderna.quant);
				
				}
			}

			(found == 0) ? printf("\n\n\t\t\t\t\tNo Zydus Vaccine Aviavlable"): 0;
		}
		else if (type == 5)
		{
			FILE * fp;
			struct center t;
			found = 0;

			fp = fopen("center.bin", "rb");

			printf("\n=======================================================================================================================================================");
			printf("\n\t\t\t\t\t\t\t\tList based on Covaxin");
			printf("\n=======================================================================================================================================================");
			printf("\n       ID\t       ADDRESS\t       DISTRICT\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

			while (1)
			{
				fread(&t, sizeof(t), 1, fp);

				if (feof(fp))
				{
					break;
				}

				if (t.vaccine.Pfizer.quant > 0)
				{
					found = 1;
					printf("\n%9d\t", t.id);
					printf("%14s\t", t.Address);
					printf("%15s\t", t.District);
					printf("%10d\t", t.Pin);
					(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
					printf("%7d\t", t.vaccine.covaxin.quant);
					printf("%10d\t", t.vaccine.covishield.quant);
					printf("%7d\t", t.vaccine.sputnik.quant);
					printf("%5d\t", t.vaccine.zydus.quant);
					printf("%6d\t", t.vaccine.Pfizer.quant);
					printf("%7d\t", t.vaccine.moderna.quant);
			
				}
			}

			(found == 0) ? printf("\n\n\t\t\t\t\tNo Pfizer Vaccine Aviavlable"): 0;
		}
		else if (type == 6)
		{
			FILE * fp;
			struct center t;
			found = 0;

			fp = fopen("center.bin", "rb");

			printf("\n=======================================================================================================================================================");
			printf("\n\t\t\t\t\t\t\t\tList based on Covaxin");
			printf("\n=======================================================================================================================================================");
			printf("\n       ID\t       ADDRESS\t       DISTRICT\t       PIN\tCENTER_TYPE\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");

			while (1)
			{
				fread(&t, sizeof(t), 1, fp);

				if (feof(fp))
				{
					break;
				}

				if (t.vaccine.moderna.quant > 0)
				{
					found = 1;
					printf("\n%9d\t", t.id);
					printf("%14s\t", t.Address);
					printf("%15s\t", t.District);
					printf("%10d\t", t.Pin);
					(t.C_type == 0) ? printf("      Govt.\t"): printf("       Pvt.\t");
					printf("%7d\t", t.vaccine.covaxin.quant);
					printf("%10d\t", t.vaccine.covishield.quant);
					printf("%7d\t", t.vaccine.sputnik.quant);
					printf("%5d\t", t.vaccine.zydus.quant);
					printf("%6d\t", t.vaccine.Pfizer.quant);
					printf("%7d\t", t.vaccine.moderna.quant);
			
				}
			}

			(found == 0) ? printf("\n\n\t\t\t\t\tNo Moderna Vaccine Aviavlable"): 0;
		}
	}
	else
	{
		printf("\nError in choice");
	}
}

int B_idMatch(int B_id)
{
	struct citizen t;
	FILE * fp;
	fp = fopen("citizen.bin", "rb");
	int match = 0;

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);
		if (feof(fp))
		{
			break;
		}

		if (t.id == B_id)
		{
			match = 1;
		}
	}

	fclose(fp);

	return match;
}

int DoseCheck(int B_id)
{
	struct citizen t;
	FILE * fp;
	fp = fopen("citizen.bin", "rb");
	int exceed = 1;

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);
		if (feof(fp))
		{
			break;
		}

		if (t.id == B_id)
		{
			if (t.No_dose < 2)
			{
				exceed = 0;
			}

			break;	//check if  this is can be used everywhere
		}
	}

	fclose(fp);

	return exceed;
}

int AppotDate(int B_id)
{
	SYSTEMTIME s;
	GetLocalTime(&s);
	struct citizen t;
	FILE * fp;
	fp = fopen("citizen.bin", "rb");
	int appot = 0;

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);
		if (feof(fp))
		{
			break;
		}

		if (t.id == B_id)
		{
			if (t.appotDate.day == s.wDay && t.appotDate.month == s.wMonth && t.appotDate.year == s.wYear)
			{
				printf("\n\t\t\t\tAppointment Already Booked. Cannot book 2 appointment on same day !");
				appot = 1;
			}
		}
	}

	fclose(fp);

	return appot;
}

int C_idMatch(int C_id)
{
	struct center t;
	FILE * fp;
	fp = fopen("center.bin", "rb");
	int match = 0;

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);
		if (feof(fp))
		{
			break;
		}

		if (t.id == C_id)
		{
			match = 1;
		}
	}

	fclose(fp);

	return match;
}

int Vaccine_availability(int C_id, int type)
{
	int retval = 0;
	FILE * fp;
	struct center t;
	fp = fopen("center.bin", "rb");

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);
		if (feof(fp))
		{
			break;
		}

		if (t.id == C_id)
		{
			(type == 1) ? retval = 1: (type == 2) ? retval = 1 : (type == 3) ? retval = 1 : (type == 4) ? retval = 1 : (type == 5) ? retval = 1 : (type == 6) ? retval = 1 : 0;
			(type == 1 && t.vaccine.covaxin.quant > 0) ? retval++ : (type == 2 && t.vaccine.covishield.quant > 0) ? retval++ : (type == 3 && t.vaccine.sputnik.quant > 0) ? retval++ : (type == 4 && t.vaccine.zydus.quant > 0) ? retval++ : (type == 5 && t.vaccine.Pfizer.quant > 0) ? retval++ : (type == 6 && t.vaccine.moderna.quant > 0) ? retval++ : 0;
		}
	}

	fclose(fp);

	return retval;
}

void BookAppointment()
{
	SYSTEMTIME s;
	GetLocalTime(&s);
	FILE *fp, *fp1;
	struct citizen t;
	struct center t1;
	int i = 0, B_id, C_id, choice;
	char type[15];
	printf("\nEnter the Beneficiary ID : ");
	scanf("%d", &B_id);

	while (i < 1)
	{
		if (B_idMatch(B_id) == 0)
		{
			printf("\n\t\tBeneficiary ID not found !");
			break;
		}

		if (DoseCheck(B_id) == 1)
		{
			printf("\n\t\tNo more than 2 doses !");
			break;
		}

		if (AppotDate(B_id) == 1)
		{
			break;
		}

		printf("Enter Center ID : ");
		scanf("%d", &C_id);
		if (C_idMatch(C_id) == 0)
		{
			printf("\n\t\tCenter ID not found !");
			break;
		}

		printf("Choose Vaccine Type from the following :\n[1] Covaxin : Rs.150\n[2] Covishield : Rs.160\n[3] Sputnik : Rs.170\n[4] Zydus : Rs.180\n[5] Pfizer : Rs.190\n[6] Moderna : Rs.200\nEnter choice Number : ");
		scanf("%d", &choice);

		if (Vaccine_availability(C_id, choice) == 1)
		{
			printf("\n\t\tVaccine Unvailable !");
			break;
		}

		if (Vaccine_availability(C_id, choice) == 0)
		{
			printf("\n\t\tInvalid Choice !");
			break;
		}

		// changes in center.bin
		fp = fopen("center.bin", "rb");
		fp1 = fopen("temp.bin", "wb");
		while (1)
		{
			fread(&t1, sizeof(t1), 1, fp);
			if (feof(fp))
			{
				break;
			}

			if (t1.id == C_id)
			{
				(choice == 1) ? (t1.vaccine.covaxin.quant--, t1.income += COVAXIN, t1.No_appoint++) : 0;
				(choice == 2) ? (t1.vaccine.covishield.quant--, t1.income += COVISHIELD, t1.No_appoint++) : 0;
				(choice == 3) ? (t1.vaccine.sputnik.quant--, t1.income += SPUTNIK, t1.No_appoint++) : 0;
				(choice == 4) ? (t1.vaccine.zydus.quant--, t1.income += ZYDUS, t1.No_appoint++) : 0;
				(choice == 5) ? (t1.vaccine.Pfizer.quant--, t1.income += PFIZER, t1.No_appoint++) : 0;
				(choice == 6) ? (t1.vaccine.moderna.quant--, t1.income += MODERNA, t1.No_appoint++) : 0;

				fwrite(&t1, sizeof(t1), 1, fp1);
			}
			else
			{
				fwrite(&t1, sizeof(t1), 1, fp1);
			}
		}

		fclose(fp1);
		fclose(fp);

		fp = fopen("center.bin", "wb");
		fp1 = fopen("temp.bin", "rb");
		while (1)
		{
			fread(&t1, sizeof(t1), 1, fp1);

			if (feof(fp1))
			{
				break;
			}

			fwrite(&t1, sizeof(t1), 1, fp);
		}

		fclose(fp);
		fclose(fp1);

		// Changes in citizen.bin
		fp = fopen("citizen.bin", "rb");
		fp1 = fopen("temp.bin", "wb");
		while (1)
		{
			fread(&t, sizeof(t), 1, fp);
			if (feof(fp))
			{
				break;
			}

			if (t.id == B_id)
			{
				t.No_dose++;
				(t.No_dose == 1) ? (t.dose1 = C_id) : 0;
				(t.No_dose == 2) ? (t.dose2 = C_id) : 0;
				t.C_id = C_id;
				t.V_type = choice;
				t.appot = 1;	// Not sure where used it!	// keep the track if appointment exist.	// dont increment just assign
				t.appotDate.day = s.wDay;
				t.appotDate.month = s.wMonth;
				t.appotDate.year = s.wYear;
				fwrite(&t, sizeof(t), 1, fp1);
			}
			else
			{
				fwrite(&t, sizeof(t), 1, fp1);
			}
		}

		fclose(fp1);
		fclose(fp);

		fp = fopen("citizen.bin", "wb");
		fp1 = fopen("temp.bin", "rb");
		while (1)
		{
			fread(&t, sizeof(t), 1, fp1);

			if (feof(fp1))
			{
				break;
			}

			fwrite(&t, sizeof(t), 1, fp);
		}
		printf("\n\t\tAppointment Booked Succesfully !");
		fclose(fp);
		fclose(fp1);
		i++;
	}
}

int checkAppot(int B_id)
{
	struct citizen t;
	FILE * fp;
	fp = fopen("citizen.bin", "rb");
	int exist = 0;

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);
		if (feof(fp))
		{
			break;
		}

		if (t.id == B_id)
		{
			if (t.appot == 1)
			{
				exist = 1;
			}
		}
	}

	fclose(fp);

	return exist;
}

void CancelAppointment()
{
	FILE *fp, *fp1;
	struct citizen t;
	struct center t1;
	int B_id, C_id_copy, i = 0, choice;
	printf("\nEnter the Beneficiary ID : ");
	scanf("%d", &B_id);

	while (i < 1)
	{
		if (B_idMatch(B_id) == 0)
		{
			printf("\n\t\tBeneficiary ID not found");
			break;
		}

		if (checkAppot(B_id) == 0)
		{
			printf("\n\t\tNo Appointment is booked");
			break;
		}

		// Changes in citizen.bin
		fp = fopen("citizen.bin", "rb");
		fp1 = fopen("temp.bin", "wb");
		while (1)
		{
			fread(&t, sizeof(t), 1, fp);
			if (feof(fp))
			{
				break;
			}

			if (t.id == B_id)
			{
				(t.No_dose == 1) ? (t.dose1 = 0) : 0;
				(t.No_dose == 2) ? (t.dose2 = 0) : 0;
				t.No_dose--;
				t.appot = 0;
				t.appotDate.day = 0;
				t.appotDate.month = 0;
				t.appotDate.year = 0;
				fwrite(&t, sizeof(t), 1, fp1);
				C_id_copy = t.C_id;
				choice = t.V_type;
			}
			else
			{
				fwrite(&t, sizeof(t), 1, fp1);
			}
		}

		fclose(fp1);
		fclose(fp);

		fp = fopen("citizen.bin", "wb");
		fp1 = fopen("temp.bin", "rb");
		while (1)
		{
			fread(&t, sizeof(t), 1, fp1);

			if (feof(fp1))
			{
				break;
			}

			fwrite(&t, sizeof(t), 1, fp);
		}

		fclose(fp);
		fclose(fp1);
		// changes in center.bin
		fp = fopen("center.bin", "rb");
		fp1 = fopen("temp.bin", "wb");
		while (1)
		{
			fread(&t1, sizeof(t1), 1, fp);
			if (feof(fp))
			{
				break;
			}

			if (t1.id == C_id_copy)
			{
				(choice == 1) ? (t1.vaccine.covaxin.quant++, t1.income -= COVAXIN, t1.No_appoint--) : 0;
				(choice == 2) ? (t1.vaccine.covishield.quant++, t1.income -= COVISHIELD, t1.No_appoint--) : 0;
				(choice == 3) ? (t1.vaccine.sputnik.quant++, t1.income -= SPUTNIK, t1.No_appoint--) : 0;
				(choice == 4) ? (t1.vaccine.zydus.quant++, t1.income -= ZYDUS, t1.No_appoint--) : 0;
				(choice == 5) ? (t1.vaccine.Pfizer.quant++, t1.income -= PFIZER, t1.No_appoint--) : 0;
				(choice == 6) ? (t1.vaccine.moderna.quant++, t1.income -= MODERNA, t1.No_appoint--) : 0;

				fwrite(&t1, sizeof(t1), 1, fp1);
			}
			else
			{
				fwrite(&t1, sizeof(t1), 1, fp1);
			}
		}

		fclose(fp1);
		fclose(fp);

		fp = fopen("center.bin", "wb");
		fp1 = fopen("temp.bin", "rb");
		while (1)
		{
			fread(&t1, sizeof(t1), 1, fp1);

			if (feof(fp1))
			{
				break;
			}

			fwrite(&t1, sizeof(t1), 1, fp);
		}

		fclose(fp);
		fclose(fp1);

		i++;
		printf("\n\t\tAppointment cancelled Successfully. Your amount has been refunded");
	}
}

void removeBeneficiary()
{
	FILE *fp, *fp1;
	struct citizen t;
	struct center t1;
	int B_id, C_id_copy, i = 0, choice, no_appot = 0, found = 0;
	printf("\nEnter the Beneficiary ID : ");
	scanf("%d", &B_id);

	while (i < 1)
	{
		if (B_idMatch(B_id) == 0)
		{
			printf("\n\t\tBeneficiary ID not found");
			break;
		}

		if (checkAppot(B_id) == 0)
		{
			printf("\n\t\tNo Appointment is booked");
			no_appot = 1;
		}

		if (no_appot == 0)
		{
			// Changes in citizen.bin
			fp = fopen("citizen.bin", "rb");
			fp1 = fopen("temp.bin", "wb");
			while (1)
			{
				fread(&t, sizeof(t), 1, fp);
				if (feof(fp))
				{
					break;
				}

				if (t.id == B_id)
				{
					(t.No_dose == 1) ? (t.dose1 = 0) : 0;
					(t.No_dose == 2) ? (t.dose2 = 0) : 0;
					t.No_dose--;
					t.appot = 0;
					t.appotDate.day = 0;
					t.appotDate.month = 0;
					t.appotDate.year = 0;
					fwrite(&t, sizeof(t), 1, fp1);
					C_id_copy = t.C_id;
					choice = t.V_type;

					fwrite(&t, sizeof(t), 1, fp1);
				}
				else
				{
					fwrite(&t, sizeof(t), 1, fp1);
				}
			}

			fclose(fp1);
			fclose(fp);

			fp = fopen("citizen.bin", "wb");
			fp1 = fopen("temp.bin", "rb");
			while (1)
			{
				fread(&t, sizeof(t), 1, fp1);

				if (feof(fp1))
				{
					break;
				}

				fwrite(&t, sizeof(t), 1, fp);
			}

			fclose(fp);
			fclose(fp1);
			// changes in center.bin
			fp = fopen("center.bin", "rb");
			fp1 = fopen("temp.bin", "wb");
			while (1)
			{
				fread(&t1, sizeof(t1), 1, fp);
				if (feof(fp))
				{
					break;
				}

				if (t1.id == C_id_copy)
				{
					(choice == 1) ? (t1.vaccine.covaxin.quant++, t1.income -= COVAXIN, t1.No_appoint--) : 0;
					(choice == 2) ? (t1.vaccine.covishield.quant++, t1.income -= COVISHIELD, t1.No_appoint--) : 0;
					(choice == 3) ? (t1.vaccine.sputnik.quant++, t1.income -= SPUTNIK, t1.No_appoint--) : 0;
					(choice == 4) ? (t1.vaccine.zydus.quant++, t1.income -= ZYDUS, t1.No_appoint--) : 0;
					(choice == 5) ? (t1.vaccine.Pfizer.quant++, t1.income -= PFIZER, t1.No_appoint--) : 0;
					(choice == 6) ? (t1.vaccine.moderna.quant++, t1.income -= MODERNA, t1.No_appoint--) : 0;

					fwrite(&t1, sizeof(t1), 1, fp1);
				}
				else
				{
					fwrite(&t1, sizeof(t1), 1, fp1);
				}
			}

			fclose(fp1);
			fclose(fp);

			fp = fopen("center.bin", "wb");
			fp1 = fopen("temp.bin", "rb");
			while (1)
			{
				fread(&t1, sizeof(t1), 1, fp1);

				if (feof(fp1))
				{
					break;
				}

				fwrite(&t1, sizeof(t1), 1, fp);
			}

			fclose(fp);
			fclose(fp1);
			no_appot == 1;
		}

		// removing beneficiary	
		fp = fopen("citizen.bin", "rb");
		fp1 = fopen("temp.bin", "wb");
		while (1)
		{
			fread(&t, sizeof(t), 1, fp);
			if (feof(fp))
			{
				break;
			}

			if (t.id == B_id)
			{
				found = 1;
			}
			else
			{
				fwrite(&t, sizeof(t), 1, fp1);
			}
		}

		fclose(fp1);
		fclose(fp);

		fp = fopen("citizen.bin", "wb");
		fp1 = fopen("temp.bin", "rb");
		while (1)
		{
			fread(&t, sizeof(t), 1, fp1);

			if (feof(fp1))
			{
				break;
			}

			fwrite(&t, sizeof(t), 1, fp);
		}

		fclose(fp1);
		fclose(fp);

		i++;
		printf("\n\t\tBeneficiary Removed Successfully.");
	}
}

void CanAppotFromCent(int B_id)
{
	FILE *fp, *fp1;
	struct citizen t;
	struct center t1;
	int C_id_copy, i = 0, choice;

	while (i < 1)
	{
		if (B_idMatch(B_id) == 0)
		{
			printf("\n\t\tBeneficiary ID not found");
			break;
		}

		if (checkAppot(B_id) == 0)
		{
			printf("\n\t\tNo Appointment is booked");
			break;
		}

		// Changes in citizen.bin
		fp = fopen("citizen.bin", "rb");
		fp1 = fopen("temp.bin", "wb");
		while (1)
		{
			fread(&t, sizeof(t), 1, fp);
			if (feof(fp))
			{
				break;
			}

			if (t.id == B_id)
			{
				(t.No_dose == 1) ? (t.dose1 = 0) : 0;
				(t.No_dose == 2) ? (t.dose2 = 0) : 0;
				t.No_dose--;
				t.appot = 0;
				t.appotDate.day = 0;
				t.appotDate.month = 0;
				t.appotDate.year = 0;
				fwrite(&t, sizeof(t), 1, fp1);
				C_id_copy = t.C_id;
				choice = t.V_type;
			}
			else
			{
				fwrite(&t, sizeof(t), 1, fp1);
			}
		}

		fclose(fp1);
		fclose(fp);

		fp = fopen("citizen.bin", "wb");
		fp1 = fopen("temp.bin", "rb");
		while (1)
		{
			fread(&t, sizeof(t), 1, fp1);

			if (feof(fp1))
			{
				break;
			}

			fwrite(&t, sizeof(t), 1, fp);
		}

		fclose(fp);
		fclose(fp1);
		// changes in center.bin
		fp = fopen("center.bin", "rb");
		fp1 = fopen("temp.bin", "wb");
		while (1)
		{
			fread(&t1, sizeof(t1), 1, fp);
			if (feof(fp))
			{
				break;
			}

			if (t1.id == C_id_copy)
			{
				(choice == 1) ? (t1.vaccine.covaxin.quant++, t1.income -= COVAXIN, t1.No_appoint--) : 0;
				(choice == 2) ? (t1.vaccine.covishield.quant++, t1.income -= COVISHIELD, t1.No_appoint--) : 0;
				(choice == 3) ? (t1.vaccine.sputnik.quant++, t1.income -= SPUTNIK, t1.No_appoint--) : 0;
				(choice == 4) ? (t1.vaccine.zydus.quant++, t1.income -= ZYDUS, t1.No_appoint--) : 0;
				(choice == 5) ? (t1.vaccine.Pfizer.quant++, t1.income -= PFIZER, t1.No_appoint--) : 0;
				(choice == 6) ? (t1.vaccine.moderna.quant++, t1.income -= MODERNA, t1.No_appoint--) : 0;

				fwrite(&t1, sizeof(t1), 1, fp1);
			}
			else
			{
				fwrite(&t1, sizeof(t1), 1, fp1);
			}
		}

		fclose(fp1);
		fclose(fp);

		fp = fopen("center.bin", "wb");
		fp1 = fopen("temp.bin", "rb");
		while (1)
		{
			fread(&t1, sizeof(t1), 1, fp1);

			if (feof(fp1))
			{
				break;
			}

			fwrite(&t1, sizeof(t1), 1, fp);
		}

		fclose(fp);
		fclose(fp1);

		i++;
	}
}

void B_idINC_id(int C_id)
{
	FILE * fp;
	struct citizen t;
	fp = fopen("citizen.bin", "rb");
	while (1)
	{
		fread(&t, sizeof(t), 1, fp);
		if (feof(fp))
		{
			break;
		}

		if (t.C_id == C_id)
		{
			CanAppotFromCent(t.id);
		}
	}

	fclose(fp);
}

void removeCenter()
{
	FILE *fp, *fp1;
	struct center t;
	int B_id, C_id, found = 0;

	fp = fopen("center.bin", "rb");
	fp1 = fopen("temp.bin", "wb");

	printf("\nEnter Center ID :");
	scanf("%d", &C_id);

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);

		if (feof(fp))
		{
			break;
		}

		if (t.id == C_id)
		{
			found = 1;
		}
		else
		{
			fwrite(&t, sizeof(t), 1, fp1);
		}
	}

	fclose(fp1);
	fclose(fp);

	if (found == 0)
	{
		printf("\n\tNo Center ID found");
	}
	else
	{
		printf("\n\n\t\tCenter Removed ! \n\t\tAll appointment for the Cancelled ! \n\t\tAmount will be refunded !");
		fp = fopen("center.bin", "wb");
		fp1 = fopen("temp.bin", "rb");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp1);	//CORRECT fp1

			if (feof(fp1))
			{
				break;
			}

			fwrite(&t, sizeof(t), 1, fp);
		}

		B_idINC_id(C_id);
	}

	fclose(fp);
	fclose(fp1);

}

void UpdateBeneficiaryInfo()
{
	int B_id, choice;
	printf("\nEnter Beneficiary ID : ");
	scanf("%d", &B_id);
	printf("\nChoose Field from the following :\n[1] Name\n[2] Gender\n[3] BirthYear\n[4] No. of dose\nEnter the field Number : ");
	scanf("%d", &choice);

	FILE *fp, *fp1;
	struct citizen t, t1;
	int found = 0;

	fp = fopen("citizen.bin", "rb");
	fp1 = fopen("temp.bin", "wb");

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);

		if (feof(fp))
		{
			break;
		}

		if (t.id == B_id)
		{
			found = 1;

			if (choice == 1)	//Update Name
			{
				char name[20];
				printf("\nEnter the new Name : ");
				fflush(stdin);
				scanf("%s", &name);
				strcpy(t.fullName, name);
			}
			else if (choice == 2)	//Update Gender
			{
				char gender;
				printf("\nEnter the updated gender (M/F/N) : ");
				fflush(stdin);
				scanf("%c", &gender);
				t.Gender = gender;
			}
			else if (choice == 3)
			{
				int year;
				printf("\nEnter new BirthYear : ");
				fflush(stdin);
				scanf("%d", &year);
				t.BirthYear = year;
			}
			else if (choice == 4)
			{
				int dose;
				printf("\nEnter No of Doses : ");
				fflush(stdin);
				scanf("%d", &dose);
				t.No_dose = dose;
			}
			else
			{
				printf("\nWrong Input");
			}

			fwrite(&t, sizeof(t), 1, fp1);
		}
		else
		{
			fwrite(&t, sizeof(t), 1, fp1);
		}
	}

	fclose(fp);
	fclose(fp1);

	if (found == 0)
	{
		printf("\n\t\tRecord Not found (Beneficiary ID Error)");
	}
	else
	{
		fp = fopen("citizen.bin", "wb");
		fp1 = fopen("temp.bin", "rb");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp1);

			if (feof(fp1))
			{
				break;
			}

			fwrite(&t, sizeof(t), 1, fp);
		}
	}

	fclose(fp1);
	fclose(fp);
	(found==1) ? printf("\n\t\t\t\tUpdated Beneficiary Info Succesfully !") : 0;
}

void UpdateCenterInfo()
{
	int C_id, choice;
	printf("\nEnter Cenetr ID needed to be updated : ");
	scanf("%d", &C_id);
	printf("\nChoose Field from the following :\n[1] Address\n[2] District\n[3] PIN code\nEnter the field Number : ");
	scanf("%d", &choice);

	FILE *fp, *fp1;
	struct center t, t1;
	int found = 0, count = 0;

	fp = fopen("center.bin", "rb");
	fp1 = fopen("temp.bin", "wb");

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);

		if (feof(fp))
		{
			break;
		}

		if (t.id == C_id)
		{
			found = 1;

			if (choice == 1)	//Update Address
			{
				char address[100];
				printf("\nEnter the new Address : ");
				fflush(stdin);
				scanf("%s", &address);
				strcpy(t.Address, address);
			}
			else if (choice == 2)	//Update District
			{
				char dis[20];
				printf("\nEnter the updated District name : ");
				fflush(stdin);
				scanf("%s", &dis);
				strcpy(t.District, dis);
			}
			else if (choice == 3)
			{
				int PIN;
				printf("\nEnter new PIN : ");
				fflush(stdin);
				scanf("%d", &PIN);
				t.Pin = PIN;
			}
			else
			{
				printf("\nWrong Choice Input");
			}

			fwrite(&t, sizeof(t), 1, fp1);
		}
		else
		{
			fwrite(&t, sizeof(t), 1, fp1);
		}
	}

	fclose(fp1);
	fclose(fp);

	if (found == 0)
	{
		printf("\n\t\tRecord Not found (Center ID Error)");
	}
	else
	{
		printf("\n\t\tChanged Successfully");
		fp = fopen("center.bin", "wb");
		fp1 = fopen("temp.bin", "rb");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp1);

			if (feof(fp1))
			{
				break;
			}

			fwrite(&t, sizeof(t), 1, fp);
		}
	}

	fclose(fp1);
	fclose(fp);
}

void MaxIncomeCenter()
{
	FILE * fp;
	struct center t;
	int max_income = 0, max_id = 0;

	fp = fopen("center.bin", "rb");
	while (1)
	{
		fread(&t, sizeof(t), 1, fp);

		if (feof(fp))
		{
			break;
		}

		if (t.income > max_income)
		{
			max_income = t.income;
			max_id = t.id;

		}
	}
	printf("\n\t\t CENTER WITH MAXIMUM INCOME ");
	printf("\n===============================================================================================");
	printf("\nC_ID\tAddress\t\tDist.\t   PIN \tC_Type\tIncome\n");

	fclose(fp);
	if (max_income != 0)
	{
		fp = fopen("center.bin", "rb");
		while (1)
		{
			fread(&t, sizeof(t), 1, fp);

			if (feof(fp))
			{
				break;
			}

			if (t.id == max_id && t.C_type != 0)
			{
				printf("%d\t", t.id);
				printf("%s\t", t.Address);
				printf("%s\t", t.District);
				printf("%d\t", t.Pin);
				(t.C_type == 0) ? printf("Govt.\t"): printf("Pvt.\t");
				printf("%d\t", t.income);
			}
		}

		fclose(fp);
	}
	else
	{
		printf("\nNo Max Income Center");
	}

}

void VaccineAvailabilityReport()
{
	printf("\n============================================================================");
	printf("\nDISTRCT\tCOVAXIN\tCOVISHIELD\tSPUTNIK\tZYDUS\tPFIZER\tMODERNA");
	FILE * fp;
	struct center t;
	int max_income = 0, max_id = 0;

	fp = fopen("center.bin", "rb");
	while (1)
	{
		fread(&t, sizeof(t), 1, fp);

		if (feof(fp))
		{
			break;
		}

		printf("\n%s\t", t.District);
		printf("%d\t\t", t.vaccine.covaxin.quant);	// (covaxin/covishield/sputnik/zydus/Pfizer/moderna)
		printf("%d\t", t.vaccine.covishield.quant);
		printf("%d\t", t.vaccine.sputnik.quant);
		printf("%d\t", t.vaccine.zydus.quant);
		printf("%d\t", t.vaccine.Pfizer.quant);
		printf("%d\t", t.vaccine.moderna.quant);
	}

	fclose(fp);
}

void DistrictReport()
{
	printf("\n=============================================================");
	printf("\nDistrict\tVACCINES_BOOKED");
	FILE * fp;
	struct center t;

	fp = fopen("center.bin", "rb");
	while (1)
	{
		fread(&t, sizeof(t), 1, fp);

		if (feof(fp))
		{
			break;
		}

		printf("\n%s\t\t\t", t.District);
		printf("%d", t.V_quantity - t.vaccine.covaxin.quant - t.vaccine.covishield.quant - t.vaccine.sputnik.quant - t.vaccine.zydus.quant - t.vaccine.Pfizer.quant - t.vaccine.moderna.quant);
	}

	fclose(fp);
}

void SeniorCitizenIntersection()
{
	printf("\n======================================================================");
	printf("\nB_ID\tName\tGender\tBirthYear\tCent_ID");
	FILE * fp;
	struct citizen t;

	fp = fopen("citizen.bin", "rb");
	while (1)
	{
		fread(&t, sizeof(t), 1, fp);

		if (feof(fp))
		{
			break;
		}

		if (t.BirthYear > 1961 && t.dose1 == t.dose2)
		{
			printf("\n%d\t%s\t%c\t%d\t%d", t.id, t.fullName, t.Gender, t.BirthYear, t.dose1);
		}
	}

	fclose(fp);
	printf("\n\n\n-----------------x-------------------");
}
