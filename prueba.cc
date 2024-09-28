#include <iostream>

int main() {
  std::cout << "Introduce un numero: ";
  int x{};
  std::cin >> x;
  std::cout << "Introduce otro numero: ";
  int y{};
  std::cin >> y;
  std::cout << "La suma de " << x << " y " << y << " es " << x + y << '\n';
  return 0;
}