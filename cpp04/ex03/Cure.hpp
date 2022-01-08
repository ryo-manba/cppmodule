#include <string>

class Cure
{
public:
    Cure();
    ~Cure();
    Cure(const Cure &other);
    Cure &operator=(const Cure &other);
private:
    const static std::string kDefaultType;
};
