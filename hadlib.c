/*
 * hadlib.c
 *
 *  Created on: 2021/09/12
 *  Author: HidemiANDO(@safs01075)
 *  Copyright © <Year> HidemiANDO. All rights reserved.
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "had_params.h"
#include "hadlib.h"

//for KCB-5
#include "kcb5.h"
#include "pio.h"
#include "ics.h"
#include "uart.h"
#include "timer.h"
#include "ad.h"
#include "dac.h"
#include "i2c.h"

void Write_angle_R_Leg(float deg1,float deg2,float deg3,float deg4,float deg5,float deg6){

	ics_set_pos (UART_SIO1, 5, translate_Deg_to_Step(deg0_RLEG1+deg1));
	ics_set_pos (UART_SIO1, 6, translate_Deg_to_Step(deg0_RLEG2+deg2));
	ics_set_pos (UART_SIO1, 7, translate_Deg_to_Step(deg0_RLEG3+deg3));
	ics_set_pos (UART_SIO1, 8, translate_Deg_to_Step(deg0_RLEG4+deg4));
	ics_set_pos (UART_SIO1, 9, translate_Deg_to_Step(deg0_RLEG5+deg5));
	ics_set_pos (UART_SIO1, 10, translate_Deg_to_Step(deg0_RLEG6+deg6));
}

void Write_angle_L_Leg(float deg1,float deg2,float deg3,float deg4,float deg5,float deg6){

	ics_set_pos (UART_SIO2, 5, translate_Deg_to_Step(deg0_LLEG1-deg1));
	ics_set_pos (UART_SIO2, 6, translate_Deg_to_Step(deg0_LLEG2-deg2));
	ics_set_pos (UART_SIO2, 7, translate_Deg_to_Step(deg0_LLEG3-deg3));
	ics_set_pos (UART_SIO2, 8, translate_Deg_to_Step(deg0_LLEG4-deg4));
	ics_set_pos (UART_SIO2, 9, translate_Deg_to_Step(deg0_LLEG5-deg5));
	ics_set_pos (UART_SIO2, 10, translate_Deg_to_Step(deg0_LLEG6-deg6));

}

unsigned short translate_Deg_to_Step(float deg){
	short step=7500;
	step=7500+(short)((deg*(float)4000)/(float)135);

	if (step < 3500)
	{
		step = 3500;
	}
	if (step > 11500)
	{
		step = 11500;
	}
	return step;
}

void IK_Rleg(float x,float y,float z,float thR){//thRは単にももピッチ角(deg)

  float dth0=thR;
  float dth1=0;
  float dth2=0;
  float dth3=0;
  float dth4=0;
  float dth5=0;

  //int n=0;

  //モモくるぶしロール角計算
  dth1=atan(y/fabsf(z+lsoleoffset))* 180.0 / PI;
  dth5=atan(y/fabsf(z+lsoleoffset))* 180.0 / PI;

  //膝関節角計算
//  float zmagshoumen;
//  float zmaghiza;
//  zmagshoumen=sqrt(pow(y,2)+pow(zankle,2));
//  zmaghiza=sqrt(pow(abs(zmagshoumen-2*loffset),2)+pow(x,2));
//  dth3=180-2*(asin(zmaghiza/(2*l1))* 180.0 / PI);
  float zmagshoumen;
  float zmaghiza;
  zmagshoumen=sqrtf(pow(y,2)+pow(z+lsoleoffset,2));
  zmaghiza=sqrt(pow(abs(zmagshoumen-2*loffset),2)+pow(x,2));
  dth3=180-2*(asin(zmaghiza/(2*l1))* 180.0 / PI);

  //モモピッチ、くるぶしピッチ計算
  dth2=atan(x/fabsf(zmagshoumen-2*loffset))* 180.0 / PI+(90-asin(zmaghiza/(2*l1))* 180.0 / PI);
  dth4=atan(x/fabsf(zmagshoumen-2*loffset))* 180.0 / PI-(90-asin(zmaghiza/(2*l1))* 180.0 / PI);

#ifdef ARDUINO_PWM
  servo_write(0,th1+dth1);
  servo_write(1,th2-dth2);
  servo_write(2,th3+dth3);
  servo_write(3,th4-dth4);
  servo_write(4,th5+dth5);
#else
  Write_angle_R_Leg(dth0,dth1,-dth2,-dth3,-dth4,dth5);
#endif
}

void IK_Lleg(float x,float y,float z,float thL){//thLは単にももピッチ角(deg)


  float dth0=thL;
  float dth1=0;
  float dth2=0;
  float dth3=0;
  float dth4=0;
  float dth5=0;

  //モモくるぶしロール角計算
  dth1=atan(y/fabsf(z+lsoleoffset))* 180.0 / PI;
  dth5=atan(y/fabsf(z+lsoleoffset))* 180.0 / PI;

  //膝関節角計算
  float zmagshoumen;
  float zmaghiza;
  zmagshoumen=sqrtf(pow(y,2)+pow(z+lsoleoffset,2));
  zmaghiza=sqrt(pow(abs(zmagshoumen-2*loffset),2)+pow(x,2));
  dth3=180-2*(asin(zmaghiza/(2*l1))* 180.0 / PI);

  //モモピッチ、くるぶしピッチ計算
  dth2=atan(x/fabsf(zmagshoumen-2*loffset))* 180.0 / PI+(90-asin(zmaghiza/(2*l1))* 180.0 / PI);
  dth4=atan(x/fabsf(zmagshoumen-2*loffset))* 180.0 / PI-(90-asin(zmaghiza/(2*l1))* 180.0 / PI);


#ifdef ARDUINO_PWM//
  servo_write(8,th1+dth1);
  servo_write(9,th2+dth2);
  servo_write(10,th3-dth3);
  servo_write(10,150);
  servo_write(11,th4+dth4);
  servo_write(12,th5+dth5);
#else
  Write_angle_L_Leg(-dth0,-dth1,-dth2,-dth3,-dth4,-dth5);
#endif
}

void IK_Rleg_Rotation(float x,float y,float z,float thR){//thRはももピッチ角ではなく、足先のピッチ角(deg)

	float x_RotatedAxis=cos(thR/ 180.0 * PI)*x+sin(thR/ 180.0 * PI)*(y);
	float y_RotatedAxis=-sin(thR/ 180.0 * PI)*x+cos(thR/ 180.0 * PI)*(y);

	IK_Rleg(x_RotatedAxis,y_RotatedAxis,z,thR);
}

void IK_Lleg_Rotation(float x,float y,float z,float thL){//thLは単にももピッチ角ではなく、足先のピッチ角(deg)

	float x_RotatedAxis=cos(thL/ 180.0 * PI)*x+sin(thL/ 180.0 * PI)*(y);
	float y_RotatedAxis=-sin(thL/ 180.0 * PI)*x+cos(thL/ 180.0 * PI)*(y);

	IK_Lleg(x_RotatedAxis,y_RotatedAxis,z,thL);
}
