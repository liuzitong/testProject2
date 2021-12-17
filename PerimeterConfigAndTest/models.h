#ifndef MODELS_H
#define MODELS_H

struct DotInfo
{
    float coordX,coordY,focalDistance;
    int motorXPos,motorYPos;
};

struct singleTableData
{
    singleTableData()=default;
    singleTableData(int row,int column,int* data):m_row(row),m_column(column),m_data(data){};
    ~singleTableData()=default;
    int m_row;
    int m_column;
    int* m_data;
};

class LocalTableData
{
public:
    LocalTableData();
//    ~LocalTableData(){
//        delete[] m_data;
//    }
public:
    singleTableData m_mainPosTableData;
    singleTableData m_secondaryPosTableData;
    singleTableData m_dbAngleDampingTableData;
    singleTableData m_xyDistTableData;
    int* m_data;
    const int dataLen=31*31*3*2+46+52*2;
};

#endif // MODELS_H
