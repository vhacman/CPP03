#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== TEST 1: Creazione e attacco base ===" << std::endl;
    ClapTrap robot1("Robot1");
    robot1.attack("Nemico1");
    robot1.attack("Nemico2");
    std::cout << std::endl;

    std::cout << "\n=== TEST 2: Prendere danno ===" << std::endl;
    robot1.takeDamage(3);
    robot1.takeDamage(5);
    std::cout << std::endl;

    std::cout << "\n=== TEST 3: Ripararsi ===" << std::endl;
    robot1.beRepaired(4);
    robot1.beRepaired(2);
    std::cout << std::endl;

    std::cout << "\n=== TEST 4: Esaurimento energia ===" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        robot1.attack("Target");
    }
    std::cout << std::endl;

    std::cout << "\n=== TEST 5: Morto non può fare azioni ===" << std::endl;
    ClapTrap robot2("Robot2");
    robot2.takeDamage(15);
    robot2.attack("Qualcuno");
    robot2.beRepaired(5);
    std::cout << std::endl;

    std::cout << "\n=== TEST 6: Costruttore di copia ===" << std::endl;
    ClapTrap robot3("Robot3");
    ClapTrap robot4(robot3);
    robot4.attack("TestTarget");
    std::cout << std::endl;

    std::cout << "\n=== TEST 7: Operatore di assegnazione ===" << std::endl;
    ClapTrap robot5("Robot5");
    robot5.takeDamage(3);
    ClapTrap robot6("Robot6");
    robot6 = robot5;
    std::cout << std::endl;

    std::cout << "\n=== Fine test - Distruzione automatica ===" << std::endl;
    return 0;
}
