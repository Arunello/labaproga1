
#include <clocale>
#include <iostream>
#include <ostream>
int main() 
{
    setlocale(0, "");
/*

5) Реализовать возможность произвольного изменения любого бита в введенном числе (для всех типов данных) с использованием логических операций.

*/


// 1


{
    std::cout << "Задание 1\n\n";
    std::cout << "int: " << sizeof(int) << "\nshort int: " << sizeof(short int) << "\nlong int: " <<  sizeof(long int) << "\nfloat: " << sizeof(float) << "\ndouble: " <<  sizeof(double) << "\nlong double: " << sizeof(long double) << "\nchar: " << sizeof(char) << "\nbool: " << sizeof(bool);
}


std::cout << "\n\nЗадание 2\n\n";


{
    
    std::cout << "Введите целое число\n";

    int value;
    std::cin >> value;
	unsigned int order = (sizeof(int)*8);
	unsigned int mask = 1 << (order - 1);

    std::cout << value << " = ";

	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		value <<= 1;

		if (i % 8 == 0 || i % order - 1 == 0)
		{
			putchar(' ');
		}
	}
}


std::cout << "\n\nЗадание 3\n\n";


{
union FloatUnion {
    float f;
    int u;
};


    std::cout << "Введите число типа float\n";

    FloatUnion fu;
    std::cin >> fu.f;
    int order = (sizeof(float)*8);
    unsigned int mask = 1 << (order - 1);

    std::cout << fu.f << " = ";

    for (int i = 1; i <= order; i++) 
    {
        putchar(fu.u & mask ? '1' : '0');
        fu.u <<= 1;

        if (i == 1 || i == 9) putchar(' ');
    }
}


std::cout << "\n\nЗадание 4\n\n";


{
union DoubleUnion {
    double d;
    unsigned long int u;
};


    std::cout << "Введите число типа double\n";

    DoubleUnion du;
    std::cin >> du.d;

    int order = (sizeof(double)*8);
    unsigned long int mask = 1ULL << (order - 1);

    std::cout << du.d << " = ";

    for (int i = 1; i <= order; i++) 
    {
        putchar(du.u & mask ? '1' : '0');
        mask >>= 1;

        if (i == 1 || i == 12) putchar(' ');
    }
}


std::cout << "\n\nЗадание 5\n\n";


{
    

    union DoubleIntUnion {
    double d;
    long int u;
    };

    std::cout << "Выберите тип вводимого числа:\n1. Целое\n2. Дробное\n";
    
    int TypeChoice;
    std::cin >> TypeChoice;

    DoubleIntUnion diu;

    if (TypeChoice == 1) 
    {
        std::cout << "Введите целое число\n";
        std::cin >> diu.u;

        int order = (sizeof(long int)*8);
	    unsigned long int mask = 1ULL << (order - 1);

        std::cout << diu.u << " = ";

	    for (int i = 1; i <= order; i++)
	    {
		    putchar(diu.u & mask ? '1' : '0');

		    mask >>= 1;

		    if (i % 8 == 0 || i % order - 1 == 0)
		    {
			putchar(' ');
		    }
	    }

        std::cout << "\n\nКакой бит изменить? (считая справа)\n";
        
        int BitChoice;
        std::cin >> BitChoice;

        mask = 1;

        diu.u = diu.u ^ (mask << BitChoice);

        std::cout << diu.u << " = ";

        mask = 1ULL << (order - 1);

	    for (int i = 1; i <= order; i++)
	    {
		    putchar(diu.u & mask ? '1' : '0');

		    mask >>= 1;

		    if (i % 8 == 0 || i % order - 1 == 0)
		    {
			putchar(' ');
		    }
	    }
    }

    if (TypeChoice == 2) 
    {
        std::cout << "Введите дробное число\n";
        std::cin >> diu.d;

        int order = (sizeof(double)*8);
        unsigned long int mask = 1ULL << (order - 1);

        std::cout << diu.d << " = ";

        for (int i = 1; i <= order; i++) 
        {
            putchar(diu.u & mask ? '1' : '0');
            mask >>= 1;

            if (i == 1 || i == 12) putchar(' ');
        }

        std::cout << "\nКакой бит изменить? (считая справа)\n";
        
        int BitChoice;
        std::cin >> BitChoice;

        mask = 1;

        diu.u = diu.u ^ (mask << BitChoice);

        std::cout << diu.d << " = ";

        mask = 1ULL << (order - 1);

	    for (int i = 1; i <= order; i++)
	    {
		    putchar(diu.u & mask ? '1' : '0');

		    mask >>= 1;

		    if (i == 1 || i == 12)
		    {
			putchar(' ');
		    }
	    }
    }
    std::cout << "\n";
    return 0;
}
}
