#include "src/core/datastatusinterface.h"

DataStatusInterface::DataStatusInterface(QObject *parent) : QObject(parent)
{

}

DataStatusInterface &DataStatusInterface::instance()
{
    static DataStatusInterface s;
    return s;
}
