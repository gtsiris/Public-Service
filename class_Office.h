#ifndef class_Office_h
#define class_Office_h

#include "class_Visitor_List.h"
#include "class_Visitor.h"

class Office {
  Visitor_List list;                 /* Includes all the visitors that are currently in this office */
  const unsigned int o_num;            /* The number of this office (eg. o_num = 1 -> first office) */
  unsigned int no;                                     /* Current number of visitors in this office */
  const unsigned int No;                               /* Maximum number of visitors in this office */
  
  public:
    Office(const unsigned int& office_number, const unsigned int& floor_capacity, const unsigned int& office_capacity);
    
    ~Office();
    
    const bool Is_Empty() const;                          /* Determine if the floor is empty or not */
    
    const bool Enter(Visitor& visitor);  /* A visitor enters the building, if there is enough space */
    
    Visitor& Exit();                         /* A randomly selected served visitor exits the office */
};

#endif