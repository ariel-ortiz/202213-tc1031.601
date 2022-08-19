#include <iostream>
#include "dinoset.h"

int main()
{
    DinoSet d;
    d.add(DinoId::pteranodon);
    d.add(DinoId::velociraptor);
    d.add(DinoId::tyrannosaurus);
    d.add(DinoId::velociraptor);
    std::cout << d.to_string() << "\n";
    std::cout << "size: " << d.size() << "\n";

    DinoSet e;
    e.add(DinoId::velociraptor);
    e.add(DinoId::procompsognathus);

    DinoSet f = d + e;
    std::cout << f.to_string() << "\n";
    std::cout << "size: " << f.size() << "\n";

    return 0;
}
