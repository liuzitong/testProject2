#include "models.h"


LocalTableData::LocalTableData()
{
    m_data=new int[dataLen]();
    m_mainPosTableData=singleTableData(31*3,31,m_data);
    m_secondaryPosTableData=singleTableData(31*3,31,m_data+31*3*31);
    m_dbAngleDampingTableData=singleTableData(46,1,m_data+31*3*31*2);
    m_xyDistTableData=singleTableData(25,2,m_data+31*3*31*2+46);
}
