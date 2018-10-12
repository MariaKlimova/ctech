#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <unistd.h> 

//присвоение ошибкам номеров

#define a_is_wrong 1                            //некорректный коэффициент а
#define b_is_wrong 2                            //некорректный коэффициент b
#define c_is_wrong 3                            //некорректный коэффициент с
#define one_root_exists_but_none_found 4        //существует один действительный корень, но он не найден
#define two_roots_exist_but_none_found 5        //существует два действительных корня, но они не найдены
#define two_roots_exist_but_only_one_found 6    //существует два действительных корня, но найден только один
#define wrong_amount_of_roots 7                 //некорректное количество корней
/*
#define ERROR(a) printf("hello! %d", \
a);
*/
float discriminant( float a, float b, float c){ //функция вычисляет дискриминант
    float disc;
    disc = b*b-4*a*c;
    return disc;
}

int linearSolver(float b, float c, float *px1){ //функция решает квадратное уравнение
    int amount_of_roots = -1;                       
    if (isnan(b)){                                //проверка корректности коэффициента b
        printf("Error %d coefficient b is not appropriate\n", b_is_wrong);//вывод сообщения о том, что коэффициент b некорректен
        assert (!isnan(b));
    }
    if (isnan(c)){                                //проверка корректности коэффициента с
        printf("Error %d coefficient c is not appropriate\n", c_is_wrong);//вывод сообщения о том, что коэффициент с некорректен
        assert(!isnan(c));
    };

    if ((b == 0) && (c==0)){//случай 0х=0. уравнение имеет бесконечное количество корней
        amount_of_roots = 3;
    }
    else if ((b == 0) && (c != 0)){//случай 0х=с, с не равно 0. уравнение не имеет корней
        amount_of_roots = 0;
    }
    else{//случай линейного уравнения с ненулевыми коэффициентами, уравнение имеет один корень
        amount_of_roots = 1;
        *px1 = c/b;
    }
    return amount_of_roots;
}

int quadraticSolver(float a, float b, float c,float *px1, float *px2){ //решение квадратного уравнения
    if (isnan(a)){                                //проверка корректности коэффициента а
        printf("Error %d: coefficient a is not appropriate\n", a_is_wrong);//вывод сообщения о том, что коэффициент а некорректен
        assert(!isnan(a));
    }
    if (isnan(b)){                                //проверка корректности коэффициента b
        printf("Error %d: coefficient b is not appropriate\n", b_is_wrong);//вывод сообщения о том, что коэффициент b некорректен
        assert(!isnan(b));
    }
    if (isnan(c)){                                //проверка корректности коэффициента с
        printf("Error %d: coefficient c is not appropriate\n", c_is_wrong);//вывод сообщения о том, что коэффициент с некорректен
        assert(!isnan(c));
    };

    float disc; //дискриминант
    int amount_of_roots = -1;
    switch ((int) (a == 0)){
        case 1: //случай, когда уравнение линейное
            printf("the equation is linear. Solving\n");//вывод сообщения о том, что уравнение линейное
            sleep(1);
            amount_of_roots = linearSolver(b,c, px1);break; //вызов функции, которая решает линейные уравнения
        default: //случай, когда уравнение нелинейно
            disc = discriminant(a,b,c);  //вычисление дискриминанта
            //printf("Discriminant is: %f\n", disc); //вывод дискриминанта
            if (disc < 0){
                amount_of_roots = 0; //дискриминант меньше нуля, уравнение не имеет действительных корней
            }
            else if (disc == 0) { //дискриминант равен нулю, уравнение имеет один действительный корень
                *px1 = ((-b/(2*a)));//вычисление корня
                 amount_of_roots = 1;
            }
            else{//дискриминант больше нуля, уравнение имеет два действительных корня
                amount_of_roots = 2;
                double square_root_of_disc;
                square_root_of_disc = sqrt((double) disc);  //вычисление корня из дискриминанта

                *px1 = ((-b - square_root_of_disc)/(2*a));  //вычисление первого корня
                *px2 = ((-b + square_root_of_disc)/(2*a));  //вычисление второго корня
            }break;
    }
    return amount_of_roots;
}


