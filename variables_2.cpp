#include <iostream>
#include <cstdint>

using namespace std;

struct Usuario
{
    uint16_t id;    // 2 bytes
    uint8_t edad;   // 1 byte
    uint8_t acceso; // 1 byte
    float saldo;    // 4 bytes
};

int main()
{
    Usuario emp1 = {54000, 30, 3, 1250.75f};

    Usuario *ptr = &emp1;

    std::cout << "--- Datos del Empleado ---" << std::endl;
    std::cout << "Direccion base en RAM: " << ptr << std::endl;
    std::cout << "ID: " << ptr->id << " (Direccion: " << &ptr->id << ")" << std::endl;
    std::cout << "Edad: " << (int)ptr->edad << " (Direccion: " << (void *)&ptr->edad << ")" << std::endl;
    std::cout << "Saldo: " << ptr->saldo << " (Direccion: " << &ptr->saldo << ")" << std::endl;

    cout << "\nTamaño de usuario antes de cambiar un valor " << sizeof(Usuario) << std::endl;
    float *ptr_saldo = &emp1.saldo;
    *ptr_saldo = 2000.0f;

    std::cout << "\nNuevo saldo modificado por puntero: " << emp1.saldo << std::endl;
    cout << "Tamaño de usuario despues de cambiar un valor " << sizeof(Usuario) << std::endl;

    return 0;
}