#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include "treeitem.h"

/**
 * @brief The TreeModel class defines the model of the tree used in this program to show
 * the leagues, the teams and the matches.
 */
class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    /**
     * @brief Contructor of TreeModel class.
     * @param name : The name of the tree model.
     * @param data : The data needed to fill the tree.
     * @param parent : The parent of the TreeModel.
     */
    explicit TreeModel(const QString &name, const QString &data, QObject *parent = 0);
    /**
     * @brief Destructor of TreeModel class.
     */
    ~TreeModel() { delete m_rootItem; }

    /**
     * @brief This method returns the data stored under the given role for the item referred to by the index.
     * @param index : The index of the data.
     * @param role : the role of the data.
     * @return The data stored under the given role for the item referred to by the index.
     */
    QVariant data(const QModelIndex &index, int role) const override;

    /**
     * @brief This method is used to ensure that views know that the model is read-only.
     * @param index : The index of the data.
     * @return The flags of the given model index.
     */
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    /**
     * @brief This method retrieves the data stored in the root item.
     * @param section : The column of the data to retrieve.
     * @param orientation : The orientation of the header.
     * @param role : The role of the header.
     * @return The data stored in the root item.
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    /**
     * @brief This method returns the index of the item in the model specified by a given row, column and parent index.
     * @param row : The given row on which the index of the item will be returned.
     * @param column : The given column on which the index of the item will be returned.
     * @param parent : The given parent of which the index of the item will be returned.
     * @return The index of the item in the model specified by a given row, column and parent index.
     */
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;

    /**
     * @brief This method returns the parent of the model item with the given index. If the item has no
     * parent, an invalid QModelIndex is returned.
     * @param index : The index of which the method returns the parent.
     * @return The parent of the model item with the given index. If the item has no
     * parent, an invalid QModelIndex is returned.
     */
    QModelIndex parent(const QModelIndex &index) const override;

    /**
     * @brief This method returns the number of child items for the TreeItem that corresponds to a given model index,
     * or the number of top-level items if an invalid index is specified.
     * @param parent : The index of the element of which the method will return the row count.
     * @return The number of child items for the TreeItem that corresponds to a given model index,
     * or the number of top-level items if an invalid index is specified.
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * @brief This method returns how many columns are present for a given model index.
     * @param parent : The given model index of which the method count the columns.
     * @return This method always returns 1 because of our application.
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    /**
     * @brief setupModelData
     * @param lines
     * @param parent
     */
    void setupModelData(const QStringList &lines, TreeItem *parent);

    /**
     * @brief m_rootItem : The root item of the tree.
     */
    TreeItem *m_rootItem;
};

#endif // TREEMODEL_H
