#include "parabolic_motion.h"
#include "collision.h"

void Collisions()
{
  float ma1, ma2;
  float vi1, vi2;
  float vf1, vf2;

  cout << "\t\t\tCOLLISION FUNCTION "  << endl;

  cout << "\nEnter first mass "  << endl;
  cin >>ma1;
  cout << "Enter second mass" << endl;
  cin >>ma2;
  cout << "Enter initial speed of the first mass" << endl;
  cin >>vi1;
  cout << "Enter initial speed of the second mass" << endl;
  cin >>vi2;

  if (vi2 !=0){

      vf1=((ma1-ma2)/(ma1+ma2))*vi1+((2*ma2)/(ma1+ma2))*vi2;    // Velocidad final de la masa 1 (si la velocidad inicial de la masa 1 es diferente de  0)
      vf2=((2*ma1)/(ma1+ma2))*vi1-((ma1-ma2)/(ma1+ma2))*vi2;      // Velocidad final de la masa 2 (si la velocidad inicial de la masa 1 es diferente de  0)
  }
   else{

      vf1= ((ma1-ma2)/(ma1+ma2))*vi1;          // Velocidad final de la masa 1 (si la velocidad inicial de la masa 1 es 0)
      vf2= ((2*ma1)/(ma1+ma2))*vi1;           // Velocidad final de la masa 2 (si la velocidad inicial de la masa 1 es 0)

   }
  cout << "Final speed of the first mass is: "<<vf1<< " m/s " << endl;
  cout << "Final speed of the second mass is: "<<vf2<< " m/s " << endl;
}


