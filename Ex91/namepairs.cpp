#include "namepairs.h"
#include <QDebug>

using namespace std;

void NamePairs::readNames() {
    cout << "Введите имена через пробел:\n";

    string oneName;

    while(cin >> oneName) {

        if (oneName == ";") break;
        name.push_back(oneName);
    }
}

void NamePairs::readAges() {
    for (size_t i = 0; i < name.size(); i++) {
        double oneAge;

        cout << "Возраст для " << name[i] << ": ";
        cin >> oneAge;

        age.push_back(oneAge);
    }
}

void NamePairs::sort() {
    for (size_t i = 0; i < name.size() - 1; i++) {
        for (size_t j = 0; j < name.size() - i - 1; j++) {
            if (name[j] > name[j+1]) {
                std::swap(name[j], name[j+1]);
                std::swap(age[j], age[j+1]);
            }
        }
    }
}

ostream& operator<<(ostream& os, const NamePairs* np) {
    for (size_t i = 0; i < np->getSize(); i++) {
        os << '(' << np->getName(i) << ", " << np->getAge(i) << ")\n";
    }

    return os;
}

ostream& operator<<(ostream& os, const NamePairs& np) {
    for (size_t i = 0; i < np.getSize(); i++) {
        os << '(' << np.getName(i) << ", " << np.getAge(i) << ")\n";
    }

    return os;
}
