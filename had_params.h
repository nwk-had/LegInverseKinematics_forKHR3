/*
 * had_params.h
 *
 *  Created on: 2021/09/12
 *  Author: HidemiANDO(@safs01075)
 *  Copyright © <Year> HidemiANDO. All rights reserved.
 */

#ifndef HAD_PARAMS_H_
#define HAD_PARAMS_H_


//ここで原点調整やトリム調整を行います。脚が良い感じにまっすぐになるよう適当に値を調整してください
#define deg0_RLEG1 0
#define deg0_RLEG2 0
#define deg0_RLEG3 0
#define deg0_RLEG4 60
#define deg0_RLEG5 24
#define deg0_RLEG6 0

#define deg0_LLEG1 0
#define deg0_LLEG2 0
#define deg0_LLEG3 0
#define deg0_LLEG4 -60
#define deg0_LLEG5 -24
#define deg0_LLEG6 0

#define deg0_RARM1 0
#define deg0_RARM2 45
#define deg0_RARM3 0
#define deg0_RARM4 0
#define deg0_RARM5 -90

#define deg0_LARM1 0
#define deg0_LARM2 -45
#define deg0_LARM3 0
#define deg0_LARM4 0
#define deg0_LARM5 90


//link length (mm)
#define l1 65
#define l2 65//=l1なので使わないかも
#define loffset 40
#define lsoleoffset 20
#define PI 3.1415926

//#define ARDUINO_PWM
#endif /* HAD_PARAMS_H_ */
