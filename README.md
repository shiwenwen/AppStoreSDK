# AppStoreSDK
> iOS分发平台 软件服务SDK
---

## Install
AppStoreSDK is available through CocoaPods. To install it, simply add the following line to your Podfile:

```obj-c
pod "AppStoreSDK"
```

## Usage
- **Import**

```obj-c
#import <AppUpdate/AppUpdate.h>
```
- **Get start**

```obj-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //初始化SDK
    SAppUpdate *sharedAppUpdate = [SAppUpdate shared];
    [sharedAppUpdate startWithAppId:@"71EF911A4D7B1D088FC7421882B6E4507486FE9D77A60A16C700FB4AAD2281D2"]; //AppId需要联系平台获取
    
    //启动时检查软件更新 当然你可以在任意需要更新的地方调用
    [sharedAppUpdate checkUpdateWith:NULL];
    
    return YES;
}
```
- **You can use it anywhere you want to check for updates**

```obj-c
- (IBAction)checkUpdate:(id)sender {
    [[SAppUpdate shared] checkUpdateWith:^(BOOL needUpdate) {
        if (needUpdate) {
            //一些保存操作等
        }else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [[[UIAlertView alloc]initWithTitle:@"提示" message:@"暂无更新" delegate:nil cancelButtonTitle:@"知道了" otherButtonTitles:nil] show];
                });
        }
        
    }];
}
```

## Method

```obj-c
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
```

**You can see the demo** [AppStoreSDKDemo](https://github.com/shiwenwen/AppStoreSDKDemo).

## Author

Michael Waterfall, shiwenwendevelop@163.com

## License

AppStoreSDK is available under the MIT license. See the LICENSE file for more info.

## Contact 

**如果需要企业证书重签名业务，APP分发下载服务，请联系:**

- QQ: 1152164614
- WeChat: sww15551706520
- Email: shiwenwendevelop@163.com

