#ifndef _GET_COORDINATE_H
#define _GET_COORDINATE_H

typedef struct GpsCoordinate GpsCoordinate;
struct GpsCoordinate {
  float x;
  float y;
};

typedef enum {
  AIRCOND,
  GARAGE_DOOR,
  WATER_HEATER,
  KITCHEN_LIGHT,
}Device;

typedef enum {
  OFF,
  ON
} State;

void turn(Device device, State state);
GpsCoordinate get_GPS_Coordinate();

#endif // _GET_COORDINATE_H
