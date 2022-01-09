#include "pointer_compare.h"

namespace mtm
{
    bool mtm::PointerCompare::operator()(mtm::Citizen* citizen1, mtm::Citizen* citizen2) const{
        return *citizen1 < *citizen2;
    }
}