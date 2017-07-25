#include "src/core/storage.h"

Storage::Storage()
{

}

Storage::Storage(const QString &storagePath) : m_storagePath(storagePath)
{

}

QString Storage::storagePath() const
{
    return m_storagePath;
}
