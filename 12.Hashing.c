/*
12 Given a File of N employee records with a set K of Keys(4-digit) which
uniquely determine the records in file F. Assume that file F is maintained in
memory by a Hash Table(HT) of m memory locations with L as the set of
memory addresses (2-digit) of locations in HT. Let the keys in K and
addresses in L are Integers. Design and develop a Program in C that uses
Hash function H: K →L as H(K)=K mod m (remainder method), and
implement hashing technique to map a given key K to the address space L.
Resolve the collision (if any) using linear probing.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct emp
{
	int empno;
	char name[20];
	int sal;
} EMPLOYEE;

void main()
{
	EMPLOYEE E;
	FILE *fp;
	int n, i, s=sizeof(EMPLOYEE), minusone=-1, choice, flag, index, indexcopy, id;
	printf("Enter number of records:\n");
	scanf("%d", &n);
	fp= fopen("emp.txt", "w+");
	for(i=0; i<n; i++)
	{
		fwrite(&minusone, sizeof(int), 1, fp);
		fseek(fp, s-sizeof(int), SEEK_CUR);
	}
	while(1)
	{
		printf("Enter\n1. Add Record\n2. Display Records\n3. Exit\n");
		scanf("%d", &choice);
		flag=0;
		switch(choice)
		{
			case 1: 
				printf("Enter Employee number, Employee name and Salary:\n");
				scanf("%d%s%d", &E.empno, E.name, &E.sal);
				//Hash function
				index= indexcopy= (E.empno % n);
				fseek(fp, s*index, SEEK_SET);
				fread(&id, sizeof(int), 1, fp);
				//Linear Probing
				while(id!=-1)
				{
					flag=1;
					index++;
					if(index==n)
						index=0;
					if(index==indexcopy)
					{
						printf("FILE FULL!!\n");
						break;
					}
					fseek(fp, s*index, SEEK_SET);
					fread(&id, sizeof(int), 1, fp);
				}
				if(!((index==indexcopy)&&flag))
				{
					fseek(fp, s*index, SEEK_SET);
					fwrite(&E, sizeof(EMPLOYEE), 1, fp);
				}
				break;
			case 2:
				printf("Records are:\n");
				for(index=0; index<n; index++)
				{
					fseek(fp, s*index, SEEK_SET);
					fread(&E.empno, sizeof(int), 1, fp);
					printf("%d\t", E.empno);
					if(E.empno!=-1)
					{
						fread(E.name, 20, 1, fp);
						fread(&E.sal, sizeof(int), 1, fp);
						printf("%s\t%d", E.name, E.sal);
					}
					printf("\n");
				}
				break;
			case 3:
				fclose(fp);
				exit(0);
		}
	}
}