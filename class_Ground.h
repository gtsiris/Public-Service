#ifndef class_Ground_h
#define class_Ground_h

#include "class_Visitor.h"
#include "class_Entrance.h"

class Ground {
  Entrance e;                                                                             /* Ground has an entrance */
  unsigned int ng;                                                      /* Current number of visitors in the ground */
  const unsigned int Ng;                                                /* Maximum number of visitors in the ground */
  unsigned int priority_counter;  /* Depending on when a visitor entered the building gets a unique priority number */
  public:
    Ground(const unsigned int& capacity, const unsigned int& ground_capacity);
    
    ~Ground();
    
    Entrance& Get_e();                                                            /* Get the entrance of the ground */
    
    const unsigned int& Get_ng() const;                         /* Get the current number of visitors in the ground */
    
    const bool Is_Empty() const;                                         /* Determine if the ground is empty or not */
    
    const bool Enter(Visitor& visitor);                    /* A visitor enters the ground, if there is enough space */
    
    void Exit(const Visitor& visitor);                                                /* A visitor exits the ground */
    
    void Wait(Visitor& visitor);                           /* A visitor waits for the lift and gets priority number */
};

#endif