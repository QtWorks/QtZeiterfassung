#pragma once

#include <QtGlobal>

#if defined(ZEITERFASSUNGGUILIB_LIBRARY)
#  define ZEITERFASSUNGGUILIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ZEITERFASSUNGGUILIBSHARED_EXPORT Q_DECL_IMPORT
#endif