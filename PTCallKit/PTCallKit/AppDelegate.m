//
//  AppDelegate.m
//  PTCallKit
//
//  Created by pantao on 2018/2/9.
//  Copyright © 2018年 pantao. All rights reserved.
//

#import "AppDelegate.h"
#import "PTCallKitManager.h"
#import <CallKit/CallKit.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [[PTCallKitManager sharedInstance] setupWithAppName:@"pantao" supportsVideo:YES actionNotificationBlock:^(CXCallAction * _Nonnull action, ADCallActionType actionType) {

    }];
//    [[XWCallKitCenter sharedInstance] configurationCallProvider];
    return YES;
}

@end
