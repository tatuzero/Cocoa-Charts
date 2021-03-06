//
//  CCSStickChart.h
//  Cocoa-Charts
//
//  Created by limc on 11-10-25.
//  Copyright 2011 limc.cn All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <Foundation/Foundation.h>
#import "CCSGridChart.h"

/*!
 CCSStickChart
 
 CCSStickChart is a kind of graph that draw the sticks on a CCSGridChart
 if you want display some moving average lines on this graph, please use see
 CCSMAStickChart for more information
 
 CCSStickChartはCCSGridChartの表面でスティックを書いたラインチャードです。移動平均線など
 分析線がお使いしたい場合、CCSMAStickChartにご参照ください。
 
 CCSStickChart是在CCSGridChart上绘制柱状数据的图表、如果需要支持显示均线，请参照
 CCSMAStickChart。
 */
@interface CCSStickChart : CCSGridChart {
    NSArray *_stickData;
    UIColor *_stickBorderColor;
    UIColor *_stickFillColor;
    NSUInteger _latitudeNum;
    NSUInteger _longitudeNum;
    NSUInteger _maxSticksNum;
    NSUInteger _selectedStickIndex;
    CGFloat _maxValue;
    CGFloat _minValue;
    NSUInteger _axisCalc;
    CCSStickChart *_coChart;
}

/*!
 Data for display stick
 スティックを表示用データ
 表示柱条用的数据
 */
@property(retain, nonatomic) NSArray *stickData;

/*!
 Color for display stick boder
 表示スティックのボーダーの色
 表示柱条的边框颜色
 */
@property(retain, nonatomic) UIColor *stickBorderColor;

/*!
 Color for display stick
 表示スティックの色
 表示柱条的填充颜色
 */
@property(retain, nonatomic) UIColor *stickFillColor;

/*!
 Numbers of grid‘s latitude line
 緯線の数量
 网格纬线的数量
 */
@property(assign, nonatomic) NSUInteger latitudeNum;

/*!
 Numbers of grid‘s longitude line
 経線の数量
 网格经线的数量
 */
@property(assign, nonatomic) NSUInteger longitudeNum;

/*!
 Max number of sticks
 スティックの最大数量
 表示柱条的最大数量
 */
@property(assign, nonatomic) NSUInteger maxSticksNum;

/*!
 Selected index of sticks
 選べたスティック
 被选中的柱条
 */
@property(assign, nonatomic) NSUInteger selectedStickIndex;

/*!
 Max display value of axis Y
 Y軸の最大値
 Y轴显示最大值
 */
@property(assign, nonatomic) CGFloat maxValue;

/*!
 Min display value of axis Y
 Y軸の最小値
 Y轴显示最小值
 */
@property(assign, nonatomic) CGFloat minValue;

/*!
 fast calculator for axis Y degrees （display degrees＝degrees/axisCalc）
 Y軸目盛りの快速計算子，（表示目盛り＝計算目盛り/axisCalc）
 Y轴显示值的快速计算子（表示刻度＝ 计算刻度/axisCalc）
 */
@property(assign, nonatomic) NSUInteger axisCalc;


/*!
 if this chart touched,will effect some other charts,this value is for save them
 連携チャート、チャートに関する動作の連携用
 两个相同类型图表之间传值用对象
 */
@property(assign, nonatomic) CCSStickChart *coChart;


/*!
 @abstract Draw sticks to this graph
 スティックデータを使いてスティックを書く
 使用数据绘制柱条
 
 @param rect the rect of the grid
 グリドのrect
 图表的rect
 */
- (void)drawData:(CGRect)rect;

/*!
 @abstract Init X axis degrees
 初期化X軸の目盛
 初始化X轴的刻度
 */
- (void)initAxisX;

/*!
 @abstract Init Y axis degrees
 初期化Y軸の目盛
 初始化Y轴的刻度
 */
- (void)initAxisY;

/*!
 calculate the selected index from selected point 
 選べたポイントから選べたインデックスを計算
 计算选中的列索引
 */
- (void)calcSelectedIndex;

/*!
 @abstract change the selected point of this graph, Redraw this graph
 選べたポイントを変更して、グラフを再書く
 设置选中的点并重新绘制图表
 
 @param point the point to draw the grid
 選べたポイント
 选中点
 */
- (void)setSelectedPointAddReDraw:(CGPoint)point;
@end
