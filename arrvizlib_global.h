#ifndef ARRVIZLIB_GLOBAL_H
#define ARRVIZLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ARRVIZLIB_LIBRARY)
#define ARRVIZLIB_EXPORT Q_DECL_EXPORT
#else
#define ARRVIZLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // ARRVIZLIB_GLOBAL_H
