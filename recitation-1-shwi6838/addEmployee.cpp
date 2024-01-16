#include "addEmployee.hpp"

int addAnEmployee(employee arr[], string name, string birthday, string emailid, int count)
/*TODO 3: complete this function
** this function will add a record in the struct array at index count
** it will return the next available index in the array
*/
{
    arr[count].name = name;
    arr[count].birthday = birthday;
    arr[count].email = emailid;
    return 0;
}
