#include <iostream>
#include "class_Ground.h"

using namespace std;

Ground::Ground(const unsigned int& capacity, const unsigned int& ground_capacity) :
priority_counter(1), Ng(ground_capacity < capacity / 2 ? ground_capacity : 0), ng(0)  /* The ground is initially empty */
                                                  /* The first visitor that enters the building gets priority number 1 */
{
  cout << "A Floor has been created with number0" << endl << endl;
}

Ground::~Ground() {
  cout << "End of service!" << endl;
}

Entrance& Ground::Get_e() {
  return e;                                                                       /* Return the entrance of the ground */
}

const unsigned int& Ground::Get_ng() const {
  return ng;                                                    /* Return the current number of visitors in the ground */
}

const bool Ground::Is_Empty() const {
  return (ng == 0);                                          /* If there is no visitor in the ground, then it is empty */
}

const bool Ground::Enter(Visitor& visitor) {
  if (ng < Ng) {                                                       /* Check if there is enough space in the ground */
    e.Enter(visitor);                                                          /* Put visitor in the ground's entrance */
    ng++;                                                        /* Increase by 1 the number of visitors in the ground */
    return 1;                                                               /* Visitor entered the ground successfully */
  }
  else {
    return 0;                                                                     /* Visitor couldn't enter the ground */
  }
}

void Ground::Exit(const Visitor& visitor) {
  e.Exit(visitor);                                      /* Visitor must leave the entrance in order to exit the ground */
  ng--;                                                          /* Decrease by 1 the number of visitors in the ground */
}

void Ground::Wait(Visitor& visitor) {
  visitor.Set_priority(priority_counter++);                                   /* Give a unique priority to the visitor */
  cout << "Waiting for the lift " << endl;
}
