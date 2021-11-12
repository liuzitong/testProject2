#ifndef COLOR_SLOT_MODEL_H
#define COLOR_SLOT_MODEL_H
#include <QAbstractTableModel>
#include <spdlog/spdlog.h>

class SlotPosModel:public QAbstractTableModel
{
    Q_OBJECT
public:
    SlotPosModel(QObject* parent=nullptr);
    ~SlotPosModel()=default;

    struct ModelItem
    {
        int Slot;
        int Pos;
    };

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
    void printData();

    QList<ModelItem> modelData;
    QList<QString> header;
    // QAbstractItemModel interface

    // QAbstractItemModel interface
public:
};

#endif // COLOR_SLOT_MODEL_H
