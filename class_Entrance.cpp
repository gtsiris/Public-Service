#include <iostream>
#include "class_Entrance.h"

using namespace std;

Entrance::Entrance() : ne(0)                           /* The entrance is initially empty */
{
  cout << "The Entrance has been created!" << endl;
}

Entrance::~Entrance() {
  cout << "End of waiting people!" << endl << endl;
}

Visitor_List& Entrance::Get_list() {
  return list;                                         /* Return the list of the entrance */
}

const bool Entrance::Is_Empty() const {
  return (ne == 0);           /* If there is no visitor in the entrance, then it is empty */
}

void Entrance::Enter(Visitor& visitor) {
  list.Add_Visitor(visitor);               /* Add the visitor to the list of the entrance */
  ne++;                           /* Increase by 1 the number of visitors in the entrance */
}

void Entrance::Exit(const Visitor& visitor) {
  list.Exclude_This_Visitor(visitor);  /* Erase the visitor from the list of the entrance */
  ne--;                           /* Decrease by 1 the number of visitors in the entrance */
}