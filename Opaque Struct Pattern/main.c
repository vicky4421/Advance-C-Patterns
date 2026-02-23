#include "sensor.h"
#include <stdio.h>

// Example usage of the Sensor API
int main()
{

    // Create a new sensor instance
    Sensor *sensor = create_sensor(101);

    // Use the sensor API to interact with the sensor
    sensor_read(sensor);            // Read a value from the sensor
    int id = sensor_get_id(sensor); // Get the sensor's ID
    destroy_sensor(sensor);         // Clean up the sensor instance
}