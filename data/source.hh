#ifndef SOURCE_HH
#define SOURCE_HH

#include "types.hh"
#include <QVariant>
namespace Program {
namespace Data {

class Source
{
    public:
        Source() = default;
        virtual ~Source() = default;
        virtual QVariant getData() const = 0;

    private:


};

}   // Data
}   // Program

#endif // SOURCE_HH
