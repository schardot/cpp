#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        _materias[i] = NULL;
    }
    std::cout << "Default MateriaSource constructed!" << std::endl;
};

MateriaSource::MateriaSource(const MateriaSource &obj) {
    for (int i = 0; i < 4; i++) {
        delete _materias[i];
        if (obj._materias[i])
            _materias[i] = obj._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
    std::cout << "MateriaSource copied!" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj) {
    if (this != &obj) {
        for (int i = 0; i < 4; i++)
        {
            delete _materias[i];
            if (obj._materias[i])
                _materias[i] = obj._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    std::cout << "Copy assignment called for MateriaSource!" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_materias[i]) {
            delete _materias[i];
            _materias[i] = NULL;
        }
    }
    std::cout << "MateriaSource destructed!" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (!_materias[i])
        {
            _materias[i] = m->clone();
            delete m; // 💥 FIX: free the original, since you cloned it
            return;
        }
    }
    delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_materias[i] && type == _materias[i]->getType()) {
            return _materias[i]->clone();
        }
    }
    return (0);
}
