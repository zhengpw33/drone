#ifndef __FTC_RC_H
#define __FTC_RC_H

#include "FTC_Config.h"

#define RC_MID  			1500                     
#define RC_MINCHECK		1200                      
#define RC_MAXCHECK  	1800 
#define RC_MINTHROTTLE 1100
#define RC_MAXTHROTTLE 1900
#define RC_RATE  			50
#define RC_EXPO  			50
#define THR_MID  			50
#define THR_EXPO 			0		

#define PITCH_LOOKUP_LENGTH 7
#define THROTTLE_LOOKUP_LENGTH 12


#define Normal 0
#define Button_Fly  1
#define Button_turn 2
#define Button_Reset 3
enum {
    ROLL = 0,
    PITCH,
    YAW,
    THROTTLE,
    AUX1,
    AUX2,
    AUX3,
    AUX4,
    AUX5,
    AUX6
};

class FTC_RC
{
	
public:
	
	FTC_RC();

	uint16_t rawData[10];
	int16_t Command[4];
  uint16_t mymode;
	//参数初始化
	void Init(void);
	//遥控通道数据处理
	void Cal_Command(void);
	//摇杆位置检测
	void check_sticks(void);
	//辅助通道检测
	void CheckAUX(void);

private:
	
	int16_t lookupPitchRollRC[PITCH_LOOKUP_LENGTH];     
	int16_t lookupThrottleRC[THROTTLE_LOOKUP_LENGTH]; 

};

extern FTC_RC rc;

#endif



