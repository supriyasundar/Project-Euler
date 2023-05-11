/**
*Author: Supriya Sundar
*Class: ECE 6122
*Last Date Modified: 22/09/2021
*Description: Determination of prime factors of a number was done sucessfully
**/
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<math.h>
#include<string>
using namespace std;
bool GetPrimeFactors(unsigned long, string&);
int main( int argc, char* argv[])
{
    ofstream file;
    unsigned long number;
    number=atoi(argv[1]); //accessing element in index 1 for input since index 0 contains name of program
    string output;
    bool checknumber=GetPrimeFactors(number,output); // function to find prime factors 
    file.open("output1.txt",ios::out | ios::trunc); //opening file and overwriting exisiting text
    if(checknumber == false)
    {
        file<<"No prime factors";
    }
    else 
    {
        file<<output;
    }
    file.close();
    return 0;
}
bool GetPrimeFactors(const unsigned long ulInputNumber,string &strOutput)
{
    unsigned long num=ulInputNumber;
    int counter=0;
    if(num>1) // checking for prime factors of positive number only
    {
        while(num%2==0)
        {
            counter++; //loop to check if it is even prime factor
            num/=2;
        }
        if(counter>0)
        {
            strOutput += std::to_string(2) + ","; //2 is the only even prime factor
        }
        for(unsigned long i=3; i<=(unsigned long)sqrt(num);i+=2)
        {
            while(num%i==0)
            {
                counter++; //loop to check for odd prime factors
                num/=i;
            }

            if(counter>0)
            {
                strOutput += std::to_string(i) + ",";
            }
        }
        if(num>2)
        {
            strOutput += std::to_string(num); // condition to check for input numbers which are prime by itself
	    counter++;
        }       
        if(counter>0)
        {
            return true; //non zero counter value indicates prime number
        }
        else 
        {
            return false;
        }
    }
    else 
    {
        strOutput="No prime factors"; //if number is zero or negative, it doesn't have prime factors
    }
}

