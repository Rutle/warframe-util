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

        virtual QVariant getData() = 0;
        virtual const QString &getName() const = 0;
        virtual const SOURCETYPE &getType() const = 0;
        virtual const QString &getId() const = 0;

};

}   // Data
}   // Program

#endif // SOURCE_HH
