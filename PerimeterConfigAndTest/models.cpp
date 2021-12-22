#include "models.h"
#include <memory>

LocalTableData::LocalTableData()
{
    m_data=new int[dataLen]();
    memset(m_data,-1,dataLen*sizeof (int));
    m_mainPosTableData=SingleTableData(31*3,31,m_data);
    m_secondaryPosTableData=SingleTableData(31*3,31,m_data+31*3*31);
    m_dbAngleDampingTableData=SingleTableData(46,1,m_data+31*3*31*2);
    m_xyDistTableData=SingleTableData(25,2,m_data+31*3*31*2+46);
}

CoordMotorPosFocalDistInfo::CoordMotorPosFocalDistInfo(int x, int y, int f):motorX(x),motorY(y),focalDist(f)
{

}

CoordMotorPosFocalDistInfo &CoordMotorPosFocalDistInfo::operator=(CoordMotorPosFocalDistInfo& other)
{
    this->motorX=other.motorX;
    this->motorY=other.motorY;
    this->focalDist=other.focalDist;
    return *this;
}

CoordMotorPosFocalDistInfo &CoordMotorPosFocalDistInfo::operator=(CoordMotorPosFocalDistInfo&& other)
{
    this->motorX=other.motorX;
    this->motorY=other.motorY;
    this->focalDist=other.focalDist;
    return *this;
}

