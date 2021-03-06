//
//  CCSLineChart.h
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
#import "CCSStickChart.h"

/*!
 CCSLineChart
 
 CCSLineChart is a kind of graph that draw some lines on a CCSGridChart
 
 CCSLineChartはCCSGridChartの表面でラインを書いたラインチャードです。
 
 CCSLineChart是在CCSGridChart上绘制一条或多条线条的图
 */
@interface CCSLineChart : CCSGridChart {
    NSArray *_linesData;
    NSUInteger _latitudeNum;
    NSUInteger _longitudeNum;
    NSUInteger _selectedIndex;
    CGFloat _lineWidth;
    CGFloat _maxValue;
    CGFloat _minValue;
}

/*!
 Data for display data
 ラインを表示用データ
 表示线条用的数据
 */
@property(retain, nonatomic) NSArray *linesData;

/*!
 Number of latitude lines
 显示纬线数 
 */
@property(assign, nonatomic) NSUInteger latitudeNum;

/*!
 Number of longitude lines
 显示经线数 
 */
@property(assign, nonatomic) NSUInteger longitudeNum;

/*! 
 Selected data's index
 选中的方柱位置
 */
@property(assign, nonatomic) NSUInteger selectedIndex;

/*! 
 Displayed line's width
 ラインのサイズ
 线宽
 */
@property(assign, nonatomic) CGFloat lineWidth;

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
 @abstract Draw lines to this graph
 ラインデータを使いてラインを書く
 使用数据绘制线条
 
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

@end
