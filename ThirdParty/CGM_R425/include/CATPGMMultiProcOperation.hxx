#include "CATThrowForNullPointer.h"
#include "CATUnicodeString.h"
#include "CATIPGMMultiProcTask.h"

//----------------------------------------------------------------
//  Implementation des methodes Templates
//----------------------------------------------------------------

template <class T>
std::shared_ptr<T> CATPGMMultiProcOperation::GetClientTask() const
{
  std::shared_ptr<T> spTask = nullptr;
  this->GetClientTask(spTask);

  return spTask;
}


// template <class T, class = typename std::enable_if<std::is_base_of<CATIPGMMultiProcTask,T>::value>::type>
template <class T,
          typename std::enable_if<std::is_base_of<CATIPGMMultiProcTask,T>::value>::type*>
void CATPGMMultiProcOperation::GetClientTask(std::shared_ptr<T> & oTask) const
{  
  std::shared_ptr<CATIPGMMultiProcTask> spCurrentTask = this->GetTask();
  if (spCurrentTask)
  {
    T localUserTask;
    CATUnicodeString testClassName = localUserTask.GetLoadFunctionName();

    CATUnicodeString currentClassName = spCurrentTask->GetLoadFunctionName();
    if (currentClassName == testClassName) // Check
    {
      // oTask = std::dynamic_pointer_cast<T> (spCurrentTask);
      oTask = std::static_pointer_cast<T> (spCurrentTask);
    }
    else
      CATThrowForNullPointer();
  }

}

