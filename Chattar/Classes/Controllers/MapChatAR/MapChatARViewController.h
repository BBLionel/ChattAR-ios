//
//  MapChatARViewController.h
//  ChattAR for Facebook
//
//  Created by Alexey on 21.03.12.
//  Copyright (c) 2012 QuickBlox. All rights reserved.
//

#import "MapViewController.h"
#import "ChatViewController.h"
#import "AugmentedRealityController.h"
#import "FBServiceResultDelegate.h"

#define kGetGeoDataCount 100
#define kDEFAULT_CLUSTER_SIZE 0.2

@class ChatViewController;
@class MapViewController;

@interface MapChatARViewController : UIViewController <QBActionStatusDelegate, FBServiceResultDelegate, UIActionSheetDelegate, FBRequestDelegate, CLLocationManagerDelegate,
MKMapViewDelegate>{
    
    NSTimer *updateTimre;
    
    short numberOfCheckinsRetrieved;
    
    BOOL isInitialized;
    
    UIActivityIndicatorView *activityIndicator;
    
    dispatch_queue_t processCheckinsQueue;
    
    dispatch_queue_t processPhotosWithLocationsQueue;
    
    BOOL showAllUsers;
    
}

@property (assign) NSMutableArray* allMapPoints;
@property (assign) NSMutableArray* allChatPoints;
@property (assign) NSMutableArray* allCheckins;
@property (nonatomic,retain) NSMutableArray* allPhotosWithLocations;

@property (assign) NSMutableArray *mapPoints;
@property (assign) NSMutableArray *chatPoints;
@property (nonatomic,retain) NSMutableArray* photoPoints;

@property (assign) NSMutableArray *chatMessagesIDs;
@property (assign) NSMutableArray *mapPointsIDs;

@property (nonatomic, retain) CLLocationManager *locationManager;

@property (nonatomic, retain) UIActionSheet *userActionSheet;

@property (retain) IBOutlet MapViewController *mapViewController;
@property (retain) IBOutlet ChatViewController *chatViewController;
@property (retain) AugmentedRealityController *arViewController;

@property (nonatomic, assign) UISegmentedControl *segmentControl;

@property (retain) UserAnnotation *selectedUserAnnotation;

@property (nonatomic, assign) BOOL initedFromCache;

@property (nonatomic, assign) CustomSwitch *allFriendsSwitch;

@property (assign) short initState; // 2 if all data(map/chat) was retrieved



- (void)segmentValueDidChanged:(id)sender;
- (void)showRadar;
- (void)showChat;
- (void)showMap;

- (void)allFriendsSwitchValueDidChanged:(id)sender;
- (BOOL)isAllShowed;

- (void)createAndAddNewAnnotationToMapChatARForFBUser:(NSDictionary *)fbUser withGeoData:(QBLGeoData *)geoData addToTop:(BOOL)toTop withReloadTable:(BOOL)reloadTable;

- (void)touchOnMarker:(UIView *)marker;
- (void)showActionSheetWithTitle:(NSString *)title andSubtitle:(NSString*)subtitle;

@end
