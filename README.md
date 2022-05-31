# LegInverseKinematics_forKHR3

KHR-3、PLEN-Dのような軸構成の足の4自由度(足先xyz位置・yaw姿勢)の逆運動学を解くライブラリです。
商用以外の用途であればご自由にお使いください
KCB-5ライブラリは近藤科学株式会社様の著作物のため付属しておりません。

#使う上での注意

*KCB-5を用いる場合はそのままプロジェクトフォルダにコピーしてmain関数等に#include "hadlib.h"追記しお使いください

*KHR-3と同様の軸配置されたPWM方式サーボで構成されたロボット(PLEN-D等)をARDUINOから制御する場合、IK_RLEG()・IK_LLEG()、IK_Rleg_Rotation()、IK_Lleg_Rotation()以外をコメントアウトし、had_params.hの//#define ARDUINO_PWMをコメント解除したうえでプロジェクトフォルダにコピーしてmain関数等に#include "hadlib.h"追記しお使いください

*KCB-5以外のマイコンボードでKONDOサーボモータに対し使用する場合、Write_angle_R_Leg()、Write_angle_L_Leg()内のics_set_pos関数を適宜対応した角度書き込み関数に置き換えてプロジェクトフォルダにコピーしてmain関数等に#include "hadlib.h"追記しお使いください

#使い方

使用時は以下二種類の関数を用途に応じて使い分けてください。以下二種類は右足用ですが、左足用も同様です。

*IK_RLEG(x,y,z,theta);
 足先位置のx(前後方向),y（左右方向）,z（上下方向）を指定して逆運動学を解きサーボを動かす関数。thetaは足の付け根のyaw軸サーボへの指令値

*IK_RLEG_Rotation(x,y,z,theta);
 足先位置のx(前後方向),y（左右方向）,z（上下方向）,theta（足先のyaw軸姿勢）を指定して逆運動学を解きサーボを動かす関数。

※x,y,zの単位はmm、thetaの単位はdegreeです

#作成者

*Twitter: @safs01075

*mail: safs0107[at]gmail.com ([at]を@に置換)
