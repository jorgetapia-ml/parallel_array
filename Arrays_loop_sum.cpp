// Arrays_loop_sum.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//compute the sum of two arrays in parallel 
#include < stdio.h >
#include <stdlib.h>
#include < omp.h >

#define N 10
#define chunk 5
#define show 10
int main(void) {
    float array_1[N], array_2[N], array_result[N];
    int tid;
    int i;
    omp_set_num_threads(2);
    /* Initialize arrays array_1 and array_2 */
    for (i = 0; i < N; i++) {
        array_1[i] = rand();
        array_2[i] = rand();
    }
    int pedazos = chunk;
    /* Compute values of array array_result = array_1+array_2 in parallel. */
#pragma omp parallel for shared(array_1, array_2, array_result, pedazos ) private(i) schedule(static, pedazos)
    
    for (i = 0; i < N; i++) {
        tid = omp_get_thread_num();
        array_result[i] = array_1[i] + array_2[i];
        if (i < show)
            printf("This result was calculated with thread number %d - Id of array result %d - value of sum  %f\n", tid ,i , array_result[i]);

    }
    
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya array_1 Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o array_1 Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver array_1 abrir este proyecto, vaya array_1 Archivo > Abrir > Proyecto y seleccione el archivo .sln
