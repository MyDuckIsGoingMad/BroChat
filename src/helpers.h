#ifndef HELPERS
#define HELPERS

#include <QtQml>

namespace QmlHelpers {

    template<class T>
    class QmlTypeRegistrator
    {
    public:
        explicit QmlTypeRegistrator(int qmlTypeId)
        {
            Q_UNUSED(qmlTypeId);
        }
        explicit QmlTypeRegistrator(const char *module, int majorVersion, int minorVersion, const char *name)
        {
            qmlRegisterType<T>(module, majorVersion, minorVersion, name);
        }
    };
}

#endif // HELPERS

