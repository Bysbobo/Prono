#include "treemodel.h"
#include <QStringList>

TreeModel::TreeModel(const QString& name, const QString& data, QObject *parent) :
    QAbstractItemModel(parent)
{
    // Create the root
    QList<QVariant> rootData;
    rootData << name;
    apRootItem = new TreeItem(rootData);

    // Fill the tree
    setupModelData(data.split(tr("\n")), apRootItem);
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    // Verify that the index and the role are valid
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    // Verify that the given index is valid
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // Verify the given orientation and the given role
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return apRootItem->data(section);

    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    // Verify that the given row and column are within the range of the tree
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    // Get the parent item
    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = apRootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    // Get the child of the parent which correspond to the item specified by the given row and column
    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem); // Use the createIndex() function to create a model index to be returned

    return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    // Verify that the given index is valid
    if (!index.isValid())
        return QModelIndex();

    // Get the index item and its parent
    TreeItem *indexItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = indexItem->parentItem();

    // Verify that the parent item is not the root
    if (parentItem == apRootItem)
        return QModelIndex();

    // Use the createIndex() function to create a model index to be returned
    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    // Verify that the parent index has a column equal to 0
    if (parent.column() > 0)
        return 0;

    // Get the parent item
    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = apRootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    // Return the number of childs that the parent has
    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    // Verify that the given index is valid and return the number of its columns
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();

    // Otherwise the number of columns is determined from the root item
    return apRootItem->columnCount();
}

void TreeModel::setupModelData(const QStringList &lines, TreeItem *parent)
{
    QList<TreeItem*> parents;
    QList<int> indentations;
    parents << parent;
    indentations << 0;

    int number = 0;

    while (number < lines.count()) {
        int position = 0;
        while (position < lines[number].length()) {
            if (lines[number].at(position) != ' ')
                break;
            position++;
        }

        QString lineData = lines[number].mid(position).trimmed();

        if (!lineData.isEmpty()) {
            // Read the column data from the rest of the line.
            QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
            QList<QVariant> columnData;
            for (int column = 0; column < columnStrings.count(); ++column)
                columnData << columnStrings[column];

            if (position > indentations.last()) {
                // The last child of the current parent is now the new parent
                // unless the current parent has no children.

                if (parents.last()->childCount() > 0) {
                    parents << parents.last()->child(parents.last()->childCount()-1);
                    indentations << position;
                }
            } else {
                while (position < indentations.last() && parents.count() > 0) {
                    parents.pop_back();
                    indentations.pop_back();
                }
            }

            // Append a new item to the current parent's list of children.
            parents.last()->appendChild(new TreeItem(columnData, parents.last()));
        }

        ++number;
    }
}
