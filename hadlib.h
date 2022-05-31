/*
 * hadlib.h

 *
 *  Created on: 2021/09/12
 *  Author: nwk-had(@safs01075)
 *  Copyright © <2022> nwk-had. All rights reserved.
 *  本プログラムの無断転載・商用利用を禁ずる.
 *
 *
 *  ~~~以下説明~~~
 * 	KHR-3、PLEN-Dのような軸構成の足の4自由度(足先xyz位置・yaw姿勢)の逆運動学を解くライブラリです。
 *  商用以外の用途であればご自由にお使いください
 *  KCB-5ライブラリは近藤科学株式会社様の著作物のため付属しておりません。
 *
 *  PLEN-Dを制御する場合等、ARDUINOでPWM制御のサーボモータに対し使用する場合、IK_RLEG()・IK_LLEG()、
 *  IK_Rleg_Rotation()、IK_Lleg_Rotation()以外をコメントアウトし、
 *  had_params.hの//#define ARDUINO_PWMをコメント解除してお使いください。
 *
 *  KCB-5以外のマイコンボードでKONDOサーボモータに対し使用する場合、Write_angle_R_Leg()、Write_angle_L_Leg()
 *  内のics_set_pos関数を適宜対応した角度書き込み関数に置き換えてご使用ください
 *
 *  使うときは以下二種類の関数を用途に応じて使い分けてください。以下二種類は右足用ですが、左足用も同様です。
 *  IK_RLEG(x,y,z,theta);
 *  	足先位置のx(前後方向),y（左右方向）,z（上下方向）を指定して逆運動学を解きサーボを動かす関数。
 *  	thetaは足の付け根のyaw軸サーボへの指令値
 *  IK_RLEG_Rotation(x,y,z,theta);
 *  	足先位置のx(前後方向),y（左右方向）,z（上下方向）,theta（足先のyaw軸姿勢）を指定して
 *  	逆運動学を解きサーボを動かす関数。
 *
 *	※x,y,zの単位はmm、thetaの単位はdegreeです
 *
 */

#ifndef HADLIB_H_
#define HADLIB_H_



#endif /* HADLIB_H_ */


unsigned short translate_Deg_to_Step(float);
void Write_angle_R_Leg(float,float,float,float,float,float);
void Write_angle_L_Leg(float,float,float,float,float,float);
void IK_Rleg(float,float,float,float);
void IK_Lleg(float,float,float,float);
void IK_Rleg_Rotation(float,float,float,float);
void IK_Lleg_Rotation(float,float,float,float);
