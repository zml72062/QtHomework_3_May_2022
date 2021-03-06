# 「保卫 4.0」塔防游戏

## 概述

本游戏为北京大学《程序设计实习》课程的一次大作业，使用 Qt 开发.

### 玩法简介

游戏共有 8 个关卡，分别对应大一上学期到大四下学期，关卡难度逐渐上升，玩家需要依次通过八个关卡才能通关。

在每个关卡中，敌人会从起点根据给定的路线前往终点，在终点处会有一个 4.0 标识。关卡中的一些位置会出现漏洞，玩家可以在漏洞上花费学分绩建造不同的 bug，每种 bug 能够对不同的敌人产生不同的效果（比如减速、减少生命值），每杀掉一个敌人，敌人会掉落学分绩。玩家的目的就是尽可能地阻止敌人到达终点的 4.0。每个关卡中存在 4.0 率上限，若敌人拿到 4.0 的比例超过 4.0 率上限时，游戏失败。

* 游戏中玩家可以建造的 bug 一览如下:

|类型	|说明	|对敌人的效果|	价格（相对）|
|:---|:---|:---|:---|
|WA|	糟糕,有case过不了,所有单位需要进行debug|	单体伤害，对目标小范围内敌人造成减速|1|
|TLE|	Python系单位永远对TLE头大	|单体伤害，对Python系敌人伤害2，对C系和卷王系敌人伤害0.5|	1|
|CE|	C系单位忘不了数十个Error扑面而来的恐惧|	单体伤害，对C系敌人伤害2，对Python系和卷王系敌人伤害0.5|	1|
|PE|	呵，小bug！不急不急慢慢debug|	无法造成伤害，但会阻挡敌人前进|	0.5|
|RTE|	你永远不知道你的代码和编译器干了什么|	需要蓄能时间，蓄能结束后杀死攻击范围内血量最高的C系单位|	2|

* 游戏中需要击败的对手一览如下:

|类型|	说明|	移动速度	|血量|	特殊技能|
|:---|:---|:---|:---|:---|
|C类学生|	C语言是全世界最好的语言|	快|	低||	
|Python类学生|	Python是全世界最好的语言|	慢|	高||	
|啥都会的卷王|	百bug不侵|	受到伤害时快，否则慢|	高|	一段时间未收到伤害会回血|
|跨院系选课的菜鸡|	呜呜呜中期退课怎么截止了|	慢|	低|	被杀死掉落学分绩*2|
