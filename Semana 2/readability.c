#include <cs50.h>
#include <stdio.h>
#include <ctype.h>                          // para usar isalpha()
#include <string.h>                         // para poder usar strlen()
#include <math.h>                           // para poder usar round

int count_letters(string text_to_count);
int count_words(string text_to_count);
int count_sentences(string text_to_count);

int main(void)
{
    string text;                                // se declara la variable texto
    do {
        text = get_string("Text: ");        // se pide el input al usuario
    }
    while (strlen(text) <= 0);               // ver que el largo de la cadena no sea menor o igual a cero
    int letters = count_letters(text);      // llama a la función que cuenta letras
    // printf("%i letters\n", letters);
    int words = count_words(text);          // llama a la función que cuenta palabras
    // printf("%i words\n", words);
    int sentences = count_sentences(text);
    // printf("%i sentences\n", sentences);
    float L = (letters * 100.0) / words;      // promedio de letras por cada 100 palabras
    // printf("L = %f\n", L);
    float S = (sentences * 100.0) / words;    // promedio de oraciones por cada 100 palabras
    // printf("S = %f\n", S);
    float index = 0.0588 * L - 0.296 * S - 15.8;    // fórmula Coleman-Liau
    // printf("index = %f\n", index);
    if (index < 1) {
        printf("Before Grade 1\n");
    }
    else if (index > 16) {
        printf("Grade 16+\n");
    }
    else {
        // printf("Grade %f\n", index);        // número decimal
        printf("Grade %i\n", (int) round(index)); // número entero
    }
}

int count_letters(string text_to_count) {
    int letters = 0;                        // cuenta letras, se debe indicar que es cero porque sino no sabe a qué sumar 1
    int length = strlen(text_to_count);     // cuenta el largo del texto
    for (int i = 0; i < length; i++) {        // bucle para que recorra el array
        if (isalpha(text_to_count[i])) {      // comprueba si es una letra
            letters++;                      // si es letra, sumar 1 a letters
        }
    }
    return letters;
}

int count_words(string text_to_count) {
    int spaces = 1;                         // cuenta espacios empezando por 1 porque siempre hay 1 palabra más que espacios
    int length = strlen(text_to_count);     // cuenta el largo del texto
    for (int i = 0; i < length; i++) {       // bucle para recorrer el array
        if (text_to_count[i] == ' ') {        // comprueba si el índice es un espacio
            spaces++;                       // si lo es, suma 1 a spaces
        }
    }
    return spaces;
}

int count_sentences(string text_to_count) {
    int sentences = 0;                          // cuenta oraciones
    int length = strlen(text_to_count);
    for (int i = 0; i < length; i++) {
        if (text_to_count[i] == '.' || text_to_count[i] == '!' || text_to_count[i] == '?') {
            sentences++;
        }
    }
    return sentences;
}


// ✓ // Pedir input
// ✓ // Función que cuente el número de letras (mayus y minus)
// ✓ // Función que cuente el número de palabras (espacios)
// ✓ // Función que cuente el número de frases (. ! ?)
// ✓ // ¿Operar con esos números?
// ✓ // Meterlos en la fórmula y redondear siempre al alza
// ✓ // Si es menor que 1, "Before Grade 1"
// ✓ // Si es 16 o mayor, "Grade 16+"

// index = 0.0588 * L - 0.296 * S - 15.8
// L es el promedio de letras por cada 100 palabras de texto y S el promedio
// de frases por cada 100 palabras.

// variables: letters, words y sentences