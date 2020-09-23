// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

/*���� ��������*/

#include <Windows.h>
#include <iostream>
#include <limits>
#include <vector>

int main() {
  SetConsoleOutputCP(1251);

  std::vector<std::string> obj = {
#include "data.txt"
  };

  std::cout << "��������� ����� �� ��������� ���������:\n\n";
  for (size_t k = obj.size() - 16; k < obj.size(); k++) {
    std::cout << obj[k] << ", ";
    if (k % 4 == 0)
      std::cout << std::endl;
  }
  std::cout << "\n\n\t� ������� �� ������������ �������.\n\n";

  size_t i = 0;

  while (i < obj.size() - 16) {
    bool answer = false;
    std::cout << "\n" << obj[i];
    std::cout << "\n��� ����� (1 - ��, 0 - ���): ";
    if (!(std::cin >> answer)) {
      std::cin.clear();
#undef max
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if (answer)
      i = 2 * i + 1;
    else
      i = 2 * i + 2;
  }

  std::cout << "\n\t��� " << obj[i] << "!" << std::endl;

  system("pause");
  return 0;
}
