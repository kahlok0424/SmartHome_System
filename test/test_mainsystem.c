#include "unity.h"
#include "mainsystem.h"
#include "mock_get_coordinate.h"

GpsCoordinate nearHouse = {
  220,
  4500,
};

GpsCoordinate nearGarage = {
  220,
  5305,
};

GpsCoordinate nearKitchen = {
  200,
  5400,
};

GpsCoordinate leaveHouse = {
  250,
  6500,
};

GpsCoordinate leaveGarage = {
  230,
  5315,
};

GpsCoordinate leaveKitchen = {
  250,
  5600,
};

GpsCoordinate parkedCar = {
  215,
  5300,
};

void setUp(void)
{
}

void tearDown(void)
{
}

void test_smartsystem_house_expect_turn_on_aircond_WaterHeater(void)
{
  get_GPS_Coordinate_ExpectAndReturn(nearHouse);
  turn_Expect(AIRCOND, ON);
  turn_Expect(WATER_HEATER, ON);
  SmartHome();
//  TEST_ASSERT_EQUAL_STRING(AIRCOND , "ON");
}

void test_smartsystem_garageDoor_expect_turn_on_garageDoor(void)
{
  get_GPS_Coordinate_ExpectAndReturn(nearGarage);
  turn_Expect(AIRCOND, ON);
  turn_Expect(WATER_HEATER, ON);
  turn_Expect(GARAGE_DOOR, ON);
  SmartHome();
}

void test_smartsystem_kitchen_expect_turn_on_KitchenLight(void)
{
  get_GPS_Coordinate_ExpectAndReturn(nearKitchen);
  turn_Expect(AIRCOND, ON);
  turn_Expect(WATER_HEATER, ON);
  turn_Expect(KITCHEN_LIGHT, ON);
  SmartHome();
}

void test_smartsystem_leave_house_expect_turn_off_aircond_WaterHeater(void)
{
  get_GPS_Coordinate_ExpectAndReturn(leaveHouse);
  turn_Expect(AIRCOND, OFF);
  turn_Expect(WATER_HEATER, OFF);
  SmartHome();
//  TEST_ASSERT_EQUAL_STRING(AIRCOND , "ON");
}

void test_smartsystem_leave_garageDoor_expect_turn_off_garageDoor(void)
{
  get_GPS_Coordinate_ExpectAndReturn(leaveGarage);
  turn_Expect(AIRCOND, OFF);
  turn_Expect(WATER_HEATER, OFF);
  turn_Expect(GARAGE_DOOR, OFF);
  SmartHome();
}

void test_smartsystem_leave_kitchen_expect_turn_off_KitchenLight(void)
{
  get_GPS_Coordinate_ExpectAndReturn(leaveKitchen);
  turn_Expect(AIRCOND, OFF);
  turn_Expect(WATER_HEATER, OFF);
  turn_Expect(KITCHEN_LIGHT, OFF);
  SmartHome();
}

void test_smartsystem_lparked_car_expect_turn_off_garage_Door(void)
{
  get_GPS_Coordinate_ExpectAndReturn(parkedCar);
  turn_Expect(GARAGE_DOOR, OFF);
  SmartHome();
}
