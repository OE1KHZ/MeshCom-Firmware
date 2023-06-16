// (C) 2023 OE1KBC Kurt Baumann, OE1KFR Rainer 
// (C) 2016, 2017, 2018, 2018, 2019, 2020 OE1KBC Kurt Baumann
//
// This code is not for distribution and may not be published!
// Vervielfältigung und Veröffentlichung des Codes sind nicht gestattet!
// Lizenz: kein Open Source.
// zugelassen ausschließlich für OE1KBC, OE1KFR
// alle anderen Finger weg !
// 20230326: Version 4.00: START

extern unsigned long rebootAuto;

extern bool bDEBUG;
extern bool bPosDisplay;
extern bool bDisplayOff;
extern bool bDisplayVolt;
extern bool bDisplayInfo;
extern unsigned long DisplayOffWait;
extern int DisplayTimeWait;
extern unsigned long BattTimeWait;
extern unsigned long BMXTimeWait;
extern bool bButtonCheck;
extern bool bDisplayTrack;
extern bool bGPSON;
extern bool bBMPON;
extern bool bBMEON;

extern bool bGATEWAY;
extern bool bEXTERN;

extern float fBaseAltidude;
extern float fBasePress;

// common variables
extern char msg_text[MAX_MSG_LEN_PHONE];

extern unsigned int _GW_ID; // ID of our Node

extern unsigned int msg_counter;

extern uint8_t RcvBuffer[UDP_TX_BUF_SIZE];

extern uint8_t own_msg_id[MAX_RING][5];

// RINGBUFFER for incoming UDP lora packets for lora TX
extern unsigned char ringBuffer[MAX_RING][UDP_TX_BUF_SIZE];
extern int iWrite;
extern int iRead;

extern bool hasMsgFromPhone;

// BLE Ringbuffer to phone
extern unsigned char BLEtoPhoneBuff[MAX_RING][UDP_TX_BUF_SIZE];
extern int toPhoneWrite;
extern int toPhoneRead;

extern uint8_t ringBufferLoraRX[MAX_RING_UDP_OUT][4]; //Ringbuffer for UDP TX from LoRa RX, first byte is length
extern uint8_t udpWrite;   // counter for ringbuffer
extern uint8_t udpRead;    // counter for ringbuffer

extern int cmd_counter; // ticker dependant on main cycle delay time
extern bool is_receiving;   // flag to store we are receiving a lora packet.
extern bool tx_is_active;   // flag to store we are transmitting  a lora packet.

extern uint8_t isPhoneReady;      // flag we receive from phone when itis ready to receive data

// timers
extern unsigned long posinfo_interval; // check interval
extern int posinfo_distance;
extern double posinfo_direction;
extern int posinfo_distance_ring[10];
extern int posinfo_ring_write;
extern double posinfo_lat;
extern double posinfo_lon;
extern double posinfo_last_lat;
extern double posinfo_last_lon;
extern double posinfo_last_direction;
extern uint32_t posinfo_satcount;
extern int posinfo_hdop;
extern bool posinfo_fix;
extern bool posinfo_shot;
extern int no_gps_reset_counter;

extern unsigned long posinfo_timer;      // we check periodically to send GPS
extern unsigned long temphum_timer;      // we check periodically get TEMP/HUM
extern unsigned long druck_timer;        // we check periodically get AIRPRESURE
extern unsigned long hb_timer;           // GW Server-Heartbeat-Timer

// batt
extern float global_batt;