int main(){
    printf("quadratic equations solver\n");//вывод заголовка 
    float a,b,c,x1,x2;//a,b,c-коэффициенты в уравнении вида ax^2+bx+c=0, x1 и х2- корни
    a = NAN;
    b = NAN;
    c = NAN;
    x1 = NAN;
    x2 = NAN;
    printf("Enter coefficients a,b and c in quadratic equation having the form ax^2+bx+c=0\n");//вывод указания ввести коэффициенты
    scanf("%f %f %f", &a, &b, &c);//ввод коэффициентов
    if (isnan(a)){                                //проверка корректности коэффициента а
        printf("Error %d: coefficient a is not appropriate\n", a_is_wrong);//вывод сообщения о том, что коэффициент а некорректен 
        assert(!isnan(a));
    }   
    if (isnan(b)){                                //проверка корректности коэффициента b
        printf("Error %d: coefficient b is not appropriate\n", b_is_wrong);//вывод сообщения о том, что коэффициент b некорректен
        assert(!isnan(b));
    }
    if (isnan(c)){                                //проверка корректности коэффициента с
        printf("Error %d: coefficient c is not appropriate\n", c_is_wrong);//вывод сообщения о том, что коэффициент с некорректен
        assert(!isnan(c));
    };
    printf("coefficents are accepted. solving in process\n");//вывод сообщения о корректности введенных коэффициентов
    sleep(1);
    int amount_of_roots;
    amount_of_roots = -1;
    amount_of_roots = quadraticSolver(a, b, c, &x1, &x2); //решение уравнения
    if ((amount_of_roots == 1) && (x1 == NAN)){ //проверка того, что если у уравнения один действительный корень, то он найден
        printf("Error %d: there is one real root, but none of the roots are found\n", one_root_exists_but_none_found);//вывод сообщения о том, что уравнения один кореень, но он не найден
        assert(((amount_of_roots) == 1) && ((x2 != NAN) || (x1 !=NAN)) );
    }
    else if ((amount_of_roots == 2) && ((x2 == NAN) || (x1 == NAN))){//проверка того, что если у уравнения два действительных корня, то оба найдены
        if ((x1 == NAN) && (x2 == NAN)){//случай, когда существует два действиных корня, но ни один не найден
        printf("Error %d: there are two real roots, but none of them found\n", two_roots_exist_but_none_found);//вывод сообщения о том, что существует два действительных корня, но ни один не найден
        assert(((amount_of_roots) == 2) && (x2 != NAN) && (x1 != NAN));
        }
        else{  //случай, когда существует два действительных корня, но только один найден
            printf("Error %d: there are two real roots, but none of them found\n", two_roots_exist_but_none_found);//вывод сообщения о том, что существует два корня, но найден только один из них
            assert(((amount_of_roots) == 2) &&((x2 != NAN) || (x1 !=NAN)) );
        }
    }
    switch (amount_of_roots) {
        case 0:
            printf ("no real roots\n");break; //вывод сообщения о том, что корней нет
        case 1:
            printf ("there is only one real root\n x=%f\n", x1);break; //вывод сообщения о том, что есть только один корень и вывод корня
        case 2:
            printf ("there are two real roots.\n x1=%f , x2=%f\n", x1, x2);break; //вывод сообщения о том, что существует два корня и вывод корней
        case 3:
            printf ("there is infinite number of roots\n");break;//вывод сообщения о том, что уравнение имеет бесконечное количество корней
        default:
            printf ("Error %d: wrong amount of roots %d\n", wrong_amount_of_roots, amount_of_roots);//вывод сообщения о том,  что количество корней некорректно
            assert((amount_of_roots >= 0) && (amount_of_roots <= 3));break;       //проверка корректности числа корней
    }
}
