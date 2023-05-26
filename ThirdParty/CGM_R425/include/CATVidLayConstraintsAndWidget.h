// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidLayConstraintsAndWidget.h
// Header definition of CATVidLayConstraintsAndWidget
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2007  Creation: jov
//===================================================================
#ifndef CATVidLayConstraintsAndWidget_H
#define CATVidLayConstraintsAndWidget_H

#include <VisuDialog.h>
#include <CATEventSubscriber.h>
#include <UIVCoreToolsInline.h>
#include <CATSYPArray.h>

class CATVidWidget;
class CATVidLayConstraints;

class CATVidLayConstraintsAndWidget;

class ExportedByVisuDialog CATVidLayConstraintsAndWidget
{
public:
  CATVidLayConstraintsAndWidget( CATVidWidget* i_pWidget, const CATVidLayConstraints* i_pConstraints);
  ~CATVidLayConstraintsAndWidget();

  void SetWidget(CATVidWidget* i_pWidget);
  INLINE CATVidWidget* GetWidget() const{return _pWidget;}

  void SetConstraints(const CATVidLayConstraints* i_pConstraints);
  INLINE CATVidLayConstraints* GetConstraints() const
  {
  return _pConstraints;
  }

private:
  CATVidWidget* _pWidget;
  CATVidLayConstraints* _pConstraints;
};

class ExportedByVisuDialog CATListOfCATVidLayConstraintsAndWidget
{
public:
  INLINE void RemovePosition (unsigned int i_index)
  {
    _array.Remove(i_index);
  }

  INLINE void Append(CATVidLayConstraintsAndWidget* i_pConstraintsAndWidget)
  {
    _array.Add(i_pConstraintsAndWidget);
  }
  INLINE void InsertAt(unsigned int i_index, CATVidLayConstraintsAndWidget* i_pConstraintsAndWidget)
  {
    if (!i_pConstraintsAndWidget)return;
    if (i_index >= (unsigned int) _array.GetLength())
      _array.Add(i_pConstraintsAndWidget);
    else
      _array.InsertAt (i_index, i_pConstraintsAndWidget);
  }

  INLINE CATVidLayConstraintsAndWidget* operator[](unsigned int i_index) const
  {
    return (i_index < (unsigned int) _array.GetLength() ? _array[i_index] : NULL);
  }

  INLINE unsigned int length() const
  {
    return _array.GetLength();
  }
  /** Gets an item without checking if the index fit the boundaries */
  INLINE CATVidLayConstraintsAndWidget* UnsafeGet(unsigned int i_index) const
  {
    return _array.UnsafeGet(i_index);
  }
  INLINE void fastadd(CATVidLayConstraintsAndWidget* i_pConstraintsAndWidget)
  {
    _array.Add(i_pConstraintsAndWidget);
  }

  INLINE void empty()
  {
    _array.RemoveAll();
  }

  INLINE void swap(unsigned int i_index1, unsigned int i_index2)
  {
    _array.Swap(i_index1, i_index2);
  }

  INLINE void operator-=(CATVidLayConstraintsAndWidget* i_pConstraintsAndWidget)
  {
    _array.RemoveElement(i_pConstraintsAndWidget);
  }

  /**
  * Sorts the list using the quicksort algorithm.
  */
  INLINE void QuickSort(int (*iPFCompare) (const void *, const void *))
  {
    if (_array.GetLength() > 0)
    {
      void *& pBlock = (void *&) ((CATVidLayConstraintsAndWidget *&) _array[0]);
      qsort(&pBlock , _array.GetLength(), sizeof(void *), iPFCompare);
    }
  }

private:
  CATSYPArray<CATVidLayConstraintsAndWidget*>_array;
};


#endif

