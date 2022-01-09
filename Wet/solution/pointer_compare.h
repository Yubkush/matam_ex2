#ifndef POINTER_COMPARE_H
#define POINTER_COMPARE_H

#include "Citizen.h"

namespace mtm
{
    class PointerCompare{
        public:
            bool operator()( mtm::Citizen*  citizen1,  mtm::Citizen*  citizen2) const;
    };
}

#endif /* POINTER_COMPARE_H */