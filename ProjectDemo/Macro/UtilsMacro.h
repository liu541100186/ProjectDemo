//
//  UtilsMacro.h
//  ProjectDemo
//
//  Created by 时代合盛 on 14-8-27.
//  Copyright (c) 2014年 时代和盛. All rights reserved.
//

#ifndef ProjectDemo_UtilsMacro_h
#define ProjectDemo_UtilsMacro_h


#define APP_SCREEN_WIDTH            [UIScreen mainScreen].bounds.size.width
#define APP_SCREEN_HEIGHT           [UIScreen mainScreen].bounds.size.height
#define APP_SCREEN_CONTENT_HEIGHT   ([UIScreen mainScreen].bounds.size.height-STATUEBAR_HEIGHT)
#define NAVIGATIONBAR_HEIGHT 44.0f
#define STATUEBAR_HEIGHT 20.0f

#define IOS_7 ([[[UIDevice currentDevice] systemVersion]floatValue]>=7.0? YES:NO)
#define IS_4_INCH                   (APP_SCREEN_HEIGHT > 480.0)

//加载图片
#define LOAD_IMAGE(file,type) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]]
#define LOAD_IMAGE_PNG(file) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:@"png"]]

//rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

//通知
#define NOTIFICATION_CENTER         [NSNotificationCenter defaultCenter]

//NSUserDefaults
#define USER_DEFAULT                [NSUserDefaults standardUserDefaults]

//单例
#define SINGLETON_GCD(classname)                        \
\
+ (classname *)shared##classname {                      \
\
static dispatch_once_t pred;                        \
__strong static classname * shared##classname = nil;\
dispatch_once( &pred, ^{                            \
shared##classname = [[self alloc] init]; });    \
return shared##classname;                           \
}

#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif


#endif
