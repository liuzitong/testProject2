#ifndef MODELS_H
#define MODELS_H

struct CoordSpacePosInfo
{
    float coordX,coordY;
};

struct CoordMotorPosFocalDistInfo
{
    int motorX,motorY,focalDist;
    CoordMotorPosFocalDistInfo()=default;
    CoordMotorPosFocalDistInfo(int x,int y,int f);
    CoordMotorPosFocalDistInfo& operator=(CoordMotorPosFocalDistInfo& other);
    CoordMotorPosFocalDistInfo& operator=(CoordMotorPosFocalDistInfo&& other);
};


struct SingleTableData
{
    SingleTableData()=default;
    SingleTableData(int row,int column,int* data):m_row(row),m_column(column),m_data(data){};
    ~SingleTableData()=default;

    int operator()(int row,int column){return m_data[row*m_column+column];}

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
    SingleTableData m_mainPosTableData;
    SingleTableData m_secondaryPosTableData;
    SingleTableData m_dbAngleDampingTableData;
    SingleTableData m_xyDistTableData;
    int* m_data;
    const int dataLen=31*31*3*2+46+52*2;
};

#endif // MODELS_H
