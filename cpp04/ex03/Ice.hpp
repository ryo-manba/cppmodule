#include <string>
class Ice
{
public:
    Ice();
    ~Ice();
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);
private:
    const static std::string kDefaultType;
};
