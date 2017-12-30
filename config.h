
#ifndef CONFIG_H_
#define CONFIG_H_

#include "utils.h"
#include "aq_serial.h"
#include "aqualink.h"


#define DEFAULT_LOG_LEVEL    10 
#define DEFAULT_WEBPORT      "6580"
#define DEFAULT_WEBROOT      "./"
#define DEFAULT_SERIALPORT   "/dev/ttyUSB0"
#define DEFAULT_DEVICE_ID    "0x0a"
#define DEFAULT_MQTT_DZ_IN   "domoticz/in"
#define DEFAULT_MQTT_DZ_OUT  "domoticz/out"
#define DEFAULT_MQTT_AQ_TP   "aqualinkd"
#define DEFAULT_MQTT_SERVER  "trident:1883"
#define DEFAULT_MQTT_USER    NULL
#define DEFAULT_MQTT_PASSWD  NULL

#define MQTT_ID_LEN 20

struct aqconfig
{
  char *serial_port;
  unsigned int log_level;
  char *socket_port;
  char *web_directory;
  unsigned char device_id;
  bool deamonize;
  char *log_file;
  char *mqtt_dz_sub_topic;
  char *mqtt_dz_pub_topic;
  char *mqtt_aq_topic;
  char *mqtt_server;
  char *mqtt_user;
  char *mqtt_passwd;
  char mqtt_ID[MQTT_ID_LEN];
  int dzidx_air_temp;
  int dzidx_pool_water_temp;
  int dzidx_spa_water_temp;
  float light_programming_mode;
  //int dzidx_pool_thermostat; // Domoticz virtual thermostats are crap removed until better
  //int dzidx_spa_thermostat;  // Domoticz virtual thermostats are crap removed until better
  //char mqtt_pub_topic[250];
  //char *mqtt_pub_tp_ptr = mqtt_pub_topic[];
};


void init_parameters (struct aqconfig * parms);
//bool parse_config (struct aqconfig * parms, char *cfgfile);
//void readCfg (struct aqconfig *config_parameters, char *cfgFile);
void readCfg (struct aqconfig *config_parameters, struct aqualinkdata *aqualink_data, char *cfgFile);

#endif