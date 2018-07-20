//
//  SAppUpdate.h
//  AppUpdate
//
//  Created by 石文文 on 2018/7/20.
//  Copyright © 2018年 石文文. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAppUpdate : NSObject

/**
 实例化单例对象

 @return SAppUpdate对象
 */
+ (instancetype)shared;

/**
 使用APP ID注册

 @param appId 平台给予的APP ID
 */
- (void)startWithAppId:(NSString *)appId;

/**
 检查更新
 */
- (void)checkUpdate;

@end
