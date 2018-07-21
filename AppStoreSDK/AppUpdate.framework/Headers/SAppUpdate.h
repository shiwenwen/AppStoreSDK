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
- (void)startWithAppId:(nonnull NSString *)appId;


/**
 检查更新

 @param callback 检查更新回调
 * needUpdate表示是否需要更新，如果需要更新，更新的处理已经在SDK内部实现 callback会在进行更新前调用，callback中可以做一些保存操作等。
 */
- (void)checkUpdateWith:(nullable void (^)(BOOL needUpdate))callback;

@end
