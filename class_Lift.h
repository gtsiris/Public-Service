#ifndef class_Lift_h
#define class_Lift_h

#include "class_Visitor_List.h"
#include "class_Visitor.h"
#include "class_Ground.h"
#include "class_Floor.h"

class Lift {
  Visitor_List list;                                         /* Includes all the visitors that are currently in the lift */
  unsigned int current_f;                                             /* The floor that the lift is currently stopped at */
  unsigned int nl;                                                             /* Current number of visitors in the lift */
  const unsigned int Nl;                                                       /* Maximum number of visitors in the lift */
  
  public:
    Lift(const unsigned int& office_capacity, const unsigned int& lift_capacity);
    
    ~Lift();
    
    const bool Is_Full() const;                                                  /* Determine if the lift is full or not */
    
    void Operate(Ground& g, Floor (&f)[4]);  /* Lift executes a cycle. During a cycle some visitors embark and disembark */
    
    const bool Enter(Visitor& visitor);                           /* A visitor enters the lift, if there is enough space */
    
    void Stop_Up(Floor (&f)[4]);                  /* Lift goes upwards and stops at each floor so visitors can disembark */
    
    void Exit(const Visitor& visitor_ready_to_leave_the_lift);                               /* A visitor exits the lift */
    
    void Stop_Down(Floor (&f)[4]);                 /* Lift goes downwards and stops at each floor so visitors can embark */
    
    void Empty_All(Ground& g);                             /* All the served visitors exit the lift and enter the ground */
};

#endif