//
//  ViewController.m
//  PTCallKit
//
//  Created by pantao on 2018/2/9.
//  Copyright © 2018年 pantao. All rights reserved.
//

#import "ViewController.h"
#import "Contact.h"
#import "PTCallKitManager.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        
    });
    
    UIButton *btn = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 200, 100)];
    btn.center = self.view.center;
    [self.view addSubview:btn];
    btn.backgroundColor = [UIColor purpleColor];
    [btn addTarget:self action:@selector(click) forControlEvents:UIControlEventTouchUpInside];
}

- (void)click
{
    NSUUID *callUUID = [[PTCallKitManager sharedInstance] reportIncomingCallWithContact:[Contact new] completion:^(NSError * _Nullable error) {

    }];
}


@end
