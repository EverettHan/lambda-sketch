// ============================================================================
// COPYRIGHT Dassault Systemes and ARBoost Technologies 2008
// ============================================================================
//
// SWXUTAVLTree
// Polymorphic AVL tree
//
// ============================================================================
// 2008-xx-xx   VQH
// ============================================================================
#ifndef SWXUTAVLTree_H
#define SWXUTAVLTree_H

#include "SWXUtGeneral.h"
#include "SWXUtAvlTreeNode.h"

class SWXUtAvlTreeCursor;

class ExportedBySWXUtGeneral SWXUtAvlTree
{
public:
    SWXUtAvlTree(SWXUtCompareFunction iCompareItems);
    ~SWXUtAvlTree();

    int GetItemNumber() const;

    bool Contains(const void *iItem) const;

    void *LookForItem(void *iItem) const;
    const SWXUtAvlTreeNode *LookForNodeOfItem(void *iItem) const;
    const SWXUtAvlTreeNode *LowerBound(void *iItem) const;
    const SWXUtAvlTreeNode *UpperBound(void *iItem) const;


    SWXUtAvlTreeCursor InsertItem(void *iItem);
    bool RemoveItem(void *iItem, SWXUtDeleteFunction iDeleteItem, void* iClosure);

    void DeleteItems(SWXUtDeleteFunction iDeleteItem, void* iClosure);

    const SWXUtAvlTreeNode *GetRootNode() const;

    int CompareItems(void *iItem1, void *iItem2) const;

    void SetCompareFunction(SWXUtCompareFunction iCompareFunction);
    SWXUtCompareFunction GetCompareFunction() const;

private:
    void DecrementItemNumber();

    static void DoNothing(SWXUtAvlTreeNode* iNode, void *iV, void* iClosure);

    SWXUtCompareFunction    mCompareItems;
    SWXUtAvlTreeNode        *mRootNode;
    int                     mItemNumber;

    friend class SWXUtAvlTreeNode;
};

#endif 
