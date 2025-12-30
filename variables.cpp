// librerias
#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;

    // variables

    // de tipo textos
    char letter = 'S';
    string text = "This is a sample text."; // esto viene de la libreria std

    // de tipo numericos
    int year = 2026;
    double pi = 3.14159;
    float temperature = 36.6f;
    int64_t population = 7800000000LL;
    long long poblacion_mundial = 7800000000LL;
    unsigned int positive_number = 42;            // solo positivos
    short small_number = 32767;                   // numeros pequeños
    unsigned short small_positive_number = 63535; // solo positivos y pequeños

    // booleanos y otros tipos
    bool is_valid = true;
    size_t size = 1024; // tipo especial para tamaños

    std::cout << "Variable 'year':" << std::endl;
    std::cout << " - Valor: " << year << std::endl;
    std::cout << " - Direccion de memoria: " << &year << std::endl;
    std::cout << " - Tamaño: " << sizeof(year) << " bytes" << std::endl;

    std::cout << "\nVariable 'poblacion':" << std::endl;
    std::cout << " - Valor: " << poblacion_mundial << std::endl;
    std::cout << " - Direccion de memoria: " << &poblacion_mundial << std::endl;
    std::cout << " - Tamaño: " << sizeof(poblacion_mundial) << " bytes" << std::endl;

    cout << "\nDiferencias de unsigned y signed:" << std::endl;
    cout << " - Valor de small_positive_number (unsigned short): " << small_positive_number << std::endl;
    cout << " - Tamaño de small_positive_number: " << sizeof(small_positive_number) << " bytes" << std::endl;
    cout << " - Valor de small_number (short signed[que por defecto no es necesario asignarlo]): " << small_number << std::endl;
    cout << " - Tamaño de small_number: " << sizeof(small_number) << " bytes" << std::endl;
    cout << "\nNota: Ambos tipos ocupan el mismo tamaño en memoria, pero el rango de valores que pueden almacenar es diferente." << std::endl;
    cout << "\nEn si estás 2 se diferencia entre que si es signed, el valor esta entre negavito a positivo sea que un short normalmente\n"
         << endl;
    cout << "es de -32768 a 32767 y con unsigned solo recibe positivos que seria de 0 a 65535\n"
         << endl;

    cout << "\nResumen de todas las variables:" << endl;

    cout << "Year: " << year << endl;
    cout << "Value of pi: " << pi << endl;

    cout << "Letter: " << letter << endl;
    cout << "Is valid: " << is_valid << endl;
    cout << "Temperature: " << temperature << endl;
    cout << "Text: " << text << endl;
    cout << "Population: " << population << endl;
    cout << "Positive number: " << positive_number << endl;
    cout << "Size: " << size << endl;

    return 0;
}