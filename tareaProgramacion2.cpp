#include <iostream>
#include <cmath>

// Definicion de la estructura Dot
struct Dot {
    float x, y, z;

    Dot(float x, float y, float z) : x(x), y(y), z(z) {}

    // Constructor para 2D
    Dot(float x, float y) : x(x), y(y), z(0) {}

    // Constructor por defecto
    Dot() : x(0), y(0), z(0) {}
};

// Calcular la distancia entre dos puntos en 2D o 3D
float calcularDistancia(const Dot& a, const Dot& b) {
    return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2) + std::pow(b.z - a.z, 2));
}

// Calcular el vector resultante de la suma de dos vectores en 2D o 3D
Dot sumaVectores(const Dot& a, const Dot& b) {
    return Dot(a.x + b.x, a.y + b.y, a.z + b.z);
}

// Calcular el vector resultante de un arreglo de N vectores en 2D o 3D
Dot sumaN_vectores(const Dot arr[], int n) {
    float x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i) {
        x += arr[i].x;
        y += arr[i].y;
        z += arr[i].z;
    }
    return Dot(x, y, z);
}

// Calcular el producto escalar de dos vectores en 2D o 3D
float productoEscalar(const Dot& a, const Dot& b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

// Calcular el producto cruz de dos vectores en 3D
Dot productoCruz(const Dot& a, const Dot& b) {
    return Dot(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

// Imprimir el vector en el formato especificado
void imprimirVector(const Dot& v) {
    std::cout << "u = " << v.x << "i + " << v.y << "j + " << v.z << "k\n";
    if (v.z == 0 && v.y == 0)
        std::cout << "Plano X\n";
    else if (v.z == 0 && v.x == 0)
        std::cout << "Plano Y\n";
    else if (v.x == 0 && v.y == 0)
        std::cout << "Plano Z\n";
    else if (v.z == 0)
        std::cout << "Plano XY\n";
    else if (v.y == 0)
        std::cout << "Plano XZ\n";
    else if (v.x == 0)
        std::cout << "Plano YZ\n";
    else
        std::cout << "Espacio XYZ\n";
}

// Resolver un sistema de fuerzas (simplificado)
Dot resolverSistemaFuerzas(const Dot fuerzas[], int n) {
    return sumaN_vectores(fuerzas, n);
}

// Funcion para leer un vector desde la entrada del usuario
Dot leerVector(bool en3D) {
    float x, y, z = 0;
    if (en3D) {
        std::cout << "Ingrese las coordenadas del vector (x y z): ";
        std::cin >> x >> y >> z;
    } else {
        std::cout << "Ingrese las coordenadas del vector (x y): ";
        std::cin >> x >> y;
    }
    return Dot(x, y, z);
}

// Funcion principal para demostrar la funcionalidad
int main() {
    bool en3D;
    char dimension;
    std::cout << "Trabajara con vectores en 2D o 3D? (Ingrese 2 o 3): ";
    std::cin >> dimension;
    en3D = (dimension == '3');

    Dot p1 = leerVector(en3D);
    Dot p2 = leerVector(en3D);

    std::cout << "Distancia entre p1 y p2: " << calcularDistancia(p1, p2) << std::endl;

    Dot suma = sumaVectores(p1, p2);
    std::cout << "Suma de p1 y p2: ";
    imprimirVector(suma);

    int n;
    std::cout << "Ingrese el numero de vectores: ";
    std::cin >> n;
    Dot* arr = new Dot[n];
    for (int i = 0; i < n; ++i) {
        std::cout << "Ingrese el vector " << i + 1 << ":\n";
        arr[i] = leerVector(en3D);
    }

    Dot resultado = sumaN_vectores(arr, n);
    std::cout << "Suma de N vectores: ";
    imprimirVector(resultado);

    std::cout << "Producto escalar de p1 y p2: " << productoEscalar(p1, p2) << std::endl;

    if (en3D) {
        Dot cruz = productoCruz(p1, p2);
        std::cout << "Producto cruz de p1 y p2: ";
        imprimirVector(cruz);
    }

    Dot sistemaFuerzas = resolverSistemaFuerzas(arr, n);
    std::cout << "Resultado del sistema de fuerzas: ";
    imprimirVector(sistemaFuerzas);

    delete[] arr;

    return 0;
}
