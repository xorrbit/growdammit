
// SSID and password
const char* wifi_ssid = "";
const char* wifi_password = "";

// google sheets logging url
// as per https://wp.josh.com/2014/06/04/using-google-spreadsheets-for-logging-sensor-data/
const char* logging_host = "script.google.com";
const char* logging_url = "";

// how often to log sensor info, in ms
#define LOG_PERIOD 60000

// NTP server, defaults should be gucci
const char* ntp_server = "time.nist.gov";
const unsigned int ntp_port = 123;
const unsigned int ntp_local_port = 1337;


