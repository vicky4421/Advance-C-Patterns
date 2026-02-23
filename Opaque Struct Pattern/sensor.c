#include <stdlib.h>
#include <stdio.h>
#include "sensor.h"

// Definition of the Sensor struct (opaque to users of the API)
struct Sensor
{
    int id;
    float last_reading;
    int battery_level;
};

// Implementation of constructor and destructor for the Sensor struct
Sensor *create_sensor(int id)
{
    Sensor *sensor = malloc(sizeof(Sensor));
    if (sensor)
    {
        sensor->id = id;
        sensor->last_reading = 0.0f;
        sensor->battery_level = 100; // Assume new sensor starts with full battery
    }
    return sensor;
}

void destroy_sensor(Sensor *sensor)
{
    free(sensor);
}

// Implementation of the public interface for the Sensor struct
void sensor_read(Sensor *sensor)
{
    if (sensor)
    {
        // Simulate reading a value from the sensor
        sensor->last_reading = (float)(rand() % 100); // Random reading between 0 and 99
        printf("Sensor ID %d: New reading = %.2f\n", sensor->id, sensor->last_reading);
    }
}

int sensor_get_id(const Sensor *sensor)
{
    return sensor ? sensor->id : -1; // Return -1 if sensor is NULL
}