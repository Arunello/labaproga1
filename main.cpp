
#include <clocale>
#include <iostream>
#include <ostream>
int main() 
{
    setlocale(0, "");
{
    //17 Создание бесконечности. Установите все биты порядка в 1, а все биты мантиссы — в 0. Знаковый бит оставьте без изменения. Вы получите +inf или -inf.
    union FloatUnion 
    {
    float f;
    unsigned int u;
    };

    std::cout << "ИДЗ\n\nВведите число\n";

	unsigned int inf = 0b1111111100000000000000000000000;
    unsigned int mask = 0b1111111111111111111111111111111;
    FloatUnion value;

    std::cin >> value.f;

    value.u = (value.u & ~mask) | (inf & mask);

    std::cout << "Бесконечность: "<< value.f;
}


std::cout << "\n\nЗадание 1\n\n";


{
    
    std::cout 
    << "int: " << sizeof(int)
    << "\nshort int: " << sizeof(short int) 
    << "\nlong int: " <<  sizeof(long int) 
    << "\nfloat: " << sizeof(float) 
    << "\ndouble: " <<  sizeof(double) 
    << "\nlong double: " << sizeof(long double) 
    << "\nchar: " << sizeof(char) 
    << "\nbool: " << sizeof(bool);
}


std::cout << "\n\nЗадание 2\n\n";


{
    
    std::cout << "Введите целое число\n";

    int value;
    std::cin >> value;

	int order = (sizeof(int) * 8);
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
union FloatUnion 
{
    float f;
    unsigned int u;
};


    std::cout << "Введите число типа float\n";

    FloatUnion fu;
    std::cin >> fu.f;

    int order = (sizeof(float) * 8);
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
union DoubleUnion 
{
    double d;
    unsigned long long u;
};


    std::cout << "Введите число типа double\n";

    DoubleUnion du;
    std::cin >> du.d;

    int order = (sizeof(double) * 8);
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
    

    union DoubleIntUnion 
    {
    double d;
    unsigned long long u;
    };

    std::cout << "Выберите тип вводимого числа:\n1. Целое\n2. Дробное\n";
    
    int TypeChoice;
    std::cin >> TypeChoice;

    DoubleIntUnion diu;

    if (TypeChoice == 1) 
    {
        std::cout << "Введите целое число\n";
        std::cin >> diu.u;

        int order = (sizeof(long int) * 8);
	    unsigned long long mask = 1ULL << (order - 1);

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

        int order = (sizeof(double) * 8);
        unsigned long long mask = 1ULL << (order - 1);

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
