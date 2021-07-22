#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include<stdlib.h>
#include <netinet/in.h>

using namespace std;

uint32_t ModifyStringToHex(char *BIN);


int main()
{
	FILE* file1 = fopen("thousand.bin", "rb");
	FILE* file2 = fopen("five-hundred.bin", "rb");
	if (file1 == NULL)
	{
		printf("There is no thousand.bin. Exit process.");
		return 0;
	}
	char bins1[21];
	fgets(bins1, 21, file1);
	fclose(file1);
	uint32_t f1_v = ModifyStringToHex(bins1);

	if (file2 == NULL)
	{
		printf("There is no five-hundred.bin. Exit process.");
		return 0;
	}
	char bins2[21];
	fgets(bins2, 21, file2);
	fclose(file2);
	uint32_t f2_v = ModifyStringToHex(bins2);

	printf("%d(%02x) + %d(%02x) = %d(%02x)", f1_v, f1_v, f2_v, f2_v, f1_v + f2_v, f1_v + f2_v);
	return 0;
}

/*Change the given string into hex
Then, change NBO to HBO
return the result*/
/*Because the input file is written in NBO, there is a possibility that
the sequence of number is not matched with HBO.*/
/*That's why I changed the byte order of 32bit number a into HBO.*/
uint32_t ModifyStringToHex(char *BIN)
{
	string s(BIN);
	s.erase(std::remove(s.begin(), s.end(), '\\'), s.end());
	uint32_t a = strtoll(BIN, NULL, 16);

	a=ntohl(a); 

	return a;
}