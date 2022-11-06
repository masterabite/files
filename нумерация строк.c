#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    
    FILE* fin = fopen("text.txt", "r");     //открываем файл для считывания 
    FILE* fout = fopen("out.txt", "w");     //открываем/создаем новый файл для записи

    if (fin == NULL || fout == NULL) {      //если какой-то из файлов не удалось открыть
        printf("Не удалось открыть файл.\n");
    }
    else {
        char temp = '-';      //символ буфер, для записи текста
        int page = 1;   //номер страницы

        while (!feof(fin)) {
            //в начале каждой строки записываем ее номер
            fprintf(fout, "%d ", page);

            //далее копируем символы из первого текста до конца строки или конца файла
            while (temp != '\n' || temp != '\0' || temp != '\0') { 
                fscanf(fin, "%c", &temp);
                fprintf(fout, "%c", &temp);
            }
            if (temp == '\n') {
                fprintf(fout, "\n"); //если строка закончилась записываем символ перехода строки
            }
            else {
                break; //если это конец файла
            }
        }

        //закрываем файлы
        fclose(fin);
        fclose(fout); 
    }
    return 0;
}
