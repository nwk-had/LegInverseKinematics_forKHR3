# LegInverseKinematics_forKHR3
![jilkukousei](https://user-images.githubusercontent.com/106475836/171871304-90795f01-4cf2-4193-84b2-5bee93a8e621.png)

KHR-3、PLEN-Dのような軸構成の足の4自由度(足先xyz位置・yaw姿勢)の逆運動学を解くプログラムです。
商用以外の用途であればご自由にお使いください
KCB-5ライブラリは近藤科学株式会社様の著作物のため付属しておりません。

#使う上での注意

*KCB-5でKHR-3を制御する用途に用いる場合

そのままプロジェクトフォルダにコピペしてmain関数等に#include "hadlib.h"追記しお使いください

*KCB-5以外のマイコンボードでKHR-3を制御する場合、PLEN-DのようなPWMサーボで構成されたロボットをARDUINOから制御する場合

IK_RLEG()・IK_LLEG()、IK_Rleg_Rotation()、IK_Lleg_Rotation()をご自身のソースコードにコピペし、サーボへの角度書き込み関数を適宜対応したものに置き換えてて用いる等でお使いください

#使い方(KHR3でKCB-5使用の場合)

まずはWrite_angle_L_Leg(0,0,0,0,0,0),Write_angle_R_Leg(0,0,0,0,0,0)関数のみを実行するプログラムを作成し、直立時の原点調整・トリム調整を行います。
実行時に足を伸びきった状態で直立できていたら成功です。
まっすぐ立たない場合はhad_params.h内の原点調整値(例：deg0_RLEG1)を調整してください。
KCB-5でKHR3を制御する以外の用途の方は、適宜同様に関節位置をオフセットしてお使いください。

使用時は以下二種類の関数を用途に応じて使い分けてください。以下二種類は右足用ですが、左足用も同様です。

*IK_RLEG(x,y,z,theta);
 足先位置のx(前後方向),y（左右方向）,z（上下方向）を指定して逆運動学を解きサーボを動かす関数。thetaは足の付け根のyaw軸サーボへの指令値

*IK_RLEG_Rotation(x,y,z,theta);
 足先位置のx(前後方向),y（左右方向）,z（上下方向）,theta（足先のyaw軸姿勢）を指定して逆運動学を解きサーボを動かす関数。

※x,y,zの単位はmm、thetaの単位はdegreeです

#作成者

*Twitter: @safs01075

*mail: safs0107[at]gmail.com ([at]を@に置換)
