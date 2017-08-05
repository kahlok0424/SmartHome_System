#include "mainsystem.h"
#include <math.h>
#include "get_coordinate.h"
#include "stdlib.h"

GpsCoordinate house = {
  200,
  5345,
};
GpsCoordinate garageDoor = {
  220,
  5300,
};

GpsCoordinate garageCenter = {
  215,
  5300,
};

GpsCoordinate kitchen = {
  196,
  5400,
};

double getRadius(GpsCoordinate Coordinate){
  return sqrt(pow(Coordinate.x, 2) + pow(Coordinate.y, 2));
}

void SmartHome(){
  GpsCoordinate gps;
  gps = get_GPS_Coordinate();

  if(abs(getRadius(gps)-getRadius(house))<=2000){
     turn(AIRCOND, ON);
     turn(WATER_HEATER, ON);
  }
  else{
    turn(AIRCOND,OFF);
    turn(WATER_HEATER,OFF);
  }

  if((abs(getRadius(gps)-getRadius(garageDoor))<=5)){
     turn(GARAGE_DOOR, ON);
  }

  if(getRadius(gps) == getRadius(garageCenter)){
     turn(GARAGE_DOOR, OFF);
  }

  if(abs(getRadius(gps)-getRadius(kitchen))<=50){
     turn(KITCHEN_LIGHT, ON);
  }

}
