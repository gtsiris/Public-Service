#ifndef class_Entrance_h
#define class_Entrance_h

#include "class_Visitor.h"
#include "class_Visitor_List.h"

class Entrance {
  Visitor_List list;  /* Includes all the visitors that are currently in this entrace */
  unsigned int ne;                     /* Current number of visitors in this entrance */
  
  public:
    Entrance();
    
    ~Entrance();
    
    Visitor_List& Get_list();                         /* Get the list of the entrance */
    
    const bool Is_Empty() const;          /* Determine if the entrace is empty or not */
    
    void Enter(Visitor& visitor);                    /* A visitor enters the entrance */
    
    void Exit(const Visitor& visitor);                /* A visitor exits the entrance */
};

#endif