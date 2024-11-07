#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** load_lines(const char* filename){
    FILE* fn = fopen(filename, "r");
    
    // посчитать количество строк
    int lines_count = 0;
    while (1){
        int sym = fgetc (fn);
        
        //Проверка на конец файла или ошибку чтения
        if (sym == EOF)
        {
            break;
        }
        else if (sym == 10){
            lines_count += 1;
        }
    }
    lines_count += 1;

    //создаем сам массив
    char** spisok = (char**)malloc(sizeof(char*) * (lines_count + 1));
    
    // возвращаюсь в начало масива
    fseek(fn, 0, SEEK_SET);

    // прохожусь по массиву повторно
    int* dliny = (int*)malloc(sizeof(int) * (lines_count));
    int len = 0;
    int shift = 0;

    while (1){
        int sym = fgetc(fn);

        //Проверка на конец файла или ошибку чтения
        if (sym == EOF)
        {
            break;
        }
        else if (sym == 10){
            dliny[shift] = len;
            len = 0;
            shift += 1;
        }
        else{
            len += 1;
        }
    }
    dliny[shift] = len;


    //выделяем память
    for (int j = 0; j < lines_count; ++j){
        spisok[j] = (char*)malloc(sizeof(char) * (dliny[j] + 1));
    }
    spisok[lines_count] = NULL;

    // возвращаюсь в начало масива
    fseek(fn, 0, SEEK_SET);

    //проходимся в третий раз по массиву
    for (int k = 0; k < lines_count; ++k){
        for (int r = 0; r < dliny[k]; ++r){
            spisok[k][r] = (char)fgetc(fn);
        }
        spisok[k][dliny[k]] = '\0';
        int temp = fgetc(fn); // считывание символа переноса строки
    }

    //освобождаем память от временного массива
    free(dliny);

    //закрываем файл
    fclose(fn);
    //возвращаем массив
    return spisok;
    }

void destroy_strings(char*** p_strings_array){
    int t = 0;
    while ((*p_strings_array)[t] != NULL){
        free((*p_strings_array)[t]);
        t += 1;
    }
    
    free(*p_strings_array);
    (*p_strings_array) = NULL;

}

void sort_strings(char** words) {

    int t = 0;
    while (words[t] != NULL) {
        t += 1;
    }

    for (int i = 0; i < t - 1; ++i) { 
        for (int j = 0; j < t - i - 1; ++j) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char *temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    const char* input_file = argv[1];
    const char* output_file = argv[2];

    char** arr = load_lines(input_file);
    sort_strings(arr);

    FILE* outfile = fopen(output_file, "w");
    int s = 0;
    while (arr[s] != NULL){
        s += 1;
    }


    for (int i = 0; i < s; i++) {
        fputs(arr[i], outfile);
    }

    fclose(outfile);
    destroy_strings(&arr);
}