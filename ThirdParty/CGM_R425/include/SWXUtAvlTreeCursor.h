// ============================================================================
// COPYRIGHT Dassault Systemes and ARBoost Technologies 2008
// ============================================================================
//
// SWXUtAvlTreeCursor
// AVL tree cursor.
//
// ============================================================================
// 2008-xx-xx   VQH
// ============================================================================
#ifndef SWXUTAVLTREECURSOR_H
#define SWXUTAVLTREECURSOR_H

class SWXUtAvlTreeNode;
class SWXUtAvlTree;

class ExportedBySWXUtGeneral SWXUtAvlTreeCursor
{
public:
    SWXUtAvlTreeCursor(const SWXUtAvlTree *iTree);
    SWXUtAvlTreeCursor(const SWXUtAvlTree &iTree);
    ~SWXUtAvlTreeCursor();

    bool IsBeforeFirstItem() const;
    bool IsAfterLastItem() const;

    void ResetOnFirstItem();
    void ResetOnLastItem();

    void ResetOnNode(const SWXUtAvlTreeNode *iNode);

    void ResetOnItem(void *iItem);

    void Increment();
    void Decrement();

    void *GetItem() const;

    const SWXUtAvlTree* Tree() const;
    const SWXUtAvlTreeNode* Node() const;

private:
    const SWXUtAvlTree        *mTree;
    const SWXUtAvlTreeNode    *mNode;
    bool                      mIsBeforeFirst;
    bool                      mIsAfterLast;
};

#endif
