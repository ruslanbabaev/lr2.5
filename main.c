#include <stdio.h>
#include <stdlib.h>

void change_num(void);

int *new_mas(int*);

int main(int) {
    
    int a, b;
    
    printf("Введите нижнюю границу диапазона: ");
    if ((scanf("%d",&a) ) != 1 ) {
            printf("Неверное введенное значение\n");
            return 1;
        }

    printf("Введите верхнюю границу диапазона: ");
    if ((scanf("%d",&b) ) != 1 ){
            printf("Неверное введенное значение\n");
            return 1;
        }
    
    if (a>b) {
        int a_new = a;
        a = b;
        b = a_new;
    }
    
    while(getchar() != '\n');
    char flag;
    printf("Введите флаг. '-a' - поменять местами макс и мин э-т массива. '-b' - создать новый массив, который содержит уникальные элементы исходного:\n");
    scanf("-%c", &flag);
    
    //Создадим массив из псевдослучайных чисел. Пусть, размер его будет 10
    int mas[10];
    for (int i = 0; i < 10; i++) {
        mas[i] = a + rand()%(b-a+1);
        printf("%d ", mas[i]);
    }
    printf("\n");
    
    if (flag == 'a') {
        //найдем минимальный и максимальный элемент
        int mas_max = a, mas_min = b;
        int adr_mas_max = 0, adr_mas_min = 0;
        for (int i = 0; i < 10; i++) {
            if (mas[i] < mas_min) {
                mas_min = mas[i];
                adr_mas_min = i;
            }
            if (mas[i] > mas_max) {
                mas_max = mas[i];
                adr_mas_max = i;
            }
        }
        change_num(mas, adr_mas_min, adr_mas_max);
        for (int i=0; i<10; i++) {
            printf("%d ", mas[i]);
        }
    }
    
    if (flag == 'b') {
        new_mas(mas);
        for (int i = 1; i <= mas[0]; i++)
            printf("%d ", mas[i]);
        
    }
    return 0;
}



int change_num(int *mas, int adr_mas_min, int adr_mas_max) {
        
    int a = mas[adr_mas_min];
    
    mas[adr_mas_min] = mas[adr_mas_max];
        
    mas[adr_mas_max] = a;

    return *mas;
}




int *new_mas(int *mas) {
    int old_mas[10];
    for (int i=0; i<10; i++) {
        old_mas[i] = mas[i];
    }
    //отсортируем массив и посчитаем количество уникальных символов
    for (int i = 9; i >= 1; i--)
            for (int j = 0; j < i; j++)
            {
                if (old_mas[j] > old_mas[j + 1])
                {
                    int foo = old_mas[j];
                    old_mas[j] = old_mas[j + 1];
                    old_mas[j + 1] = foo;
                }
            }
    int new_mas[12];
    new_mas[1] = old_mas[0];
    int k = 1;
    
    //формируем новый массив из уникальных символов
    for (int i = 1; i < 10; i++) {
        if (old_mas[i] != old_mas[i-1]) {
            new_mas[k+1] = old_mas[i];
            k++;
        }
    }
    
    new_mas[0] = k; //количество уникальных символов помещаем в первый элемент массива
    
    //в цикле проходим по старому массиву и берем оттуда только уникальные символы
    int result[k+1];
    result[0] = k;
    int l = 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= k; j++) {
            if (mas[i] == new_mas[j]) {
                result[l] = mas[i];
                new_mas[j] = 0.1;
                l++;
            }
        }
    }
    mas[0] = k;
    for (int i=1; i<=k; i++) {
        mas[i] = result[i];
    }
    return result;
}
