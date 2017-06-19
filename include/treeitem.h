#ifndef TREEITEM_H
#define TREEITEM_H

#include <QString>
#include <QList>
#include <QVariant>

/**
 * @brief The TreeItem class represent an item in a tree view and may contain several columns of data.
 */
class TreeItem
{
public:
    /**
     * @brief This is the constructor of TreeItem class.
     * @param data : The data associated for each column.
     * @param parent : The parent of the item.
     */
    explicit TreeItem(const QList<QVariant> &data, TreeItem *parent = 0) :
        m_itemData(data),
        m_parentItem(parent)
    {
    }

    /**
     * @brief The destructor of TreeItem class.
     */
    ~TreeItem() { qDeleteAll(m_childItems); }

    /**
     * @brief This method allows to append a child to the item.
     * @param child : The new child to be appended.
     */
    inline void appendChild(TreeItem *child) { m_childItems.append(child); }

    /**
     * @brief This method retuns the child on a given row.
     * @param row : The row number of the child to be returned.
     * @return A pointer to the child on the given row.
     */
    inline TreeItem* child(int row) { return m_childItems.value(row); }

    /**
     * @brief This method counts the number of children of the item.
     * @return The number of the item's children.
     */
    inline int childCount() const { return m_childItems.count(); }

    /**
     * @brief This method counts the number of available columns.
     * @return The number of available columns.
     */
    inline int columnCount() const { return m_itemData.count(); }

    /**
     * @brief This method retrieves the data on a given column.
     * @param column : The column on which the data should be retrieved.
     * @return The data on a given column.
     */
    inline QVariant data(int column) const { return m_itemData.value(column); }

    /**
     * @brief This method reports the item's location within its parent's list of items.
     * @return The item's location within its parent's list of items. With no parents, the method returns 0;
     */
    inline int row() const
    {
        if (m_parentItem)
            return m_parentItem->m_childItems.indexOf(const_cast<TreeItem*>(this));
        return 0;
    }

    /**
     * @brief This method returns the parent of the item.
     * @return A pointer to the parent of the item.
     */
    inline TreeItem* parentItem() { return m_parentItem; }

private:
    /**
     * @brief m_childItems : A list of pointers to the item's own child item.
     */
    QList<TreeItem*> m_childItems;
    /**
     * @brief m_itemData : A list of culumn data of the item.
     */
    QList<QVariant> m_itemData;
    /**
     * @brief m_parentItem : The parent of the item.
     */
    TreeItem* m_parentItem;
};

#endif // TREEITEM_H
