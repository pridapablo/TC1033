/* Programa que indica si un valor X es un número circular primo. Los números circulares 
primos son aquellos que son números primos y que todas las rotaciones de dicho número 
también son primos. Ej. El número 197 es circular primo pq es primo y su primera rotación 
971 también es primo y su segunda rotación 719 también es primo. */

#include <iostream>

bool es_circular_primo(int *num)
{
    ;
}

int main ()
{
    int x = 197;

    if (es_circular_primo(&x))
    {
        return 1;
        std::cout << "El número " << x << " es circular primo";
    }

    else 
    {
        return 0;
        std::cout << "El número " << x << " no es circular primo";
    }
}
