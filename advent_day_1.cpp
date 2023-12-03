//
// Created by vincent on 03/12/23.
//
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include "advent_day_1.h"

//The aim of day one is to take a random string input of many lines
//Breaking on new each line, identify the numbers in the string
//Then add those numbers and return the total sum
int StartDay1(char* fileName) {
    FILE *fptr;
    fptr = fopen(fileName, "r");
    char myString[100];
    int totalSumOfFile = 0;
    while(fgets(myString, 100, fptr)){
        //printf("%s", myString);
        char lineSum = ScanLineForNumber(myString);
        printf("%i\n", lineSum);
        totalSumOfFile += lineSum;

    }
    fclose(fptr);
    return totalSumOfFile;
}

//Will return the first and second digits combined int one number
int ScanLineForNumber(char* inputLine){
    char finalNumber;
    char startNumber = '0';
    char *t;
    for(t = inputLine; *t != '\0'; t++){
        if (*t >= '0' && *t <= '9'){
            finalNumber = *t;
            if(startNumber == '0'){
                startNumber = *t;
            }
        }
    }
    char returnValue[] = { startNumber, finalNumber};
    //printf("%s", returnValue[0]);
    return atoi(returnValue);
}