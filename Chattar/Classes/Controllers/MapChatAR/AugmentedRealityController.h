//
//  AugmentedRealityController.h
//  MashApp-location_users-ar-ios
//
//  Created by QuickBlox developers on 3/26/12.
//  Copyright (c) 2012 QuickBlox. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <CoreMedia/CoreMedia.h>
#import <CoreVideo/CoreVideo.h>
#import "UserAnnotation.h"
#import "CustomSwitch.h"

@class ARCoordinate;

@interface AugmentedRealityController : UIViewController   <UIAccelerometerDelegate,
                                                            CLLocationManagerDelegate,
                                                            AVCaptureVideoDataOutputSampleBufferDelegate,
                                                        	UIActionSheetDelegate>
{
@private
    CGRect viewFrame;
	int switchedDistance;
    
    NSMutableArray *sliderNumbers;
    BOOL showAllUsers;
    
    BOOL isDataRetrieved;
}

@property (nonatomic, assign) BOOL scaleViewsBasedOnDistance;
@property (nonatomic, assign) BOOL transparenViewsBasedOnDistance;
@property (nonatomic, assign) BOOL rotateViewsBasedOnPerspective;

@property (nonatomic, assign) double maximumScaleDistance;
@property (nonatomic, assign) double minimumScaleFactor;
@property (nonatomic, assign) double maximumRotationAngle;
@property (nonatomic, assign) double degreeRange;
@property (nonatomic, assign) double latestHeading;
@property (nonatomic, assign) float  viewAngle;

@property (nonatomic, retain) UIAccelerometer         *accelerometerManager;
@property (nonatomic, retain) CLLocationManager       *locationManager;
@property (nonatomic, retain) ARCoordinate            *centerCoordinate;
@property (nonatomic, retain) CLLocation              *centerLocation;
@property (nonatomic, retain) UIImageView             *displayView;
@property (nonatomic, assign) UIDeviceOrientation	  currentOrientation;

@property (nonatomic, assign) id delegate;

@property (nonatomic, assign) UISlider* distanceSlider;
@property (retain, nonatomic) IBOutlet UIActivityIndicatorView *loadingIndicator;
@property (nonatomic, assign) UILabel* distanceLabel;
@property (nonatomic, retain) UIActionSheet* userActionSheet;
@property (retain) UserAnnotation *selectedUserAnnotation;
@property (nonatomic, assign) CustomSwitch *allFriendsSwitch;

/*!
 @brief	The capture session takes the input from the camera and capture it
 */
@property (nonatomic, retain) AVCaptureSession *captureSession;

- (IBAction) initCapture;

- (id)initWithViewFrame:(CGRect) viewFrame;

- (void)displayAR;
- (void)dissmisAR;

- (void)updateLocations;
- (void)updateMarkersPositionsForCenterLocation:(CLLocation *)_centerLocation;

// points
- (void)refreshWithNewPoints:(NSArray *)mapPoints;
- (void)addPoints:(NSArray *)mapPoints;
- (void)addPoint:(UserAnnotation *)point;

- (void)clear;


- (UIView *)viewForAnnotation:(UserAnnotation *)annotation;
- (UIView *)viewForExistAnnotation:(UserAnnotation *)userAnnotation;

// Adding coordinates to the underlying data model.
- (void)addCoordinate:(ARCoordinate *)coordinate augmentedView:(UIView *)agView animated:(BOOL)animated ;

// Removing coordinates
- (void)removeCoordinate:(ARCoordinate *)coordinate;
- (void)removeCoordinate:(ARCoordinate *)coordinate animated:(BOOL)animated;
- (void)removeCoordinates:(NSArray *)coordinateArray;

- (IBAction)distanceDidChanged:(id)sender;

@end
