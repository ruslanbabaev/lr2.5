#include <stdio.h>
#include <stdlib.h>

int change_num(int *mas, int *mas_min, int *mas_max) {
    int l_max = 0, l_min = 0;

    for (int i = 0; i < 10; i++) {
        if ((mas[i] == *mas_min) && (l_max == 0)) {
            mas[i] = *mas_max;
            l_max = 1;
        }
        else if ((mas[i] == *mas_max) && (l_min == 0)) {
            mas[i] = *mas_min;
            l_min= 1;
        }
    }
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


int main() {
    
    int a, b;
    
    printf("Введите нижнюю границу диапазона: ");
    scanf("%d", &a);
    printf("Введите верхнюю границу диапазона: ");
    scanf("%d", &b);
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
        for (int i = 0; i < 10; i++) {
            if (mas[i] < mas_min)
                mas_min = mas[i];
            if (mas[i] > mas_max)
                mas_max = mas[i];
        }
        change_num(mas, &mas_min, &mas_max);
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
