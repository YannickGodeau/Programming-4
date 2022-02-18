// VLDCheck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vld.h>
#include <vector>
int main()
{
	int* vldCheck = new int{ 1 };

	// program finishes with 1 memory leaks
	// 4 bytes on x86
	// 4 bytes on x64
	// vld ends on 40 bytes in x86
	// vld ends on 56 bytes in x64

}

