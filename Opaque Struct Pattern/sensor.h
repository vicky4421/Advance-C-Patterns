#ifndef SENSOR_H
#define SENSOR_H

// Forward declaration of the Sensor struct
typedef struct Sensor Sensor;

// Constructor and destructor for the Sensor struct
Sensor *create_sensor(int id);
void destroy_sensor(Sensor *sensor);

// Public interface for the Sensor struct
void sensor_read(Sensor *sensor);
int sensor_get_id(const Sensor *sensor);

#endif // SENSOR_H