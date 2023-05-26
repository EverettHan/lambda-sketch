#ifndef CATVidLayGridIterator_h
#define CATVidLayGridIterator_h

// COPYRIGHT Dassault Systemes 2009

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidLayIterator.h>
#include <CATVidLayConstraints.h>
#include <CATVidLayConstraintsAndWidget.h>
#include <CATVidLayIndexedWidget.h>
#include <CATVidWidget.h>

// System framework
#include <CATBoolean.h>

#include <list.h>


class CATVidLayCollection;
class CATVidCtlCollection;

/**
 * @ingroup VIDLayout
 */
class ExportedByVisuDialog CATVidLayGridIterator: public CATVidLayIterator
{
  CATDeclareClass;

public:

  enum GridIteratorType{GridIteratorRow=0, GridIteratorColumn};

  // Standard constructors and destructors
  CATVidLayGridIterator(const CATVidLayCollection& i_collection, CATVidLayGridIterator::GridIteratorType i_gridIteratorType);
  CATVidLayGridIterator(const CATVidCtlCollection& i_ctlCollection, CATVidLayGridIterator::GridIteratorType i_gridIteratorType);
  
  virtual ~CATVidLayGridIterator();

  int GetGroupIndex(CATVidWidget* i_pWidget);

  CATMathPoint2Df GetGroupMinimumDimension(unsigned int i_groupIndex) const;

  /**
   * Returns TRUE if there is at least one layoutable widget in the group 
   * specified by the given index, FALSE otherwise.
   */
  CATBoolean IsGroupLayoutable(unsigned int i_groupIndex) const;

  /**
   * Returns TRUE if all the widgets in the group, specified by the given index,
   * have compact constraints, FALSE otherwise.
   * @param i_groupIndex The index of the group
   * @param i_horizontally Set to TRUE if the compacity must be checked horizontallly, FALSE otherwise
   * @param i_vertically Set to TRUE if the compacity must be checked vertically, FALSE otherwise
   */
  CATBoolean IsGroupCompact(unsigned int i_groupIndex, CATBoolean i_horizontally, CATBoolean i_vertically) const;

  virtual CATVidWidget * GetAt(int i_index);

  CATVidLayIndexedWidget * GetIndexedWidget(int i_index) const;

private:

  // Copy constructor and equal operator
  CATVidLayGridIterator (const CATVidLayGridIterator &);
  CATVidLayGridIterator& operator=(const CATVidLayGridIterator&);

  void _Init(const CATListOfCATVidLayConstraintsAndWidget& i_constraintsAndWidgetList);

  class WidgetList
  {
  public:
    WidgetList(unsigned int i_index)
    {
      _index = i_index;
    };
    ~WidgetList()
    {
      CATVidLayIndexedWidget* pIndexedWidget = NULL;
      for (int i = 0; pIndexedWidget = _widgetWRList[i]; i++)
      {
        pIndexedWidget->Release();
        pIndexedWidget = NULL;
      }
      _widgetWRList.empty();
    };
    int _index;
    list <CATVidLayIndexedWidget> _widgetWRList; 
  };

  WidgetList* GetWidgetList(unsigned int i_index);
  void BubbleSort(list <CATVidLayIndexedWidget>& i_list);
  void BubbleSort(list <WidgetList>& i_list);

private:

  GridIteratorType _gridIteratorType;
  list <WidgetList> _mainList; 
};

#endif // CATVidLayGridIterator_h
