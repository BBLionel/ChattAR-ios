//
//  SplashController.h
//  FB_Radar
//
//  Created by Sonny Black on 04.05.12.
//  Copyright (c) 2012 Injoit. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FBServiceResultDelegate.h"

@interface SplashController : UIViewController <QBActionStatusDelegate, FBServiceResultDelegate, FBSessionDelegate>{
    IBOutlet UIActivityIndicatorView *activityIndicator;
    IBOutlet UIButton *loginButton;
}

@property (nonatomic) BOOL openedAtStartApp;

@property (retain, nonatomic) IBOutlet UIImageView *backgroundImage;
- (IBAction)login:(id)sender;
- (void)startApplication;
- (void)showLoginButton:(BOOL)isShow;

@end