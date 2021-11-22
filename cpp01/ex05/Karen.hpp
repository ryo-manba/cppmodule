#ifndef KAREN_HPP
#define KAREN_HPP

#include <string>

#define MAX 4

enum : int
{
    DEBUG   = 1,
    INFO    = 2,
    WARNING = 3,
    ERROR   = 4
};

class Karen
{
public:
    Karen();
    ~Karen();

    void complain(std::string level);

private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif
