#ifndef QT5LEXER_GLOBAL_H
#define QT5LEXER_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QVector>
#include <QDebug>
#include <QSharedPointer>
#include <unordered_map>
#include <limits>
#include "lexertk.h"
#include "exprtk.h"

#if defined(QT5LEXER_LIBRARY)
#  define QT5LEXER_EXPORT Q_DECL_EXPORT
#else
#  define QT5LEXER_EXPORT Q_DECL_IMPORT
#endif

#endif // QT5LEXER_GLOBAL_H
