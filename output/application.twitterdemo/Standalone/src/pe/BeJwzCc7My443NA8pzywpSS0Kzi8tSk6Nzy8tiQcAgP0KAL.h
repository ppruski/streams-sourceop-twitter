// eJxjdCwtyWdkNGIMzszLZgwpzywpSS0Kzi8tSk6Nzy8tAQCSPAqB



#ifndef BEJWZCC7MY443NA8PZYWPSS0KZI8TSK6NZY8TIQCAGP0KAL_H_
#define BEJWZCC7MY443NA8PZYWPSS0KZI8TSK6NZY8TIQCAGP0KAL_H_

#include <SPL/Runtime/ProcessingElement/PE.h>

#define MYPE BeJwzCc7My443NA8pzywpSS0Kzi8tSk6Nzy8tiQcAgP0KAL

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

#endif // BEJWZCC7MY443NA8PZYWPSS0KZI8TSK6NZY8TIQCAGP0KAL_H_

