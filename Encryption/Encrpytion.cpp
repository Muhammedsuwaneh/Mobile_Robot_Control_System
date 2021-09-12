/**
 * @file Encrpytion.cpp
 * @Author Yakupcan ERGEN,Alperen BÝÞKÝN,Muhammed SUWANEH,Halil Kadirhan KUBAT
 * @date December, 2020
 * @brief This  class is responsible for encrpytion and decrpytion.
 */
#include "Encrpytion.h"
#include<math.h>
#include<iostream>
#include<string>
#define size 4
using namespace std;
/**
 *encrpyt do encrpytcode
 *@param code is an integer argument.
 *@returns encrpyted code value.
 */
int Encrpytion::encrypt(int code)
{
	if((int)(code / pow(10, size - 1)) == 0)
	{
		return -1;
	}
	else
	{
		int arr[size];
		int i = size - 1;
		while (code != 0)
		{
			arr[i] = (code % 10) - 3;
			if (arr[i] < 0)
				arr[i] += 10;
			i--;
			code /= 10;
		}
		int temp = arr[0];
		arr[0] = arr[2];
		arr[2] = temp;
		temp = arr[1];
		arr[1] = arr[3];
		arr[3] = temp;
		int result = 0;
		for (int i = 0; i < 4; i++)
		{
			result += arr[i] * pow(10, size - (i + 1));
		}
		return result;
	}
}
/**
 *dencrpyt do decrpytcode operation
 *@param code is an integer argument.
 *@returns decrpyted code value.
 */
int Encrpytion::decrypt(int code)//7087
{
	int i,j=0;
	int arr[size];
	i = size - 1;
	while((int)(code /pow(10, size-(j+1))) == 0)
	{
		arr[j] = 3;
		j++;
	}
	while (code != 0)
	{
		arr[i] = (code % 10) + 3;
		if (arr[i] >= 10)
			arr[i] -= 10;
		i--;
		code /= 10;
	}
	int result = 0;
	int temp = arr[0];
	arr[0] = arr[2];
	arr[2] = temp;
	temp = arr[1];
	arr[1] = arr[3];
	arr[3] = temp;
	for (int i = 0; i < 4; i++)
	{
		result += arr[i] * pow(10, size - (i + 1));
	}
	return result;
}
