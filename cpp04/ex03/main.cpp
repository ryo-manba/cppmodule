#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <climits>

void test()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "-----myTest-----" << std::endl;

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // learnMateria more than the maximum number of 4.
    AMateria *five = new Ice();
    src->learnMateria(five);

    // Specify a non-existent Materia_name.
    tmp = src->createMateria("NO_SUCH_MATERIA");
    if (tmp == NULL)
    {
        std::cout << "Materia is full." << std::endl;
    }

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Equip more than the maximum number of 4.
    AMateria* tmp2;
    tmp2 = src->createMateria("ice");
    me->equip(tmp2);

    std::cout << "unequip(3)" << std::endl;
    me->unequip(3);
    delete tmp;

    std::cout << "use(2, *bob)" << std::endl;
    me->use(2, *bob);
    std::cout << "use(3, *bob)" << std::endl;
    me->use(3, *bob);
    std::cout << "use(-1, *bob)" << std::endl;
    me->use(-1, *bob);
    std::cout << "use(UINT_MAX, *bob)" << std::endl;
    me->use(UINT_MAX, *bob);

    delete bob;
    delete me;
    delete src;
    delete five;
    delete tmp2;
}

int main()
{
    test();
    system("leaks a.out");
    return 0;
}
