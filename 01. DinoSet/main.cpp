#include <iostream>
#include "dinoset.h"

int main()
{
    DinoSet d;
    d.add(DinoId::pteranodon);
    d.add(DinoId::velociraptor);
    d.add(DinoId::tyrannosaurus);
    std::cout << d.to_string() << "\n";
    return 0;
}
