// eJxjdCwtyWdkNGQMzszLBgAVpANk



#ifndef BEJWZCC7MY44HAACAAIP_H_
#define BEJWZCC7MY44HAACAAIP_H_

#include <SPL/Runtime/ProcessingElement/PE.h>

#define MYPE BeJwzCc7My44HAAcAAIp

namespace SPL 
{
    class MYPE : public SPL::PE
    {
    public:
        MYPE(bool isStandalone=false);

        virtual void registerResources(const std::string & applicationDir, const std::string & streamsInstallDir);

    };
} // end namespace SPL

#undef MYPE

#endif // BEJWZCC7MY44HAACAAIP_H_

