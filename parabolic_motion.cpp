#include "parabolic_motion.h"

void Parabolic_Motion_Friction()
{

  // Variables para movimiento sin fuerza friccion

  float v0=0;                          // velocidad inicial de disparo
  float y0=0;                          // altura (posicion) inicial en y
  float theta=0;                       // angulo de disparo
  float t=0;                           // tiempo de duracion de movimiento
  float vy,vx;                         // velocidad en componente "y" y componente en "x"
  float x,y;                           // posicion (altura y distancia) en "x" y en "y"

  // Variables para movimiento con fuerza de friccion

  float k=0;                           // constante de friccion
  float m=0;                           // masa
  float alpha=0;                       // angulo
  float rad=0;                         // radio
  float vm=0;                          // magnitud del vector velocidad
  float vxf, vyf;                      // velocidad final en "x" y "y"
  float ax, ay;                        // aceleracion en "x" y "y"
  float xf, yf;                        // posicion final en "x" y "y"

  cout << "Enter initial speed" << endl;
  cin >> v0;
  cout << "Enter 'Y' initial height" << endl;
  cin >> y0;
  cout << "Enter angle" << endl;
  cin >> theta;
  cout << "Enter sampling time" << endl;
  cin >> t;
  cout << "Enter friction coefficient" << endl;
  cin >> k;

  float mp=t;                      // variable auxiliar
  t=0;

  if (k == 0){


      cout << "\t\t\t PARABOLIC MOTION WITHOUT FRICTION" << endl;

      for(int i=0;i<=mp;i++)
       {

        x= v0*cos((theta*PI)/180)*t;                       // ecuacion para posicion en x
        y= y0+v0*sin((theta*PI)/180)*t-0.5*g*pow(t,2);     // ecuaciones para posicion en y
        vx= v0*cos((theta*PI)/180);                        // ecuacion para componente de velocidad en x
        vy= v0*sin((theta*PI)/180)-g*t;                    // ecuacion para componente de velocidad en y con aceleracion constante

        cout << "\nPosition in x for t= "<<t << " seg. is: "<<x<< " m " << endl;
        cout << "Position in y for t= "<<t<<" seg. is: "<<y<< " m " <<  endl;
        cout << "Speed in x for t= "<<t<<" seg. is: "<<vx<< " m/s " <<  endl;
        cout << "Speed in y for t= "<<t<<" seg. is: "<<vy<< " m/s " << endl;
        cout <<endl;

        t++;

       }
   }
    else {

         cout << "Enter mass" << endl;
         cin >> m;
         cout << "Enter object radius" << endl;
         cin >> rad;

         cout << "\t\t\tPARABOLIC MOTION WITH FRICTION" << endl;

          for(int i=0;i<=mp;i++)
          {
              // estas dos ecuaciones se toman del movimieno parablico sin friccion, para hallar el angulo (alpha) de la friccion

              vx= v0*cos((theta*PI)/180);
              vy= v0*sin((theta*PI)/180)-g*t;
              alpha= atan(vx/vy);


              // las siguientes ecuaciones describen el movimiento con friccion

              vm=sqrt(pow(vx,2)+pow(vy,2));                            // magnitud velocidad
              ax= -((k*pow(vm,2)*pow(rad,2))/m)*cos(alpha*PI/180);     // ecuacion para la aceleracion en x
              ay= -((k*pow(vm,2)*pow(rad,2))/m)*sin(alpha*PI/180)-g;   // ecuacion para la aceleracion en y

              vxf= v0*cos(theta*PI/180)+(ax*t);                       // ecuacion para componente de velocidad en x
              vyf= v0*sin(theta*PI/180)+(ay*t);                       // ecuacion para componente de velocidad en y

              xf= v0*cos(theta*PI/180)*t+(1/2)*ax*pow(t,2);           // ecuacion para posicion en x
              yf= y0+v0*sin(theta*PI/180)*t+(1/2)*ay*pow(t,2);        // ecuaciones para posicion en y



              cout<<"\nPosition in x for t= "<<t<<" seg. is: "<<xf<< " m " <<endl;
              cout<<"Position in y for t= "<<t<<" seg. is: "<<yf<< " m " <<endl;
              cout<<"Acceleration in x for t= "<<t<<" seg. is: "<<ax<< " m/s^2 " <<endl;
              cout<< "Acceleration in y for t= "<<t<<" seg. is: "<<ay<< " m/s^2 " <<endl;
              cout<< "Speed in x for t= "<<t<<" seg. is: "<<vxf<< " m/s " <<endl;
              cout<< "Speed in y for t= "<<t<<" seg. is: "<<vyf<< " m/s " <<endl;
              cout <<endl;
              t++;
          }

   }


}
