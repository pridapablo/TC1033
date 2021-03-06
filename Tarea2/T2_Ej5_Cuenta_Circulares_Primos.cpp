// Nota: Realizado por Pablo Banzo, con apoyo colaborativo (no copia) de Pablo Bolio, Arantza, Shaul, Sabrina y Oswaldo. 

// Programa que imprime cuántos números circulares primos hay debajo de 1000000 

//nota: no tiene sentido usar apuntadores a x en este programa dado que se modifica su valor (y el cout final requiere el valor inicial de x)


#include <iostream>
#include <math.h>

bool isPrime(int number)
{
    if ((number == 0) || (number == 1))
    {
        return false;
    }
    else if (number == 2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i < (number); ++i) 
        {
            if ((number % i) == 0)
            {
                return false;
                continue;
            }
        }
        return true;
    }
}
int countDigits(int number)
{
    int numberOfDigits = 0;
    while (number > 0)
    {
        numberOfDigits++;
        number/=10;
    }
    return numberOfDigits;
}
bool isCircularPrime(int number)
{
    if (isPrime(number) == false)
    {
        // std::cout << number << " no es circular primo. \n";
        return false;
    }
    else
    {
        int expo = countDigits(number)-1;
        int countCircularPrimes = 0;
        for (int i=0; i < countDigits(number); i++)
        {
            int lastDigit = number%10;
            number /= 10;
            int base = pow(10,expo)*lastDigit;
            number += base;
            if (isPrime(number) == true) 
            {
            countCircularPrimes++; 
            }
        }
        if (countCircularPrimes == countDigits(number)) //Todas las rotaciones son primas
        {
            //std::cout << number << " es circular primo. \n";
            return true;
        }
        else 
        {
            //std::cout << number << " no es circular primo. \n";
            return false;
        }
    }
}
int circularPrimesInRange(int min, int max)
{
    int counter = 0;
    for(int i = min; i <= max; i++)
    {
        if (isCircularPrime(i) == true)
        {
            counter++;
        }
    }
    std::cout << "En el rango " << min << "-" <<max << " hay " << counter << " números circulares primos. \n";
    return counter;
}

int main ()
{
    int min = 0;
    int max = 100;
    return circularPrimesInRange(min, max);
}
