#ifndef BATTERY_H
#define BATTERY_H

// Ardumower battery/charger management

#include <Arduino.h>


class BatteryControl
{
  public:
    bool enableMonitor;
    float batFactor       ;     // battery conversion factor
    float batGoHomeIfBelow;     // drive home voltage (Volt)
    float batSwitchOffIfBelow;  // switch off battery if below voltage (Volt)
    int batSwitchOffIfIdle ;      // switch off battery if idle (minutes)  
    float batChgFactor       ;     // battery conversion factor    
    float batFull         ;      // battery reference Voltage (fully charged)
    float batChargingCurrentMax ; // maximum current your charger can devliver
    float batFullCurrent   ; // current flowing when battery is fully charged
    float startChargingIfBelow; // start charging if battery Voltage is below
    unsigned long chargingTimeout; // safety timer for charging
    int batADC;
    float chgSenseZero    ;       // charge current sense zero point
    float chgFactor       ;     // charge current conversion factor
    float chgSense        ;       // mV/A empfindlichkeit des Ladestromsensors in mV/A (Für ACS712 5A = 185)
    char chgChange        ;       // messwertumkehr von - nach +         1oder 0
    float batVoltage ;  // battery voltage (Volt)
    byte chgSelection     ;       // Senor Auswahl
    float batRefFactor ;
    float batCapacity ; // battery capacity (mAh)
    float chgVoltage ;  // charge voltage (Volt)
    float chgCurrent ;  // charge current  (Ampere)
    int chgNull;        // Nulldurchgang Ladestromsensor         
    int batteryReadCounter;
    bool chargeRelayEnabled;
    int idleTimeSec;    // number of seconds robot is idle (no user-interaction and no mowing)
    BatteryControl();            
    void setup();    
    void run();        
    void read();       
    void print();    
    void setBatterySwitch(bool state);
    bool chargerConnected();
    bool robotShouldGoHome();
    bool robotShouldSwitchOff();
    bool robotShouldStartCharging();
    void enableChargingRelay(bool state);
  private:
    unsigned long nextBatteryTime;
};


extern BatteryControl Battery;  

  
#endif
